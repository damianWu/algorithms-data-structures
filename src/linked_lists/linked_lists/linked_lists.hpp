// Copyright [2022] <DamianWu>

#ifndef SRC_LINKED_LISTS_LINKED_LISTS_LINKED_LISTS_HPP_
#define SRC_LINKED_LISTS_LINKED_LISTS_LINKED_LISTS_HPP_

#include <initializer_list>
#include <iostream>
#include <utility>

namespace singly_linked_list {

template <typename T>
struct Element {
    T value{};
    Element *next{nullptr};  // pointer to the next element
};

template <typename T>
class SinglyLinkedList {
    template <typename U>
    friend SinglyLinkedList operator+(const SinglyLinkedList<U> &,
                                      const SinglyLinkedList<U> &);
    template <typename U>
    friend bool operator==(const SinglyLinkedList<U> &,
                           const SinglyLinkedList<U> &);
    template <typename U>
    friend bool operator!=(const SinglyLinkedList<U> &,
                           const SinglyLinkedList<U> &);

 public:
    SinglyLinkedList() = default;
    SinglyLinkedList(std::initializer_list<T>);

    const Element<T> *cfront() const;
    const Element<T> *cback() const;
    Element<T> *front() const;
    Element<T> *back() const;
    Element<T> *find(const T &) const;
    Element<T> *find(Element<T> *) const;
    bool empty() const;

    void remove(Element<T> *e);
    void push_back(const T &);
    void push_back(Element<T> *);
    void push_front(const T &);
    void push_front(Element<T> *);
    void pop_back();
    void pop_front();
    // Index begin with 0
    void insert(uint32_t, const T &);
    ~SinglyLinkedList();

 private:
    Element<T> *first_{nullptr};
    Element<T> *last_{nullptr};

 private:
    void handle_last(Element<T> *, Element<T> *);
    void handle_first(Element<T> *);
    void handle_before(Element<T> *, Element<T> *);
    void remove(Element<T> *, Element<T> *);
    auto find_position(uint32_t);
    void insert(Element<T> *, Element<T> *, const T &);
    void add(Element<T> *, Element<T> *, const T &);
};

template <typename T>
inline SinglyLinkedList<T>::~SinglyLinkedList() {
    Element<T> *current{first_};
    while (current) {
        Element<T> *next{current->next};
        delete current;
        current = next;
    }
    first_ = nullptr;
    last_ = nullptr;
}
template <typename T>
inline bool SinglyLinkedList<T>::empty() const {
    return !first_ && !last_;
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(std::initializer_list<T> li) {
    for (const auto e : li) {
        push_back(e);
    }
}
template <typename T>
Element<T> *SinglyLinkedList<T>::find(const T &x) const {
    Element<T> *current{first_};
    while (current != nullptr) {
        if (current->value == x) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template <typename T>
Element<T> *SinglyLinkedList<T>::find(Element<T> *const e) const {
    Element<T> *current{first_};
    while (current != nullptr) {
        if (current == e) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template <typename T>
void SinglyLinkedList<T>::push_back(const T &x) {
    auto *new_element = new Element<T>{x};
    push_back(new_element);
}

template <typename T>
void SinglyLinkedList<T>::push_back(Element<T> *const new_element) {
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

template <typename T>
void SinglyLinkedList<T>::push_front(const T &x) {
    auto *new_element{new Element<T>{x}};
    push_front(new_element);
}

template <typename T>
void SinglyLinkedList<T>::push_front(Element<T> *const new_element) {
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

template <typename T>
void SinglyLinkedList<T>::pop_back() {
    remove(last_);
}

template <typename T>
void SinglyLinkedList<T>::pop_front() {
    remove(first_);
}

template <typename T>
auto SinglyLinkedList<T>::find_position(const uint32_t position) {
    auto *current{first_};
    Element<T> *before_current{nullptr};
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

template <typename T>
void SinglyLinkedList<T>::add(Element<T> *const before_current,
                              Element<T> *const current, const T &value) {
    auto *new_element{new Element<T>{value}};
    new_element->next = current;
    if (before_current) {  // handle before
        before_current->next = new_element;
    } else {  // if not empty and pos == 0
        first_ = new_element;
    }
}

template <typename T>
void SinglyLinkedList<T>::insert(Element<T> *const before_current,
                                 Element<T> *const current, const T &value) {
    if (!current) {  // position not found; add an element on the back
        push_back(value);
    } else {  // position found; add element
        add(before_current, current, value);
    }
}

template <typename T>
void SinglyLinkedList<T>::insert(const uint32_t position, const T &value) {
    const auto [before_current, before]{find_position(position)};
    insert(before_current, before, value);
}

template <typename T>
void SinglyLinkedList<T>::remove(Element<T> *element) {
    if (element) {
        Element<T> *current{first_};
        Element<T> *before_current{nullptr};
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

template <typename T>
void SinglyLinkedList<T>::handle_before(Element<T> *const element,
                                        Element<T> *const before_element) {
    if (before_element) {
        before_element->next = element->next;
    }
}

template <typename T>
void SinglyLinkedList<T>::handle_first(Element<T> *const element) {
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

template <typename T>
void SinglyLinkedList<T>::handle_last(Element<T> *const element,
                                      Element<T> *const before_last) {
    if (element == last_) {  // element is guarantee not to be nullptr
        if (before_last) {
            before_last->next = nullptr;
            last_ = before_last;
        }
    }
}

template <typename T>
void SinglyLinkedList<T>::remove(Element<T> *element,
                                 Element<T> *before_element) {
    // Handle element before
    handle_before(element, before_element);
    // Handle if element was @first_ or @last_
    handle_first(element);
    handle_last(element, before_element);
    delete element;
}

template <typename T>
bool operator==(const SinglyLinkedList<T> &lhs,
                const SinglyLinkedList<T> &rhs) {
    if (&lhs == &rhs) {
        return true;
    }

    Element<T> *lhs_current{lhs.first_};
    Element<T> *rhs_current{rhs.first_};
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

template <typename T>
bool operator!=(const SinglyLinkedList<T> &lhs,
                const SinglyLinkedList<T> &rhs) {
    return !(lhs == rhs);
}

template <typename T>
SinglyLinkedList<T> operator+(const SinglyLinkedList<T> &lhs,
                              const SinglyLinkedList<T> &rhs) {
    SinglyLinkedList<T> result;

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

template <typename T>
std::ostream &operator<<(std::ostream &os, SinglyLinkedList<T> &ll) {
    auto *current{ll.front()};
    while (current) {
        os << current->value << ' ';
        current = current->next;
    }
    return os;
}

template <typename T>
inline const Element<T> *SinglyLinkedList<T>::cfront() const {
    return first_;
}
template <typename T>
inline const Element<T> *SinglyLinkedList<T>::cback() const {
    return last_;
}
template <typename T>
inline Element<T> *SinglyLinkedList<T>::front() const {
    return first_;
}
template <typename T>
inline Element<T> *SinglyLinkedList<T>::back() const {
    return last_;
}

}  // namespace singly_linked_list

namespace doubly_linked_list {}  // namespace doubly_linked_list

#endif  // SRC_LINKED_LISTS_LINKED_LISTS_LINKED_LISTS_HPP_
