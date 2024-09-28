#include <iostream>
using namespace std;

class CircularDoublyLinkedList {
 public:
  int data;
  CircularDoublyLinkedList* next;
  CircularDoublyLinkedList* previous;

  CircularDoublyLinkedList(int value) {
    data = value;
    next = nullptr;
    previous = nullptr;
  }

  ~CircularDoublyLinkedList() {}

  void insert_at_tail(CircularDoublyLinkedList*& head, int value) {
    CircularDoublyLinkedList* new_node = new CircularDoublyLinkedList(value);

    if (head == nullptr) {
      head = new_node;
      new_node->next = head;
      new_node->previous = head;
    }

    CircularDoublyLinkedList* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }

    temp->next = new_node;
    new_node->previous = temp;
    new_node->next = head;
    head->previous = new_node;
  }

  void display(CircularDoublyLinkedList* head) {
    if (head == nullptr) {
      cout << "List is empty\n";
      return;
    }

    CircularDoublyLinkedList* temp = head;
    do {
      cout << temp->data << " <-> ";
      temp = temp->next;
    } while (temp != head);
    cout << "HEAD\n";
  }

  void insert_at_head(CircularDoublyLinkedList*& head, int value) {
    CircularDoublyLinkedList* new_node = new CircularDoublyLinkedList(value);

    if (head == nullptr) {
      head = new_node;
      new_node->next = head;
      new_node->previous = head;
      return;
    }

    CircularDoublyLinkedList* last = head;
    while (last->next != head) {
      last = last->next;
    }
    last->next = new_node;
    new_node->next = head;
    head->previous = new_node;
    head = new_node;
  }

  void insert_at_position(CircularDoublyLinkedList*& head, int value,
                          int position) {
    CircularDoublyLinkedList* new_node = new CircularDoublyLinkedList(value);

    if (position < 0 || head == nullptr) {
      cout << "Invalid Position\n";
      return;
    }

    if (position == 1) {
      insert_at_head(head, value);
      return;
    }

    CircularDoublyLinkedList* temp = head;
    for (int i = 1; i < position - 1 && temp != head; i++) {
      temp = temp->next;
    }
    new_node->previous = temp;
    new_node->next = temp->next;
    temp->next = new_node;
    temp->next->previous = new_node;
  }

  void delete_head(CircularDoublyLinkedList*& head) {
    if (head == nullptr) {
      cout << "Empty List\n";
      return;
    }

    if (head->next == head) {
      delete head;
      head->next = nullptr;
      return;
    }

    CircularDoublyLinkedList* last = head;
    while (last->next != head) {
      last = last->next;
    }

    CircularDoublyLinkedList* temp = head;
    head = head->next;
    head->previous = last;
    last->next = head;
    delete temp;
  }

  void delete_at_position(CircularDoublyLinkedList*& head, int position) {
    if (position < 0 || head == nullptr) {
      cout << "Invalid Position\n";
      return;
    }
    if (position == 1) {
      delete_head(head);
      return;
    }
    CircularDoublyLinkedList* temp = head;
    for (int i = 1; i < position && temp->next != head; i++) {
      temp = temp->next;
    }
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    delete temp;
  }
};

int main() {
  CircularDoublyLinkedList* head = nullptr;
  CircularDoublyLinkedList cdll(0);

  for (int i = 0; i < 10; i++) {
    cdll.insert_at_tail(head, i);
  }

  cdll.insert_at_head(head, 200);
  cdll.insert_at_head(head, 2002);
  cdll.insert_at_position(head, 3333, 3);
  cdll.display(head);
  cdll.delete_head(head);
  cdll.delete_at_position(head, 5);
  cdll.display(head);
}