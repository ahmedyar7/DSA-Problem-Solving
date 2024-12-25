#include <iostream>

#include "practice.h"

int main() {
  Node *head = nullptr;
  Node node(0);
  DoublyLinkedList dll;

  dll.insert_at_tail(head, 10);
  dll.insert_at_tail(head, 10);
  dll.insert_at_tail(head, 10);
  dll.insert_at_tail(head, 10);
  dll.insert_at_tail(head, 1022);

  dll.insert_at_head(head, 23);
  dll.insert_at_head(head, 233);
  dll.insert_at_head(head, 213);

  dll.insert_at_position(head, 534, 2);
  dll.insert_at_position(head, 534, 5);
  dll.display(head);

  // dll.delete_head(head);
  dll.delete_at_position(head, 4);

  dll.display(head);
}