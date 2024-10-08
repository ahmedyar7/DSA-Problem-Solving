#include "SinglyLinkedList.cpp"
#include "SinglyLinkedList.h"

int main() {
  SinglyLinkedList* head = nullptr;

  SinglyLinkedList sll(0);

  // Call methods on the instance of the linked list
  sll.insert_at_tail(head, 2);
  sll.insert_at_tail(head, 1);
  sll.insert_at_tail(head, 3);
  sll.insert_at_tail(head, 5);
  sll.insert_at_tail(head, 6);
  sll.insert_at_tail(head, 4);
  sll.insert_at_tail(head, 7);

  cout << "Un-Segregated List: \n";
  sll.display(head);

  cout << "Segregated List\n";
  SinglyLinkedList* segregated = sll.segregate_oddeven(head);
  sll.display(segregated);
}
