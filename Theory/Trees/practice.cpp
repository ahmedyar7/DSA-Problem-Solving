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
  void preorder() { preorder_traversal(root); }
  void inorder() { inorder_traversal(root); }
  void postorder() { postorder_traversal(root); }
  void levelorder() { levelorder_traversal(root); }
  void count() { cout << number_of_nodes(root); }
  void count_leafs() { cout << count_leaf_nodes(root); }
  void height() { cout << get_height(root); }
  void deg1() { cout << tree_with_degree1(root); }
  void deg2() { cout << tree_with_degree2(root); }

  TreeNode* construct_tree(int preorder[], int inorder[], int& preorder_index,
                           int inorder_start, int inorder_end) {
    if (inorder_start > inorder_end) return nullptr;
    int rootvalue = preorder[preorder_index++];
    TreeNode* rootnode = new TreeNode(rootvalue);
    if (inorder_start == inorder_end) return rootnode;
    int rootindex = find_index(inorder, inorder_start, inorder_end, rootvalue);
    rootnode->left = construct_tree(preorder, inorder, preorder_index,
                                    inorder_start, rootindex - 1);
    rootnode->right = construct_tree(preorder, inorder, preorder_index,
                                     rootindex + 1, inorder_end);
  }

  ~BinaryTree() { delete_tree(root); }

 private:
  TreeNode* insert_node(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);
    if (value > node->data) node->right = insert_node(node->right, value);
    if (value < node->data) node->left = insert_node(node->left, value);
    return node;
  }

  TreeNode* delete_tree(TreeNode* node) {
    if (node == nullptr) return nullptr;
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

  int number_of_nodes(TreeNode* node) {
    if (node == nullptr) return 0;
    return number_of_nodes(node->left) + number_of_nodes(node->right);
  }

  int count_leaf_nodes(TreeNode* node) {
    if (node == nullptr) return 0;
    int left_subtree = count_leaf_nodes(node->left);
    int right_subtree = count_leaf_nodes(node->right);
    if (node->left == nullptr && node->right == nullptr) {
      return 1 + left_subtree + right_subtree;
    } else {
      left_subtree + right_subtree;
    }
  }

  int tree_with_degree1(TreeNode* node) {
    if (node == nullptr) return 0;
    int left_subtree = tree_with_degree1(node->left);
    int right_subtree = tree_with_degree1(node->right);
    if ((node->left != nullptr && node->right == nullptr) ||
        (node->left == nullptr && node->right != nullptr)) {
      return 1 + left_subtree + right_subtree;
    } else {
      return left_subtree + right_subtree;
    }
  }

  int tree_with_degree2(TreeNode* node) {
    if (node == nullptr) return 0;
    int left_subtree = tree_with_degree2(node->left);
    int right_subtree = tree_with_degree2(node->right);
    if (node->left != nullptr && node->right != nullptr) {
      return 1 + left_subtree + right_subtree;
    } else {
      left_subtree + right_subtree;
    }
  }

  int get_height(TreeNode* node) {
    if (node == nullptr) return -1;
    int left_subtree = get_height(node->left);
    int right_subtree = get_height(node->right);
    return 1 + max(left_subtree, right_subtree);
  }

  int find_index(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++)
      if (inorder[i] == value) return i;
    return -1;
  }

  bool balanced_tree(TreeNode* node) {
    if (node == nullptr) true;
    bool left_subtree = balanced_tree(node->left);
    bool right_subtree = balanced_tree(node->right);
    bool difference =
        abs(get_height(node->left) - get_height(node->right) <= 1);
    if (left_subtree && right_subtree && difference) return true;
    return false;
  }

  int diameter_of_tree(TreeNode* node) {
    if (node == nullptr) return 0;
    int left_subtree = diameter_of_tree(node->left);
    int right_subtree = diameter_of_tree(node->right);
    int both = 1 + get_height(node->left) + get_height(node->right);
    int diameter = 0;
    diameter = max(left_subtree, max(right_subtree, both));
    return diameter;
  }

  bool same_tree(TreeNode* node1, TreeNode* node2) {
    if (node1 == nullptr && node2 == nullptr) return true;
    if (node1 == nullptr || node2 == nullptr) return false;
    bool left_tree = same_tree(node1->left, node2->left);
    bool right_tree = same_tree(node1->right, node2->right);
    bool value = (node1->data == node2->data);
    if (left_tree && right_tree, value) return true;
    return false;
  }
};