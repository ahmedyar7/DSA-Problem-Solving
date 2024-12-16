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
  void delete_node(int data) { root = delete_node_recursive(root, data); }
  bool search(int data) { return search_node(root, data); }

  ~BinaryTree() { delete_tree(root); }

 private:
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

  TreeNode* delete_node_recursive(TreeNode* node, int value) {
    if (node == nullptr) return nullptr;

    if (value < node->data) {
      node->left = delete_node_recursive(node->left, value);
    } else if (value > node->data) {
      node->right = delete_node_recursive(node->right, value);
    } else {
      // Node found
      if (node->left == nullptr) {
        TreeNode* temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        TreeNode* temp = node->left;
        delete node;
        return temp;
      } else {
        // Node with two children: replace with inorder successor
        TreeNode* successor = find_min_node(node->right);
        node->data = successor->data;
        node->right = delete_node_recursive(node->right, successor->data);
      }
    }
    return node;
  }

  TreeNode* find_min_node(TreeNode* node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  bool search_node(TreeNode* node, int value) {
    if (node == nullptr) return false;
    if (node->data == value) return true;
    if (value < node->data) return search_node(node->left, value);
    return search_node(node->right, value);
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

  int get_min(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != nullptr) current = current->left;
    return current->data;
  }

  int get_height(TreeNode* node) {
    if (node == nullptr) return -1;
    int left = get_height(node->left);
    int right = get_height(node->right);
    return 1 + max(left, right);
  }
};

int main() {
  BinaryTree bt;
  bt.insert(50);
  bt.insert(30);
  bt.insert(70);
  bt.insert(20);
  bt.insert(40);
  bt.insert(60);
  bt.insert(80);

  cout << "Inorder traversal: ";
  bt.inorder();
  cout << endl;

  cout << "Searching for 40: " << (bt.search(40) ? "Found" : "Not Found")
       << endl;
  cout << "Deleting 40..." << endl;
  bt.delete_node(40);
  cout << "Inorder traversal after deletion: ";
  bt.inorder();
  cout << endl;

  return 0;
}
