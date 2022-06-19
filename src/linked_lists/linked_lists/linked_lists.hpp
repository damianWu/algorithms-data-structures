// Copyright [2022] <DamianWu>

#ifndef SRC_LINKED_LISTS_LINKED_LISTS_LINKED_LISTS_HPP_
#define SRC_LINKED_LISTS_LINKED_LISTS_LINKED_LISTS_HPP_

#include <iostream>

namespace singly_linked_list {

// TODO(@damianWu) necessary?
enum class SEARCH_RESULT { FAIL, SUCCESS };

struct Element {
    int value{};
    Element *next{nullptr};  // pointer to the next element
};

class SinglyLinkedList {
    friend SinglyLinkedList operator+(const SinglyLinkedList &,
                                      const SinglyLinkedList &);

 public:
    const Element *cfront() const;
    const Element *cback() const;
    Element *find(int) const;
    Element *find(Element *) const;
    bool empty() const;

    void remove(int);
    void push_back(int);
    void push_front(int);

    ~SinglyLinkedList();

 private:
    Element *first_{nullptr};
    Element *last_{nullptr};
};

inline SinglyLinkedList::~SinglyLinkedList() {
    Element *current{first_};
    while (current != nullptr) {
        Element *next{current->next};
        delete current;
        current = next;
    }
    first_ = nullptr;
    last_ = nullptr;
}

inline SinglyLinkedList operator+(const SinglyLinkedList &lhs,
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

}  // namespace singly_linked_list

namespace doubly_linked_list {}  // namespace doubly_linked_list

#endif  // SRC_LINKED_LISTS_LINKED_LISTS_LINKED_LISTS_HPP_
