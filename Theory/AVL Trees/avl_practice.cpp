#include <iostream>
using namespace std;

template <typename T>
class Treenode {
 public:
  T data;
  Treenode* left;
  Treenode* right;
  int height;

  Treenode(T data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
    height = 1;
  }
};

// NOTE: Private member functions are marked with single underscore

template <typename T>
class AvlTree {
 public:
  Treenode<T>* root;
  AvlTree() { root = nullptr; }

  void insert(T data) { root = insert_node(root, data); }
  void inorder() { inorder_traverse(root); }

  ~AvlTree() { delete_tree(root); }

 private:
  // Rotate left
  Treenode<T>* rotate_left(Treenode<T>* node) {
    Treenode<T>* new_root = node->right;
    Treenode<T>* subtree = new_root->left;

    new_root->left = node;
    node->right = subtree;

    node->height = 1 + max(get_height(node->left), get_height(node->right));
    new_root->height =
        1 + max(get_height(new_root->left), get_height(new_root->right));

    return new_root;
  }

  // Rotate right
  Treenode<T>* rotate_right(Treenode<T>* node) {
    Treenode<T>* new_root = node->left;
    Treenode<T>* subtree = new_root->right;

    new_root->right = node;
    node->left = subtree;

    node->height = 1 + max(get_height(node->left), get_height(node->right));
    new_root->height =
        1 + max(get_height(new_root->left), get_height(new_root->right));

    return new_root;
  }

  // Delete tree and free memory
  void delete_tree(Treenode<T>* node) {
    if (node == nullptr) {
      return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
  }

  // Get height of node
  int get_height(Treenode<T>* node) {
    if (node == nullptr) return 0;
    return node->height;
  }

  // Calculate balance factor of node
  int balance_factor(Treenode<T>* node) {
    if (node == nullptr) return 0;
    return get_height(node->left) - get_height(node->right);
  }

  // Inorder traversal
  void inorder_traverse(Treenode<T>* node) {
    if (node == nullptr) return;
    inorder_traverse(node->left);
    cout << node->data << " ";
    inorder_traverse(node->right);
  }

  // Insert node in the AVL tree
  Treenode<T>* insert_node(Treenode<T>* node, T data) {
    if (node == nullptr) {
      return new Treenode<T>(data);
    }

    // Perform standard BST insert
    if (data < node->data) {
      node->left = insert_node(node->left, data);
    } else if (data > node->data) {
      node->right = insert_node(node->right, data);
    } else {
      return node;  // No duplicates allowed
    }

    // Update height of current node
    node->height = 1 + max(get_height(node->left), get_height(node->right));

    // Check balance factor and perform rotations if necessary
    int balance = balance_factor(node);

    // LL Case
    if (balance > 1 && data < node->left->data) {
      return rotate_right(node);
    }

    // RR Case
    if (balance < -1 && data > node->right->data) {
      return rotate_left(node);
    }

    // LR Case
    if (balance > 1 && data > node->left->data) {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }

    // RL Case
    if (balance < -1 && data < node->right->data) {
      node->right = rotate_right(node->right);
      return rotate_left(node);
    }

    return node;  // No rotation needed
  }
};

int main() {
  AvlTree<int> tree;
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(15);
  tree.insert(25);

  tree.inorder();  // Should print the sorted tree
}
