#include <iostream>
using namespace std;

template <typename T>
class Node {
 private:
 public:
  T data;
  Node* next;

  Node(T data) {
    this->data = data;
    next = nullptr;
  }
};

template <typename T>
class LinkedList {
 private:
  Node<T>* head;

 public:
  LinkedList() { head = nullptr; }

  void insert_at_tail(T data) {
    Node<T>* new_node = new Node<T>(data);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    Node<T>* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = new_node;
    return;
  }

  void insert_at_head(T data) {
    Node<T>* new_node = new Node<T>(data);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    Node<T>* temp = head;
    new_node->next = temp;
    head = new_node;
    return;
  }

  void print() {
    if (head == nullptr) {
      cout << "Head is empty";
      return;
    }
    Node<T>* temp = head;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "end\n";
  }

  void insert_at_position(int position, int data) {
    if (position <= 0) {
      cout << "Please enter valid position\n";
    }
    Node<T>* new_node = new Node<T>(data);
    if (position == 1 || head == nullptr) {
      head = new_node;
      return;
    }
    Node<T>* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return;
  }

  void max_n_min() {
    int max = head->data;
    int min = head->data;
    Node<T>* temp = head;

    while (temp->next != nullptr) {
      if (temp->data > max) {
        max = temp->data;
      }
      if (temp->data <= min) {
        min = temp->data;
      }
      temp = temp->next;
    }

    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
  }

  void count_nodes() {
    int count = 0;
    Node<T>* temp = head;
    while (temp->next != nullptr) {
      count++;
      temp = temp->next;
    }
    cout << "Total Nodes: " << count << endl;
  }

  Node<T>* reverse_node() {
    if (head == nullptr) {
      cout << "List is empty\n";
      return nullptr;
    }
    Node<T>* p = head;
    Node<T>* q = nullptr;
    Node<T>* r = nullptr;
    while (p != nullptr) {
      r = q;
      q = p;
      p = p->next;
      q->next = r;
    }
    head = q;
    return q;
  }

  // Destructor
  ~LinkedList() {
    Node<T>* temp = head;
    while (temp != nullptr) {
      Node<T>* to_delete = temp;
      temp = temp->next;
      delete to_delete;
    }
  }
};