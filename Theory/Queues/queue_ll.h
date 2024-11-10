#ifndef QUEUE_LL_H
#define QUEUE_LL_H

#include <iostream>
using namespace std;

template <class T>
class Node {
 public:
  T data;
  Node* next;

  Node(T data) {
    this->data = data;
    next = nullptr;
  }
};

template <class T>
class queue {
 private:
  Node<T>* front;
  Node<T>* rear;

 public:
  queue() {
    front = nullptr;
    rear = nullptr;
  }

  bool empty() { return front == nullptr; }

  void enqueue(T value) {
    Node<T>* new_node = new Node<T>(value);
    if (empty()) {
      front = new_node;
      rear = new_node;
    } else {
      rear->next = new_node;
      rear = rear->next;
    }
    return;
  }

  T dequeue() {
    if (empty()) {
      return T();
    }
    Node<T>* temp = front;
    T value = front->data;
    front = front->next;
    delete temp;
    return value;
  }

  T get_front() { return front->data; }

  void display() {
    Node<T>* temp = front;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "end\n";
  }
};

#endif