#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;

  Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
 public:
  Node* head;

  DoublyLinkedList() : head(nullptr) {}

  // Function to delete a node with a specific value
  void deleteNode(int value) {
    if (head == nullptr) {
      std::cout << "The list is empty." << std::endl;
      return;
    }

    Node* temp = head;

    // If the node to be deleted is the head node
    if (temp != nullptr && temp->data == value) {
      head = temp->next;  // Move the head to the next node
      if (head != nullptr) {
        head->prev =
            nullptr;  // If there's a next node, update its prev pointer
      }
      delete temp;
      std::cout << "Node with value " << value << " deleted." << std::endl;
      return;
    }

    // Traverse the list to find the node
    while (temp != nullptr && temp->data != value) {
      temp = temp->next;
    }

    // If the node was not found
    if (temp == nullptr) {
      std::cout << "Node with value " << value << " not found." << std::endl;
      return;
    }

    // If the node is found, update the pointers and delete the node
    if (temp->next != nullptr) {
      temp->next->prev = temp->prev;  // Update the next node's prev pointer
    }
    if (temp->prev != nullptr) {
      temp->prev->next = temp->next;  // Update the previous node's next pointer
    }

    delete temp;
    std::cout << "Node with value " << value << " deleted." << std::endl;
  }

  // Function to insert a node at the end (for testing purposes)
  void append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
      head = newNode;
      return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }

  // Function to display the list (for testing purposes)
  void display() {
    Node* temp = head;
    while (temp != nullptr) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }
};

int main() {
  DoublyLinkedList list;
  list.append(10);
  list.append(20);
  list.append(30);
  list.append(40);

  std::cout << "Original list: ";
  list.display();

  list.deleteNode(20);
  std::cout << "After deleting 20: ";
  list.display();

  list.deleteNode(10);
  std::cout << "After deleting 10: ";
  list.display();

  return 0;
}
