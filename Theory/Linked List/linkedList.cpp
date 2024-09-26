#include <climits>
#include <iostream>
using namespace std;

class SinglyLinkedList {
 public:
  int data;
  SinglyLinkedList* next;

  SinglyLinkedList(int value) {
    data = value;
    next = nullptr;
  }

  ~SinglyLinkedList() {}

  void insert_at_tail(SinglyLinkedList*& head, int value) {
    SinglyLinkedList* new_SinglyLinkedList = new SinglyLinkedList(value);
    if (head == nullptr) {
      head = new_SinglyLinkedList;
      return;
    }
    SinglyLinkedList* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = new_SinglyLinkedList;
    return;
  }

  void insert_at_head(SinglyLinkedList*& head, int value) {
    SinglyLinkedList* new_SinglyLinkedList = new SinglyLinkedList(value);
    if (head == nullptr) {
      head = new_SinglyLinkedList;
      return;
    }
    new_SinglyLinkedList->next = head;
    head = new_SinglyLinkedList;
  }

  void insert_at_location(SinglyLinkedList*& head, int value, int position) {
    SinglyLinkedList* new_SinglyLinkedList = new SinglyLinkedList(value);
    if (position < 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (position == 1) {
      insert_at_head(head, value);
    }
    SinglyLinkedList* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
      current = current->next;
    }
    new_SinglyLinkedList->next = current->next;
    current->next = new_SinglyLinkedList;
  }

  int max_element(SinglyLinkedList* head) {
    int max = INT_MIN;
    SinglyLinkedList* temp = head;
    while (temp->next != nullptr) {
      if (temp->data > max) {
        max = temp->data;
      }
      temp = temp->next;
    }

    return max;
  }

  int min_element(SinglyLinkedList* head) {
    int min = INT_MAX;
    while (head != nullptr) {
      if (head->data < min) {
        min = head->data;
      }
      head = head->next;
    }
    return min;
  }

  int count_SinglyLinkedLists(SinglyLinkedList* head) {
    int counter = 0;
    if (head == nullptr) {
      return counter;
    }

    while (head != nullptr) {
      counter++;
      head = head->next;
    }
    return counter;
  }

  void reversing_ll(SinglyLinkedList*& head) {
    SinglyLinkedList* p = head;
    SinglyLinkedList* q = nullptr;
    SinglyLinkedList* r = nullptr;

    while (p != nullptr) {
      r = q;
      q = p;
      p = p->next;
      q->next = r;
    }
    head = q;
  }

  bool search_SinglyLinkedList(SinglyLinkedList* head, int search_value) {
    while (head != nullptr) {
      if (head->data == search_value) {
        return true;
      }
      head = head->next;
    }
    return false;
  }

  void display(SinglyLinkedList* head) {
    if (head == nullptr) {
      cout << "Empty List\n";
      return;
    }
    while (head != nullptr) {
      cout << head->data << " -> ";
      head = head->next;
    }
    cout << "NULL\n";
  }

  bool is_looped(SinglyLinkedList* head) {
    SinglyLinkedList* fast = head;
    SinglyLinkedList* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        return true;
      }
    }
    return false;
  }

  void insert_at_sorted(SinglyLinkedList*& head, int value) {
    SinglyLinkedList* new_SinglyLinkedList = new SinglyLinkedList(value);

    if (head == nullptr || head->data > value) {
      head = new_SinglyLinkedList;
      return;
    }

    SinglyLinkedList* current = head;
    while (current->next != nullptr && current->next->data < value) {
      current = current->next;
    }
    new_SinglyLinkedList->next = current->next;
    current->next = new_SinglyLinkedList;
    return;
  }

  SinglyLinkedList* conatenate(SinglyLinkedList*& SinglyLinkedList1,
                               SinglyLinkedList*& SinglyLinkedList2) {
    SinglyLinkedList* first = SinglyLinkedList1;
    SinglyLinkedList* second = SinglyLinkedList2;

    if (first == nullptr) return second;
    if (second == nullptr) return first;

    while (first->next != nullptr) {
      first = first->next;
    }
    first->next = second;
    return SinglyLinkedList1;
  }

  SinglyLinkedList* merge_ll(SinglyLinkedList*& SinglyLinkedList1,
                             SinglyLinkedList*& SinglyLinkedList2) {
    SinglyLinkedList* first = SinglyLinkedList1;
    SinglyLinkedList* second = SinglyLinkedList2;
    SinglyLinkedList* last = nullptr;
    SinglyLinkedList* third = nullptr;

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

    if (first == nullptr) last->next = second;
    if (second == nullptr) last->next = first;

    return third;
  }

  bool is_sorted(SinglyLinkedList* head) {
    SinglyLinkedList* current = head;
    SinglyLinkedList* previous = nullptr;

    while (current->next != nullptr) {
      previous = current;
      if (previous->data < current->data) return true;
      current = current->next;
    }
    return false;
  }

  void remove_duplicate(SinglyLinkedList*& head) {
    SinglyLinkedList* prev = head;
    SinglyLinkedList* current = prev->next;
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
      }
    }
  }
};

int main() {
  SinglyLinkedList* SinglyLinkedList1 = nullptr;
  SinglyLinkedList* SinglyLinkedList2 = nullptr;
  SinglyLinkedList sll(0);

  for (int i = 0; i <= 10; i++) {
    if (i % 2 == 0) {
      sll.insert_at_tail(SinglyLinkedList1, i * 2);
    }
  }
  sll.display(SinglyLinkedList1);

  for (int i = 0; i <= 10; i++) {
    if (i % 2 != 0) {
      sll.insert_at_tail(SinglyLinkedList2, i * 9);
      sll.insert_at_tail(SinglyLinkedList2, i * 9);
    }
  }
  sll.display(SinglyLinkedList2);

  SinglyLinkedList* merged = sll.merge_ll(SinglyLinkedList1, SinglyLinkedList2);
  sll.display(merged);

  sll.remove_duplicate(merged);
  sll.display(merged);
}