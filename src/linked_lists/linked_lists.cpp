// Copyright [2022] <DamianWu>

#include "linked_lists/linked_lists.hpp"

namespace singly_linked_list {

const Element *SinglyLinkedList::cfront() const { return first_; }
const Element *SinglyLinkedList::cback() const { return last_; }

Element *SinglyLinkedList::find(const int x) const {
    Element *current{first_};
    while (current != nullptr) {
        if (current->value == x) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void SinglyLinkedList::push_back(const int x) {
    auto *new_element = new Element{x};

    if (!first_) {
        first_ = new_element;
        last_ = new_element;
    } else {
        last_->next = new_element;
        last_ = new_element;
    }
}

// void SinglyLinkedList::remove(int x);

// void SinglyLinkedList::push_front(int x);

}  // namespace singly_linked_list

namespace doubly_linked_list {}  // namespace doubly_linked_list
