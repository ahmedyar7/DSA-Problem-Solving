#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Treenode {
 public:
  T data;
  Treenode* left;
  Treenode* right;

  Treenode(T data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

template <typename T>
class BinaryTree {
 public:
  Treenode<T>* root;
  BinaryTree() { root = nullptr; }

  // Insert & Delete
  void insert(T data) { root = __insert_node(root, data); }
  Treenode<T>* remove(T data) { __remove_node(root, T); }

  // Traversal
  void inorder() { __inorder_traversal(root); }
  void preorder() { __preorder_traversal(root); }
  void postorder() { __postorder_traversal(root); }
  void levelorder() { __levelorder_traversal(root); }

  // Auxillary
  int height() { return __height(root); }
  bool is_balanced() { return __balance_factor(root); }
  bool same_tree() { return __same_tree(root, root) }

  // Destructor
  ~BinaryTree() { delete_tree(root); }

 private:
  // Insert Node
  Treenode<T>* __insert_node(Treenode<T>* node, T data) {
    if (node == nullptr) return new Treenode<T>(data);
    if (node->data < data) {
      node->left = __insert_node(node->left, T);
    } else if (node->data > data) {
      node->right = __insert_node(node->right, T);
    }
    return node;
  }

  // Delete Node
  Treenode<T>* delete_tree(Treenode<T>* node) {
    if (node == nullptr) return nullptr;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
  }

  // Traversals
  void __levelorder_traversal(Treenode<T>* node) {
    if (node == nullptr) return;
    queue<Treenode<T>*> q;
    q.push(node);
    while (!q.empty()) {
      Treenode<T>* current = q.front();
      cout << current->data << " ";
      q.pop();

      if (node->left != nullptr) {
        q.push(node->left);
      }
      if (node->right != nullptr) {
        q.push(node->right);
      }
    }
  }

  void __inorder_traversal(Treenode<T>* node) {
    if (node == nullptr) {
      return;
    }
    __inorder_traversal(node->left);
    cout << node->data << " ";
    __inorder_traversal(node->right);
  }

  void __preorder_traversal(Treenode<T>* node) {
    if (node == nullptr) {
      return;
    }
    __preorder_traversal(node->left);
    __preorder_traversal(node->right);
    cout << node->data << " ";
  }

  void __postorder_traversal(Treenode<T>* node) {
    if (node == nullptr) {
      return;
    }
    __postorder_traversal(node->left);
    __postorder_traversal(node->right);
    cout << node->data << " ";
  }

  // Helper function for deletion
  Treenode<T>* __find_min(Treenode<T>* node) {
    Treenode<T>* current = node;
    whlie(current->left != nullptr) current = current->left;
    return current;
  }

  Treenode<T>* __remove_node(Treenode<T>* node, T value) {
    if (node == nullptr) {
      return;
    }
    if (node->data < value) {
      node->left = __remove_node(node->left, value);
    } else if (node->data > value) {
      node->right = __remove_node(node->right, value);
    } else {
      // no child
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
      }
      // left child
      else if (node->left == nullptr) {
        Treenode<T>* temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        Treenode<T>* temp = node->left;
        delete node;
        return temp;
      } else {
        Treenode<T>* temp = __find_min(node->right);
        temp->data = node->data;
        node->data = __remove_node(node->right, temp->data);
      }
    }
    return node;
  }

  // Auxillary Function
  int __height(Treenode<T>* node) {
    if (node == nullptr) return 0;
    int left_subtree = __height(node->left);
    int right_subtree = __height(node->right);
    return 1 + max(left_subtree, right_subtree);
  }

  bool __balance_factor(Treenode<T>* node) {
    if (node == nullptr) false;
    bool left_subtree = __balance_factor(node->left);
    bool right_subtree = __balance_factor(node->right);
    bool diff = (abs(__height(node->left) - __height(node->right)) <= 1);
    if (left_subtree && right_subtree && diff) {
      return true;
    } else {
      return false;
    }
  }

  bool __same_tree(Treenode<T>* node1, Treenode<T>* node2) {
    if (node1 == nullptr && node2 == nullptr) return true;
    if (node1 == nullptr && node2 != nullptr) return false;

    bool left_tree = __same_tree(node1->left, node2->left);
    bool right_tree = __same_tree(node1->right, node2->right);
    bool value = (node1->data == node2->data);

    if (left_tree && right_tree && value) {
      return true;
    }
    return false;
  }
};