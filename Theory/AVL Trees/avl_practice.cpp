#include <iostream>
using namespace std;

class Treenode {
 private:
 public:
  int data;
  int height;
  Treenode* left;
  Treenode* right;

  Treenode(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
    height = 1;
  }
};

class AvlTree {
 private:
  void delete_tree(Treenode* node) {
    if (node == nullptr) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
  }

  int get_height(Treenode* node) {
    if (node == nullptr) return 0;
    return node->height;
  }

  int balance_factor(Treenode* node) {
    if (node == nullptr) return 0;
    return get_height(node->left) - get_height(node->right);
  }

  Treenode* rotate_left(Treenode* node) {
    Treenode* new_root = node->right;
    Treenode* subtree = new_root->left;

    new_root->left = node;
    node->right = subtree;

    node->height = 1 + max(get_height(node->left), get_height(node->right));
    new_root->height =
        1 + max(get_height(new_root->left), get_height(new_root->right));

    return new_root;
  }

  Treenode* rotate_right(Treenode* node) {
    Treenode* new_root = node->left;
    Treenode* subtree = new_root->right;

    new_root->right = node;
    node->left = subtree;

    node->height = 1 + max(get_height(node->left), get_height(node->right));
    new_root->height =
        1 + max(get_height(new_root->left), get_height(new_root->right));

    return new_root;
  }

  Treenode* find_min(Treenode* node) {
    if (node == nullptr) return nullptr;
    Treenode* current = node;
    while (current->left != nullptr) current = current->left;
    return current;
  }

  void inorder_traversal(Treenode* node) {
    if (node == nullptr) return;
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }

  Treenode* insert_node(Treenode* node, int value) {
    if (node == nullptr) return new Treenode(value);
    if (value > node->data)
      node->right = insert_node(node->right, value);
    else if (value < node->data)
      node->left = insert_node(node->left, value);
    else
      return node;

    int balance = balance_factor(node);
    node->height = 1 + max(get_height(node->left), get_height(node->right));

    // LL Case
    if (balance > 1 && value < node->left->data) {
      return rotate_right(node);
    }
    // RR Case
    if (balance < -1 && value > node->right->data) {
      return rotate_left(node);
    }
    // LR Case
    if (balance > 1 && value > node->left->data) {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }
    // RL Case
    if (balance < -1 && value < node->right->data) {
      node->right = rotate_right(node->right);
      return rotate_left(node);
    }
    return node;
  }

  Treenode* delete_node(Treenode* node, int data) {
    if (node == nullptr) return nullptr;
    if (data > node->data)
      node->right = delete_node(node->right, data);
    else if (data < node->data)
      node->left = delete_node(node->left, data);
    else {
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
      } else if (node->left == nullptr) {
        Treenode* temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        Treenode* temp = node->left;
        delete node;
        return temp;
      } else {
        Treenode* inorder_successor = find_min(node->right);
        node->data = inorder_successor->data;
        node->right = delete_node(node->right, inorder_successor->data);
      }
    }

    int balance = balance_factor(node);
    node->height = 1 + max(get_height(node->left), get_height(node->right));

    if (node == nullptr) return root;

    // LL Case
    if (balance > 1 && balance_factor(node->left) >= 0)
      return rotate_right(node);

    // RR Case
    if (balance < -1 && balance_factor(node->right) <= 0)
      return rotate_left(node);

    // LR Case
    if (balance > 1 && balance_factor(node->left) < 0) {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }

    // RL Case
    if (balance < -1 && balance_factor(node->right) > 0) {
      node->right = rotate_right(node->right);
      return rotate_left(node);
    }
    return node;
  }

 public:
  Treenode* root;
  AvlTree() { root = nullptr; }

  void inorder() { inorder_traversal(root); }
  void insert(int data) { root = insert_node(root, data); }
  Treenode* remove(int data) { return delete_node(root, data); }

  ~AvlTree() { delete_tree(root); }
};

int main() {
  AvlTree tree;

  // Insert nodes into AVL Tree
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(15);  // Causes rotation

  cout << "Inorder Traversal of AVL Tree: ";
  tree.inorder();  // Expected Output: 10 15 20 30
  cout << endl;

  tree.remove(20);  // Remove a node

  cout << "Inorder Traversal of AVL Tree after deletion: ";
  tree.inorder();  // Expected Output: 10 15 30
  cout << endl;

  return 0;
}