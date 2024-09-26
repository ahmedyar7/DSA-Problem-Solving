#include <iostream>
using namespace std;

class CircularLinkedList {
 public:
  int data;
  CircularLinkedList* next;

  CircularLinkedList(int value) {
    data = value;
    next = nullptr;
  }

  ~CircularLinkedList() {}

  //. Inserting at tail
  void insert_at_tail(CircularLinkedList*& head, int value) {
    CircularLinkedList* new_node = new CircularLinkedList(value);
    if (head == nullptr) {
      head = new_node;
      new_node->next = head;
      return;
    }
    CircularLinkedList* current = head;

    while (current->next != head) {
      current = current->next;
    }
    current->next = new_node;
    new_node->next = head;
  }

  //. Inserting at head
  void insert_at_head(CircularLinkedList*& head, int value) {
    CircularLinkedList* new_node = new CircularLinkedList(value);
    if (head == nullptr) {
      head = new_node;
      new_node->next = head;
      return;
    }
    CircularLinkedList* current = head;
    while (current->next != head) {
      current = current->next;
    }
    new_node->next = head;
    current->next = new_node;
    head = new_node;
  }

  //. Inserting at given position
  void insert_at_position(CircularLinkedList*& head, int value, int position) {
    CircularLinkedList* new_node = new CircularLinkedList(value);

    // Edge cases
    if (position < 1) {
      cout << "Invalid Position\n";
      delete new_node;  // Prevent memory leak
      return;
    }

    if (position == 1) {
      insert_at_head(head, value);
      return;
    }

    CircularLinkedList* current = head;
    for (int i = 1; i < position - 1 && current->next != head; i++) {
      current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
  }

  //. Display the Circular Linked List
  void display(CircularLinkedList* head) {
    if (head == nullptr) {
      cout << "Empty Linked List\n";
      return;
    }
    CircularLinkedList* current = head;
    do {
      cout << current->data << " -> ";
      current = current->next;
    } while (current != head);
    cout << "HEAD\n";
  }

  //. Deleting the head node
  void delete_head(CircularLinkedList*& head) {
    if (head == nullptr) {
      cout << "List is empty.\n";
      return;
    }

    if (head->next == head) {  // Only one node in the list
      delete head;
      head = nullptr;
      return;
    }

    CircularLinkedList* temp = head;
    CircularLinkedList* last = head;

    // Find the last node in the circular list
    while (last->next != head) {
      last = last->next;
    }

    // Point the last node to the second node
    last->next = head->next;
    head = head->next;

    delete temp;
  }

  //..  Deleting node at a given position
  void delete_at_position(CircularLinkedList*& head, int position) {
    if (head == nullptr || position < 1) {
      cout << "Invalid Position\n";
      return;
    }

    // Case when deleting the first node (position == 1)
    if (position == 1) {
      delete_head(head);
      return;
    }

    // Traverse to the node just before the position
    CircularLinkedList* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
      temp = temp->next;
    }

    // If temp->next is head, the position is out of range
    if (temp->next == head || temp->next == nullptr) {
      cout << "Position out of range\n";
      return;
    }

    // Delete the node at the desired position
    CircularLinkedList* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    delete node_to_delete;
  }
};

int main() {
  CircularLinkedList* head = nullptr;  // Create an empty circular linked list

  CircularLinkedList cll(0);

  // Insert at tail
  for (int i = 1; i <= 10; i++) {
    cll.insert_at_tail(head, i);
  }

  // Insert at a specific position
  cll.insert_at_position(head, 22, 2);

  // Display list
  cll.display(head);

  // Delete first node
  cll.delete_head(head);

  // Display list after deletion
  cll.display(head);

  return 0;
}
