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

  int find_index(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
      if (inorder[i] == value) return i;
    }
    return -1;
  }
  int count_nodes(TreeNode* node) {
    if (node == nullptr) return 0;
    int left = count_nodes(node->left);
    int right = count_nodes(node->right);
    return left + right + 1;
  }

  int count_leafnodes(TreeNode* node) {
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 1;
    return count_leafnodes(node->left) + count_leafnodes(node->right);
  }

  int get_height(TreeNode* node) {
    if (node == nullptr) return -1;
    return max(get_height(node->left), get_height(node->left)) + 1;
  }

  int count_deg2(TreeNode* node) {
    if (node == nullptr) return 0;
    int left = count_deg2(node->left);
    int right = count_deg2(node->right);
    if (node->left != nullptr && node->right != nullptr)
      return left + right + 1;
    return left + right;
  }

  int count_deg1(TreeNode* node) {
    if (node == nullptr) return 0;
    int left = count_deg1(node->left);
    int right = count_deg1(node->right);
    if ((node->left != nullptr && node->right == nullptr) &&
        (node->left == nullptr && node->right != nullptr))
      return left + right + 1;
    return left + right;
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

  void count() { cout << count_nodes(root); }  // Counts the total nodes
  void count_leafs() { cout << count_leafnodes(root); }
  void height() { cout << get_height(root); }
  void deg2() { cout << count_deg2(root); }
  void deg1() { cout << count_deg1(root); }

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
  ~BinaryTree() { delete_tree(root); }  // Deletes Tres
};
