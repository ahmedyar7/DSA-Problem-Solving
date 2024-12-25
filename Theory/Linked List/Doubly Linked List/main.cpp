#include <iostream>

#include "doublycircular.h"
using namespace std;

int main() {
  DoublyCircular list;

  // Insert nodes at head
  list.insert_at_head(10);
  list.insert_at_head(20);
  list.insert_at_head(30);

  cout << "List after inserting at head: ";
  list.display();

  // Insert nodes at tail
  list.insert_at_tail(40);
  list.insert_at_tail(50);

  cout << "List after inserting at tail: ";
  list.display();

  // Insert node at position
  list.insert_at_position(3, 35);
  cout << "List after inserting at position 3: ";
  list.display();

  list.insert_at_position(1, 25);
  cout << "List after inserting at position 1: ";
  list.display();

  return 0;
}
