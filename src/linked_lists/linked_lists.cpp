// Copyright [2022] <DamianWu>

#include "linked_lists/linked_lists.hpp"

#include <iostream>

namespace singly_linked_list {

SinglyLinkedList::SinglyLinkedList(std::initializer_list<int> li) {
    for (const auto e : li) {
        push_back(e);
    }
}

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

auto SinglyLinkedList::find_position(const uint32_t position) {
    auto *current{first_};
    Element *before_current{nullptr};
    // Find position (for current)
    for (size_t i = 0; i < position; ++i) {  // initial current is not null
        // if end is reached (position > size)
        if (!current) {
            break;
        }
        before_current = current;
        current = current->next;
    }
    return std::make_pair(before_current, current);
}

void SinglyLinkedList::add(Element *const before_current,
                           Element *const current, const int value) {
    auto *new_element{new Element{value}};
    new_element->next = current;
    if (before_current) {  // handle before
        before_current->next = new_element;
    } else {  // if not empty and pos == 0
        first_ = new_element;
    }
}

void SinglyLinkedList::insert(Element *const before_current,
                              Element *const current, const int value) {
    if (!current) {  // position not found; add an element on the back
        push_back(value);
    } else {  // position found; add element
        add(before_current, current, value);
    }
}

void SinglyLinkedList::insert(const uint32_t position, const int value) {
    const auto [before_current, before]{find_position(position)};
    insert(before_current, before, value);
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

void SinglyLinkedList::handle_before(Element *const element,
                                     Element *const before_element) {
    if (before_element) {
        before_element->next = element->next;
    }
}

void SinglyLinkedList::handle_first(Element *const element) {
    if (element == first_) {
        // If next element exist
        if (element->next) {
            first_ = element->next;
        } else {
            first_ = nullptr;
            last_ = nullptr;
        }
    }
}

void SinglyLinkedList::handle_last(Element *const element,
                                   Element *const before_last) {
    if (element == last_) {  // element is guarantee not to be nullptr
        if (before_last) {
            before_last->next = nullptr;
            last_ = before_last;
        }
    }
}

void SinglyLinkedList::remove(Element *element, Element *before_element) {
    // Handle element before
    handle_before(element, before_element);
    // Handle if element was @first_ or @last_
    handle_first(element);
    handle_last(element, before_element);
    delete element;
}

bool operator==(const SinglyLinkedList &lhs, const SinglyLinkedList &rhs) {
    if (&lhs == &rhs) {
        return true;
    }

    Element *lhs_current{lhs.first_};
    Element *rhs_current{rhs.first_};
    // If both lists are empty, then they are equal
    while (lhs_current && rhs_current) {
        if (lhs_current->value != rhs_current->value) {
            return false;
        }
        lhs_current = lhs_current->next;
        rhs_current = rhs_current->next;
    }
    return !lhs_current && !rhs_current;
}

bool operator!=(const SinglyLinkedList &lhs, const SinglyLinkedList &rhs) {
    return !(lhs == rhs);
}

SinglyLinkedList operator+(const SinglyLinkedList &lhs,
                           const SinglyLinkedList &rhs) {
    SinglyLinkedList result;

    auto *lhs_current{lhs.first_};
    while (lhs_current != nullptr) {
        result.push_back(lhs_current->value);
    }

    auto *rhs_current{rhs.first_};
    while (rhs_current != nullptr) {
        result.push_back(rhs_current->value);
    }

    return result;
}

std::ostream &operator<<(std::ostream &os, SinglyLinkedList &ll) {
    auto *current{ll.front()};
    while (current) {
        os << current->value << ' ';
        current = current->next;
    }
    return os;
}

}  // namespace singly_linked_list

namespace doubly_linked_list {}  // namespace doubly_linked_list
