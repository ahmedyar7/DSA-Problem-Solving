#include <iostream>

#include "practice.h"

int main() {
  Node *head = nullptr;
  Node node(0);
  DoublyLinkedList dll;

  dll.insert_at_tail(head, 0);
  dll.insert_at_tail(head, 2);
  dll.insert_at_tail(head, 4);
  dll.insert_at_tail(head, 8);
  dll.insert_at_tail(head, 10);
  dll.display(head);

  Node *head2 = nullptr;
  Node node2(0);
  DoublyLinkedList dll2;

  dll2.insert_at_tail(head2, 1);
  dll2.insert_at_tail(head2, 3);
  dll2.insert_at_tail(head2, 5);
  dll2.insert_at_tail(head2, 7);
  dll2.insert_at_tail(head2, 9);

  // Node *concat = dll.contatenation(head, head2);

  dll.display(head2);

  Node *merge = dll.merge_dll(head, head2);
  dll.display(merge);
}