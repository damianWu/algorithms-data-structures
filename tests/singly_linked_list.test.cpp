// Copyright [2022] <@damianWu>

#include <gtest/gtest.h>

// #include <linked_lists/linked_lists.hpp>

namespace {

TEST(SinglyLinkedListPushBackTest, PushBackTest1) {
    // given
    int expected{-2005};
    // singly_linked_list::SinglyLinkedList sll;

    // when
    // sll.push_back(-2005);
    // int result{sll.cfront()->value};

    // // then
    ASSERT_EQ(-2005, expected);
}

// Find tests
// TEST(SinglyLinkedListFindTest, FindTest1) {
//     // given
//     singly_linked_list::SinglyLinkedList sll;
//     sll.push_back(2);
//     sll.push_back(5);
//     sll.push_back(10);
//     sll.push_back(15);
//     // when
//     // then
// }

}  // namespace
