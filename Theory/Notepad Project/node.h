#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
 private:
  T data;
  Node *next;  // Pointer to the next node

 public:
  Node(T data) {
    this->data = data;
    next = nullptr;
  }

  // Default constructor
  Node() { next = nullptr; }

  T get_data() { return data; }

  void set_data(T data) { this->data = data; }

  Node *get_next() { return next; }

  void set_next(Node *next) { this->next = next; }
};

#endif