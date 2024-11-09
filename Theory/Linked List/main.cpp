#include <iostream>

#include "Node.h"
#include "circular_ll.h"
using namespace std;

int main() {
  CircularLinkedList cll;

  cll.insert_at_head(5);
  cll.insert_at_head(15);
  cll.insert_at_head(35);
  cll.insert_at_head(45);

  cll.insert_at_tail(5);
  cll.insert_at_tail(15);
  cll.insert_at_tail(35);
  cll.insert_at_tail(45);

  cll.display();
}