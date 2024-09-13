#include <iostream>
using namespace std;

// . Making the Node
class Node {
 public:
  int data;
  Node* next;
  Node(int value) {
    data = value;
    next = NULL;
  }
};

//. Inserting at tail
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

//. Total No.of Nodes
void count_nodes(Node* head) {
  int counter = 0;
  while (head != NULL) {
    counter++;
    head = head->next;
  }
  cout << "No. of Nodes: " << counter << endl;
}

//. Insert at head
void insert_at_head(Node*& head, int value) {
  Node* new_node = new Node(value);
  Node* p = head;
  new_node->next = p;
  head = new_node;
}

//. Maximum element In LL
void maximum_element(Node* head) {
  int max = -1000000;
  while (head != NULL) {
    if (head->data > max) {
      max = head->data;
    }
    head = head->next;
  }
  cout << "Maximum Element: " << max << endl;
}

void minimum_element(Node* head) {
  int min = 1000000;
  while (head != NULL) {
    if (head->data < min) {
      min = head->data;
    }
    head = head->next;
  }
  cout << "Minimum Element: " << min << endl;
}

Node* search(Node* head, int key) {
  Node* p = head;
  Node* q = NULL;
  while (head != NULL) {
    if (p->data == key) {
      if (q != NULL) {
        q->next = p->next;
        p->next = head;
        head = p;
      }
      return p;
    }
    return NULL;
  }
}

void insert_at_sorted(Node* head, int value) {
  Node* p = head;
  Node* q = NULL;
  Node* new_node = new Node(value);
  if (head == NULL || head->data >= value) {
    new_node->next = head;  // New node points to the current head
    head = new_node;        // Head now points to the new node
    return;
  }
  while (p != NULL && p->data < value) {
    q = p;
    p = p->next;
  }
  new_node->next = p;
  q->next = new_node;
}

void deallocate_memory(Node* head) {
  Node* current = head;
  Node* next_node;
  while (current != NULL) {
    next_node = current->next;
    delete current;
    current = next_node;
  }
  head = NULL;
}

void delete_node(Node*& head, int pos) {
  if (pos < 1 || head == NULL) return;

  Node* current = head;
  Node* previous = NULL;

  for (int i = 1; i < pos; i++) {
    if (current == NULL) return;
    previous = current;
    current = current->next;
  }

  if (previous == NULL) {
    head = current->next;
  }
  previous->next = current->next;
  delete previous;
}

void display(Node* head) {
  while (head != NULL) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

int main() {
  Node* node = NULL;

  for (int i = 0; i <= 10; i++) {
    insert_at_tail(node, i);
  }
  insert_at_sorted(node, 11);
  insert_at_head(node, 1010);
  insert_at_sorted(node, 10010);
  delete_node(node, 0);
  display(node);
  count_nodes(node);
  maximum_element(node);
  minimum_element(node);
  cout << "Element found: " << search(node, 10010) << endl;
  deallocate_memory(node);
}