// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <gtest/gtest.h>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <string>
#include <memory>
#include <exception>
#include <limits>

#include "c_string.h"

#include <cstring>
#include <cstdint>

struct access_private {
    size_t capacity_m;
    size_t size_m;
    char *data_m;
};

namespace {

    class ClassDeclaration : public testing::Test {
    protected:
        ClassDeclaration() = default;

        // because there are no empty constructors this year.
        // TODO: 2023 - fix it.
        my_str_t string_size_20 = my_str_t{20, 'c'};
        my_str_t string_size_2 = my_str_t{2, 'c'};
        my_str_t string_empty = my_str_t("");

        void SetUp() override {
            string_size_20 = my_str_t{20, 'c'};
            string_size_2 = my_str_t{2, 'c'};
            string_empty = my_str_t("");
        };

    };

}

TEST_F(ClassDeclaration, constructors) {
    // test string parameters after create
    ASSERT_EQ(string_size_20.size(), 20);
    ASSERT_EQ(string_size_20.capacity(), 31);

    ASSERT_EQ(string_empty.size(), 0);
    ASSERT_EQ(string_empty.capacity(), 15);

    // test create return code if string != NULL
    ASSERT_NO_THROW(my_str_t(20, 'c'));

    // should assert 1 out of 2. TODO: rewrite to have one assert
    ASSERT_ANY_THROW((my_str_t{std::numeric_limits<size_t>::max()/100, 'c'}));
}

TEST_F(ClassDeclaration, cstring_constructor) {
    // TODO
    ASSERT_NO_THROW(my_str_t("hello"));
}

TEST_F(ClassDeclaration, stdstring_constructor) {
    // TODO
    ASSERT_NO_THROW(my_str_t("hello"));
}

TEST_F(ClassDeclaration, copy_constructor) {
    // TODO
    ASSERT_NO_THROW(my_str_t("hello"));
}

TEST_F(ClassDeclaration, my_str_size) {
    // Check the size of a normal string
    ASSERT_EQ(string_size_20.size(), 20);
}

TEST_F(ClassDeclaration, my_str_capacity) {
    // Check the capacity of a normal string
    ASSERT_EQ(string_size_20.capacity(), 31);
    ASSERT_EQ(string_size_2.capacity(), 15);
    ASSERT_EQ(string_empty.capacity(), 15);
}

// TODO: add such method for 2023 =)
//TEST_F(ClassDeclaration, my_str_empty) {
//    // Check an empty string
//    ASSERT_TRUE(string1.);
//
//    // Check the NULL pointer
//    ASSERT_TRUE(my_str_empty(nullptr));
//
//    // Check a non-empty string
//    string1.m_size = 1;
//    ASSERT_FALSE(my_str_empty(&string1));
//}

//TEST_F(ClassDeclaration, my_str_getc) {
//    my_str_from_cstr(&string1, "hello, world!", 20);
//
//    // check position inside
//    ASSERT_EQ(my_str_getc(&string1, 4), 'o');
//    ASSERT_EQ(my_str_getc(&string1, 10), 'l');
//
//    // check 0 position
//    ASSERT_EQ(my_str_getc(&string1, 0), 'h');
//
//    // check last position
//    ASSERT_EQ(my_str_getc(&string1, 12), '!');
//
//    // bad index
//    ASSERT_EQ(my_str_getc(&string1, 15), RANGE_ERR);
//    ASSERT_EQ(my_str_getc(&string1, -13), RANGE_ERR);
//
//    // index equal to size
//    ASSERT_EQ(my_str_getc(&string1, my_str_size(&string1)), RANGE_ERR);
//
//    // NULL pointer
//    ASSERT_EQ(my_str_getc(nullptr, 12), NULL_PTR_ERR);
//
//    // empty string
//    my_str_from_cstr(&string2, "", 20);
//    ASSERT_EQ(my_str_getc(&string2, 0), RANGE_ERR);
//}
//
//TEST_F(ClassDeclaration, my_str_get_cstr) {
//    my_str_from_cstr(&string1, "hello, world!", 20);
//
//    // check normal string
//    ASSERT_STREQ("hello, world!", my_str_get_cstr(&string1));
//
//    // check empty string
//    my_str_from_cstr(&string2, "", 20);
//    ASSERT_STREQ("", my_str_get_cstr(&string2));
//
//    // parse NULL pointer
//    ASSERT_EQ(nullptr, my_str_get_cstr(nullptr));
//}
//
//TEST_F(ClassDeclaration, my_str_putc) {
//    my_str_from_cstr(&string1, "hello, world!", 20);
//
//    // put inside the string
//    my_str_putc(&string1, 1, 'a');
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hallo, world!");
//    my_str_putc(&string1, 10, 'r');
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hallo, worrd!");
//
//    // put on the string's edges
//    my_str_putc(&string1, 0, 'g');
//    ASSERT_STREQ(my_str_get_cstr(&string1), "gallo, worrd!");
//    my_str_putc(&string1, 12, '?');
//    ASSERT_STREQ(my_str_get_cstr(&string1), "gallo, worrd?");
//
//    // put outside the edges
//    ASSERT_EQ(my_str_putc(&string1, -1, 'a'), RANGE_ERR);
//    ASSERT_EQ(my_str_putc(&string1, 13, 'a'), RANGE_ERR);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "gallo, worrd?");
//
//    // put at the beginning of an empty string
//    my_str_from_cstr(&string2, "", 20);
//    ASSERT_EQ(my_str_putc(&string2, 0, 'a'), RANGE_ERR);
//
//    // put in the NULL pointer
//    ASSERT_EQ(my_str_putc(nullptr, 0, '1'), NULL_PTR_ERR);
//
//    // put a NULL character
//    ASSERT_EQ(my_str_putc(&string1, 0, '\0'), NULL_PTR_ERR);
//}
//
//TEST_F(ClassDeclaration, my_str_append_c) {
//    const std::string test_str = "Hello, world";
//    my_str_from_cstr(&string1, test_str.c_str(), 20);
//
//    // Normal pushback
//    ASSERT_EQ(my_str_append_c(&string1, '!'), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "Hello, world!");
//
//    // Check if the push increases buffer by some factor >= 1.8 (rounding up) when required
//    my_str_from_cstr(&string2, test_str.c_str(), 0);
//    my_str_append_c(&string2, '!');
//    ASSERT_GE(my_str_capacity(&string2), std::ceil(1.8f * (test_str.size() - 1)));
//
//    // multiple pushbacks
//    my_str_from_cstr(&string3, test_str.c_str(), 15);
//    for (int i = 0; i < 10; ++i) {
//        my_str_append_c(&string3, '!');
//    }
//    ASSERT_STREQ(my_str_get_cstr(&string3), "Hello, world!!!!!!!!!!");
//
//    // Check NULL handling
//    ASSERT_EQ(my_str_append_c(&string1, '\0'), NULL_PTR_ERR);
//    ASSERT_EQ(my_str_append_c(nullptr, 'c'), NULL_PTR_ERR);
//}
//
//TEST_F(ClassDeclaration, my_str_popback) {
//    my_str_from_cstr(&string1, "hello, world!", 20);
//
//    // normal popback
//    int last = my_str_popback(&string1);
//    ASSERT_EQ(static_cast<char>(last), '!');
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//
//    // many popbacks
//    for (int i = 0; i < 11; i++)
//        last = my_str_popback(&string1);
//    EXPECT_EQ(static_cast<char>(last), 'e');
//    ASSERT_STREQ(my_str_get_cstr(&string1), "h");
//
//    // pop from empty string
//    my_str_popback(&string1);
//    last = my_str_popback(&string1);
//    ASSERT_EQ(last, RANGE_ERR);
//
//    // pass NULL
//    last = my_str_popback(nullptr);
//    ASSERT_EQ(last, NULL_PTR_ERR);
//}
//
//TEST_F(ClassDeclaration, my_str_reserve) {
//    my_str_from_cstr(&string1, "hello, world", 20);
//
//    // reserve more capacity
//    ASSERT_EQ(my_str_reserve(&string1, 40), 0);
//    ASSERT_EQ(my_str_capacity(&string1), 40);
//    ASSERT_EQ(my_str_reserve(&string1, 80), 0);
//    ASSERT_EQ(my_str_capacity(&string1), 80);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//
//    // reserve less or equal
//    ASSERT_EQ(my_str_reserve(&string1, 40), 0);
//    ASSERT_EQ(my_str_capacity(&string1), 80);
//    ASSERT_EQ(my_str_reserve(&string1, 79), 0);
//    ASSERT_EQ(my_str_capacity(&string1), 80);
//    ASSERT_EQ(my_str_reserve(&string1, 80), 0);
//    ASSERT_EQ(my_str_capacity(&string1), 80);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//
//    // if string is NULL
//    ASSERT_EQ(my_str_reserve(nullptr, 20), NULL_PTR_ERR);
//
//    // if reserve max possible memory (buf and buf+1 support)
//    size_t s = SIZE_MAX;
//    int errcode1 = my_str_reserve(&string2, s);
//    int errcode2 = my_str_reserve(&string3, s - 1);
//    ASSERT_TRUE((errcode1 == MEMORY_ALLOCATION_ERR) || (errcode2 == MEMORY_ALLOCATION_ERR));
//}
//
//
//TEST_F(ClassDeclaration, my_str_copy) {
//    my_str_from_cstr(&string1, "hello", 40);
//
//    //normal copy, reserve = 1
//    int copy_code = my_str_copy(&string1, &string2, 1);
//    ASSERT_EQ(copy_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "hello");
//    ASSERT_EQ(my_str_capacity(&string2), my_str_capacity(&string1));
//
//    // check copy invariants
//    my_str_putc(&string1, 1, 'a');
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hallo");
//    ASSERT_STREQ(my_str_get_cstr(&string2), "hello");
//    my_str_putc(&string2, 0, 'f');
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hallo");
//    ASSERT_STREQ(my_str_get_cstr(&string2), "fello");
//
//    // normal copy, reserve = 0
//    my_str_free(&string2);
//    my_str_create(&string2, 10);
//    copy_code = my_str_copy(&string1, &string2, 0);
//    ASSERT_EQ(copy_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "hallo");
//    ASSERT_EQ(my_str_capacity(&string2), 10);
//
//    // check copy invariants
//    my_str_putc(&string1, 1, 'e');
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello");
//    ASSERT_STREQ(my_str_get_cstr(&string2), "hallo");
//    my_str_putc(&string2, 0, 'f');
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello");
//    ASSERT_STREQ(my_str_get_cstr(&string2), "fallo");
//
//    // buffer too small, reserve = 0
//    my_str_from_cstr(&string2, "x", 0);
//    copy_code = my_str_copy(&string1, &string2, 0);
//    ASSERT_EQ(copy_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "hello");
//    ASSERT_EQ(my_str_capacity(&string2), my_str_size(&string1));
//
//    // buffer too small, reserve = 1
//    my_str_from_cstr(&string2, "a", 0);
//    copy_code = my_str_copy(&string1, &string2, 1);
//    ASSERT_EQ(copy_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "hello");
//    ASSERT_EQ(my_str_capacity(&string2), my_str_capacity(&string1));
//
//    // one of strings is NULL
//    copy_code = my_str_copy(&string1, nullptr, 1);
//    ASSERT_EQ(copy_code, NULL_PTR_ERR);
//    copy_code = my_str_copy(nullptr, &string1, 1);
//    ASSERT_EQ(copy_code, NULL_PTR_ERR);
//
//    // reserve is not 0 or 1 (means true)
//    my_str_from_cstr(&string2, "a", 0);
//    copy_code = my_str_copy(&string1, &string2, 4);
//    ASSERT_EQ(copy_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "hello");
//    ASSERT_EQ(my_str_capacity(&string2), my_str_capacity(&string1));
//    copy_code = my_str_copy(&string1, &string2, -1);
//    ASSERT_EQ(copy_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "hello");
//    ASSERT_EQ(my_str_capacity(&string2), my_str_capacity(&string1));
//
//}
//
//TEST_F(ClassDeclaration, my_str_clear) {
//    my_str_from_cstr(&string1, "hello, world", 20);
//
//    //normal clear
//    my_str_clear(&string1);
//    EXPECT_TRUE(my_str_empty(&string1));
//    EXPECT_STREQ(my_str_get_cstr(&string1), "");
//    EXPECT_EQ(my_str_capacity(&string1), 20);
//    ASSERT_NE(string1.m_data, nullptr);
//
//    // clear empty string
//    my_str_clear(&string1);
//    ASSERT_TRUE(my_str_empty(&string1));
//
//    // clearing NULL either returns 0 or NULL pointer error
//    int clear_code = my_str_clear(nullptr);
//    ASSERT_TRUE(clear_code == NULL_PTR_ERR || !clear_code);
//}
//
//TEST_F(ClassDeclaration, my_str_insert_c) {
//    my_str_from_cstr(&string1, "hello, world!", 20);
//
//    // normal insert inside
//    int in_code = my_str_insert_c(&string1, '1', 2);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "he1llo, world!");
//    ASSERT_EQ(my_str_size(&string1), 14);
//    ASSERT_EQ(my_str_capacity(&string1), 20);
//
//    // insert on the last position + 1
//    in_code = my_str_insert_c(&string1, '!', 14);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "he1llo, world!!");
//    ASSERT_EQ(my_str_size(&string1), 15);
//    ASSERT_EQ(my_str_capacity(&string1), 20);
//
//    // insert on the 0 position
//    in_code = my_str_insert_c(&string1, 'h', 0);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hhe1llo, world!!");
//    ASSERT_EQ(my_str_size(&string1), 16);
//    ASSERT_EQ(my_str_capacity(&string1), 20);
//
//    // bad position
//    in_code = my_str_insert_c(&string1, '!', 19);
//    ASSERT_EQ(in_code, RANGE_ERR);
//    ASSERT_EQ(my_str_size(&string1), 16);
//    ASSERT_EQ(my_str_capacity(&string1), 20);
//
//    // insert in the empty string
//    my_str_clear(&string1);
//    in_code = my_str_insert_c(&string1, '!', 0);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "!");
//    ASSERT_EQ(my_str_size(&string1), 1);
//
//    // insert in NULL or NULL char
//    in_code = my_str_insert_c(nullptr, '!', 0);
//    ASSERT_EQ(in_code, NULL_PTR_ERR);
//    in_code = my_str_insert_c(&string1, '\0', 0);
//    ASSERT_EQ(in_code, NULL_PTR_ERR);
//
//    // insert with extending buffer
//    in_code = my_str_insert_c(&string3, 'i', 0);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string3), "i");
//    ASSERT_EQ(my_str_size(&string3), 1);
//    ASSERT_GE(my_str_capacity(&string3), 1);
//
//    // next insertion after extension
//    in_code = my_str_insert_c(&string3, 'h', 0);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string3), "hi");
//    ASSERT_EQ(my_str_size(&string3), 2);
//}
//
//TEST_F(ClassDeclaration, my_str_insert) {
//    my_str_from_cstr(&string1, "herld", 20);
//    my_str_from_cstr(&string2, "llo, wo", 20);
//
//    // normal insert
//    int in_code = my_str_insert(&string1, &string2, 2);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//    ASSERT_EQ(my_str_size(&string1), 12);
//    ASSERT_EQ(my_str_size(&string2), 7);
//
//    // insert at the end of the string
//    my_str_from_cstr(&string1, "hello, ", 20);
//    my_str_from_cstr(&string2, "world", 20);
//    in_code = my_str_insert(&string1, &string2, 7);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//    ASSERT_EQ(my_str_size(&string1), 12);
//    ASSERT_EQ(my_str_size(&string2), 5);
//
//    // insert at the start of the string
//    my_str_from_cstr(&string1, "world", 20);
//    my_str_from_cstr(&string2, "hello, ", 20);
//    in_code = my_str_insert(&string1, &string2, 0);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//    ASSERT_EQ(my_str_size(&string1), 12);
//    ASSERT_EQ(my_str_size(&string2), 7);
//
//    // insert in the empty string
//    my_str_clear(&string1);
//    my_str_from_cstr(&string2, "hello", 20);
//    in_code = my_str_insert(&string1, &string2, 0);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello");
//    ASSERT_EQ(my_str_size(&string1), 5);
//    ASSERT_EQ(my_str_size(&string2), 5);
//
//    // insert empty string
//    my_str_clear(&string2);
//    my_str_from_cstr(&string1, "hello", 20);
//    in_code = my_str_insert(&string1, &string2, 0);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello");
//    ASSERT_EQ(my_str_size(&string1), 5);
//    ASSERT_EQ(my_str_size(&string2), 0);
//
//    // insert with extending buffer
//    my_str_from_cstr(&string2, ", world", 0);
//    in_code = my_str_insert(&string2, &string1, 0);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "hello, world");
//    ASSERT_EQ(my_str_size(&string1), 5);
//    ASSERT_EQ(my_str_size(&string2), 12);
//
//    // one of strings is NULL
//    in_code = my_str_insert(nullptr, &string2, 0);
//    ASSERT_EQ(in_code, NULL_PTR_ERR);
//    in_code = my_str_insert(&string1, nullptr, 0);
//    ASSERT_EQ(in_code, NULL_PTR_ERR);
//
//    // bad position
//    in_code = my_str_insert(&string1, &string2, 20);
//    ASSERT_EQ(in_code, RANGE_ERR);
//}
//
//TEST_F(ClassDeclaration, my_str_insert_cstr) {
//    my_str_from_cstr(&string1, "herld", 20);
//
//    std::string c_string{"llo, wo"};
//    std::string c_string_long;
//
//    // normal insert
//    int in_code = my_str_insert_cstr(&string1, c_string.c_str(), 2);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//    ASSERT_EQ(my_str_size(&string1), 12);
//    ASSERT_EQ(c_string.size(), 7);
//
//    // insert at the end of the string
//    my_str_from_cstr(&string1, "hello", 20);
//    c_string = ", world";
//    in_code = my_str_insert_cstr(&string1, c_string.c_str(), 5);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//    ASSERT_EQ(my_str_size(&string1), 12);
//    ASSERT_EQ(c_string.size(), 7);
//
//    // insert at the start of the string
//    my_str_from_cstr(&string1, "world", 20);
//    c_string = "hello, ";
//    in_code = my_str_insert_cstr(&string1, c_string.c_str(), 0);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//    ASSERT_EQ(my_str_size(&string1), 12);
//    ASSERT_EQ(c_string.size(), 7);
//
//    // insert in the empty string
//    my_str_clear(&string1);
//    c_string = "hello";
//    in_code = my_str_insert_cstr(&string1, c_string.c_str(), 0);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello");
//    ASSERT_EQ(my_str_size(&string1), 5);
//    ASSERT_EQ(c_string.size(), 5);
//
//    // insert empty string
//    c_string = "";
//    my_str_from_cstr(&string1, "hello", 20);
//    in_code = my_str_insert_cstr(&string1, c_string.c_str(), 0);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello");
//    ASSERT_EQ(my_str_size(&string1), 5);
//    ASSERT_EQ(c_string.size(), 0);
//
//    //insert with extending buffer
//    my_str_from_cstr(&string1, "hello, ", 20);
//    c_string_long = "world, how is it going? for me it is just a test";
//    in_code = my_str_insert_cstr(&string1, c_string_long.c_str(), 7);
//    ASSERT_EQ(in_code, 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world, how is it going? for me it is just a test");
//    ASSERT_EQ(my_str_size(&string1), 55);
//    ASSERT_EQ(c_string_long.size(), 48);
//
//    // one of strings is NULL
//    my_str_from_cstr(&string1, "hello", 20);
//    in_code = my_str_insert_cstr(nullptr, c_string.c_str(), 2);
//    ASSERT_EQ(in_code, NULL_PTR_ERR);
//    in_code = my_str_insert_cstr(&string1, nullptr, 2);
//    ASSERT_EQ(in_code, NULL_PTR_ERR);
//
//    // bad position
//    in_code = my_str_insert_cstr(&string1, c_string.c_str(), 20);
//    ASSERT_EQ(in_code, RANGE_ERR);
//}
//
//TEST_F(ClassDeclaration, my_str_append) {
//    my_str_from_cstr(&string1, "hello, ", 20);
//    my_str_from_cstr(&string2, "world", 20);
//
//    // normal append
//    ASSERT_EQ(my_str_append(&string1, &string2), 0);
//    ASSERT_EQ(my_str_size(&string1), 12);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//    ASSERT_STREQ(my_str_get_cstr(&string2), "world");
//
//    // append empty string
//    my_str_clear(&string2);
//    ASSERT_EQ(my_str_append(&string1, &string2), 0);
//    ASSERT_EQ(my_str_size(&string1), 12);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//
//    // append to empty string
//    ASSERT_EQ(my_str_append(&string2, &string1), 0);
//    ASSERT_EQ(my_str_size(&string2), 12);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "hello, world");
//
//    // one of the strings is NULL
//    ASSERT_EQ(my_str_append(nullptr, &string1), NULL_PTR_ERR);
//    ASSERT_EQ(my_str_append(&string2, nullptr), NULL_PTR_ERR);
//
//    // append with extending buffer
//    my_str_from_cstr(&string1, "hello, ", 0);
//    my_str_from_cstr(&string2, "world, how is it going? for me it is just a test", 60);
//    ASSERT_EQ(my_str_append(&string1, &string2), 0);
//    ASSERT_EQ(my_str_size(&string1), 55);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world, how is it going? for me it is just a test");
//}
//
//TEST_F(ClassDeclaration, my_str_append_cstr) {
//    my_str_from_cstr(&string1, "hello, ", 20);
//    std::string c_string = "world";
//
//    // normal append
//    ASSERT_EQ(my_str_append_cstr(&string1, c_string.c_str()), 0);
//    ASSERT_EQ(my_str_size(&string1), 12);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//    ASSERT_STREQ(c_string.c_str(), "world");
//
//    // append empty string
//    c_string = "";
//    ASSERT_EQ(my_str_append_cstr(&string1, c_string.c_str()), 0);
//    ASSERT_EQ(my_str_size(&string1), 12);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//
//    // append to empty string
//    c_string = "hello";
//    my_str_clear(&string1);
//    ASSERT_EQ(my_str_append_cstr(&string1, c_string.c_str()), 0);
//    ASSERT_EQ(my_str_size(&string2), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "");
//
//    // one of the strings is NULL
//    ASSERT_EQ(my_str_append_cstr(nullptr, c_string.c_str()), NULL_PTR_ERR);
//    ASSERT_EQ(my_str_append_cstr(&string2, nullptr), NULL_PTR_ERR);
//
//    // append with extending buffer
//    my_str_from_cstr(&string1, "hello, ", 0);
//    ASSERT_EQ(my_str_append_cstr(&string1, "world, how is it going? for me it is just a test"), 0);
//    ASSERT_EQ(my_str_size(&string1), 55);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world, how is it going? for me it is just a test");
//}
//
//TEST_F(ClassDeclaration, my_str_substr) {
//    my_str_from_cstr(&string1, "hello, world. My name is Myk0la and today I want to test your lab work!", 80);
//
//    // substring inside
//    ASSERT_EQ(my_str_substr(&string1, &string2, 2, 5), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "llo");
//    ASSERT_EQ(my_str_size(&string2), 3);
//
//    // substring from the start
//    ASSERT_EQ(my_str_substr(&string1, &string2, 0, 5), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "hello");
//    ASSERT_EQ(my_str_size(&string2), 5);
//
//    // substring to the end, within capacity
//    ASSERT_EQ(my_str_substr(&string1, &string2, 7, 75), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "world. My name is Myk0la and today I want to test your lab work!");
//    std::string s = "world. My name is Myk0la and today I want to test your lab work!";
//    ASSERT_EQ(my_str_size(&string2), s.size());
//
//    // bad boundaries
//    ASSERT_EQ(my_str_substr(&string1, &string2, 13, 11), RANGE_ERR);
//
//    // one of strings is NULL
//    ASSERT_EQ(my_str_substr(nullptr, &string2, 1, 2), NULL_PTR_ERR);
//    ASSERT_EQ(my_str_substr(&string1, nullptr, 1, 2), NULL_PTR_ERR);
//
//    // substring to end, more than capacity
//    ASSERT_EQ(my_str_substr(&string1, &string2, 7, 90), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "world. My name is Myk0la and today I want to test your lab work!");
//    s = "world. My name is Myk0la and today I want to test your lab work!";
//    ASSERT_EQ(my_str_size(&string2), s.size());
//
//    // substring from the punultimate position
//    ASSERT_EQ(my_str_substr(&string1, &string2, my_str_size(&string1) - 1, 90), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "!");
//    ASSERT_EQ(my_str_size(&string2), 1);
//
//    // beg == end
//    ASSERT_EQ(my_str_substr(&string1, &string2, 1, 1), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "");
//
//    // from empty string
//    my_str_clear(&string1);
//    ASSERT_EQ(my_str_substr(&string1, &string2, 0, 10), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "");
//}
//
//TEST_F(ClassDeclaration, my_str_substr_cstr) {
//
//    my_str_from_cstr(&string1, "hello, world", 20);
//    char c_string[20] = "";
//
//    // substring inside
//    ASSERT_EQ(my_str_substr_cstr(&string1, c_string, 2, 5), 0);
//    ASSERT_STREQ(c_string, "llo");
//
//    // substring from the start
//    ASSERT_EQ(my_str_substr_cstr(&string1, c_string, 0, 5), 0);
//    ASSERT_STREQ(c_string, "hello");
//
//    // substring to end, within capacity
//    ASSERT_EQ(my_str_substr_cstr(&string1, c_string, 7, 14), 0);
//    ASSERT_STREQ(c_string, "world");
//
//    // substring to end, greater than capacity
//    ASSERT_EQ(my_str_substr_cstr(&string1, c_string, 7, 25), 0);
//    ASSERT_STREQ(c_string, "world");
//
//
//    // bad boundaries
//    ASSERT_EQ(my_str_substr_cstr(&string1, c_string, 13, 11), RANGE_ERR);
//    ASSERT_EQ(my_str_size(&string1), 12);
//
//    // one ofthe  strings is NULL
//    ASSERT_EQ(my_str_substr_cstr(nullptr, c_string, 1, 2), NULL_PTR_ERR);
//    ASSERT_EQ(my_str_substr_cstr(&string1, nullptr, 1, 2), NULL_PTR_ERR);
//
//    // substring from penultimate position
//    ASSERT_EQ(my_str_substr_cstr(&string1, c_string, 11, 25), 0);
//    ASSERT_STREQ(c_string, "d");
//
//    // beg == end
//    ASSERT_EQ(my_str_substr_cstr(&string1, c_string, 1, 1), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "");
//
//    // from empty string
//    my_str_clear(&string1);
//    ASSERT_EQ(my_str_substr_cstr(&string1, c_string, 0, 10), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "");
//}
//
//TEST_F(ClassDeclaration, my_str_erase) {
//    my_str_from_cstr(&string1, "hello_world", 20);
//
//    // erase inside
//    ASSERT_EQ(my_str_erase(&string1, 5, 8), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hellorld");
//
//    // erase from the start
//    ASSERT_EQ(my_str_erase(&string1, 0, 2), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "llorld");
//
//    // erase to the end (out of bounds)
//    ASSERT_EQ(my_str_erase(&string1, 4, 20), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "llor");
//
//    // erase from the end
//    ASSERT_EQ(my_str_erase(&string1, 3, 6), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "llo");
//
//    // bad boundaries
//    ASSERT_EQ(my_str_erase(&string1, 13, 14), RANGE_ERR);
//    ASSERT_EQ(my_str_erase(&string1, 1, 0), RANGE_ERR);
//
//    // string is NULL
//    ASSERT_EQ(my_str_erase(nullptr, 0, 1), NULL_PTR_ERR);
//
//    // beg == end
//    ASSERT_EQ(my_str_erase(&string1, 1, 1), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "llo");
//
//    // from empty string
//    my_str_clear(&string1);
//    ASSERT_EQ(my_str_erase(&string1, 0, 10), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "");
//
//    // delete everything
//    my_str_from_cstr(&string1, "hello_world", 20);
//    ASSERT_EQ(my_str_erase(&string1, 0, 11), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "");
//}
//
//
//TEST_F(ClassDeclaration, my_str_shrink_to_fit) {
//    my_str_from_cstr(&string1, "hello, world", 20);
//
//    // normal shrink
//    ASSERT_EQ(my_str_shrink_to_fit(&string1), 0);
//    ASSERT_EQ(my_str_capacity(&string1), my_str_size(&string1));
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world");
//
//    // shrink empty string
//    my_str_clear(&string1);
//    ASSERT_EQ(my_str_shrink_to_fit(&string1), 0);
//    ASSERT_EQ(my_str_capacity(&string1), 0);
//
//    // string is NULL
//    ASSERT_EQ(my_str_shrink_to_fit(nullptr), NULL_PTR_ERR);
//}
//
//TEST_F(ClassDeclaration, my_str_resize) {
//    my_str_from_cstr(&string1, "hello, world", 20);
//
//    // bigger size without buffer extension
//    ASSERT_EQ(my_str_resize(&string1, 17, '!'), 0);
//    ASSERT_EQ(my_str_size(&string1), 17);
//    ASSERT_EQ(my_str_capacity(&string1), 20);
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world!!!!!");
//
//    // bigger size with buffer extension
//    ASSERT_EQ(my_str_resize(&string1, 21, '!'), 0);
//    ASSERT_EQ(my_str_size(&string1), 21);
//    ASSERT_GE(my_str_capacity(&string1), std::ceil(1.8f * 20));
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello, world!!!!!!!!!");
//
//    // smaller size
//    ASSERT_EQ(my_str_resize(&string1, 5, 'a'), 0);
//    ASSERT_EQ(my_str_size(&string1), 5);
//    ASSERT_GE(my_str_capacity(&string1), std::ceil(1.8f * 20));
//    ASSERT_STREQ(my_str_get_cstr(&string1), "hello");
//
//    // size = 0
//    ASSERT_EQ(my_str_resize(&string1, 0, 'a'), 0);
//    ASSERT_EQ(my_str_size(&string1), 0);
//    ASSERT_GE(my_str_capacity(&string1), std::ceil(1.8f * 20));
//    ASSERT_STREQ(my_str_get_cstr(&string1), "");
//
//    // string is NULL
//    ASSERT_EQ(my_str_resize(nullptr, 1, 'a'), NULL_PTR_ERR);
//
//    // resize newly created string
//    ASSERT_EQ(my_str_resize(&string2, 2, 'a'), 0);
//    ASSERT_EQ(my_str_size(&string2), 2);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "aa");
//
//    // if reserve max possible memory (buf and buf+1 support)
//
////    TODO: fix this, find out a normal test
////    size_t s = SIZE_MAX;
////    int errcode1 = my_str_resize(&string2, s, ' ');
////    int errcode2 = my_str_resize(&string3, s, ' ');
////    ASSERT_TRUE((errcode1 == MEMORY_ALLOCATION_ERR) || (errcode2 == MEMORY_ALLOCATION_ERR));
//}
//
//TEST_F(ClassDeclaration, my_str_find) {
//    my_str_from_cstr(&string1, "hello, world", 20);
//    my_str_from_cstr(&string2, "hello", 20);
//
//    // find, from 0 and substr exists
//    ASSERT_EQ(my_str_find(&string1, &string2, 0), static_cast<size_t>(0));
//
//    // find, from inside and substr exists
//    my_str_from_cstr(&string2, "world", 20);
//    ASSERT_EQ(my_str_find(&string1, &string2, 3), static_cast<size_t>(7));
//
//    // from 0, substr does not exist
//    my_str_from_cstr(&string2, "hii", 20);
//    ASSERT_EQ(my_str_find(&string1, &string2, 0), static_cast<size_t>(SIZE_MAX));
//
//    // from inside, substr does not exist
//    my_str_from_cstr(&string2, "hii", 20);
//    ASSERT_EQ(my_str_find(&string1, &string2, 3), static_cast<size_t>(SIZE_MAX));
//
//    // find from end, does not exist
//    my_str_from_cstr(&string2, "world", 20);
//    ASSERT_EQ(my_str_find(&string1, &string2, my_str_size(&string1) - 1), static_cast<size_t>(SIZE_MAX));
//
//    // one of the strings is null
//    ASSERT_EQ(my_str_find(nullptr, &string2, 3), static_cast<size_t>(SIZE_MAX));
//    ASSERT_EQ(my_str_find(&string1, nullptr, 3), static_cast<size_t>(SIZE_MAX));
//
//    // tofind is larger
//    my_str_from_cstr(&string2, "hello, world!", 20);
//    ASSERT_EQ(my_str_find(&string1, &string2, 0), static_cast<size_t>(SIZE_MAX));
//
//    // tofind is empty
//    my_str_from_cstr(&string2, "", 20);
//    ASSERT_EQ(my_str_find(&string1, &string2, 0), static_cast<size_t>(SIZE_MAX));
//
//    // from is out of bounds
//    my_str_from_cstr(&string2, "hello", 20);
//    ASSERT_EQ(my_str_find(&string1, &string2, 19), static_cast<size_t>(SIZE_MAX));
//}
//
//TEST_F(ClassDeclaration, my_str_cmp) {
//    // equal size normal strings
//    my_str_from_cstr(&string1, "hello", 20);
//    my_str_from_cstr(&string2, "hellw", 20);
//    ASSERT_EQ(my_str_cmp(&string1, &string2), -1);
//    ASSERT_EQ(my_str_cmp(&string2, &string1), 1);
//
//    // one is longer
//    my_str_from_cstr(&string1, "aaba", 20);
//    my_str_from_cstr(&string2, "aab", 20);
//    ASSERT_EQ(my_str_cmp(&string2, &string1), -1);
//    ASSERT_EQ(my_str_cmp(&string1, &string2), 1);
//
//    // single symbol strings
//    my_str_from_cstr(&string1, "b", 20);
//    my_str_from_cstr(&string2, "a", 20);
//    ASSERT_EQ(my_str_cmp(&string2, &string1), -1);
//    ASSERT_EQ(my_str_cmp(&string1, &string2), 1);
//
//    // one is empty
//    my_str_from_cstr(&string1, "", 20);
//    my_str_from_cstr(&string2, "a", 20);
//    ASSERT_EQ(my_str_cmp(&string1, &string2), -1);
//    ASSERT_EQ(my_str_cmp(&string2, &string1), 1);
//
//    // equal
//    my_str_from_cstr(&string1, "hello, world", 20);
//    my_str_from_cstr(&string2, "hello, world", 20);
//    ASSERT_EQ(my_str_cmp(&string1, &string2), 0);
//
//    // empty and equal
//    my_str_from_cstr(&string1, "", 20);
//    my_str_from_cstr(&string2, "", 20);
//    ASSERT_EQ(my_str_cmp(&string1, &string2), 0);
//
//    // all NULL equalities
//
//    ASSERT_EQ(my_str_cmp(nullptr, nullptr), 0);
//    ASSERT_EQ(my_str_cmp(nullptr, &string1), 0);
//    ASSERT_EQ(my_str_cmp(&string1, nullptr), 0);
//
//    // NULL inequalities
//    my_str_from_cstr(&string1, "a", 20);
//    ASSERT_EQ(my_str_cmp(nullptr, &string1), -1);
//    ASSERT_EQ(my_str_cmp(&string1, nullptr), 1);
//}
//
//TEST_F(ClassDeclaration, my_str_cmp_cstr) {
//    // equal size normal strings
//    char lt_cstr[20] = "hella";
//    char gt_cstr[20] = "hellw";
//
//    my_str_from_cstr(&string1, "hello", 20);
//    ASSERT_LT(my_str_cmp_cstr(&string1, gt_cstr), 0);
//    ASSERT_GT(my_str_cmp_cstr(&string1, lt_cstr), 0);
//
//    // one is longer
//    sprintf(lt_cstr, "aa");
//    sprintf(gt_cstr, "aaba");
//    my_str_from_cstr(&string1, "aab", 20);
//    ASSERT_LT(my_str_cmp_cstr(&string1, gt_cstr), 0);
//    ASSERT_GT(my_str_cmp_cstr(&string1, lt_cstr), 0);
//
//    // single symbol strings
//    sprintf(lt_cstr, "a");
//    sprintf(gt_cstr, "c");
//    my_str_from_cstr(&string1, "b", 20);
//    ASSERT_LT(my_str_cmp_cstr(&string1, gt_cstr), 0);
//    ASSERT_GT(my_str_cmp_cstr(&string1, lt_cstr), 0);
//
//    // one is empty
//    sprintf(lt_cstr, "");
//    sprintf(gt_cstr, "b");
//    my_str_from_cstr(&string2, "", 20);
//    my_str_from_cstr(&string1, "b", 20);
//    ASSERT_LT(my_str_cmp_cstr(&string2, gt_cstr), 0);
//    ASSERT_GT(my_str_cmp_cstr(&string1, lt_cstr), 0);
//
//    // equal
//    sprintf(lt_cstr, "hello, world");
//    my_str_from_cstr(&string1, "hello, world", 20);
//    ASSERT_EQ(my_str_cmp_cstr(&string1, lt_cstr), 0);
//
//    // empty and equal
//    sprintf(lt_cstr, "");
//    my_str_from_cstr(&string1, "", 20);
//    ASSERT_EQ(my_str_cmp_cstr(&string1, lt_cstr), 0);
//
//    // all NULL equalities
//    ASSERT_EQ(my_str_cmp_cstr(&string1, nullptr), 0);
//    ASSERT_EQ(my_str_cmp_cstr(nullptr, lt_cstr), 0);
//
//    // NULL inequalities
//    sprintf(gt_cstr, "a");
//    my_str_from_cstr(&string1, "a", 20);
//    ASSERT_EQ(my_str_cmp_cstr(nullptr, gt_cstr), -1);
//    ASSERT_EQ(my_str_cmp_cstr(&string1, nullptr), 1);
//}
//
//TEST_F(ClassDeclaration, my_str_find_c) {
//    my_str_from_cstr(&string1, "hello, world", 20);
//
//    // find from 0
//    ASSERT_EQ(my_str_find_c(&string1, 'e', 0), static_cast<size_t>(1));
//
//    // find from inside
//    ASSERT_EQ(my_str_find_c(&string1, 'l', 3), static_cast<size_t>(3));
//
//    // miss from 0
//    ASSERT_EQ(my_str_find_c(&string1, 'i', 0), static_cast<size_t>(SIZE_MAX));
//
//    // miss inside
//    ASSERT_EQ(my_str_find_c(&string1, 'm', 5), static_cast<size_t>(SIZE_MAX));
//
//    // find from last symbol
//    ASSERT_EQ(my_str_find_c(&string1, 'd', 11), static_cast<size_t>(11));
//
//    // bad from
//    ASSERT_EQ(my_str_find_c(&string1, 'd', 12), static_cast<size_t>(SIZE_MAX));
//    ASSERT_EQ(my_str_find_c(&string1, 'd', 13), static_cast<size_t>(SIZE_MAX));
//
//    //string is NULL
//    ASSERT_EQ(my_str_find_c(nullptr, 'd', 10), static_cast<size_t>(SIZE_MAX));
//}
//
//
//// predicates for find_if
//static inline int equal_l(int symbol) {
//    return symbol == 'l';
//}
//
//static inline int equal_s(int symbol) {
//    return symbol == 's';
//}
//
//static inline int equal_d(int symbol) {
//    return symbol == 'd';
//}
//
//static inline int gt_5(int symbol) {
//    return symbol > '5';
//}
//
//static inline int true_predicate(int) {
//    return 1;
//}
//
//TEST_F(ClassDeclaration, my_str_find_if) {
//    my_str_from_cstr(&string1, "hello, world", 20);
//    my_str_from_cstr(&string2, "123987456", 20);
//
//    // find from 0
//    ASSERT_EQ(my_str_find_if(&string1, 0, equal_l), static_cast<size_t>(2));
//
//    // find inside
//    ASSERT_EQ(my_str_find_if(&string1, 3, equal_l), static_cast<size_t>(3));
//
//    // miss from 0
//    ASSERT_EQ(my_str_find_if(&string1, 0, equal_s), SIZE_MAX);
//
//    // miss inside
//    ASSERT_EQ(my_str_find_if(&string1, 6, equal_s), SIZE_MAX);
//
//    // find from last symbol
//    ASSERT_EQ(my_str_find_if(&string1, 11, equal_d), static_cast<size_t>(11));
//
//    // invalid from
//    ASSERT_EQ(my_str_find_if(&string1, 12, equal_d), SIZE_MAX);
//    ASSERT_EQ(my_str_find_if(&string1, 13, true_predicate), SIZE_MAX);
//
//    // one of the arguments is NULL
//    ASSERT_EQ(my_str_find_if(nullptr, 0, true_predicate), SIZE_MAX);
//    ASSERT_EQ(my_str_find_if(&string1, 0, nullptr), SIZE_MAX);
//
//    // empty string
//    my_str_clear(&string1);
//    ASSERT_EQ(my_str_find_if(&string1, 0, true_predicate), SIZE_MAX);
//
//    // more complex predicate
//    ASSERT_EQ(my_str_find_if(&string2, 0, gt_5), static_cast<size_t>(3));
//}
//
//static inline unique_file_ptr smart_fopen(const char *filename, const char *mode) {
//    return unique_file_ptr{fopen(filename, mode), fclose};
//}
//
//static inline std::string test_read_file(const char *c_str_path) {
//    std::ifstream in{c_str_path};
//    if (in.is_open() && in.good()) {
//        std::ostringstream ss{};
//        ss << in.rdbuf();
//        return ss.str();
//    } else throw std::runtime_error("Unable to read file");
//}
//
//static inline void test_write_file(const char *c_str_path, std::string &&content) {
//    std::ofstream out{c_str_path, std::ios::trunc};
//    if (out.is_open() && out.good()) {
//        out << content;
//    } else throw std::runtime_error("Unable to write to file");
//}
//
//TEST_F(ClassDeclaration, my_str_write_file) {
//    my_str_from_cstr(&string1, "hello, \nworld", 20);
//    char path_to_wfile[500];
//    sprintf(path_to_wfile, "%s%s", FILE_DIR, "/write_file.txt");
//    std::string read_content;
//
//
//    // normal write to file
//    // !FILE_DIR is located in SOURCE_DIR/google_tests/test_files!
//    {
//        auto file = smart_fopen(path_to_wfile, "w");
//        if (file) {
//            ASSERT_EQ(my_str_write_file(&string1, file.get()), 0);
//        } else throw std::runtime_error("Unable to write to file");
//    }
//
//    // now read and check content of file
//    read_content = test_read_file(path_to_wfile);
//    ASSERT_STREQ(my_str_get_cstr(&string1), read_content.c_str());
//    ASSERT_EQ(my_str_size(&string1), read_content.length());
//
//
//    // bad file stream
//    {
//        auto file = smart_fopen(path_to_wfile, "r");
//        if (file) {
//            ASSERT_EQ(my_str_write_file(&string1, file.get()), IO_WRITE_ERR);
//        } else throw std::runtime_error("Unable to write to file");
//    }
//
//    // write empty string
//    my_str_clear(&string1);
//    {
//        auto file = smart_fopen(path_to_wfile, "w");
//        if (file) {
//            ASSERT_EQ(my_str_write_file(&string1, file.get()), 0);
//        } else throw std::runtime_error("Unable to write to file");
//    }
//
//    // now read and check content of file
//    read_content = test_read_file(path_to_wfile);
//    ASSERT_STREQ(my_str_get_cstr(&string1), read_content.c_str());
//    ASSERT_EQ(0, read_content.length());
//    ASSERT_STREQ("", read_content.c_str());
//
//    // one of the arguments is NULL
//    {
//        auto file = smart_fopen(path_to_wfile, "w");
//        if (file) {
//            ASSERT_EQ(my_str_write_file(nullptr, file.get()), NULL_PTR_ERR);
//            ASSERT_EQ(my_str_write_file(&string1, nullptr), NULL_PTR_ERR);
//        } else throw std::runtime_error("Unable to write to file");
//    }
//
//}
//
//TEST_F(ClassDeclaration, my_str_write) {
//    testing::internal::CaptureStdout();
//
//    // normal string
//    my_str_from_cstr(&string1, "hello, world!", 20);
//    ASSERT_EQ(my_str_write(&string1), 0);
//    ASSERT_STREQ(testing::internal::GetCapturedStdout().c_str(), "hello, world!");
//
//    testing::internal::CaptureStdout();
//    // empty string
//    my_str_clear(&string1);
//    ASSERT_EQ(my_str_write(&string1), 0);
//    ASSERT_STREQ(testing::internal::GetCapturedStdout().c_str(), "");
//
//    testing::internal::CaptureStdout();
//    // string with \n
//    my_str_from_cstr(&string1, "hello, \nworld", 20);
//    ASSERT_EQ(my_str_write(&string1), 0);
//    ASSERT_STREQ(testing::internal::GetCapturedStdout().c_str(), "hello, \nworld");
//
//    // string is null
//    ASSERT_EQ(my_str_write(nullptr), NULL_PTR_ERR);
//}

//TEST_F(ClassDeclaration, my_str_read_file) {
//
//    my_str_from_cstr(&string1, "hello, \nworld", 20);
//    char path_to_rfile[500];
//    sprintf(path_to_rfile, "%s%s", FILE_DIR, "/read_file.txt");
//    test_write_file(path_to_rfile, std::string{"hello, \nworld"});
//
//    // normal read
//    // !FILE_DIR is located in SOURCE_DIR/google_tests/test_files!
//    {
//        auto file = smart_fopen(path_to_rfile, "r");
//        if (file) {
//            ASSERT_EQ(my_str_read_file(&string2, file.get()), 0);
//        } else throw std::runtime_error("Unable to read file");
//        ASSERT_STREQ(my_str_get_cstr(&string1), my_str_get_cstr(&string2));
//        ASSERT_EQ(my_str_size(&string1), my_str_size(&string2));
//    }
//
//    // read from empty file
//    test_write_file(path_to_rfile, std::string{});
//    {
//        auto file = smart_fopen(path_to_rfile, "r");
//        if (file) {
//            ASSERT_EQ(my_str_read_file(&string2, file.get()), 0);
//        } else throw std::runtime_error("Unable to read file");
//        ASSERT_STREQ(my_str_get_cstr(&string2), "");
//        ASSERT_EQ(my_str_size(&string2), 0);
//    }
//
//    // bad stream
//    {
//        auto file = smart_fopen(path_to_rfile, "w");
//        if (file) {
//            ASSERT_EQ(my_str_read_file(&string2, file.get()), IO_READ_ERR);
//        } else throw std::runtime_error("Unable to read file");
//    }
//
//    // one of the arguments is NULL
//    {
//        auto file = smart_fopen(path_to_rfile, "r");
//        if (file) {
//            ASSERT_EQ(my_str_read_file(nullptr, file.get()), NULL_PTR_ERR);
//            ASSERT_EQ(my_str_read_file(&string2, nullptr), NULL_PTR_ERR);
//        } else throw std::runtime_error("Unable to read file");
//    }
//
//}

//TEST_F(ClassDeclaration, my_str_read_file) {
//    my_str_from_cstr(&string1, "hello, world", 20);
//    char path_to_rfile[500];    // char path_to_rfile[test_c_str_len(FILE_DIR) + 30];
//    sprintf(path_to_rfile, "%s%s", FILE_DIR, "/read_file.txt");
//
//    // normal read
//    FILE *file = fopen(path_to_rfile, "w");
//    if (file) {
//        my_str_write_file(&string1, file);
//        fclose(file);
//    }
//
//    file = fopen(path_to_rfile, "r");
//    if (file) {
//        ASSERT_EQ(my_str_read_file(&string2, file), 0);
//        ASSERT_STREQ(my_str_get_cstr(&string1), my_str_get_cstr(&string2));
//        ASSERT_EQ(my_str_size(&string1), my_str_size(&string2));
//        fclose(file);
//    }
//
//    // read from empty file
//    my_str_clear(&string1);
//    file = fopen(path_to_rfile, "w");
//    if (file) {
//        my_str_write_file(&string1, file);
//        fclose(file);
//    }
//
//    file = fopen(path_to_rfile, "r");
//    if (file) {
//
//        ASSERT_EQ(my_str_read_file(&string2, file), 0);
//        ASSERT_STREQ(my_str_get_cstr(&string2), "");
//        ASSERT_EQ(my_str_size(&string2), 0);
//
//
//        // one of arguments is NULL
//        ASSERT_EQ(my_str_read_file(NULL, file), NULL_PTR_ERR);
//        ASSERT_EQ(my_str_read_file(&string2, NULL), NULL_PTR_ERR);
//        fclose(file);
//    }
//}

//TEST_F(ClassDeclaration, my_str_read_file_delim) {
//    my_str_from_cstr(&string1, "hello, world!", 20);
//    char path_to_rfile[500]; //char path_to_rfile[test_c_str_len(FILE_DIR) + 30];
//    sprintf(path_to_rfile, "%s%s", FILE_DIR, "/read_file.txt");
//
//    FILE *file = fopen(path_to_rfile, "w");
//    my_str_write_file(&string1, file);
//    if (file)
//        fclose(file);
//
//    // read to delimiter inside
//    file = fopen(path_to_rfile, "r");
//    ASSERT_EQ(my_str_read_file_delim(&string2, file, 'l'), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "he");
//    ASSERT_EQ(my_str_size(&string2), 2);
//    if (file)
//        fclose(file);
//
//    // read to delimiter at the beginning
//    file = fopen(path_to_rfile, "r");
//    ASSERT_EQ(my_str_read_file_delim(&string2, file, 'h'), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "");
//    ASSERT_EQ(my_str_size(&string2), 0);
//    if (file)
//        fclose(file);
//    // read to delimiter at the end
//    file = fopen(path_to_rfile, "r");
//    ASSERT_EQ(my_str_read_file_delim(&string2, file, '!'), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "hello, world");
//    ASSERT_EQ(my_str_size(&string2), 12);
//    if (file)
//        fclose(file);
//}

//TEST_F(ClassDeclaration, my_str_read) {
//    my_str_from_cstr(&string1, "hello, world!\n", 20);
//    char path_to_rfile[500]; //char path_to_rfile[test_c_str_len(FILE_DIR) + 30];
//    sprintf(path_to_rfile, "%s%s", FILE_DIR, "/new_stdin_file.txt");
//    FILE *file = fopen(path_to_rfile, "w");
//    my_str_write_file(&string1, file);
//    if (file)
//        fclose(file);
//
//    // in stream is now in the file
//    FILE *nstdin = freopen(path_to_rfile, "r", stdin);
//    // normal text read
//    ASSERT_EQ(my_str_read(&string2), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "hello, world!");
//    ASSERT_EQ(my_str_size(&string2), 13);
//    if (nstdin)
//        fclose(nstdin);
//
//    // read from empty stdin
//    my_str_from_cstr(&string1, "\n", 20);
//    file = fopen(path_to_rfile, "w");
//    my_str_write_file(&string1, file);
//    if (file)
//        fclose(file);
//
//    nstdin = freopen(path_to_rfile, "r", stdin);
//    ASSERT_EQ(my_str_read(&string2), 0);
//    ASSERT_STREQ(my_str_get_cstr(&string2), "");
//    ASSERT_EQ(my_str_size(&string2), 0);
//    if (nstdin)
//        fclose(nstdin);
//
//    // string is  NULL
//    ASSERT_EQ(my_str_read(NULL), NULL_PTR_ERR);
//}

//TEST_F(ClassDeclaration, my_str_read_file_HUGE) {
//    try {
//        // !DO NOT DECREASE FILE SIZE
//        char path_to_rfile[500];
//        sprintf(path_to_rfile, "%s%s", FILE_DIR, "/big_test.txt");
//
//        std::string test_str = test_read_file(path_to_rfile);
//        {
//            auto file = smart_fopen(path_to_rfile, "r");
//            if (file) {
//                ASSERT_EQ(my_str_read_file(&string1, file.get()), 0);
//            } else throw std::runtime_error("Unable to write to file");
//            ASSERT_STREQ(my_str_get_cstr(&string1), test_str.c_str());
//            ASSERT_EQ(my_str_size(&string1), test_str.length());
//        }
//    } catch (const std::runtime_error &e) {
//        std::cerr << e.what() << std::endl;
//    }
//}
//



//TEST_F(ClassDeclaration, my_str_read_file_delim) {
//    try {
//        my_str_from_cstr(&string1, "hello, \nworld", 20);
//        char path_to_rfile[500];
//        sprintf(path_to_rfile, "%s%s", FILE_DIR, "/read_file.txt");
//        test_write_file(path_to_rfile, std::string{"hello, \nworld"});
//
//        // read with the delimiter inside
//        // !FILE_DIR is located in SOURCE_DIR/google_tests/test_files!
//        {
//            auto file = smart_fopen(path_to_rfile, "r");
//            if (file) {
//                ASSERT_EQ(my_str_read_file_delim(&string2, file.get(), 'l'), 0);
//            } else throw std::runtime_error("Unable to read file");
//            ASSERT_STREQ(my_str_get_cstr(&string2), "he");
//            ASSERT_EQ(my_str_size(&string2), 2);
//        }
//
//        // read with delimiter at the beginning
//        test_write_file(path_to_rfile, std::string{});
//        {
//            auto file = smart_fopen(path_to_rfile, "r");
//            if (file) {
//                ASSERT_EQ(my_str_read_file_delim(&string2, file.get(), 'h'), 0);
//            } else throw std::runtime_error("Unable to read file");
//            ASSERT_STREQ(my_str_get_cstr(&string2), "");
//            ASSERT_EQ(my_str_size(&string2), 0);
//        }
//
//        // read to zero delimiter
//        {
//            auto file = smart_fopen(path_to_rfile, "r");
//            if (file) {
//                ASSERT_EQ(my_str_read_file_delim(&string2, file.get(), '\0'), 0);
//            } else throw std::runtime_error("Unable to read file");
//            ASSERT_STREQ(my_str_get_cstr(&string2), "");
//            ASSERT_EQ(my_str_size(&string2), 0);
//        }
//
//        // bad stream
//        {
//            auto file = smart_fopen(path_to_rfile, "w");
//            if (file) {
//                ASSERT_EQ(my_str_read_file_delim(&string2, file.get(), 'w'), IO_READ_ERR);
//            } else throw std::runtime_error("Unable to read file");
//        }
//
//        // read from empty file
//        test_write_file(path_to_rfile, std::string{});
//        {
//            auto file = smart_fopen(path_to_rfile, "r");
//            if (file) {
//                ASSERT_EQ(my_str_read_file_delim(&string2, file.get(), 'l'), 0);
//            } else throw std::runtime_error("Unable to read file");
//            ASSERT_STREQ(my_str_get_cstr(&string2), "");
//            ASSERT_EQ(my_str_size(&string2), 0);
//        }
//
//        // one of the arguments is NULL
//        {
//            auto file = smart_fopen(path_to_rfile, "r");
//            if (file) {
//                ASSERT_EQ(my_str_read_file_delim(nullptr, file.get(), 'w'), NULL_PTR_ERR);
//                ASSERT_EQ(my_str_read_file_delim(&string2, nullptr, 'w'), NULL_PTR_ERR);
//            } else throw std::runtime_error("Unable to read file");
//        }
//    } catch (const std::runtime_error &e) {
//        std::cerr << e.what() << std::endl;
//    }
//}
//
//static inline unique_file_ptr smart_freopen(const char *filename, const char *mode) {
//    return unique_file_ptr{freopen(filename, mode, stdin), fclose};
//}
//
//TEST_F(ClassDeclaration, my_str_read) {
//    try {
//        // read without \n
//        my_str_from_cstr(&string1, "hello, world", 20);
//        char path_to_rfile[500];
//        sprintf(path_to_rfile, "%s%s", FILE_DIR, "/read_file.txt");
//        test_write_file(path_to_rfile, std::string{"hello, world\n"});
//
//        // normal read
//        // !FILE_DIR is located in SOURCE_DIR/google_tests/test_files!
//        {
//            auto file = smart_freopen(path_to_rfile, "r");
//            if (file) {
//                ASSERT_EQ(my_str_read(&string2), 0);
//            } else throw std::runtime_error("Unable to read file");
//            ASSERT_STREQ(my_str_get_cstr(&string1), my_str_get_cstr(&string2));
//            ASSERT_EQ(my_str_size(&string1), my_str_size(&string2));
//        }
//
//        // read from empty file
//        test_write_file(path_to_rfile, std::string{});
//        {
//            auto file = smart_freopen(path_to_rfile, "r");
//            if (file) {
//                ASSERT_EQ(my_str_read(&string2), 0);
//            } else throw std::runtime_error("Unable to read file");
//            ASSERT_STREQ(my_str_get_cstr(&string2), "");
//            ASSERT_EQ(my_str_size(&string2), 0);
//        }
//
//        // bad stream
//        {
//            auto file = smart_freopen(path_to_rfile, "w");
//            if (file) {
//                ASSERT_EQ(my_str_read(&string2), IO_READ_ERR);
//            } else throw std::runtime_error("Unable to read file");
//        }
//
//        // the argument is NULL
//        {
//            auto file = smart_freopen(path_to_rfile, "r");
//            if (file) {
//                ASSERT_EQ(my_str_read(nullptr), NULL_PTR_ERR);
//            } else throw std::runtime_error("Unable to read file");
//        }
//    } catch (const std::runtime_error &e) {
//        std::cerr << e.what() << std::endl;
//    }
//}
//
