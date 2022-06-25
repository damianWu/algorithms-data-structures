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

void SinglyLinkedList::push_front(Element *const new_element) {
    if (new_element) {
        // if first_ contains sth
        if (empty()) {
            // if first_ is null
            first_ = new_element;
            last_ = new_element;
        } else {
            new_element->next = first_;
            first_ = new_element;
        }
    }
}

void SinglyLinkedList::pop_back() { remove(last_); }

void SinglyLinkedList::pop_front() { remove(first_); }

auto SinglyLinkedList::find_position(const uint32_t pos) {
    auto *current{first_};
    Element *before_current{nullptr};
    // Find position (for current)
    for (size_t i = 0; i < pos - 1; ++i) {  // initial current is not null
        // if end is reached (pos > size)
        if (!current) {
            break;
        }
        before_current = current;
        current = current->next;
    }
    return std::make_pair(before_current, current);
}

void SinglyLinkedList::insert(
    const std::pair<Element *, Element *> &before_current_and_current,
    const int value) {
    auto [before_current, current] = before_current_and_current;
    if (!current) {
        push_back(value);
    } else {
        // position found; add element
        auto *new_element{new Element{value}};
        new_element->next = current;
        if (before_current) {
            // handle before
            before_current->next = new_element;
        }
    }
}

void SinglyLinkedList::insert(const uint32_t pos, const int value) {
    if (!empty()) {
        // find position
        const auto before_current_and_current{find_position(pos)};
        // insert value
        insert(before_current_and_current, value);
    } else {
        // if empty
        auto *new_element{new Element{value}};
        first_ = new_element;
        last_ = new_element;
    }
}

bool SinglyLinkedList::empty() const {
    return !static_cast<bool>(first_) && !static_cast<bool>(last_);
}

void SinglyLinkedList::remove(Element *element) {
    if (element) {
        Element *current{first_};
        Element *before_current{nullptr};
        // execute only if current != nullptr and element != nullptr
        for (; current != nullptr; current = current->next) {
            if (current == element) {  // found
                remove(element, before_current);
                return;
            }
            before_current = current;
        }
    }
}

// void SinglyLinkedList::push_front(int x);

}  // namespace singly_linked_list

namespace doubly_linked_list {}  // namespace doubly_linked_list
