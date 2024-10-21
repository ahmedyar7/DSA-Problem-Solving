#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

int josophus(int n, int k) {
  Node* head = new Node(1);
  Node* prev = head;

  for (int i = 2; i <= n; i++) {
    Node* new_node = new Node(i);
    prev->next = new_node;
    prev = new_node;
  }
  prev->next = head;

  Node* current_node = head;
  Node* prev_node = prev;

  while (current_node->next != current_node) {
    for (int i = 1; i < k; i++) {
      prev_node = current_node;
      current_node = current_node->next;
    }

    cout << "Removing " << current_node->data << endl;
    Node* temp = current_node;
    prev_node->next = current_node->next;
    current_node = current_node->next;
    delete temp;
  }

  int result = current_node->data;
  delete current_node;
  return result;
}

int main() {
  int n, k;
  cout << "Enter the number of people: ";
  cin >> n;
  cout << "Enter the step count (k): ";
  cin >> k;

  int safePosition = josophus(n, k);
  cout << "The safe position is: " << safePosition << endl;

  return 0;
}
