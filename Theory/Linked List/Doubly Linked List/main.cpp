#include "DoublyLinkedList.cpp"
#include "DoublyLinkedList.h"

int main() {
  DoublyLinkedList *head = nullptr;
  DoublyLinkedList dll(0);

  dll.insert_at_tail(head, 10);
  dll.insert_at_tail(head, 10);
  dll.insert_at_tail(head, 10);
  dll.insert_at_tail(head, 10);
  dll.insert_at_tail(head, 1022);

  dll.display(head);
}