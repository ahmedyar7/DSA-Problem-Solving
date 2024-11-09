#include <iostream>

#include "Node.h"
#include "circular_ll.h"
#include "doublyll.h"
using namespace std;

int main() {
  Doublyll dll;
  Doublyll dll2;

  dll.insert_at_tail(1);
  dll.insert_at_tail(3);
  dll.insert_at_tail(5);
  dll.insert_at_tail(7);
  dll.insert_at_tail(9);

  dll2.insert_at_tail(2);
  dll2.insert_at_tail(4);
  dll2.insert_at_tail(6);
  dll2.insert_at_tail(8);
  dll2.insert_at_tail(10);

  // dll.head = dll.merging(dll2);
  dll.display();

  dll.head = dll.concatenation(dll2);
  dll.display();
}