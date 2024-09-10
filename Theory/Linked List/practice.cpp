#include <climits>
#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int value) {
    data = value;
    next = NULL;
  }
};

//. Inserting Element At Tail
void insert_at_tail(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == NULL) {
    head = new_node;
    return;
  }
  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
}

//. Display Linked List
void display(Node* head) {
  while (head->next != NULL) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

// . Insert at Head
void insert_at_head(Node*& head, int value) {
  Node* new_node = new Node(value);
  new_node->next = head;
  head = new_node;
}

// . Count Number of Nodes
int count_node(Node* head) {
  int count = 0;
  while (head->next != NULL) {
    count++;
    head = head->next;
  }
  cout << "Number of Nodes " << count << endl;
}

// . Maximum Element
void maximum_element(Node* head) {
  int max = INT_MIN;
  while (head->next != NULL) {
    if (head->data > max) {
      max = head->data;
    }
    head = head->next;
  }
  cout << "Maximum Element " << max << endl;
}

// . Minimum Element
void minimum_element(Node* head) {
  int min = INT_MAX;
  while (head->next != NULL) {
    if (head->data < min) {
      min = head->data;
    }
    head = head->next;
  }
  cout << "Minimum Element " << min << endl;
}

// . Searching in array
Node* search(Node* head, int key) {
  Node* p = head;
  Node* q = NULL;

  while (p != NULL) {
    if (p->data == key) {
      return p;
      q->next = p->next;
      p->next = head;
      head = p;
    }
    q = p;
    p = p->next;
  }
}

int main() {
  Node* node = NULL;
  int count = 1;

  insert_at_head(node, 250);
  for (int i = 0; i <= 10; i++) {
    insert_at_tail(node, count);
    count = count * 2;
  }
  display(node);
  count_node(node);
  maximum_element(node);
  minimum_element(node);
}