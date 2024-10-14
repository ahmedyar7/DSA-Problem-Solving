#include <iostream>

#include "DoublyLinkedList.cpp"
#include "DoublyLinkedList.h"
#include "node.h"
using namespace std;

int main() {
  Node* head = nullptr;
  DoublyLinkedList dll;

  cout << "Checking the insert at head function\n";
  dll.insert_at_head(head, 2);
  dll.insert_at_head(head, 12);
  dll.insert_at_head(head, 22);
  dll.insert_at_head(head, 32);

  dll.display_H_T(head);

  cout << "Checking the insert at tail function\n";

  dll.insert_at_tail(head, 2);
  dll.insert_at_tail(head, 23);
  dll.insert_at_tail(head, 24);
  dll.display_H_T(head);

  cout << "Insert at position\n";
  dll.insert_at_location(head, 1, 1);
  dll.insert_at_location(head, 2, 2);
  dll.insert_at_location(head, 3, 3);

  dll.display_H_T(head);

  cout << "Cheking of the value in node\n";
  cout << dll.search_node(head, 32);

  cout << "Deleting the node from the doubly linked list\n";

  dll.delete_at_position(head, 2);
  dll.display_H_T(head);
}