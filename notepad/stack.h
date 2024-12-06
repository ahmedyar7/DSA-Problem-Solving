#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <class T>
class stack {
  int size;
  Node<T> *Head;

 public:
  stack(int size);
  stack();  // Default constructor

  void push(T data);
  void pop();
  T top();
  bool empty();
};

#endif