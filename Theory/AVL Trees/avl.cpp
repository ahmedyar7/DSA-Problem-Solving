#include <iostream>
using namespace std;

// Define a node for the AVL tree
struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
  int height;

  TreeNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree class
class AVLTree {
 public:
  TreeNode* root;

  AVLTree() : root(nullptr) {}

  // Public insert function
  void insert(int key) { root = insertNode(root, key); }

  // Public delete function
  void remove(int key) { root = deleteNode(root, key); }

  // Display the tree (in-order traversal)
  void inOrderTraversal() {
    inOrder(root);
    cout << endl;
  }

 private:
  // Utility function to get the height of a node
  int height(TreeNode* node) { return node == nullptr ? 0 : node->height; }

  // Utility function to calculate the balance factor
  int getBalanceFactor(TreeNode* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
  }

  // Right rotation
  TreeNode* rotateRight(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
  }

  // Left rotation
  TreeNode* rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
  }

  // Insert a node
  TreeNode* insertNode(TreeNode* node, int key) {
    if (node == nullptr) return new TreeNode(key);

    if (key < node->data)
      node->left = insertNode(node->left, key);
    else if (key > node->data)
      node->right = insertNode(node->right, key);
    else
      return node;  // Duplicate keys are not allowed

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Balance the node
    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && key < node->left->data) return rotateRight(node);

    // Right Right Case
    if (balance < -1 && key > node->right->data) return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && key > node->left->data) {
      node->left = rotateLeft(node->left);
      return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data) {
      node->right = rotateRight(node->right);
      return rotateLeft(node);
    }

    return node;
  }

  // Find the node with the smallest value
  TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != nullptr) current = current->left;
    return current;
  }

  // Delete a node
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data)
      root->left = deleteNode(root->left, key);
    else if (key > root->data)
      root->right = deleteNode(root->right, key);
    else {
      // Node with only one child or no child
      if ((root->left == nullptr) || (root->right == nullptr)) {
        TreeNode* temp = root->left ? root->left : root->right;

        if (temp == nullptr) {  // No child case
          temp = root;
          root = nullptr;
        } else {  // One child case
          *root = *temp;
        }
        delete temp;
      } else {
        // Node with two children: Get the inorder successor
        TreeNode* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
      }
    }

    if (root == nullptr) return root;

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Balance the node
    int balance = getBalanceFactor(root);

    // Left Left Case
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
      return rotateRight(root);

    // Left Right Case
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
      root->left = rotateLeft(root->left);
      return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
      return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
      root->right = rotateRight(root->right);
      return rotateLeft(root);
    }

    return root;
  }

  // In-order traversal
  void inOrder(TreeNode* node) {
    if (node != nullptr) {
      inOrder(node->left);
      cout << node->data << " ";
      inOrder(node->right);
    }
  }
};
