// Copyright [2022] <DamianWu>

#include "linked_lists/linked_lists.hpp"

#include <cstddef>
#include <iostream>

namespace singly_linked_list {

SinglyLinkedList::SinglyLinkedList(std::initializer_list<int> li) {
    for (const auto e : li) {
        push_back(e);
    }
}

const Element *SinglyLinkedList::cfront() const { return first_; }
const Element *SinglyLinkedList::cback() const { return last_; }

Element *SinglyLinkedList::front() const { return first_; }
Element *SinglyLinkedList::back() const { return last_; }

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

Element *SinglyLinkedList::find(Element *const e) const {
    Element *current{first_};
    while (current != nullptr) {
        if (current == e) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void SinglyLinkedList::push_back(const int x) {
    auto *new_element = new Element{x};
    push_back(new_element);
}

void SinglyLinkedList::push_back(Element *const new_element) {
    if (new_element) {
        // If list is empty
        if (empty()) {
            first_ = new_element;
            last_ = new_element;
        } else {
            last_->next = new_element;
            new_element->next = nullptr;
            last_ = new_element;
        }
    }
}

void SinglyLinkedList::push_front(const int x) {
    auto *new_element{new Element{x}};
    push_front(new_element);
}

    // If linked list is empty
    if (!static_cast<bool>(first_)) {
        first_ = new_element;
        last_ = new_element;
        return;
    }
    last_->next = new_element;
    last_ = new_element;
}

bool SinglyLinkedList::empty() const { return !static_cast<bool>(first_); }

// void SinglyLinkedList::remove(int x);

// void SinglyLinkedList::push_front(int x);

}  // namespace singly_linked_list

namespace doubly_linked_list {}  // namespace doubly_linked_list
