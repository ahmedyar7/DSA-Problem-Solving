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
  void solve(Treenode* root, vector<int>& ans, int level) {
    if (root == nullptr) return;
    if (level == ans.size()) ans.push_back(root->data);
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1)
  }

  vector<int> leftView(Treenode* root) {
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
  }

  Treenode* root;

  BinaryTree() { root = nullptr; }
};