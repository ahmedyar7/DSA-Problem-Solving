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
 public:
  TreeNode* root;
  BinaryTree() { root = nullptr; }

  void insert(int data) { root = insert_node(root, data); }
  void inorder() { inorder_traversal(root); }
  void preorder() { preorder_traversal(root); }
  void postorder() { postorder_traversal(root); }
  void levelorder() { levelorder_traversal(root); }
  int height() { return get_height(root); }
  int find_min() { return get_min(root); }

  ~BinaryTree() { delete_tree(root); }

 private:
  TreeNode* insert_node(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);
    if (value > node->data) {
      insert_node(node->right, value);
    }
    if (value < node->data) {
      insert_node(node->left, value);
    }
    return node;
  }

  void delete_tree(TreeNode* node) {
    if (node == nullptr) {
      return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
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
    q.push(node);

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
    return count_nodes(node->left) + count_nodes(node->right);
  }

  int count_deg2(TreeNode* node) {
    if (node == nullptr) return 0;
    int left = count_deg2(node->left);
    int right = count_deg2(node->right);
    if (node->left != nullptr && node->right != nullptr) {
      return 1 + left + right;
    }
    return left + right;
  }

  int count_deg1(TreeNode* node) {
    if (node == nullptr) return 0;
    int left = count_deg1(node->left);
    int right = count_deg1(node->right);
    if ((node->left == nullptr && node->right != nullptr) ||
        (node->right == nullptr && node->left != nullptr)) {
      return 1 + left + right;
    }
    return left + right;
  }

  int get_min(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != nullptr) current = current->left;
    return current->data;
  }

  int count_leaf(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }
    int left = count_leaf(node->left);
    int right = count_leaf(node->right);
    if (node->left == nullptr && node->right == nullptr)
      return 1 + left + right;
    return left + right;
  }

  int get_height(TreeNode* node) {
    if (node == nullptr) return -1;
    int left = get_height(node->left);
    int right = get_height(node->right);
    return 1 + max(left, right);
  }

  bool same_tree(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr && t2 == nullptr) return true;
    if (t1 == nullptr || t2 == nullptr) return false;
    bool left = same_tree(t1->left, t2->left);
    bool right = same_tree(t1->right, t2->right);
    bool value = t1->data == t2->data;
    if (left && right && value) return true;
    return false;
  }
};