// Copyright [2022] <@damianWu>

#include <iostream>

#include "linked_lists/linked_lists.hpp"

int main() {
    using singly_linked_list::SinglyLinkedList;
    try {
        SinglyLinkedList<int> ll;
        ll.push_back(2);
        ll.push_back(-756);
        ll.push_back(456);
        ll.push_back(200);
        // std::cout << sll << '\n';
        ll.insert(0, 20000);
        std::cout << ll << '\n';
        std::cout << ll.empty() << '\n';
        // ll.pop_back();
        ll.pop_front();
        std::cout << ll.empty() << '\n';
        SinglyLinkedList<int> ll2;
        std::cout << (ll == ll2) << '\n';
        // sll.insert(0, 10000);
        // std::cout << sll << '\n';
        // sll.insert(1, 456);
        // sll.insert(1, 456);
        // sll.insert(1, 456);

        // when
        // sll.pop_back();
        // sll.pop_back();
        // sll.pop_back();
        // auto result{sll.empty()};
    } catch (const std::exception& e) {
        std::cerr << "Exception catch in main function with message: "
                  << e.what() << '\n';
    } catch (...) {
        std::cerr << "Unknown type of exception catch in main function" << '\n';
    }
    std::cout << "======================main() end reached\n";
    return 0;
}
