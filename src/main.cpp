// Copyright [2022] <@damianWu>

#include <iostream>

#include "linked_lists/linked_lists.hpp"

int main() {
    try {
        singly_linked_list::SinglyLinkedList sll;
        sll.push_back(-2005);

        // int result{sll.cfront()->value};
        // std::cout << result << '\n';
    } catch (const std::exception &e) {
        std::cerr << "Exception catch in main function with message: "
                  << e.what() << '\n';
    } catch (...) {
        std::cerr << "Unknown type of exception catch in main function" << '\n';
    }
    std::cout << "======================main() end reached\n";
    return 0;
}
