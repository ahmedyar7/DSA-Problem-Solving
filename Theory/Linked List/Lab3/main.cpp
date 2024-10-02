#include <iostream>
using namespace std;

class CircularDoublyLinkedList {
 public:
  int data;
  CircularDoublyLinkedList* next;
  CircularDoublyLinkedList* prev;

  CircularDoublyLinkedList(int value) {
    data = value;
    next = nullptr;
    prev = nullptr;
  }

  ~CircularDoublyLinkedList() {}

  // Insert Data at the beginning
  void insert_at_head(CircularDoublyLinkedList*& head, int value) {
    CircularDoublyLinkedList* new_node = new CircularDoublyLinkedList(value);

    if (head == nullptr) {
      head = new_node;
      new_node->next = new_node;
      new_node->prev = new_node;
      return;
    }

    CircularDoublyLinkedList* last = head->prev;

    new_node->next = head;
    new_node->prev = last;
    last->next = new_node;
    head->prev = new_node;
    head = new_node;
  }

  // Insert at the end of the list
  void insert_at_tail(CircularDoublyLinkedList*& head, int value) {
    CircularDoublyLinkedList* new_node = new CircularDoublyLinkedList(value);

    if (head == nullptr) {
      head = new_node;
      new_node->next = new_node;
      new_node->prev = new_node;
      return;
    }

    CircularDoublyLinkedList* last = head->prev;

    last->next = new_node;
    new_node->prev = last;
    new_node->next = head;
    head->prev = new_node;
  }

  // Insert at specific location
  void insert_at_location(CircularDoublyLinkedList*& head, int value,
                          int position) {
    if (position <= 0) {
      cout << "Invalid position\n";
      return;
    }

    if (position == 1) {
      insert_at_head(head, value);
      return;
    }

    CircularDoublyLinkedList* new_node = new CircularDoublyLinkedList(value);
    CircularDoublyLinkedList* temp = head;

    for (int i = 1; i < position - 1 && temp->next != head; i++) {
      temp = temp->next;
    }

    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
  }

  // Delete at a specific location
  void delete_at_location(CircularDoublyLinkedList*& head, int position) {
    if (head == nullptr || position <= 0) {
      cout << "Invalid position\n";
      return;
    }

    CircularDoublyLinkedList* temp = head;

    if (position == 1) {
      CircularDoublyLinkedList* last = head->prev;
      temp = head;
      last->next = head->next;
      head->next->prev = last;
      head = head->next;
      delete temp;
      return;
    }

    for (int i = 1; i < position && temp->next != head; i++) {
      temp = temp->next;
    }

    if (temp == head) {
      cout << "Position out of range\n";
      return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
  }

  void display(CircularDoublyLinkedList* head) {
    if (head == nullptr) {
      cout << "List is empty.\n";
      return;
    }

    CircularDoublyLinkedList* temp = head;
    do {
      cout << temp->data << " <-> ";
      temp = temp->next;
    } while (temp != head);

    cout << "HEAD\n";
  }
};

int main() {
  CircularDoublyLinkedList* head = nullptr;
  CircularDoublyLinkedList dll(0);
  int choice, value, position;

  while (true) {
    cout << "\nMenu:\n";
    cout << "1. Insert at Head\n";
    cout << "2. Insert at Tail\n";
    cout << "3. Insert at Specific Location\n";
    cout << "4. Delete at Specific Location\n";
    cout << "5. Display List\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:  // Insert at Head
        cout << "Enter value to insert at head: ";
        cin >> value;
        dll.insert_at_head(head, value);
        break;

      case 2:  // Insert at Tail
        cout << "Enter value to insert at tail: ";
        cin >> value;
        dll.insert_at_tail(head, value);
        break;

      case 3:  // Insert at Specific Location
        cout << "Enter value to insert: ";
        cin >> value;
        cout << "Enter position to insert at: ";
        cin >> position;
        dll.insert_at_location(head, value, position);
        break;

      case 4:  // Delete at Specific Location
        cout << "Enter position to delete: ";
        cin >> position;
        dll.delete_at_location(head, position);
        break;

      case 5:  // Display List
        dll.display(head);
        break;

      case 6:  // Exit
        cout << "Exiting...\n";
        return 0;

      default:
        cout << "Invalid choice. Please try again.\n";
        break;
    }
  }

  return 0;
}
