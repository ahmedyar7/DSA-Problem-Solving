#include <iostream>
using namespace std;

// . Creating Linked List

class Node {
 public:
  int data;
  Node* next;

  Node(int value) {
    data = value;
    next = NULL;
  }
};

Node* first = NULL;

// . Insert at tail
void insert_at_tail(Node*& head, int value) {
  Node* n = new Node(value);
  if (head == NULL) {
    head = n;
    return;
  }
  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = n;
}

//. Display Function
void display(Node* head) {
  int count = 0;
  int sum = 0;
  while (head->next != NULL) {
    cout << head->data << " -> ";
    sum = sum + head->data;
    head = head->next;
    count++;
  }
  cout << "NULL" << endl;
  cout << "COUNT: " << count << endl;
  cout << "SUM: " << sum << endl;
}

// . Maximum Element
void maximum_element(Node* head) {
  int max = -2147483647;
  while (head->next != NULL) {
    if (head->data > max) {
      max = head->data;
    }
    head = head->next;
  }
  cout << "Maximum Element " << max << endl;
}

//. Minimum Element
void minimum_element(Node* head) {
  int min = 2147483647;
  while (head->next != NULL) {
    if (head->data < min) min = head->data;
    head = head->next;
  }
  cout << "Minimum Element " << min << endl;
}

//. Searching Element
Node* search(Node*& first, int key) {
  Node* p = first;
  Node* q = NULL;
  while (p != NULL) {
    if (p->data == key) {
      if (q != NULL) {
        q->next = p->next;
        p->next = first;
        first = p;
      }
      return p;
    }
    q = p;
    p = p->next;
  }
  return NULL;
}

// . Inserting at Head
void before_first_node(Node*& head, int value) {
  Node* new_node = new Node(value);
  new_node->next = head;
  head = new_node;
}

int main() {
  Node* node = NULL;
  int count = 1;
  for (int i = 0; i <= 10; i++) {
    insert_at_tail(node, count);
    count = count * 2;
  }
  display(node);
  before_first_node(node, 900);
  display(node);
  maximum_element(node);
  minimum_element(node);
  cout << "Searching An Element " << search(node, 10) << endl;
}
