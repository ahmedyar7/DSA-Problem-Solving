#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

#include "Node.h"
using namespace std;

class Queue {
 private:
 public:
  Node* front;
  Node* rear;

  Queue() {
    front = nullptr;
    rear = nullptr;
  }

  bool empty();
  int peek();
  void enqueue(int value);
  int dequeue();
  void display();

  ~Queue() { delete front, rear; }
};

#endif