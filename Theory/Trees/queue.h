#include <iostream>
using namespace std;

template <class T>
class Node {
 public:
  T data;
  Node* next;
};

template <class T>
class Queue {
 private:
  Node* front = nullptr;
  Node* rear = nullptr;

 public:
  bool empty() { return front == nullptr; }
};