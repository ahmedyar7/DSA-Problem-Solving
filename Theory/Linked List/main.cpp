#include <iostream>

#include "circular_ll.h"

using namespace std;

#include <iostream>
using namespace std;
int main() {
  CircularLL cll;

  // Insert elements
  cll.insert_at_head(10);
  cll.insert_at_tail(20);
  cll.insert_at_tail(30);
  cll.insert_at_position(15, 2);

  cout << "Circular Linked List after insertions: ";
  cll.display();

  // Delete head
  cll.delete_head();
  cout << "After deleting head: ";
  cll.display();

  // Delete at position
  cll.delete_at_position(2);
  cout << "After deleting at position 2: ";
  cll.display();

  // Insert again
  cll.insert_at_tail(40);
  cll.insert_at_tail(50);
  cout << "After additional insertions: ";
  cll.display();

  return 0;
}
