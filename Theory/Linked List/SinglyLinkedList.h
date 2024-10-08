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

  static void insert_at_tail(SinglyLinkedList*& head, int value);
  static void insert_at_head(SinglyLinkedList*& head, int value);
  static void insert_at_location(SinglyLinkedList*& head, int value,
                                 int position);
  static int max_element(SinglyLinkedList* head);
  static int min_element(SinglyLinkedList* head);
  static int count_SinglyLinkedLists(SinglyLinkedList* head);
  static void reversing_ll(SinglyLinkedList*& head);
  static bool search_SinglyLinkedList(SinglyLinkedList* head, int search_value);
  static void display(SinglyLinkedList* head);
  static bool is_looped(SinglyLinkedList* head);
  static void insert_at_sorted(SinglyLinkedList*& head, int value);
  static SinglyLinkedList* concatenate(SinglyLinkedList*& head,
                                       SinglyLinkedList*& SinglyLinkedList2);
  static bool is_sorted(SinglyLinkedList* head);
  static void remove_duplicate(SinglyLinkedList*& head);
  static SinglyLinkedList* merge_ll(SinglyLinkedList*& SinglyLinkedList1,
                                    SinglyLinkedList*& SinglyLinkedList2);
  static SinglyLinkedList* find_mid(SinglyLinkedList* head);
  static SinglyLinkedList* sort_ll(SinglyLinkedList* head);
  static SinglyLinkedList* segregate_oddeven(SinglyLinkedList* head);
};

#endif
