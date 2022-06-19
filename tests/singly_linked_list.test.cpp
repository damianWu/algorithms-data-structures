// Copyright [2022] <@damianWu>

#include <gtest/gtest.h>

#include <linked_lists/linked_lists.hpp>

namespace {

using singly_linked_list::Element;
using singly_linked_list::SinglyLinkedList;

TEST(SinglyLinkedListPushBackTest, PushBackTest1) {
    // given
    int expected{-2005};
    SinglyLinkedList sll;

    // when
    sll.push_back(-2005);
    int result{sll.cfront()->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListPushBackTest, PushBackTest2) {
    // given
    int expected{-2005};
    SinglyLinkedList sll;

    // when
    sll.push_back(-2005);
    int result{sll.cback()->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListPushBackTest, PushBackTest3) {
    // given
    int expected{-2005};
    SinglyLinkedList sll;

    // when
    sll.push_back(-2005);
    int result{sll.cfront()->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListNullElementTest, PushBackTestFrontIsNull) {
    // given
    const Element* expected{nullptr};
    SinglyLinkedList sll;

    // when
    const auto* result{sll.cfront()};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListNullElementTest, PushBackTestBackIsNull) {
    // given
    const Element* expected{nullptr};
    SinglyLinkedList sll;

    // when
    const auto* result{sll.cback()};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListIsEmptyTest, IsEmptyTest) {
    // given
    SinglyLinkedList sll;
    bool expected{true};

    // when
    auto result{sll.empty()};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListIsNotEmptyTest, IsNotEmptyTest) {
    // given
    SinglyLinkedList sll;
    sll.push_back(2);
    sll.push_back(-756);

    bool expected{false};

    // when
    auto result{sll.empty()};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListElementAccessTest, ElementAccessTest1) {
    // given
    SinglyLinkedList sll;
    sll.push_back(-2);
    sll.push_back(12);

    int expected{10};

    // when
    auto result_a{sll.find(-2)->value};
    auto result_b{sll.find(12)->value};
    auto result{result_a + result_b};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListElementAccessTest, ElementAccessTest2) {
    // given
    SinglyLinkedList sll;
    sll.push_back(-2);
    sll.push_back(12);
    sll.push_back(1);
    sll.push_back(10);

    int expected{21};

    // when
    auto result_a{sll.find(-2)->value};
    auto result_b{sll.find(12)->value};
    auto result_c{sll.find(1)->value};
    auto result_d{sll.find(10)->value};
    auto result{result_a + result_b + result_c + result_d};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListElementAccessTest, ElementAccessTest3) {
    // given
    SinglyLinkedList sll;
    sll.push_back(1);
    sll.push_back(-1);

    int expected{0};

    // when
    auto result_a_ptr{sll.find(-1)};
    auto result_b_ptr{sll.find(1)};
    auto result_a{sll.find(result_a_ptr)};
    auto result_b{sll.find(result_b_ptr)};
    auto result{result_a->value + result_b->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListElementAccessTest, ElementAccessTest4) {
    // given
    SinglyLinkedList sll;
    sll.push_back(8734);
    sll.push_back(711);

    int expected1{8734};
    int expected2{711};

    // when
    auto result_a{sll.find(8734)->value};
    auto result_b{sll.find(711)->value};
    auto result{expected1 == result_a && expected2 == result_b};

    // then
    ASSERT_TRUE(result);
}

TEST(SinglyLinkedListElementAccessTest, ElementAccessTest5) {
    // given
    SinglyLinkedList sll;
    sll.push_back(8734);
    sll.push_back(711);

    int expected1{8734};
    int expected2{711};

    // when
    auto result_a{sll.find(8734)->value};
    auto result_b{sll.find(711)->value};
    auto result{expected1 != result_a && expected2 != result_b};

    // then
    ASSERT_FALSE(result);
}

}  // namespace
