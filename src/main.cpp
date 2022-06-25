// Copyright [2022] <@damianWu>

#include <iostream>

#include "linked_lists/linked_lists.hpp"

int main() {
    using singly_linked_list::SinglyLinkedList;
    try {
        // given
        constexpr int before{12};
        constexpr int new_value{542};
        constexpr int after{13};
        constexpr int pos{2};
        SinglyLinkedList sll{before, after};

        // when
        sll.insert(pos, new_value);
        auto* before_result{sll.find(before)};
        auto* result{sll.find(new_value)};
        // auto* after_result{sll.find(after)};
        std::cout << before_result->next << '\n';
        std::cout << result << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Exception catch in main function with message: "
                  << e.what() << '\n';
    } catch (...) {
        std::cerr << "Unknown type of exception catch in main function" << '\n';
    }
    std::cout << "======================main() end reached\n";
    return 0;
}
