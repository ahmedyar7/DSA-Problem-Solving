#include <iostream>

#include "DoublyLinkedList.cpp"
#include "DoublyLinkedList.h"
#include "node.h"
using namespace std;

void menu();

int main() {
  DoublyLinkedList dll;
  Node* head = nullptr;
  int choice;
  int value;
  int position;

  while (true) {
    menu();
    cin >> choice;

    switch (choice) {
      case 1:  // Display List
        dll.display_H_T(head);
        break;

      case 2:  // Insert at Head
        cout << "Enter value to insert at head: ";
        cin >> value;
        dll.insert_at_head(head, value);
        break;

      case 3:  // Insert at Tail
        cout << "Enter value to insert at tail: ";
        cin >> value;
        dll.insert_at_tail(head, value);
        break;

      case 4:  // Insert at Position
        cout << "Enter position to insert at: ";
        cin >> position;
        cout << "Enter value to insert: ";
        cin >> value;
        dll.insert_at_location(head, position, value);
        break;

      case 5:  // Delete at Position
        cout << "Enter Valie to delete: ";
        cin >> position;
        value = dll.delete_value(head, value);
        if (value != -1)
          cout << "Deleted value: " << value << endl;
        else
          cout << "Invalid position!" << endl;
        break;

      case 6:  // Search for a Node
        cout << "Enter value to search: ";
        cin >> value;
        if (dll.search_node(head, value))
          cout << "Value " << value << " found in the list.\n";
        else
          cout << "Value " << value << " not found in the list.\n";
        break;

      case 7:  // Reverse the List
        head = dll.reverse_dll(head);
        cout << "List has been reversed.\n";
        break;

      case 8:  // Exit
        cout << "Exiting...\n";
        return 0;

      default:
        cout << "Invalid choice! Please try again.\n";
    }
  }

  return 0;
}

void menu() {
  cout << "\n--- Doubly Linked List Menu ---\n";
  cout << "1. Display List\n";
  cout << "2. Insert at Head\n";
  cout << "3. Insert at Tail\n";
  cout << "4. Insert at Position\n";
  cout << "5. Delete Value\n";
  cout << "6. Search for a Node\n";
  cout << "7. Reverse the List\n";
  cout << "8. Exit\n";
  cout << "Enter your choice: ";
}