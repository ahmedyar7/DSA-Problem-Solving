#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
 private:
  T data;
  Node* next;

 public:
  // Constructor
  Node(T data) : data(data), next(nullptr) {}

  // Default Constructor
  Node() : next(nullptr) {}

  T get_data() const { return data; }

  void set_data(T data) { this->data = data; }

  Node* get_next() const { return next; }

  void set_next(Node* next) { this->next = next; }
};

#endif
