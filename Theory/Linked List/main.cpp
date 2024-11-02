#include <iostream>

#include "Node.h"
using namespace std;

int main() {
  Node* head = nullptr;
  Node* head2 = nullptr;
  Node cdll(0);

  cdll.insert_at_head(head, 1);
  cdll.insert_at_head(head, 2);
  cdll.insert_at_head(head, 3);
  cdll.insert_at_head(head, 4);
  cdll.insert_at_head(head, 5);

  cdll.display(head);

  cdll.insert_at_tail(head2, 1);
  cdll.insert_at_tail(head2, 2);
  cdll.insert_at_tail(head2, 3);
  cdll.insert_at_tail(head2, 4);
  cdll.insert_at_tail(head2, 5);

  cdll.display(head2);
}