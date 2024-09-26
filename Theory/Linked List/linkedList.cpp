#include <climits>
#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

void insert_at_tail(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == nullptr) {
    head = new_node;
    return;
  }
  Node* temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = new_node;
  return;
}

void insert_at_head(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == nullptr) {
    head = new_node;
    return;
  }
  new_node->next = head;
  head = new_node;
}

void insert_at_location(Node*& head, int value, int position) {
  Node* new_node = new Node(value);
  if (position < 0) {
    cout << "Invalid Position\n";
    return;
  }
  if (position == 1) {
    insert_at_head(head, value);
  }
  Node* current = head;
  for (int i = 0; i < position - 1 && current != nullptr; i++) {
    current = current->next;
  }
  new_node->next = current->next;
  current->next = new_node;
}

int max_element(Node* head) {
  int max = INT_MIN;
  Node* temp = head;
  while (temp->next != nullptr) {
    if (temp->data > max) {
      max = temp->data;
    }
    temp = temp->next;
  }

  return max;
}

int min_element(Node* head) {
  int min = INT_MAX;
  while (head != nullptr) {
    if (head->data < min) {
      min = head->data;
    }
    head = head->next;
  }
  return min;
}

int count_nodes(Node* head) {
  int counter = 0;
  if (head == nullptr) {
    return counter;
  }

  while (head != nullptr) {
    counter++;
    head = head->next;
  }
  return counter;
}

void reversing_ll(Node*& head) {
  Node* p = head;
  Node* q = nullptr;
  Node* r = nullptr;

  while (p != nullptr) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  head = q;
}

bool search_node(Node* head, int search_value) {
  while (head != nullptr) {
    if (head->data == search_value) {
      return true;
    }
    head = head->next;
  }
  return false;
}

void display(Node* head) {
  if (head == nullptr) {
    cout << "Empty List\n";
    return;
  }
  while (head != nullptr) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

bool is_looped(Node* head) {
  Node* fast = head;
  Node* slow = head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return true;
    }
  }
  return false;
}

void insert_at_sorted(Node*& head, int value) {
  Node* new_node = new Node(value);

  if (head == nullptr || head->data > value) {
    head = new_node;
    return;
  }

  Node* current = head;
  while (current->next != nullptr && current->next->data < value) {
    current = current->next;
  }
  new_node->next = current->next;
  current->next = new_node;
  return;
}

Node* conatenate(Node*& node1, Node*& node2) {
  Node* first = node1;
  Node* second = node2;

  if (first == nullptr) return second;
  if (second == nullptr) return first;

  while (first->next != nullptr) {
    first = first->next;
  }
  first->next = second;
  return node1;
}

Node* merge_ll(Node*& node1, Node*& node2) {
  Node* first = node1;
  Node* second = node2;
  Node* last = nullptr;
  Node* third = nullptr;

  if (first == nullptr) return second;
  if (second == nullptr) return first;

  if (first->data < second->data) {
    third = last = first;
    first = first->next;
  } else {
    third = last = second;
    second = second->next;
  }

  while (first != nullptr && second != nullptr) {
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

  if (first == nullptr) last->next = second;
  if (second == nullptr) last->next = first;

  return third;
}

bool is_sorted(Node* head) {
  Node* current = head;
  Node* previous = nullptr;

  while (current->next != nullptr) {
    previous = current;
    if (previous->data < current->data) return true;
    current = current->next;
  }
  return false;
}

void remove_duplicate(Node*& head) {
  Node* previous = head;
  Node* current = previous->next;

  while (current != nullptr) {
    if (previous->data != current->data) {
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

int main() {
  Node* node1 = nullptr;
  Node* node2 = nullptr;

  for (int i = 0; i <= 10; i++) {
    if (i % 2 == 0) {
      insert_at_tail(node1, i * 2);
    }
  }
  display(node1);

  for (int i = 0; i <= 10; i++) {
    if (i % 2 != 0) {
      insert_at_tail(node2, i * 9);
      insert_at_tail(node2, i * 9);
    }
  }
  display(node2);

  Node* merged = merge_ll(node1, node2);
  display(merged);

  remove_duplicate(merged);
  display(merged);
}