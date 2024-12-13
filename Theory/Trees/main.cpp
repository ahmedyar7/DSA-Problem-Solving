#include <iostream>

#include "practice.cpp"
using namespace std;

int main() {
  BinaryTree tree;
  int choice, value;

  do {
    cout << "\nMenu:" << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. Find the height of the tree" << endl;
    cout << "3. Find the minimum value in the tree" << endl;
    cout << "4. Display Inorder Traversal" << endl;
    cout << "5. Display Preorder Traversal" << endl;
    cout << "6. Display Postorder Traversal" << endl;
    cout << "7. Display Level-order Traversal" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter value to insert: ";
        cin >> value;
        tree.insert(value);
        break;
      case 2:
        cout << "Height of the tree: " << tree.height() << endl;
        break;
      case 3:
        cout << "Minimum value in the tree: " << tree.find_min() << endl;
        break;
      case 4:
        cout << "Inorder Traversal: ";
        tree.inorder();
        cout << endl;
        break;
      case 5:
        cout << "Preorder Traversal: ";
        tree.preorder();
        cout << endl;
        break;
      case 6:
        cout << "Postorder Traversal: ";
        tree.postorder();
        cout << endl;
        break;
      case 7:
        cout << "Level-order Traversal: ";
        tree.levelorder();
        cout << endl;
        break;
      case 0:
        cout << "Exiting program." << endl;
        break;
      default:
        cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 0);

  return 0;
}
