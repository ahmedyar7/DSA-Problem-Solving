#include "DoublyLinkedList.h"

#include "node.h"

void DoublyLinkedList ::display_H_T(Node* head) {
  while (head != nullptr) {
    cout << "[" << head->get_data() << "] <-> ";
    head = head->get_next();
  }
  cout << "NUll\n";
}

void DoublyLinkedList::insert_at_head(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == nullptr) {
    head = new_node;
    return;
  }
  new_node->set_next(head);
  new_node->set_prev(nullptr);
  head->set_prev(new_node);
  head = new_node;
  return;
}

void DoublyLinkedList::insert_at_tail(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == nullptr) {
    head = new_node;
    return;
  }

  Node* temp = head;
  while (temp->get_next() != nullptr) {
    temp = temp->get_next();
  }
  temp->set_next(new_node);
  new_node->set_prev(head);
  new_node->set_next(nullptr);
  return;
}

void DoublyLinkedList::insert_at_location(Node*& head, int position,
                                          int value) {
  if (position <= 0) {
    cout << "Invalid Position\n";
    return;
  }

  Node* new_node = new Node(value);

  if (position == 1) {
    insert_at_head(head, value);
    return;
  }

  Node* temp = head;
  for (int i = 1; i < position - 1 && temp->get_next() != nullptr; i++) {
    temp = temp->get_next();
  }

  new_node->set_next(temp->get_next());
  if (temp->get_next() != nullptr) temp->get_next()->set_prev(new_node);
  new_node->set_prev(temp);
  temp->set_next(new_node);

  return;
}

bool DoublyLinkedList::search_node(Node* head, int search_value) {
  Node* temp = head;

  while (temp->get_next() != nullptr) {
    temp = temp->get_next();
    if (temp->get_data() == search_value) {
      return true;
    }
  }
  return false;
}

int DoublyLinkedList::delete_at_position(Node*& head, int position) {
  if (position <= 0) {
    cout << "Invalid Position\n";
    return -1;
  }

  if (position == 1) {
    Node* temp = head;
    int value = temp->get_data();
    head = head->get_next();
    delete temp;
    return value;
  }

  Node* temp = head;
  for (int i = 1; i < position && temp->get_next() != nullptr; i++) {
    temp = temp->get_next();
  }
  int value = temp->get_data();

  temp->get_prev()->set_next(temp->get_next());
  temp->get_next()->set_prev(temp->get_prev());

  delete temp;
  return value;
}

Node* DoublyLinkedList::merge(Node*& head1, Node*& head2) {
  if (head1 == nullptr) return head2;
  if (head2 == nullptr) return head1;

  Node* first = head1;
  Node* second = head2;
  Node* last = nullptr;
  Node* third = nullptr;

  if (first->get_data() < second->get_data()) {
    third = last = first;
    first = first->get_next();
  } else {
    third = last = second;
    second = second->get_next();
  }

  while (first != nullptr && second != nullptr) {
    if (first->get_data() < second->get_data()) {
      last->set_next(first);
      last = first;
      first = first->get_next();
    } else {
      last->set_next(second);
      last = second;
      second = second->get_next();
    }
  }

  if (first == nullptr) {
    last->set_next(second);
  } else {
    last->set_next(first);
  }

  return third;
}

Node* DoublyLinkedList::reverse_dll(Node* head) {
  if (head == nullptr || head->get_next() == nullptr) {
    return head;
  }

  Node* current = head;
  Node* temp = nullptr;

  while (current != nullptr) {
    temp = current->get_prev();
    current->set_prev(current->get_next());
    current->set_next(temp);
    current = current->get_prev();
  }
  if (temp != head) {
    head = temp->get_prev();
  }
  return head;
}
