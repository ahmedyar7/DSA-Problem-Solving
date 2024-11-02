#include <iostream>

#include "Node.h"
using namespace std;

int main() {
  Node<int>* head1 = nullptr;
  Node<int>* head2 = nullptr;
  Node<int> dll(0);

  dll.insert_at_tail(head1, 10);
  dll.insert_at_tail(head1, 20);
  dll.insert_at_tail(head1, 20);
  dll.insert_at_tail(head1, 30);
  dll.insert_at_tail(head1, 20);

  // Node<int>* sorted = dll.sort_dll(head1);

  dll.display(head1);
  dll.remove_duplicates(head1);
  dll.display(head1);
}