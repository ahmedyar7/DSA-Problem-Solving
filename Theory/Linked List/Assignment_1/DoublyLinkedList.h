#include "node.h"
using namespace std;

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

class DoublyLinkedList {
 public:
  // . -- DISPLAY --
  void display_H_T(Node* head);

  //.  -- INSERTION --
  void insert_at_head(Node*& head, int value);
  void insert_at_tail(Node*& head, int value);
  void insert_at_location(Node*& head, int position, int value);

  //. -- DELETION --
  int delete_at_position(Node*& head, int position);

  //. -- SEARCHING --
  bool search_node(Node* head, int search_value);

  //. -- REVERSING --
  void reverse_dll(Node* head);
};

#endif
