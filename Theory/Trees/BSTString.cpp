#include <iostream>
#include <string>
using namespace std;

// Define a Node structure
struct Node {
  string data;  // The string data
  Node* left;   // Pointer to the left child
  Node* right;  // Pointer to the right child

  // Constructor
  Node(string value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a string into the binary tree
Node* insert(Node* root, const string& value) {
  if (root == nullptr) {
    // Create a new node if the tree is empty or we reach a leaf
    return new Node(value);
  }

  // Lexicographical comparison to decide where to insert
  if (value < root->data) {
    root->left = insert(root->left, value);  // Insert into the left subtree
  } else if (value > root->data) {
    root->right = insert(root->right, value);  // Insert into the right subtree
  }
  // Duplicate values are ignored
  return root;
}

// Function for in-order traversal (to display strings in sorted order)
void inOrderTraversal(Node* root) {
  if (root == nullptr) return;

  inOrderTraversal(root->left);   // Visit left subtree
  cout << root->data << " ";      // Visit root
  inOrderTraversal(root->right);  // Visit right subtree
}

// Function to delete the tree and free memory
void deleteTree(Node* root) {
  if (root == nullptr) return;

  deleteTree(root->left);   // Delete left subtree
  deleteTree(root->right);  // Delete right subtree
  delete root;              // Delete current node
}

int main() {
  Node* root = nullptr;

  // Strings to insert into the binary tree
  string strings[] = {"apple", "banana", "cherry", "date", "fig", "grape"};

  // Build the tree
  for (const string& str : strings) {
    root = insert(root, str);
  }

  // Display strings in lexicographical order
  cout << "Strings in sorted order: ";
  inOrderTraversal(root);
  cout << endl;

  // Free allocated memory
  deleteTree(root);

  return 0;
}
