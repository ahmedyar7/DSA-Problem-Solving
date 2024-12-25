#include <iostream>

#include "doublycircular.h"
using namespace std;

int main() {
  DoublyCircular list;

  // Insert at the head
  list.insert_at_head(10);
  list.insert_at_head(20);
  list.insert_at_head(30);
  cout << "List after inserting at head: ";
  list.display();

  // Insert at the tail
  list.insert_at_tail(40);
  list.insert_at_tail(50);
  cout << "List after inserting at tail: ";
  list.display();

  // Insert at a specific position
  list.insert_at_position(3, 35);  // Insert 35 at position 3
  cout << "List after inserting at position 3: ";
  list.display();

  // Delete the head
  list.delete_head();
  cout << "List after deleting the head: ";
  list.display();

  // Delete at a specific position
  list.delete_at_position(3);  // Delete the node at position 3
  cout << "List after deleting at position 3: ";
  list.display();

  // Try to delete an invalid position
  list.delete_at_position(10);  // Invalid position
  cout << "List after attempting to delete at invalid position: ";
  list.display();

  return 0;
}