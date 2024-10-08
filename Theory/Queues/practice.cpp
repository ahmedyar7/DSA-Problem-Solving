#include <iostream>
using namespace std;

class Node {
 private:
 public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

class CircularQueue {
 private:
 public:
  Node* front = nullptr;
  Node* rear = nullptr;
};