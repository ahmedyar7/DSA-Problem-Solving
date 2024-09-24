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

void insert_at_tail(Node*& head, int value) {
  Node* new_node = new Node(value);

  if (head == NULL) {
    head = new_node;
    return;
  }

  Node* current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

void display(Node* head) {
  if (head == NULL) return;

  while (head != NULL) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

void reverse_list(Node*& head) {
  Node* p = head;
  Node *q = NULL, *r = NULL;

  while (p != NULL) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  head = q;
}

Node* concatenate_LL(Node* list1, Node* list2) {
  Node *first = list1, *second = list2;
  while (first->next != NULL) {
    first = first->next;
  }
  first->next = second;
  second = NULL;
  return list1;
}

Node* merge_ll(Node*& node1, Node*& node2) {
  Node *first = node1, *second = node2;
  Node *last = NULL, *third = NULL;

  if (first == NULL) return second;
  if (second == NULL) return first;

  if (first->data < second->data) {
    third = last = first;
    first = first->next;
  } else {
    third = last = second;
    second = second->next;
  }

  while (first != NULL && second != NULL) {
    if (first->data < second->data) {
      last->next = first;
      last = first;
      first = first->next;
    } else {
      last->next = second;
      last = second;
      second = second->next;
    }
  }

  if (first != NULL)
    last->next = first;
  else
    last->next = second;

  return third;
}

void print_circular(Node* head) {
  if (head == nullptr) {
    cout << "The list is empty." << endl;
    return;
  }

  Node* temp = head;

  // Use a do-while loop to ensure we print the head node
  do {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != head);

  cout << endl;
}

int main() {
  Node* node1 = nullptr;
  Node* node2 = nullptr;

  insert_at_tail(node1, 2);
  insert_at_tail(node1, 4);
  insert_at_tail(node1, 6);
  insert_at_tail(node1, 8);
  print_circular(node1);

  // insert_at_tail(node2, 1);
  // insert_at_tail(node2, 3);
  // insert_at_tail(node2, 5);
  // insert_at_tail(node2, 7);

  //   Node* concate = concatenate_LL(node1, node2);
  //   display(concate);

  // Node* merged = merge_ll(node1, node2);
  display(node1);
}