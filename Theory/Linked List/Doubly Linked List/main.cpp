#include <iostream>

#include "practice.h"

int main() {
  DoublyLinkedList dll;
  Node* head1 = nullptr;
  Node* head2 = nullptr;

  // Testing insert_at_head
  cout << "Inserting at head:\n";
  dll.insert_at_head(head1, 10);
  dll.insert_at_head(head1, 20);
  dll.insert_at_head(head1, 30);
  dll.display(head1);

  // Testing insert_at_tail
  cout << "\nInserting at tail:\n";
  dll.insert_at_tail(head1, 5);
  dll.insert_at_tail(head1, 0);
  dll.display(head1);

  // Testing insert_at_position
  cout << "\nInserting at position 3:\n";
  dll.insert_at_position(head1, 15, 3);
  dll.display(head1);

  // Testing delete_head
  cout << "\nDeleting head:\n";
  dll.delete_head(head1);
  dll.display(head1);

  // Testing delete_at_position
  cout << "\nDeleting at position 4:\n";
  dll.delete_at_position(head1, 4);
  dll.display(head1);

  // Testing concatenation
  cout << "\nCreating second list and concatenating:\n";
  dll.insert_at_tail(head2, 50);
  dll.insert_at_tail(head2, 60);
  dll.insert_at_tail(head2, 70);
  dll.display(head2);

  // Testing merge_dll
  cout << "\nTesting merge of two sorted lists:\n";
  Node* sorted1 = nullptr;
  Node* sorted2 = nullptr;
  dll.insert_at_tail(sorted1, 1);
  dll.insert_at_tail(sorted1, 3);
  dll.insert_at_tail(sorted1, 5);
  dll.insert_at_tail(sorted2, 2);
  dll.insert_at_tail(sorted2, 4);
  dll.insert_at_tail(sorted2, 6);

  cout << "List 1: ";
  dll.display(sorted1);
  cout << "List 2: ";
  dll.display(sorted2);

  Node* merged = dll.merge_dll(sorted1, sorted2);
  cout << "Merged list: ";
  dll.display(merged);

  // Testing sort
  cout << "\nTesting sorting of an unsorted list:\n";
  Node* unsorted = nullptr;
  dll.insert_at_tail(unsorted, 7);
  dll.insert_at_tail(unsorted, 2);
  dll.insert_at_tail(unsorted, 9);
  dll.insert_at_tail(unsorted, 1);
  dll.insert_at_tail(unsorted, 5);

  cout << "Unsorted list: ";
  dll.display(unsorted);

  Node* sorted = dll.sort(unsorted);
  cout << "Sorted list: ";
  dll.display(sorted);

  return 0;
}
