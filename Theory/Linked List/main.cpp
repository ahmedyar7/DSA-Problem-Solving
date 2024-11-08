#include <iostream>

#include "Node.h"
using namespace std;

int main() {
  LinkedList ll;
  LinkedList ll2;

  ll.insert_at_tail(2);
  ll.insert_at_tail(4);
  ll.insert_at_tail(6);
  ll.insert_at_tail(8);
  ll.insert_at_tail(10);

  ll2.insert_at_tail(1);
  ll2.insert_at_tail(3);
  ll2.insert_at_tail(5);
  ll2.insert_at_tail(7);
  ll2.insert_at_tail(9);

  Node* merged = ll.merged_ll(ll2);

  ll.display();
}