

#include <iostream>
using namespace std;

class DoublyLinkedList {
 public:
  int data;
  DoublyLinkedList* next;
  DoublyLinkedList* previous;

  // Constructor
  DoublyLinkedList(int value) : data(value), next(nullptr), previous(nullptr) {}

  // Destructor
  ~DoublyLinkedList() {}

  // Function declarations
  void insert_at_tail(DoublyLinkedList*& head, int value);
  void display(DoublyLinkedList* head);
  void insert_at_head(DoublyLinkedList*& head, int value);
  void insert_at_position(DoublyLinkedList*& head, int value, int position);
  void delete_head(DoublyLinkedList*& head);
  void delete_at_position(DoublyLinkedList*& head, int position);
  DoublyLinkedList* concatenate(DoublyLinkedList*& list1,
                                DoublyLinkedList*& list2);
  DoublyLinkedList* merge_dll(DoublyLinkedList*& list1,
                              DoublyLinkedList*& list2);
  void remove_duplicate(DoublyLinkedList*& head);
  void insert_at_sorted_position(DoublyLinkedList*& head, int value);
};
