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

  Treenode<T>* construct_tree(int inorder[], int preorder[],
                              int& preorder_index, int inorder_start,
                              int inorder_end) {
    if (inorder_start > inorder_end) {
      return nullptr;
    }

    int rootvalue = preorder[preorder_index];
    Treenode<T>* rootnode = new Treenode<T>(rootvalue);

    if (inorder_start == inorder_end) {
      return rootnode;
    }

    int rootindex = find_index(inorder, inorder_start, inorder_end, rootvalue);

    rootnode->left = construct_tree(inorder, preorder, preorder_index,
                                    inorder_start, rootindex - 1);
    rootnode->right = construct_tree(inorder, preorder, preorder_index,
                                     rootindex + 1, inorder_end);

    return rootnode;
  }

  // Insert & Delete
  void insert(T data) { root = __insert_node(root, data); }
  Treenode<T>* remove(T data) { return __remove_node(root, data); }

  // Traversal
  void inorder() { __inorder_traversal(root); }
  void preorder() { __preorder_traversal(root); }
  void postorder() { __postorder_traversal(root); }
  void levelorder() { __levelorder_traversal(root); }

  // Auxillary
  int height() { return __height(root); }
  bool is_balanced() { return __balance_factor(root); }
  bool same_tree() { return __same_tree(root, root); }
  int diameter() { return __diameter(root); }

  // Counting Function
  int count() { return __count(root); }
  int deg1() { return __deg1(root); }
  int deg2() { return __deg2(root); }
  int deg0() { return __deg0(root); }

  // Destructor
  ~BinaryTree() { delete_tree(root); }

 private:
  // Insert Node
  Treenode<T>* __insert_node(Treenode<T>* node, T data) {
    if (node == nullptr) return new Treenode<T>(data);
    if (node->data < data) {
      node->left = __insert_node(node->left, data);
    } else if (node->data > data) {
      node->right = __insert_node(node->right, data);
    }
    return node;
  }

  // Delete Node
  void delete_tree(Treenode<T>* node) {
    if (node == nullptr) return;
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

      if (current->left != nullptr) {
        q.push(current->left);
      }
      if (current->right != nullptr) {
        q.push(current->right);
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
    cout << node->data << " ";
    __preorder_traversal(node->left);
    __preorder_traversal(node->right);
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
    while (current->left != nullptr) current = current->left;
    return current;
  }

  Treenode<T>* __remove_node(Treenode<T>* node, T value) {
    if (node == nullptr) {
      return nullptr;  // Corrected to return nullptr
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
        node->data = temp->data;  // Using temp->data for assignment
        node->right = __remove_node(node->right, temp->data);
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
    if (node == nullptr) return false;
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

  int __diameter(Treenode<T>* node) {
    if (node == nullptr) return 0;

    int left = __diameter(node->left);
    int right = __diameter(node->right);
    int both = 1 + max(__height(node->left), __height(node->right));
    int diameter = 0;

    diameter = max(left, max(right, both));
    return diameter;
  }

  int __count(Treenode<T>* node) {
    if (node == nullptr) {
      return 0;
    }
    return 1 + __count(node->left) + __count(node->right);
  }

  // Count Nodes
  int __deg0(Treenode<T>* node) {
    if (node == nullptr) {
      return 0;
    }
    int left = __deg0(node->left);
    int right = __deg0(node->right);
    if (node->left == nullptr && node->right == nullptr) {
      return 1 + left + right;
    } else
      return left + right;
  }

  int __deg2(Treenode<T>* node) {
    if (node == nullptr) {
      return 0;
    }
    int left = __deg2(node->left);
    int right = __deg2(node->right);
    if (node->left != nullptr && node->right != nullptr) {
      return 1 + left + right;
    } else
      return left + right;
  }

  int __deg1(Treenode<T>* node) {
    if (node == nullptr) {
      return 0;
    }
    int left = __deg1(node->left);
    int right = __deg1(node->right);
    if ((node->left == nullptr && node->right != nullptr) ||
        (node->left != nullptr && node->right == nullptr)) {
      return 1 + left + right;
    } else
      return left + right;
  }

  int find_index(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
      if (inorder[i] == value) return i;
    }
    return -1;
  }
};