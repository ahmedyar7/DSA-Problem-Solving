#include <climits>
#include <iostream>

#include "Node.h"

int main() {
  Node* head1 = nullptr;
  Node* head2 = nullptr;
  Node sll(0);

  ;

  Node* head3 = nullptr;
  sll.insert_at_tail(head3, 1);
  sll.insert_at_tail(head3, 2);
  sll.insert_at_tail(head3, 3);
  sll.insert_at_tail(head3, 4);
  sll.insert_at_tail(head3, 5);
  sll.insert_at_tail(head3, 5);
  sll.insert_at_position(head3, 55, 2);
  // sll.delete_head(head3);
  sll.delete_at_position(head3, 2);

  // Node* oddeven = sll.segregate_into_odd_even(head3);
  // sll.display(oddeven);

  sll.display(head3);
}