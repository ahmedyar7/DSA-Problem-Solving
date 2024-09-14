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

bool check_sorted(Node* head) {
  int x = INT_MIN;
  while (head != NULL) {
    if (head->data < x) {
      return false;
    }
    x = head->data;
    head = head->next;
  }
  return true;
}

void remove_duplicates(Node* head) {
  if (head == NULL) return;

  Node* prev = head;
  Node* current = prev->next;

  while (current != NULL) {
    if (prev->data != current->data) {
      prev = current;
    } else {
      prev->next = current->next;
      delete current;
    }
    current = prev->next;
  }
}

Node* search_node(Node* head, int key) {
  Node* current = head;
  Node* prev = NULL;

  while (current != NULL) {
    if (current->data == key) {
      if (prev != NULL) {
        prev->next = current->next;
        current->next = head;
        head = current;
      }
      return current;
    }
    prev = current;
    current = current->next;
  }
  return NULL;
}

void insert_at_sorted(Node*& head, int value) {
  Node* current = head;
  Node* prev = NULL;
  Node* new_node = new Node(value);

  if (head == NULL || head->data > value) {
    head->next = new_node;
    head = new_node;
    return;
  }

  while (current != NULL && current->data < value) {
    prev = current;
    current = current->next;
  }
  prev->next = new_node;
  new_node->next = current;
}

// . Concatenate 2 Linked Lists
Node* concatenate_linked_list(Node*& head_1, Node*& head_2) {
  Node* current = head_1;
  while (current->next != NULL) current = current->next;
  current->next = head_2;
  head_2 = NULL;
  return head_1;
}

//. Merging two linked lists
Node* merge_nodes(Node*& list_1, Node*& list_2) {
  Node* first = list_1;
  Node* second = list_2;
  Node* third = NULL;
  Node* last = NULL;

  // Edge Case
  if (first == NULL) return second;
  if (second == NULL) return first;

  // Initial Condition
  if (first->data < first->data) {
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

  // If either of list finish first
  if (first != NULL) {
    last->next = first;
  } else {
    last->next = second;
  }

  return third;
}

// . Check for loops in Linked list
bool isLoop(Node* head) {
  Node* slow = head;
  Node* fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;        // move one step
    fast = fast->next->next;  // move 2 step
    if (slow == fast) return true;
  }
  return false;
}

void display(Node* head) {
  if (head == NULL) return;
  while (head != NULL) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

int main() {
  Node* node_1 = NULL;
  Node* node_2 = NULL;

  insert_at_tail(node_1, 1);
  insert_at_tail(node_1, 2);
  insert_at_tail(node_1, 4);

  insert_at_tail(node_2, 1);
  insert_at_tail(node_2, 3);
  insert_at_tail(node_2, 4);

  // Node* concat = concatenate_linked_list(node_1, node_2);
  // display(concat);
  Node* merged_linked_list = merge_nodes(node_1, node_2);
  display(merged_linked_list);
}