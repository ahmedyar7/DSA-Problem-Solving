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

// Concatenation
Node* concate(Node* node1, Node* node2) {
  Node *first = node1, *second = node2;
  while (first->next != NULL) {
    first = first->next;
  }
  first->next = second;
  second = NULL;
  return node1;
}

// Merging
Node* merge_ll(Node*& node1, Node*& node2) {
  Node* first = node1;
  Node* second = node2;
  Node* third = NULL;
  Node* last = NULL;

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

  if (first != NULL) {
    last->next = first;
  } else {
    last->next = second;
  }

  return third;
}

bool is_looped(Node* head) {
  Node* fast = head;
  Node* slow = NULL;

  while (head != NULL) {
    slow = slow->next;        // 1 nodes
    fast = fast->next->next;  // 2 nodes

    if (fast == slow) {
      return true;
    }
  }
  return false;
}

void insert_at_sorted(Node*& head, int value) {
  Node* current = head;
  Node* previous = NULL;
  Node* new_node = new Node(value);
  if (head == NULL) return;

  while (current != NULL && current->data >= value) {
    new_node->next = head;
    head = new_node;
  }

  while (current != NULL && current->data < value) {
    previous = current;
    current = current->next;
  }
  new_node->next = current;
  previous->next = new_node;
}

void delete_duplicates(Node*& head) {
  Node* previous = head;
  Node* current = previous->next;

  while (current != NULL) {
    if (current->data != previous->data) {
      previous = current;
      current = current->next;
    } else {
      previous->next = current->next;
      delete current;
      current = previous->next;
    }
  }
  return;
}

void reversing_nodes(Node*& head) {
  Node* p = head;
  Node* q = NULL;
  Node* r = NULL;

  while (head->next != NULL) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  return;
}

int main() {
  Node* node1 = NULL;
  Node* node2 = NULL;

  insert_at_tail(node1, 2);
  insert_at_tail(node1, 4);
  insert_at_tail(node1, 6);
  insert_at_tail(node1, 8);
  insert_at_tail(node1, 10);
  //   insert_at_tail(node1, 10);

  insert_at_tail(node2, 1);
  insert_at_tail(node2, 3);
  insert_at_tail(node2, 5);
  insert_at_tail(node2, 7);
  insert_at_tail(node2, 9);

  delete_duplicates(node1);

  //   Node* concatenation = concate(node1, node2);
  Node* merged_linked_list = merge_ll(node1, node2);
  reversing_nodes(merged_linked_list);
  //   insert_at_sorted(node1, 79);

  display(node1);
}