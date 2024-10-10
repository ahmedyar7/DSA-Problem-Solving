#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node* prev;

  Node(int data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
  }
};

class Deque {
 private:
  Node* front;
  Node* rear;
  int size;

 public:
  Deque() {
    front = nullptr;
    rear = nullptr;
    size = 0;
  }

  bool empty() { return size == 0; }

  void insert_front(int value) {
    Node* new_node = new Node(value);
    if (empty()) {
      front = rear = new_node;
    } else {
      new_node->next = front;
      front->prev = new_node;
      front = new_node;
    }
    size++;
  }

  void insert_rear(int value) {
    Node* new_node = new Node(value);
    if (empty()) {
      front = rear = new_node;
    } else {
      rear->next = new_node;
      new_node->prev = rear;
      rear = new_node;
    }
    size++;
  }

  int delete_front() {
    if (empty()) {
      front = rear = nullptr;
    }
    Node* temp = front;
    front = front->next;
    int value = temp->data;
    delete temp;
    size--;

    return value;
  }

  int delete_rear() {
    if (empty()) {
      front = rear = nullptr;
    }
    Node* temp = rear;
    rear = rear->prev;
    int value = rear->data;
    delete temp;
    size--;

    return value;
  }

  int get_first() { return front->data; }
  int get_rear() { return rear->data; }

  void display() {
    Node* temp = front;
    while (temp != nullptr) {
      cout << "[" << temp->data << "] -> ";
      temp = temp->next;
    }
    cout << "null\n";
  }

  ~Deque() {
    while (!empty()) {
      delete_front();
    }
  }
};

int main() {
  Deque qe;

  qe.insert_front(5);
  qe.insert_front(15);
  qe.insert_front(25);
  qe.insert_front(35);

  qe.display();

  qe.delete_front();
  qe.display();

  qe.insert_rear(32);
  qe.insert_rear(3232);
  qe.insert_rear(322);

  qe.display();
}