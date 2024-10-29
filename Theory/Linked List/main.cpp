#include <iostream>

#include "Node.h"
using namespace std;

int main() {
  Node<int>* head = nullptr;

  // Create an object of Node to access methods
  Node<int> cll(0);

  cll.insert_at_head(head, 5);
  cll.insert_at_head(head, 15);
  cll.insert_at_head(head, 25);

  cll.insert_at_tail(head, 22);
  cll.insert_at_tail(head, 32);

  cll.insert_at_position(head, 2, 23222);
  cll.delete_head(head);
  cll.delete_at_position(head, 2);

  cll.display(head);
}