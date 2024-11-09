#include <iostream>

#include "Node.h"
#include "circular_ll.h"
#include "doublyll.h"
using namespace std;

int main() {
  Doublyll dll;
  Doublyll dll2;

  dll.insert_at_tail(0);
  dll.insert_at_tail(1);
  dll.insert_at_tail(2);
  dll.insert_at_tail(3);
  dll.insert_at_tail(4);
  dll.insert_at_tail(5);
  dll.insert_at_tail(5);
  dll.insert_at_tail(6);
  dll.insert_at_tail(6);
  dll.insert_at_tail(7);
  dll.insert_at_tail(8);
  dll.insert_at_tail(9);
  dll.insert_at_tail(9);
  dll.insert_at_tail(10);
  dll.insert_at_tail(10);

  dll.display();

  dll.remove_duplicates();
  dll.display();
}