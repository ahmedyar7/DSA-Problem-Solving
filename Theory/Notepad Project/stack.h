#ifndef STACK_H
#define STACK_H

#include <stdexcept>

#include "node.h"

template <class T>
class stack {
 private:
  Node<T>* head;

 public:
  // Default Constructor
  stack() : head(nullptr) {}

  // Destructor for cleanup
  ~stack() {
    while (!empty()) {
      pop();
    }
  }

  // Push operation
  void push(T data) {
    Node<T>* new_node = new Node<T>(data);
    new_node->set_next(head);
    head = new_node;
  }

  // Pop operation
  void pop() {
    if (!empty()) {
      Node<T>* temp = head;
      head = head->get_next();
      delete temp;
    } else {
      throw std::runtime_error("Stack is empty. Cannot pop.");
    }
  }

  // Peek operation
  T top() const {
    if (!empty()) {
      return head->get_data();
    } else {
      throw std::runtime_error("Stack is empty. Cannot get top.");
    }
  }

  // Check if the stack is empty
  bool empty() const { return head == nullptr; }
};

#endif
