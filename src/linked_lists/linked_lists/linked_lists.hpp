// Copyright [2022] <DamianWu>

#ifndef SRC_LINKED_LISTS_LINKED_LISTS_LINKED_LISTS_HPP_
#define SRC_LINKED_LISTS_LINKED_LISTS_LINKED_LISTS_HPP_

namespace singly_linked_list {

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

    void remove(int);
    void push_back(int);
    void push_front(int);

    ~SinglyLinkedList();

 private:
    Element *first_;
    Element *last_;
};

// TODO(@damianWu) Is this correct?
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
