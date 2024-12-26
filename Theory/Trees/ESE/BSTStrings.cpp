#include <iostream>
using namespace std;

class Treenode {
 private:
 public:
  const char* data;
  Treenode* left;
  Treenode* right;

  Treenode(const char* data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class BSTStrings {
 private:
  int strcmp(const char* str1, const char* str2) {
    while (*str1 && *str2) {
      if (*str1 != *str2) return *str1 - *str2;
      str1++;
      str2++;
    }
    return *str1 - *str2;
  }

  Treenode* insert_node(Treenode* node, const char* data) {
    if (node == nullptr) {
      return new Treenode(data);
    }
    if (strcmp(data, node->data) < 0) {
      node->left = insert_node(node->left, data);
    } else if (strcmp(data, node->data) > 0) {
      node->right = insert_node(node->right, data);
    }
    return node;
  }

  void inorder_traversal(Treenode* node) {
    if (node == nullptr) {
      return;
    }
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }

 public:
  Treenode* root;

  BSTStrings() { root = nullptr; }
  void insert(const char* data) { root = insert_node(root, data); }
  void inorder() { inorder_traversal(root); }
};

int main() {
  BSTStrings tree;

  // Insert strings into the BST
  tree.insert("A");
  tree.insert("B");
  tree.insert("C");
  tree.insert("F");  // Duplicate, will not be inserted

  cout << "Inorder Traversal of BST: ";
  tree.inorder();
  cout << endl;

  return 0;
}