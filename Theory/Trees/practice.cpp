#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class BinaryTree {
 private:
  Node* root;

  // Insertion Helper Function
  Node* insert_node(Node* node, int data) {
    if (node == nullptr) {
      return new Node(data);  // Creating initial node
    }
    // Smaller the root left  child
    if (data < node->data) {
      node->left = insert_node(node->left, data);
    }
    // larger the root right child
    if (data > node->data) {
      node->right = insert_node(node->right, data);
    }

    return node;  // Binary Tree
  }

  // Helper function for the inorder traversal
  void inorder_traversal(Node* node) {
    if (node == nullptr) {
      cout << "Node is null\n";
      return;
    }
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }

  // Delete Tree
  void delete_tree(Node* node) {
    if (node == nullptr) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
  }

 public:
  BinaryTree() { root = nullptr; }

  void insert(int data) {
    if (data <= 0) {
      return;
    }
    root = insert_node(root, data);
  }

  void display() {
    if (root == nullptr) {
      cout << "Root node is empty\n";
      return;
    }
    cout << "In-order Traversal\n";
    inorder_traversal(root);
    cout << endl;
  }

  // Destructor
  ~BinaryTree() { delete_tree(root); }
};
