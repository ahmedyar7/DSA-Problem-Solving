#include <iostream>
#include <queue>
using namespace std;

class Treenode {
 public:
  int data;
  Treenode* left;
  Treenode* right;

  Treenode(int data) {
    this->data = data;
    left = nullptr, right = nullptr;
  }
};

class BinaryTree {
 public:
  Treenode* root;
  BinaryTree() { root = nullptr; }

  void preorder() { preorder_traversal(root); }
  void inorder() { inorder_traversal(root); }
  void postorder() { postorder_traversal(root); }
  void levelorder() { levelorder_traversal(root); }

  void insert(int value) { root = insert_node(root, value); }

  void count() { cout << count_nodes(root); }
  void count_leafs() { cout << count_leaf(root); }
  void height() { cout << get_height(root); }
  void deg2() { cout << count_deg2(root); }
  void deg1() { cout << count_deg1(root); }
  bool isbalanced() { return balanced_tree(root); }

  Treenode* construct_tree(int preorder[], int inorder[], int& preorder_index,
                           int inorder_start, int inorder_end) {
    if (inorder_start > inorder_end) return nullptr;
    int rootvalue = preorder[preorder_index++];
    Treenode* rootnode = new Treenode(rootvalue);

    if (inorder_start == inorder_end) {
      return rootnode;
    }
    int rootindex = find_index(inorder, inorder_start, inorder_end, rootvalue);
    rootnode->left = construct_tree(preorder, inorder, preorder_index,
                                    inorder_start, rootindex - 1);
    rootnode->right = construct_tree(preorder, inorder, preorder_index,
                                     rootindex + 1, inorder_end);
  }

 private:
  Treenode* insert_node(Treenode* node, int value) {
    if (node == nullptr) return new Treenode(value);
    if (value > node->data) {
      node->right = insert_node(node->right, value);
    }
    if (value < node->data) {
      node->left = insert_node(node->left, value);
    }
    return node;
  }

  void preorder_traversal(Treenode* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
  }

  void inorder_traversal(Treenode* node) {
    if (node == nullptr) return;
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }

  void postorder_traversal(Treenode* node) {
    if (node == nullptr) return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout << node->data << " ";
  }

  void levelorder_traversal(Treenode* node) {
    if (node == nullptr) return;
    queue<Treenode*> q;
    q.push(node);

    while (!q.empty()) {
      Treenode* current = q.front();
      cout << current->data << " ";
      q.pop();

      if (current->left != nullptr) {
        q.push(current->left);
      }
      if (current->right != nullptr) {
        q.push(current->right);
      }
    }
  }

  int count_nodes(Treenode* node) {
    if (node == nullptr) return -1;
    int left = count_nodes(node->left);
    int right = count_nodes(node->right);
    return left + right + 1;
  }

  int get_height(Treenode* node) {
    if (node == nullptr) return 0;
    int left = get_height(node->left);
    int right = get_height(node->right);
    return max(left, right) + 1;
  }

  int count_leaf(Treenode* node) {
    if (node == nullptr) return 0;
    int left = count_leaf(node->left);
    int right = count_leaf(node->right);
    if (node->left == nullptr && node->right == nullptr)
      return left + right + 1;
    return left + right;
  }

  int count_deg2(Treenode* node) {
    if (node == nullptr) return 0;
    int left = count_deg2(node->left);
    int right = count_deg2(node->right);
    if (node->left != nullptr && node->right != nullptr)
      return left + right + 1;
    return left + right;
  }

  int count_deg1(Treenode* node) {
    if (node == nullptr) return 0;

    int left = count_deg1(node->left);
    int right = count_deg1(node->right);

    if ((node->left == nullptr && node->right != nullptr) ||
        (node->left != nullptr && node->right == nullptr)) {
      return left + right + 1;
    }
    return left + right;
  }

  int find_index(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end - 1; i++) {
      if (inorder[i] == value) return i;
    }
    return -1;
  }

  bool balanced_tree(Treenode* node) {
    if (node == nullptr) return false;
    bool left = balanced_tree(node->left);
    bool right = balanced_tree(node->right);

    bool difference =
        abs(get_height(node->left) - get_height(node->right) <= 1);
    if (left && right && difference)
      return true;
    else
      return false;
  }

  int diameter_of_tree(Treenode* node) {
    if (node == nullptr) return 0;
    int left_sub_tree = diameter_of_tree(node->left);
    int right_sub_tree = diameter_of_tree(node->right);
    int both_sub_tree = get_height(node->left) + get_height(node->right) + 1;

    int diameter = 0;
    diameter = max(left_sub_tree, max(right_sub_tree, both_sub_tree));
    return diameter;
  }

  bool isSameTree(Treenode* p, Treenode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;

    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    bool value = (p->data == q->data);

    if (left && right && value)
      return true;
    else {
      return false;
    }
  }
};