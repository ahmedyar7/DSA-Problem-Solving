#include <iostream>

#include "q.h"
using namespace std;

class Treenode {
 private:
 public:
  int data;
  Treenode* left;
  Treenode* right;

  Treenode(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class BinaryTree {
 public:
  Treenode* root;
  BinaryTree() { root = nullptr; }

  void insert(int data) { root = insert_node(root, data); }
  void preorder() { preorder_traversal(root); }
  void inorder() { inorder_traversal(root); }
  void postorder() { postorder_traversal(root); }
  void levelorder() { levelorder_traversal(root); }

  int count_nodes() { return count(root); }
  int deg0() { return count_deg0(root); }
  int deg1() { return count_deg1(root); }
  int deg2() { return count_deg2(root); }

  bool same(Treenode* root2) { return is_same(root, root2); }
  int height() { return get_height(root); }
  bool search(int target) { return find_node(root, target); }
  Treenode* remove(int target) { return delete_node(root, target); }

  ~BinaryTree() { delete_tree(root); }

 private:
  // Insertion
  Treenode* insert_node(Treenode* node, int data) {
    if (node == nullptr) {
      return new Treenode(data);
    }
    if (data > node->data) {
      node->right = insert_node(node->right, data);
    }
    if (data < node->data) {
      node->left = insert_node(node->left, data);
    }
    return node;
  }

  void delete_tree(Treenode* node) {
    if (node == nullptr) {
      return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
  }

  // Traversals
  void preorder_traversal(Treenode* node) {
    if (node == nullptr) {
      return;
    }
    cout << node->data << " ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
  }

  void inorder_traversal(Treenode* node) {
    if (node == nullptr) {
      return;
    }
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }

  void postorder_traversal(Treenode* node) {
    if (node == nullptr) {
      return;
    }
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout << node->data << " ";
  }

  void levelorder_traversal(Treenode* node) {
    if (node == nullptr) {
      return;
    }
    Queue<Treenode*> q;
    q.push(node);

    while (!q.empty()) {
      Treenode* current = q.peek();
      cout << current->data << " ";
      q.pop();

      if (current->left != nullptr) {
        q.push(current->left);
      }
      if (current->right != nullptr) {
        q.push(current->right);
      }
    }
    return;
  }

  int count(Treenode* node) {
    if (node == nullptr) {
      return 0;
    }
    int left = count(node->left);
    int right = count(node->right);
    return 1 + left + right;
  }

  int count_deg0(Treenode* node) {
    if (node == nullptr) return 0;

    int left = count_deg0(node->left);
    int right = count_deg0(node->right);

    if (node->left == nullptr && node->right == nullptr)
      return 1 + left + right;
    return left + right;
  }

  int count_deg1(Treenode* node) {
    if (node == nullptr) return 0;

    int left = count_deg1(node->left);
    int right = count_deg1(node->right);

    if ((node->left == nullptr && node->right != nullptr) ||
        (node->left != nullptr && node->right == nullptr))
      return 1 + left + right;
    return left + right;
  }

  int count_deg2(Treenode* node) {
    if (node == nullptr) return 0;

    int left = count_deg2(node->left);
    int right = count_deg2(node->right);

    if (node->left != nullptr && node->right != nullptr)
      return 1 + left + right;
    return left + right;
  }

  bool is_same(Treenode* node1, Treenode* node2) {
    if (node1 == nullptr && node2 == nullptr) return true;
    if (node1 == nullptr || node2 == nullptr) return false;

    bool left = is_same(node1->left, node2->left);
    bool right = is_same(node1->right, node2->right);
    bool value = node1->data == node2->data;

    if (left && right && value) return true;
    return false;
  }

  int get_height(Treenode* node) {
    if (node == nullptr) return 0;
    int left = get_height(node->left);
    int right = get_height(node->right);
    return 1 + max(left, right);
  }

  bool find_node(Treenode* node, int target) {
    if (node == nullptr) return false;
    if (node->data == target)
      return true;
    else if (target > node->data) {
      find_node(node->right, target);
    } else {
      find_node(node->left, target);
    }
    return false;
  }

  Treenode* find_min(Treenode* node) {
    if (node == nullptr) return nullptr;
    Treenode* current = node;
    while (current->left != nullptr) current = current->left;
    return current;
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
    return node;
  }
};
