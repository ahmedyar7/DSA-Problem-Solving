#include <iostream>
using namespace std;

class Node {
 public:
  string url;
  Node* next;
  Node* prev;

  Node(string url) {
    this->url = url;
    next = nullptr;
    prev = nullptr;
  }
};

class BrowserHistory {
 public:
  Node* current;

  BrowserHistory(string homepage) { current->url = homepage; }

  void visit(string url) {
    Node* new_node = new Node(url);
    current->next = nullptr;
    current->next = new_node;
    new_node->prev = new_node;
    current = new_node;
  }

  string forward(int steps) {
    if (steps > 0 && current->next != nullptr) {
      current = current->next;
    }
    return current->url;
  }

  string backward(int steps) {
    if (steps > 0 && current->prev != nullptr) {
      current = current->prev;
    }
    return current->url;
  }
};