#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
 public:
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class BinaryTree {
 private:
  // Helper Function for insertion
  TreeNode* insert_node(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);
    if (value > node->data) {
      node->right = insert_node(node->right, value);
    }
    if (value < node->data) {
      node->left = insert_node(node->left, value);
    }
    return node;
  }

  void preorder_traversal(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
  }

  void inorder_traversal(TreeNode* node) {
    if (node == nullptr) return;
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }

  void postorder_traversal(TreeNode* node) {
    if (node == nullptr) return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout << node->data << " ";
  }

  void levelorder_traversal(TreeNode* node) {
    if (node == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* current = q.front();
      cout << current->data << " ";
      q.pop();
      if (current->left != nullptr) q.push(current->left);
      if (current->right != nullptr) q.push(current->right);
    }
  }

  int count_nodes(TreeNode* node) {
    if (node == nullptr) return 0;
  }

  // Helper Function for Deletion
  void delete_tree(TreeNode* node) {
    if (node == nullptr) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
  }

 public:
  TreeNode* root;
  BinaryTree() { root = nullptr; }  // Initialize rootnode == null

  // Insertion in Binary Tree
  void insert(int value) { root = insert_node(root, value); }

  // Traversal In Binary Tree
  void preorder() { preorder_traversal(root); }      // preorder
  void postorder() { postorder_traversal(root); }    // postorder
  void inorder() { inorder_traversal(root); }        // inorder
  void levelorder() { levelorder_traversal(root); }  // levelorder

  ~BinaryTree() { delete_tree(root); }
};