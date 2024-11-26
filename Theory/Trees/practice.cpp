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

  // Helper for insertion
  TreeNode* insert_node(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);
    if (value > node->data) node->right = insert_node(node->right, value);
    if (value < node->data) node->left = insert_node(node->left, value);
    return node;
  }

  // Helper for delete
  TreeNode* delete_binary_tree(TreeNode* node) {
    if (node == nullptr) return nullptr;
    delete_binary_tree(node->left);
    delete_binary_tree(node->right);
    return node;
  }

  // Helper function for traversals

  void preorder_traversal(TreeNode* node) {  // Preorder Traversal
    if (node == nullptr) {
      return;
    }
    cout << node->data << " ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
  }

  void postorder_traversal(TreeNode* node) {  // Postorder Traversal
    if (node == nullptr) {
      return;
    }
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout << node->data << " ";
  }

  void inorder_traversal(TreeNode* node) {  // Inorder Traversal
    if (node == nullptr) {
      return;
    }
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }

  void levelorder_traversal(TreeNode* node) {  // Level order traversal
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

  int count_nodes(TreeNode* node) {  // Counts the the total nodes
    if (node == nullptr) return 0;
    int left = count_nodes(node->left);
    int right = count_nodes(node->right);
    return left + right + 1;
  }

  int get_height(TreeNode* node) {
    if (node == nullptr) return -1;  // Base case
    int left = get_height(node->left);
    int right = get_height(node->right);
    return max(left, right) + 1;
  }

  int count_nodes_with_deg2(TreeNode* node) {  // Nodes with degree = 2
    if (node == nullptr) return 0;
    int left = count_nodes_with_deg2(node->left);
    int right = count_nodes_with_deg2(node->right);
    if (node->left != nullptr && node->right != nullptr) {
      return left + right + 1;
    }
    return left + right;
  }

  int count_leaf_nodes(TreeNode* node) {  // Terminal nodes
    if (node == nullptr) return 0;        // Base case
    if (node->left == nullptr && node->right == nullptr) {
      return 1;  // Increment for leaf node
    }
    int left = count_leaf_nodes(node->left);
    int right = count_leaf_nodes(node->right);
    return left + right;  // Sum up leaf nodes from both subtrees
  }

  int find_index(int inorder_arr[], int inorder_start, int inorder_end,
                 int value) {  // Find Preorder value in inorder array
    // code
  }

 public:
  BinaryTree() { root = nullptr; }

  void insert(int value) { root = insert_node(root, value); }

  void display() {
    cout << "Preorder Display\n";
    preorder_traversal(root);
    cout << "\nInorder Traversal\n";
    inorder_traversal(root);
    cout << "\nPostorder Traversal\n";
    postorder_traversal(root);

    cout << "\nLevel order Traversal\n";
    levelorder_traversal(root);
  }

  int count() { return count_nodes(root); }
  int height() { return get_height(root); }
  int leaf_nodes() { return count_leaf_nodes(root); }
  int node_deg2() { return count_nodes_with_deg2(root); }

  ~BinaryTree() { delete_binary_tree(root); }
};