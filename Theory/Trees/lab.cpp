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
  int find_min() { return root ? find_min_node(root) : -1; }

  ~BinaryTree() { delete_tree(root); }

 private:
  TreeNode* insert_node(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);
    if (value < node->data) {
      node->left = insert_node(node->left, value);
    } else if (value > node->data) {
      node->right = insert_node(node->right, value);
    }
    return node;
  }

  void delete_tree(TreeNode* node) {
    if (node == nullptr) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
  }

  void inorder_traversal(TreeNode* node) {
    if (node == nullptr) return;
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }

  void preorder_traversal(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
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
      q.pop();
      cout << current->data << " ";
      if (current->left != nullptr) q.push(current->left);
      if (current->right != nullptr) q.push(current->right);
    }
  }

  int get_height(TreeNode* node) {
    if (node == nullptr) return -1;
    int left = get_height(node->left);
    int right = get_height(node->right);
    return 1 + max(left, right);
  }

  int find_min_node(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != nullptr) {
      current = current->left;
    }
    return current->data;
  }
};

int main() {
  BinaryTree tree;
  int choice, value;

  do {
    cout << "\nMenu:" << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. Find the height of the tree" << endl;
    cout << "3. Find the minimum value in the tree" << endl;
    cout << "4. Display Inorder Traversal" << endl;
    cout << "5. Display Preorder Traversal" << endl;
    cout << "6. Display Postorder Traversal" << endl;
    cout << "7. Display Level-order Traversal" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter value to insert: ";
        cin >> value;
        tree.insert(value);
        break;
      case 2:
        cout << "Height of the tree: " << tree.height() << endl;
        break;
      case 3:
        cout << "Minimum value in the tree: " << tree.find_min() << endl;
        break;
      case 4:
        cout << "Inorder Traversal: ";
        tree.inorder();
        cout << endl;
        break;
      case 5:
        cout << "Preorder Traversal: ";
        tree.preorder();
        cout << endl;
        break;
      case 6:
        cout << "Postorder Traversal: ";
        tree.postorder();
        cout << endl;
        break;
      case 7:
        cout << "Level-order Traversal: ";
        tree.levelorder();
        cout << endl;
        break;
      case 0:
        cout << "Exiting program." << endl;
        break;
      default:
        cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 0);

  return 0;
}
