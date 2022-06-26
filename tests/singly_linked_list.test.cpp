// Copyright [2022] <@damianWu>

#include <gtest/gtest.h>

#include <linked_lists/linked_lists.hpp>

namespace {

using singly_linked_list::Element;
using singly_linked_list::SinglyLinkedList;

TEST(SinglyLinkedListPushBackTest, PushBackTest1) {
    // given
    int expected{-2005};
    SinglyLinkedList<int> sll;

    // when
    sll.push_back(-2005);
    int result{sll.cfront()->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListPushBackTest, PushBackTest2) {
    // given
    int expected{-2005};
    SinglyLinkedList<int> sll;

    // when
    sll.push_back(-2005);
    int result{sll.cback()->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListPushBackTest, PushBackTest3) {
    // given
    int expected{-2005};
    SinglyLinkedList<int> sll;

    // when
    sll.push_back(-2005);
    int result{sll.cfront()->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListPushFrontTest, PushFrontTest1) {
    // given
    constexpr int expected{-2005};
    SinglyLinkedList<int> sll;

    // when
    sll.push_front(-2005);
    int result{sll.cfront()->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListPushFrontTest, PushFrontTest2) {
    // given
    constexpr int n1{-2005};
    constexpr int expected{621};
    SinglyLinkedList<int> sll;

    // when
    sll.push_front(n1);
    sll.push_front(expected);
    int result{sll.cfront()->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListPushFrontTest, PushFrontTest3) {
    // given
    constexpr int expected{-2005};
    auto* e1{new Element<int>{expected}};
    SinglyLinkedList<int> sll;

    // when
    sll.push_front(e1);
    int result{sll.cfront()->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListPushFrontTest, PushFrontTest4) {
    // given
    constexpr int n1{-2005};
    constexpr int expected{980};
    auto* e1{new Element<int>{n1}};
    auto* e2{new Element<int>{expected}};
    SinglyLinkedList<int> sll;

    // when
    sll.push_front(e1);
    sll.push_front(e2);
    int result{sll.cfront()->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListPopBackTest, PopBackTest1) {
    // given
    constexpr int expected{-2005};
    constexpr int n1{980};
    SinglyLinkedList<int> sll{expected, n1};

    // when
    sll.pop_back();
    int result{sll.back()->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListPopBackTest, PopBackTest2) {
    // given
    SinglyLinkedList<int> sll{2005};

    // when
    sll.pop_back();
    auto* result{sll.back()};

    // then
    ASSERT_EQ(result, nullptr);
}

TEST(SinglyLinkedListPopBackTest, PopBackTest3) {
    // given
    SinglyLinkedList<int> sll{};

    // when
    sll.pop_back();
    auto* result{sll.back()};

    // then
    ASSERT_EQ(result, nullptr);
}

TEST(SinglyLinkedListPopFrontTest, PopFrontTest1) {
    // given
    constexpr int n1{980};
    constexpr int expected{-2005};
    SinglyLinkedList<int> sll{n1, expected};

    // when
    sll.pop_front();
    auto result{sll.front()->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListPopFrontTest, PopFrontTest2) {
    // given
    SinglyLinkedList<int> sll{2005};

    // when
    sll.pop_front();
    auto* result{sll.front()};

    // then
    ASSERT_EQ(result, nullptr);
}

TEST(SinglyLinkedListPopFrontTest, PopFrontTest3) {
    // given
    SinglyLinkedList<int> sll{};

    // when
    sll.pop_front();
    auto* result{sll.front()};

    // then
    ASSERT_EQ(result, nullptr);
}

TEST(SinglyLinkedListNullElementTest, PushBackTestFrontIsNull) {
    // given
    const Element<int>* expected{nullptr};
    SinglyLinkedList<int> sll;

    // when
    const auto* result{sll.cfront()};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListNullElementTest, PushBackTestBackIsNull) {
    // given
    const Element<int>* expected{nullptr};
    SinglyLinkedList<int> sll;

    // when
    const auto* result{sll.cback()};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListInsertElementTest, InsertElementTest1) {
    // given
    constexpr int before{12};
    constexpr int expected{542};
    constexpr int after{13};
    constexpr int pos{2};
    SinglyLinkedList<int> sll{before, after};

    // when
    sll.insert(pos, expected);
    auto result{sll.find(expected)->value};

    // then
    ASSERT_EQ(result, expected);
}

TEST(SinglyLinkedListInsertElementTest, InsertElementTest2) {
    // given
    constexpr int before{12};
    constexpr int new_value{542};
    constexpr int after{13};
    constexpr int pos{1};
    SinglyLinkedList<int> sll{before, after};

    // when
    sll.insert(pos, new_value);
    auto* before_result{sll.find(before)};
    auto* result{sll.find(new_value)};
    auto* after_result{sll.find(after)};

    // then
    ASSERT_TRUE(before_result->next == result && result->next == after_result);
}

TEST(SinglyLinkedListInsertElementTest, InsertElementOutOfRangeTest1) {
    // given
    constexpr int before_before{12};
    constexpr int before{13};
    constexpr int new_value{542};
    constexpr int pos{50};
    SinglyLinkedList<int> sll{before_before, before};

    // when
    sll.insert(pos, new_value);
    auto* before_before_result{sll.find(before_before)};
    auto* before_result{sll.find(before)};
    auto* result{sll.find(new_value)};

    // then
    ASSERT_TRUE(before_before_result->next == before_result &&
                before_result->next == result);
}

TEST(SinglyLinkedListInsertElementTest, InsertElementOutOfRangeTest2) {
    // given
    constexpr int expected{542};
    constexpr int pos{50};
    SinglyLinkedList<int> sll{};

    // when
    sll.insert(pos, expected);
    auto result{sll.find(expected)->value};

    // then
    ASSERT_EQ(expected, result);
}

// TEST(SinglyLinkedListInsertElementTest, InsertElementOutOfRangeTest3) {
//     // given
//     constexpr int expected{542};
//     constexpr int pos{-50};
//     SinglyLinkedList<int> sll{};

//     // when
//     sll.insert(pos, expected);
//     auto result{sll.find(expected)->value};

//     // then
//     ASSERT_EQ(expected, result);
// }

TEST(SinglyLinkedListInsertElementTest, InsertElementPositionZeroTest1) {
    // given
    constexpr int expected{542};
    constexpr int pos{0};
    SinglyLinkedList<int> sll{};

    // when
    sll.insert(pos, expected);
    auto result{sll.find(expected)->value};

    // then
    ASSERT_EQ(expected, result);
}

TEST(SinglyLinkedListIsEmptyTest, IsEmptyTest1) {
    // given
    SinglyLinkedList<int> sll;

    // when
    auto result{sll.empty()};

    // then
    ASSERT_TRUE(result);
}

TEST(SinglyLinkedListIsEmptyTest, IsEmptyTest2) {
    // given
    SinglyLinkedList<int> sll;
    sll.push_back(2);
    sll.push_back(-756);
    sll.insert(1, 456);

    // when
    sll.pop_back();
    sll.pop_back();
    sll.pop_back();
    sll.pop_back();
    auto result{sll.empty()};

    // then
    ASSERT_TRUE(result);
}

TEST(SinglyLinkedListIsEmptyTest, IsEmptyTest3) {
    // given
    SinglyLinkedList<int> sll;
    sll.push_back(2);
    sll.push_back(-756);
    sll.insert(1, 456);
    sll.insert(0, 1000);

    // when
    sll.pop_back();
    sll.pop_back();
    sll.pop_back();
    sll.pop_back();
    auto result{sll.empty()};

    // then
    ASSERT_TRUE(result);
}

TEST(SinglyLinkedListIsNotEmptyTest, IsNotEmptyTest) {
    // given
    SinglyLinkedList<int> sll;
    sll.push_back(2);
    sll.push_back(-756);

    // when
    auto result{sll.empty()};

    // then
    ASSERT_FALSE(result);
}

TEST(SinglyLinkedListElementAccessTest, ElementAccessTest1) {
    // given
    SinglyLinkedList<int> sll;
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
    SinglyLinkedList<int> sll;
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
    SinglyLinkedList<int> sll;
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
    SinglyLinkedList<int> sll;
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
    SinglyLinkedList<int> sll;
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

TEST(SinglyLinkedListInitializerListTest, InitializerListTest1) {
    // given
    int expected1{534};
    int expected2{12};
    SinglyLinkedList<int> sll{expected1, expected2};

    // when
    auto result_1{sll.find(expected1)->value};
    auto result_2{sll.find(expected2)->value};
    auto result{result_1 == expected1 && result_2 == expected2};

    // then
    ASSERT_TRUE(result);
}

TEST(SinglyLinkedListInitializerListTest, InitializerListFailTest1) {
    // given
    int expected1{534};
    int expected2{12};
    SinglyLinkedList<int> sll{expected1, 54};

    // when
    auto result_1{sll.find(expected1)->value};
    auto result_2_temp{sll.find(expected2)};
    auto result_2{result_2_temp == nullptr ? 0 : result_2_temp->value};
    auto result{result_1 == expected1 && result_2 == expected2};

    // then
    ASSERT_FALSE(result);
}

TEST(SinglyLinkedListCompareListsTest, CompareListsTest1) {
    // given
    SinglyLinkedList<int> sll1{100};
    SinglyLinkedList<int> sll2{100};

    // when
    auto result{sll1 == sll2};

    // then
    ASSERT_TRUE(result);
}

TEST(SinglyLinkedListCompareListsTest, CompareListsTest2) {
    // given
    SinglyLinkedList<int> sll1{100};
    SinglyLinkedList<int> sll2{200};

    // when
    auto result{sll1 == sll2};

    // then
    ASSERT_FALSE(result);
}

TEST(SinglyLinkedListCompareListsTest, CompareListsTest3) {
    // given
    SinglyLinkedList<int> sll1{};
    SinglyLinkedList<int> sll2{};

    // when
    auto result{sll1 == sll2};

    // then
    ASSERT_TRUE(result);
}

TEST(SinglyLinkedListCompareListsTest, CompareListsTest4) {
    // given
    SinglyLinkedList<int> sll1;
    SinglyLinkedList<int> sll2;

    // when
    auto result{sll1 == sll2};

    // then
    ASSERT_TRUE(result);
}

TEST(SinglyLinkedListCompareListsTest, CompareListsTest5) {
    // given
    SinglyLinkedList<int> sll1{100};
    SinglyLinkedList<int> sll2{};

    // when
    auto result{sll1 == sll2};

    // then
    ASSERT_FALSE(result);
}

TEST(SinglyLinkedListCompareListsTest, CompareListsTest6) {
    // given
    SinglyLinkedList<int> sll1{100, 200, 300, 400, 800};
    SinglyLinkedList<int> sll2{100, 200, 300, 400, 800};

    // when
    auto result{sll1 == sll2};

    // then
    ASSERT_TRUE(result);
}

TEST(SinglyLinkedListCompareListsTest, CompareListsTest7) {
    // given
    SinglyLinkedList<int> sll1{100, 200, 300, -400, 800};
    SinglyLinkedList<int> sll2{100, 200, 300, 400, 800};

    // when
    auto result{sll1 == sll2};

    // then
    ASSERT_FALSE(result);
}

TEST(SinglyLinkedListConcatenateWithPlusOperatorTest, PlusOperatorTest1) {
    // given
    SinglyLinkedList<int> sll1{100};
    SinglyLinkedList<int> sll2{200};
    SinglyLinkedList<int> expected{100, 200};

    // when
    auto result{sll1 == sll2};
    // then
    ASSERT_FALSE(result);
}

TEST(SinglyLinkedListEmptyListTest, EmptyListTest1) {
    // given
    SinglyLinkedList<int> sll;

    // when
    // then
    ASSERT_TRUE(sll.empty());
}

TEST(SinglyLinkedListEmptyListTest, EmptyListTest2) {
    // given
    auto* e1{new Element<int>{100}};
    auto* e2{new Element<int>{100}};
    SinglyLinkedList<int> sll;
    sll.push_back(e1);
    sll.push_back(e2);

    // then
    ASSERT_FALSE(sll.empty());
}

TEST(SinglyLinkedListDeleteElementTest, DeleteElementTest1) {
    // given
    auto* e{new Element<int>{100}};
    SinglyLinkedList<int> sll;
    sll.push_back(e);

    // when
    sll.remove(e);

    // then
    ASSERT_TRUE(sll.empty());
}

TEST(SinglyLinkedListDeleteElementTest, DeleteSameElementTwiceTest2) {
    // given
    auto* e{new Element<int>{100}};
    SinglyLinkedList<int> sll;
    sll.push_back(e);

    // when
    sll.remove(e);
    sll.remove(e);

    // then
    ASSERT_TRUE(sll.empty());
}

TEST(SinglyLinkedListDeleteElementTest, DeleteElementTest3) {
    // given
    auto* e1{new Element<int>{100}};
    auto* e2{new Element<int>{123}};
    auto* e3{new Element<int>{345}};
    auto* e4{new Element<int>{5656}};
    SinglyLinkedList<int> sll;
    sll.push_back(e1);
    sll.push_back(e2);
    sll.push_back(e3);
    sll.push_back(e4);

    // when
    sll.remove(e1);
    sll.remove(e2);
    sll.remove(e3);
    sll.remove(e4);

    // then
    ASSERT_TRUE(sll.empty() && !sll.cfront() && !sll.cback());
}

TEST(SinglyLinkedListDeleteElementTest, DeleteSecondElementTest4) {
    // given
    constexpr int n1{100};
    constexpr int n2{123};
    constexpr int n3{345};
    constexpr int n4{5656};
    auto* expected1{new Element<int>{n1}};
    auto* expected2{new Element<int>{n2}};
    auto* expected3{new Element<int>{n3}};
    auto* expected4{new Element<int>{n4}};
    SinglyLinkedList<int> sll;
    sll.push_back(expected1);
    sll.push_back(expected2);
    sll.push_back(expected3);
    sll.push_back(expected4);

    // when
    sll.remove(expected2);
    expected1 = sll.find(expected1);
    expected2 = sll.find(expected2);
    expected3 = sll.find(expected3);
    expected4 = sll.find(expected4);

    // then
    ASSERT_TRUE(expected1->value == n1 && expected3->value == n3 &&
                expected4->value == n4 && !expected2);
}

TEST(SinglyLinkedListDeleteElementTest, DeleteNullElementTest5) {
    // given
    SinglyLinkedList<int> sll;

    // when
    sll.remove(nullptr);
    sll.remove(nullptr);

    // then
    ASSERT_TRUE(sll.empty());
}

TEST(SinglyLinkedListDeleteElementTest, DeleteElementWhichNotExistTest6) {
    // given
    auto* e{new Element<int>{42}};
    SinglyLinkedList<int> sll;

    // when
    sll.remove(e);
    sll.remove(nullptr);
    sll.remove(nullptr);
    delete e;

    // then
    ASSERT_TRUE(sll.empty());
}

TEST(SinglyLinkedListDeleteElementTest, DeleteElementLastTest7) {
    // given
    auto* e1{new Element<int>{42}};
    auto* e2{new Element<int>{43}};
    auto* e3{new Element<int>{44}};
    SinglyLinkedList<int> sll;
    sll.push_back(e1);
    sll.push_back(e2);
    sll.push_back(e3);
    const auto* expected{e2};

    // when
    sll.remove(sll.back());

    // then
    ASSERT_TRUE(expected == sll.cback());
}

TEST(SinglyLinkedListDeleteElementTest, DeleteElementFirstTest8) {
    // given
    auto* e1{new Element<int>{42}};
    auto* e2{new Element<int>{43}};
    auto* e3{new Element<int>{44}};
    SinglyLinkedList<int> sll;
    sll.push_back(e1);
    sll.push_back(e2);
    sll.push_back(e3);
    const auto* expected{e2};

    // when
    sll.remove(sll.front());

    // then
    ASSERT_TRUE(expected == sll.cfront());
}

TEST(SinglyLinkedListDeleteElementTest, DeleteElementOneFirstTest9) {
    // given
    auto* e1{new Element<int>{42}};
    SinglyLinkedList<int> sll;
    sll.push_back(e1);

    // when
    sll.remove(sll.front());

    // then
    ASSERT_TRUE(nullptr == sll.cfront());
}

TEST(SinglyLinkedListDeleteElementTest, DeleteElementOneLastTest10) {
    // given
    auto* e1{new Element<int>{42}};
    SinglyLinkedList<int> sll;
    sll.push_back(e1);

    // when
    sll.remove(sll.back());

    // then
    ASSERT_TRUE(nullptr == sll.cback());
}

}  // namespace
