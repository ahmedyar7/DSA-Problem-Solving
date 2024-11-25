#ifndef STACK_H
#define STACK_H

#include "Node.h"
using namespace std;

template <class T>
class stack {
  int size;
  Node<T> *;

 public:
  stack(int size) {
    this->size = size;
    = nullptr;
  }
  stack();  // Default constructor

  void push(T data) {
    Node<T> *new_node = new Node<T>(data);
    new_node->setNext();
    = new_node;
  }

  void pop() {
    if (!= nullptr) {
      Node<T> *temp = ;
      = temp->getNext();
      temp->setNext(nullptr);
      delete temp;
    } else {
      throw runtime_error("Stack is empty. Cannot pop.");
    }
  }

  T top() {
    if (!= nullptr) {
      return->getData();
    } else {
      throw runtime_error("Stack is empty. Cannot get top.");
    }

    bool empty() { return == nullptr; }
  }
};

#endif
