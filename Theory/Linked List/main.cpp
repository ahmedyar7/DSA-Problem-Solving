#include <iostream>

#include "Node.h"
using namespace std;

int main() {
  LinkedList ll;
  LinkedList ll2;

  ll.insert_at_tail(21);
  ll.insert_at_tail(24);
  ll.insert_at_tail(36);
  ll.insert_at_tail(8);
  ll.insert_at_tail(10);
  ll.insert_at_tail(212);
  ll.insert_at_tail(14);
  ll.display();

  ll2.insert_at_tail(1);
  ll2.insert_at_tail(3);
  ll2.insert_at_tail(5);
  ll2.insert_at_tail(7);
  ll2.insert_at_tail(9);
  ll2.insert_at_tail(11);
  ll2.insert_at_tail(13);

  ll2.display();

  // ll.head = ll.concatenation(ll2);

  // ll.head = ll.merged_ll(ll2);

  ll.min_n_max();

  ll.count_nodes();
}