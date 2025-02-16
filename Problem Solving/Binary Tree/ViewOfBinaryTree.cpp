#include <iostream>
#include <vector>
using namespace std;

class Treenode {
 private:
 public:
  int data;
  Treenode* left;
  Treenode* right;

  Treenode(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class BinaryTree {
 private:
 public:
  void leftViewHelper(Treenode* root, vector<int>& ans, int level) {
    if (root == nullptr) return;
    if (level == ans.size()) ans.push_back(root->data);
    leftViewHelper(root->left, ans, level + 1);
    leftViewHelper(root->right, ans, level + 1)
  }

  void rightViewHelper(Treenode* root, vector<int>& ans, int level) {
    if (root == nullptr) return;
    if (level == ans.size()) ans.push_back(root->data);
    rightViewHelper(root->left, ans, level + 1);
    rightViewHelper(root->right, ans, level + 1)
  }

  vector<int> leftView(Treenode* root) {
    vector<int> ans;
    leftViewHelper(root, ans, 0);
    return ans;
  }

  vector<int> rightView(Treenode* root) {
    vector<int> ans;
    rightViewHelper(root, ans, 0);
    return ans;
  }

  Treenode* root;

  BinaryTree() { root = nullptr; }
};