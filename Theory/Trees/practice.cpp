#include <iostream>
using namespace std;

class TreeNode {
 private:
 public:
  const char* data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(const char* data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class BST {
 public:
  TreeNode* root;
  BST() { root = nullptr; }

  // Public Methods
  void insert(const char* data) { root = insert_node(root, data); }
  void inorder() { inorder_traversal(root); }

  ~BST() { delete_node(root); }

 private:
  int strcmp(const char* str1, const char* str2) {
    while (*str1 && *str2) {
      if (*str1 != *str2) {
        return *str1 - *str2;
      }
      ++str1;
      ++str2;
    }
    return *str1 - *str2;
  }

  TreeNode* insert_node(TreeNode* node, const char* value) {
    if (node == nullptr) return new TreeNode(value);
    if (strcmp(value, node->data) < 0) {
      node->left = insert_node(node->left, value);
    } else if (strcmp(value, node->data) > 0) {
      node->right = insert_node(node->right, value);
    }
    return node;
  }

  void inorder_traversal(TreeNode* node) {
    if (node == nullptr) return;
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }

  void delete_node(TreeNode* node) {
    if (node == nullptr) return;
    delete_node(node->left);
    delete_node(node->right);
    delete node;
  }
};

int main() {
  BST tree;  // Create an instance of BST

  // Array of strings to insert into the BST
  const char* strings[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
  int n = sizeof(strings) / sizeof(strings[0]);

  // Insert strings into the tree
  for (int i = 0; i < n; ++i) {
    tree.insert(strings[i]);
  }

  // Perform in-order traversal to display the strings in sorted order
  cout << "Strings in sorted order: ";
  tree.inorder();
  cout << endl;

  return 0;
}
