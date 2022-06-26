// Copyright [2022] <DamianWu>

#ifndef SRC_LINKED_LISTS_LINKED_LISTS_LINKED_LISTS_HPP_
#define SRC_LINKED_LISTS_LINKED_LISTS_LINKED_LISTS_HPP_

#include <initializer_list>
#include <iostream>
#include <utility>

namespace singly_linked_list {

struct Element {
    int value{};
    Element *next{nullptr};  // pointer to the next element
};

class SinglyLinkedList {
    friend SinglyLinkedList operator+(const SinglyLinkedList &,
                                      const SinglyLinkedList &);
    friend bool operator==(const SinglyLinkedList &, const SinglyLinkedList &);
    friend bool operator!=(const SinglyLinkedList &, const SinglyLinkedList &);

 public:
    SinglyLinkedList() = default;
    SinglyLinkedList(std::initializer_list<int>);

    const Element *cfront() const;
    const Element *cback() const;
    Element *front() const;
    Element *back() const;
    Element *find(int) const;
    Element *find(Element *) const;
    bool empty() const;

    void remove(Element *e);
    void push_back(int);
    void push_back(Element *);
    void push_front(int);
    void push_front(Element *);
    void pop_back();
    void pop_front();
    // Index begin with 0
    void insert(uint32_t, int);
    ~SinglyLinkedList();

 private:
    Element *first_{nullptr};
    Element *last_{nullptr};

 private:
    void handle_last(Element *, Element *);
    void handle_first(Element *);
    void handle_before(Element *, Element *);
    void remove(Element *, Element *);
    auto find_position(uint32_t);
    void insert(const std::pair<Element *, Element *> &, int);
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

}  // namespace singly_linked_list

namespace doubly_linked_list {}  // namespace doubly_linked_list

#endif  // SRC_LINKED_LISTS_LINKED_LISTS_LINKED_LISTS_HPP_
