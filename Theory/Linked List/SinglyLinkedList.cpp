#include <climits>

#include "SinglyLinkedList.h"
using namespace std;

SinglyLinkedList::SinglyLinkedList(int value) {
  data = value;
  next = nullptr;
}

// Destructor
SinglyLinkedList::~SinglyLinkedList() { delete next; }

void SinglyLinkedList::insert_at_tail(SinglyLinkedList*& head, int value) {
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

void SinglyLinkedList::insert_at_head(SinglyLinkedList*& head, int value) {
  SinglyLinkedList* new_SinglyLinkedList = new SinglyLinkedList(value);
  if (head == nullptr) {
    head = new_SinglyLinkedList;
    return;
  }
  new_SinglyLinkedList->next = head;
  head = new_SinglyLinkedList;
}

void SinglyLinkedList::insert_at_location(SinglyLinkedList*& head, int value,
                                          int position) {
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

int SinglyLinkedList::max_element(SinglyLinkedList* head) {
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

int SinglyLinkedList::min_element(SinglyLinkedList* head) {
  int min = INT_MAX;
  while (head != nullptr) {
    if (head->data < min) {
      min = head->data;
    }
    head = head->next;
  }
  return min;
}

int SinglyLinkedList::count_SinglyLinkedLists(SinglyLinkedList* head) {
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

void SinglyLinkedList::reversing_ll(SinglyLinkedList*& head) {
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

bool SinglyLinkedList::search_SinglyLinkedList(SinglyLinkedList* head,
                                               int search_value) {
  while (head != nullptr) {
    if (head->data == search_value) {
      return true;
    }
    head = head->next;
  }
  return false;
}

void SinglyLinkedList::display(SinglyLinkedList* head) {
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

bool SinglyLinkedList::is_looped(SinglyLinkedList* head) {
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

void SinglyLinkedList::insert_at_sorted(SinglyLinkedList*& head, int value) {
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

SinglyLinkedList* conatenate(SinglyLinkedList*& head,
                             SinglyLinkedList*& SinglyLinkedList2) {
  SinglyLinkedList* first = head;
  SinglyLinkedList* second = SinglyLinkedList2;

  if (first == nullptr) return second;
  if (second == nullptr) return first;

  while (first->next != nullptr) {
    first = first->next;
  }
  first->next = second;
  return head;
}

bool SinglyLinkedList::is_sorted(SinglyLinkedList* head) {
  SinglyLinkedList* current = head;
  SinglyLinkedList* previous = nullptr;

  while (current->next != nullptr) {
    previous = current;
    if (previous->data < current->data) return true;
    current = current->next;
  }
  return false;
}

void SinglyLinkedList::remove_duplicate(SinglyLinkedList*& head) {
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
SinglyLinkedList* SinglyLinkedList::merge_ll(
    SinglyLinkedList*& SinglyLinkedList1,
    SinglyLinkedList*& SinglyLinkedList2) {
  if (SinglyLinkedList1 == nullptr) return SinglyLinkedList2;
  if (SinglyLinkedList2 == nullptr) return SinglyLinkedList1;

  SinglyLinkedList* first = SinglyLinkedList1;
  SinglyLinkedList* second = SinglyLinkedList2;
  SinglyLinkedList* third = nullptr;
  SinglyLinkedList* last = nullptr;

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

  if (first == nullptr)
    last->next = second;
  else {
    last->next = first;
  }

  return third;
}

SinglyLinkedList* SinglyLinkedList::find_mid(SinglyLinkedList* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  SinglyLinkedList* slow = head;
  SinglyLinkedList* fast = head->next;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

SinglyLinkedList* SinglyLinkedList::sort_ll(SinglyLinkedList* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  SinglyLinkedList* middle = find_mid(head);
  SinglyLinkedList* left = head;
  SinglyLinkedList* right = middle->next;
  middle->next = nullptr;

  left = sort_ll(left);
  right = sort_ll(right);

  return merge_ll(left, right);
}

SinglyLinkedList* SinglyLinkedList::segregate_oddeven(SinglyLinkedList* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  SinglyLinkedList* odd = head;
  SinglyLinkedList* even = head->next;
  SinglyLinkedList* even_head = even;

  while (odd && odd->next) {
    odd->next = even->next;
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }
  odd->next = even_head;

  return head;
}

int main() {
  SinglyLinkedList* head = nullptr;

  SinglyLinkedList sll(0);

  // Call methods on the instance of the linked list
  sll.insert_at_tail(head, 2);
  sll.insert_at_tail(head, 1);
  sll.insert_at_tail(head, 3);
  sll.insert_at_tail(head, 5);
  sll.insert_at_tail(head, 6);
  sll.insert_at_tail(head, 4);
  sll.insert_at_tail(head, 7);

  cout << "Un-Segregated List: \n";
  sll.display(head);

  cout << "Segregated List\n";
  SinglyLinkedList* segregated = sll.segregate_oddeven(head);
  sll.display(segregated);
}
