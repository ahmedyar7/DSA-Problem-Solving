#include <climits>
#include <iostream>

#include "Node.h"

int main() {
  Node* head1 = nullptr;
  Node* head2 = nullptr;
  Node sll(0);

  sll.insert_at_tail(head1, 1);
  sll.insert_at_tail(head1, 433);
  sll.insert_at_tail(head2, 22);
  sll.insert_at_tail(head2, 314);
  sll.insert_at_tail(head1, 2435);
  sll.insert_at_tail(head1, 235);
  sll.insert_at_tail(head1, 235);

  sll.display(head1);

  sll.insert_at_tail(head2, 6);
  sll.insert_at_tail(head2, 7);
  sll.insert_at_tail(head1, 8);
  sll.insert_at_tail(head2, 9);
  sll.insert_at_tail(head1, 10);
  sll.display(head2);

  // Node* concaten = sll.concatenate_linked_list(head1, head2);
  Node* merge = sll.merged_linked_list(head1, head2);
  sll.display(merge);

  Node* sorted = sll.sort_ll(merge);
  sll.display(sorted);
}