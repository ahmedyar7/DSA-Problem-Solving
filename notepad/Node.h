#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
  T data;
  Node *next;  // Pointer to the next node

 public:
  Node(T data) : data(data), next(nullptr) {}

  // Default constructor
  Node() : next(nullptr) {}

  T getData() { return data; }

  void setData(T data) { this->data = data; }

  Node *getNext() { return next; }

  void setNext(Node *next) { this->next = next; }
};

#endif