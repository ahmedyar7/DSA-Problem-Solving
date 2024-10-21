#include <iostream>
using namespace std;

// Node structure for the circular linked list
struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

// Function to solve the Josephus problem using a circular linked list
int josephus(int n, int k) {
  // Create the circular linked list with n nodes
  Node* head = new Node(1);
  Node* prev = head;
  for (int i = 2; i <= n; ++i) {
    Node* newNode = new Node(i);
    prev->next = newNode;
    prev = newNode;
  }
  prev->next = head;  // Make it circular

  Node* current = head;
  Node* prevNode = prev;

  // Continue until only one node is left
  while (current->next != current) {
    // Move k-1 steps ahead (since we eliminate every k-th node)
    for (int count = 1; count < k; ++count) {
      prevNode = current;
      current = current->next;
    }

    // Remove the k-th node
    cout << "Removing " << current->data << endl;
    prevNode->next = current->next;
    Node* temp = current;
    current = current->next;
    delete temp;
  }

  int result = current->data;
  delete current;
  return result;
}

int main() {
  int n, k;
  cout << "Enter the number of people: ";
  cin >> n;
  cout << "Enter the step count (k): ";
  cin >> k;

  int safePosition = josephus(n, k);
  cout << "The safe position is: " << safePosition << endl;

  return 0;
}
