#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;  // Self Referencing Data Structures

  // Constructor
  Node(int val) {
    data = val;
    next = NULL;
  }
};

void insert_at_tail(Node*& head, int value) {
  Node* n = new Node(value);  // This will allocates memory in the heap

  if (head == NULL) {
    head = n;  // if node is null then added the current node
    return;
  }

  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = n;
}

void display(Node* head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

int main() {
  Node* head = NULL;
  insert_at_tail(head, 1);
  insert_at_tail(head, 2);
  insert_at_tail(head, 3);

  display(head);
}