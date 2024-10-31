#include <iostream>

#include "Node.h"
using namespace std;

int main() {
  Node<int>* head = nullptr;
  Node<int> dll(0);

  dll.insert_at_tail(head, 10);
  dll.insert_at_tail(head, 20);
  dll.insert_at_tail(head, 30);
  dll.insert_at_tail(head, 40);
  dll.insert_at_tail(head, 50);

  dll.display(head);

  dll.reverse_dll(head);
  dll.display(head);
}