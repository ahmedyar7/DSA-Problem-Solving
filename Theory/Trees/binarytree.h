#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int data) {
    this->data = data;
    left = nullptr, right = nullptr;
  }
};

class BinaryTree {
 private:
  Node* root;

  Node* insert_node(Node* node, int value) {
    if (node == nullptr) {
      return new Node(value);
    }
    if (node->data > value) {
      node->left = insert_node(node->left, value);
    } else if (node->data < value) {
      node->right = insert_node(node->right, value);
    }
    return node;
  }

  void inorder_traversal(Node* node) {
    if (node == nullptr) {
      return;
    }
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }

 public:
  BinaryTree() { root = nullptr; }

  void insert(int value) { root = insert_node(root, value); }
  void display_inorder_traversal() {
    inorder_traversal(root);
    cout << " \n";
  }

  void delete_tree(Node* node) {
    if (node == nullptr) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
  }

  ~BinaryTree() { delete_tree(root); }
};