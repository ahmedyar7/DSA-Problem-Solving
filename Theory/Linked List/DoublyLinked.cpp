#include <iostream>
using namespace std;

class DoublyLinkedList {
 public:
  int data;
  DoublyLinkedList* next;
  DoublyLinkedList* previous;

  DoublyLinkedList(int value) {
    data = value;
    next = nullptr;
    previous = nullptr;
  }

  ~DoublyLinkedList() {}

  void insert_at_tail(DoublyLinkedList*& head, int value) {
    DoublyLinkedList* new_DoublyLinkedList = new DoublyLinkedList(value);
    if (head == nullptr) {
      head = new_DoublyLinkedList;
      return;
    }
    DoublyLinkedList* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = new_DoublyLinkedList;
    new_DoublyLinkedList->previous = temp;
  }

  void display(DoublyLinkedList* head) {
    if (head == nullptr) {
      cout << "Empty List\n";
      return;
    }
    while (head != nullptr) {
      cout << head->data << " <-> ";
      head = head->next;
    }
    cout << "NULL\n";
  }

  void insert_at_head(DoublyLinkedList*& head, int value) {
    DoublyLinkedList* new_DoublyLinkedList = new DoublyLinkedList(value);
    if (head == nullptr) {
      head = new_DoublyLinkedList;
      return;
    }
    new_DoublyLinkedList->next = head;
    head->previous = new_DoublyLinkedList;
    head = new_DoublyLinkedList;
  }

  void insert_at_position(DoublyLinkedList*& head, int value, int position) {
    DoublyLinkedList* new_DoublyLinkedList = new DoublyLinkedList(value);
    if (head == nullptr || position < 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (position == 1) {
      insert_at_head(head, value);
      return;
    }
    DoublyLinkedList* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
      temp = temp->next;
    }
    new_DoublyLinkedList->next = temp->next;
    temp->next = new_DoublyLinkedList;
    temp->next->previous = new_DoublyLinkedList;
    new_DoublyLinkedList->previous = temp;

    return;
  }

  void delete_head(DoublyLinkedList*& head) {
    if (head == nullptr) {
      cout << "Empty Linked List\n";
      return;
    }
    DoublyLinkedList* temp = head;
    head = head->next;
    delete temp;
  }

  void delete_at_position(DoublyLinkedList*& head, int position) {
    if (head == nullptr || position < 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (position == 1) {
      delete_head(head);
      return;
    }
    DoublyLinkedList* temp = head;
    for (int i = 1; i < position && temp->next != nullptr; i++) {
      temp = temp->next;
    }
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    delete temp;
  }

  DoublyLinkedList* concatenate(DoublyLinkedList*& DoublyLinkedList1,
                                DoublyLinkedList*& DoublyLinkedList2) {
    DoublyLinkedList* first = DoublyLinkedList1;
    DoublyLinkedList* second = DoublyLinkedList2;

    if (first == nullptr) return second;
    if (second == nullptr) return first;

    while (first->next != nullptr) {
      first = first->next;
    }
    first->next = second;
    return DoublyLinkedList1;
  }

  DoublyLinkedList* merge_dll(DoublyLinkedList*& DoublyLinkedList1,
                              DoublyLinkedList*& DoublyLinkedList2) {
    DoublyLinkedList* first = DoublyLinkedList1;
    DoublyLinkedList* second = DoublyLinkedList2;
    DoublyLinkedList* third = nullptr;
    DoublyLinkedList* last = nullptr;

    if (first == nullptr) return second;
    if (second == nullptr) return first;

    if (first->data < second->data) {
      third = last = first;
      first = first->next;
    } else {
      third = last = second;
      second = second->next;
    }

    while (first != nullptr && second != nullptr) {
      if (first->data < second->data) {
        last->next = first;
        last = first;
        first = first->next;
      } else {
        last->next = second;
        last = second;
        second = second->next;
      }
    }

    if (first == nullptr) {
      last->next = second;
    }
    if (second == nullptr) {
      last->next = first;
    }
    return third;
  }

  void remove_duplicate(DoublyLinkedList*& head) {
    DoublyLinkedList* prev = head;
    DoublyLinkedList* current = prev->next;
    if (head == nullptr) {
      cout << "List Is Empty\n";
      return;
    }
    while (current != nullptr) {
      if (current->data != prev->data) {
        prev = current;
        current = current->next;
      } else {
        prev->next = current->next;
        delete current;
        current = prev->next;
        current->previous = current;
      }
    }
  }

  void insert_at_sorted_position(DoublyLinkedList*& head, int value) {
    DoublyLinkedList* new_DoublyLinkedList = new DoublyLinkedList(value);
    if (head == nullptr || head->data >= value) {
      new_DoublyLinkedList->next = head;
      if (head != nullptr) {
        head->previous = new_DoublyLinkedList;
      }
      head = new_DoublyLinkedList;
      return;
    }
    DoublyLinkedList* temp = head;
    while (temp->next != nullptr || temp->data < value) {
      temp = temp->next;
    }
    new_DoublyLinkedList->next = temp->next;
    if (temp->next != nullptr) {
      temp->next->previous = new_DoublyLinkedList;
    }
    temp->next = new_DoublyLinkedList;
    new_DoublyLinkedList->previous = temp;
  }
};

int main() {
  DoublyLinkedList* DoublyLinkedList1 = nullptr;  // node 1
  DoublyLinkedList* DoublyLinkedList2 = nullptr;  // node 2
  DoublyLinkedList dll(0);                        // object
  for (int i = 0; i < 10; i++) {
    dll.insert_at_tail(DoublyLinkedList1, i);
    dll.insert_at_tail(DoublyLinkedList2, i - 2);
  }
  dll.display(DoublyLinkedList1);
  dll.display(DoublyLinkedList2);

  // DoublyLinkedList* concat = concatenate(DoublyLinkedList1,
  // DoublyLinkedList2);
  DoublyLinkedList* merged =
      dll.merge_dll(DoublyLinkedList1, DoublyLinkedList2);

  dll.display(merged);
  dll.remove_duplicate(merged);
  dll.insert_at_sorted_position(merged, 5);
  dll.display(merged);
}