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
      return;
    }
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }

  // Implementation of Pre-order Traversal
  void pre_order_traversal(Node* node) {
    if (node == nullptr) {
      return;
    }
    cout << node->data << " ";
    pre_order_traversal(node->left);
    pre_order_traversal(node->right);
  }

  // Implementation of Post-Order-Traversal
  void post_order_traversal(Node* node) {
    if (node == nullptr) return;
    post_order_traversal(node->left);
    post_order_traversal(node->right);
    cout << node->data << " ";
  }

  // Delete Tree
  void delete_tree(Node* node) {
    if (node == nullptr) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
  }

 public:
  bool empty() { return front == nullptr; }
};