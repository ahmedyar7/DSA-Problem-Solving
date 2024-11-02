// SinglyLinkedList.h
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
using namespace std;

class SinglyLinkedList {
 private:
 public:
  int data;
  SinglyLinkedList* next;
  SinglyLinkedList(int value);
  ~SinglyLinkedList();

  void insert_at_tail(SinglyLinkedList*& head, int value);
  void insert_at_head(SinglyLinkedList*& head, int value);
  void insert_at_location(SinglyLinkedList*& head, int value, int position);
  int max_element(SinglyLinkedList* head);
  int min_element(SinglyLinkedList* head);
  int count_SinglyLinkedLists(SinglyLinkedList* head);
  void reversing_ll(SinglyLinkedList*& head);
  bool search_SinglyLinkedList(SinglyLinkedList* head, int search_value);
  void display(SinglyLinkedList* head);
  bool is_looped(SinglyLinkedList* head);
  void insert_at_sorted(SinglyLinkedList*& head, int value);
  //   SinglyLinkedList* concatenate(SinglyLinkedList*& head,
  // SinglyLinkedList*& SinglyLinkedList2);
  bool is_sorted(SinglyLinkedList* head);
  void remove_duplicate(SinglyLinkedList*& head);
  SinglyLinkedList* merge_ll(SinglyLinkedList*& SinglyLinkedList1,
                             SinglyLinkedList*& SinglyLinkedList2);
  SinglyLinkedList* find_mid(SinglyLinkedList* head);
  SinglyLinkedList* sort_ll(SinglyLinkedList* head);
  SinglyLinkedList* segregate_oddeven(SinglyLinkedList* head);
};

#endif
