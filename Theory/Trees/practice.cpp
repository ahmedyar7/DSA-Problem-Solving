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
  TreeNode* root;

  // Helper function for insertion
  TreeNode* insert_node(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);
    if (value > node->data) node->right = insert_node(node->right, value);
    if (value < node->data) node->left = insert_node(node->left, value);
    return node;
  }

  // Tree Travesal Functions
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

  void delete_tree(TreeNode* node) {
    if (node == nullptr) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
  }

  int count_nodes(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }

    int x = count_nodes(node->left);
    int y = count_nodes(node->right);

    return x + y + 1;
  }

 public:
  BinaryTree() { root = nullptr; }
  ~BinaryTree() { delete_tree(root); }

  void insert(int value) {
    if (value <= 0) return;
    root = insert_node(root, value);
  }

  void display() {
    cout << "Preorder Traversal\n";
    preorder_traversal(root);
    cout << endl << endl;

    cout << "Inorder Traversal\n";
    inorder_traversal(root);
    cout << endl << endl;

    cout << "Postorder Traversal\n";
    postorder_traversal(root);
    cout << endl << endl;

    cout << "Level Order Traversal\n";
    levelorder_traversal(root);
    cout << endl << endl;
  }

  int find_index(int inorder_arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++)
      if (inorder_arr[i] == value) return i;
    return -1;
  }

  TreeNode* construct_tree(int preorder_arr[], int inorder_arr[],
                           int& preorder_index, int inorder_start,
                           int inorder_end) {
    if (inorder_start > inorder_end) return nullptr;

    int rootvalue = preorder_arr[preorder_index++];
    TreeNode* rootnode = new TreeNode(rootvalue);

    if (inorder_start == inorder_end) return rootnode;

    int rootindex =
        find_index(inorder_arr, inorder_start, inorder_end, rootvalue);

    rootnode->left = construct_tree(preorder_arr, inorder_arr, preorder_index,
                                    inorder_start, rootindex - 1);
    rootnode->left = construct_tree(preorder_arr, inorder_arr, preorder_index,
                                    rootindex + 1, inorder_end);

    return rootnode;
  }

  int maxDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }

    int left_height = maxDepth(root->left);
    int right_height = maxDepth(root->right);

    return 1 + max(left_height, right_height);
  }

  int count() { return count_nodes(root); }
};