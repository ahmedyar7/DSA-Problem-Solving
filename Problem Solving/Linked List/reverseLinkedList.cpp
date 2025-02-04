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

  Node* reverseList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    Node* temp = head;
    Node* prev = nullptr;

    while (temp->next != nullptr) {
      Node* front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
    }
    return prev;
  }
};