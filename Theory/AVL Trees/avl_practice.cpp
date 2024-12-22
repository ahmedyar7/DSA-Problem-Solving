#include <iostream>
using namespace std;

class TreeNode {
 public:
  int data;
  TreeNode* left;
  TreeNode* right;
  int height = 1;

  TreeNode(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class AvlTree {
 private:
  int get_height(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }
    return node->height;
  }

  int balance_factor(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }
    return get_height(node->left) - get_height(node->right);
  }

  TreeNode* rotate_left(TreeNode* node) {
    TreeNode* new_root = node->right;
    TreeNode* subtree = new_root->left;

    new_root->left = node;
    node->right = subtree;

    new_root->height =
        1 + max(get_height(new_root->left), get_height(new_root->right));
    node->height = 1 + max(get_height(node->left), get_height(node->right));

    return new_root;
  }

  TreeNode* rotate_right(TreeNode* node) {
    TreeNode* new_root = node->left;
    TreeNode* subtree = new_root->right;

    new_root->right = node;
    node->left = subtree;

    new_root->height =
        1 + max(get_height(new_root->left), get_height(new_root->right));
    node->height = 1 + max(get_height(node->left), get_height(node->right));

    return new_root;
  }

  TreeNode* find_min(TreeNode* node) {
    if (node == nullptr) {
      return nullptr;
    }
    TreeNode* current = node;
    while (current->left != nullptr) current = current->left;
    return current;
  }

  void inorder_traversal(TreeNode* node) {
    if (node == nullptr) return;
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }

  TreeNode* insert_node(TreeNode* node, int data) {
    if (node == nullptr) return new TreeNode(data);
    if (data < node->data) {
      node->left = insert_node(node->left, data);
    } else if (data > node->data) {
      node->right = insert_node(node->right, data);
    } else {
      return node;
    }

    int balance = balance_factor(node);
    node->height = 1 + max(get_height(node->left), get_height(node->right));

    // LL Case
    if (balance > 1 && data < node->left->data) {
      return rotate_right(node);
    }
    // RR Case
    else if (balance < -1 && data > node->right->data) {
      return rotate_left(node);
    }
    // LR Case
    else if (balance > 1 && data > node->left->data) {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }
    // RL Case
    else if (balance < -1 && data < node->right->data) {
      node->right = rotate_right(node->left);
      return rotate_left(node);
    } else {
      return node;
    }
  }

  void delete_tree(TreeNode* node) {
    if (node == nullptr) {
      return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
  }

  TreeNode* remove_node(TreeNode* node, int data) {
    if (node == nullptr) return nullptr;
    if (node->data < data) {
      node->right = remove_node(node->right, data);
    } else if (node->data > data) {
      node->left = remove_node(node->left, data);
    } else {
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
      } else if (node->left == nullptr) {
        TreeNode* temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        TreeNode* temp = node->left;
        delete node;
        return temp;
      } else {
        TreeNode* temp = find_min(node->right);
        node->data = temp->data;
        node->right = remove_node(node->right, temp->data);
      }
    }

    int balance = balance_factor(node);
    node->height = 1 + max(get_height(node->left), get_height(node->right));

    // LL Case
    if (balance > 1 && balance_factor(node->left) >= 0) {
      return rotate_right(node);
    }
    // RR Case
    else if (balance < -1 && balance_factor(node->right) <= 0) {
      return rotate_left(node);
    }
    // LR Case
    else if (balance > 1 && balance_factor(node->left) <= 0) {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }
    // RL Case
    else if (balance < -1 && balance_factor(node->right) >= 0) {
      node->right = rotate_right(node->left);
      return rotate_left(node);
    } else {
      return node;
    }
  }

 public:
  TreeNode* root;

  AvlTree() { root = nullptr; }

  void insert(int data) { root = insert_node(root, data); }
  void inorder() { inorder_traversal(root); }
  TreeNode* remove(int data) { return remove_node(root, data); }
  ~AvlTree() { delete_tree(root); }
};

#include <iostream>
using namespace std;

int main() {
  AvlTree tree;

  cout << "Inserting elements into the AVL Tree..." << endl;
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);
  tree.insert(25);

  cout << "Inorder traversal of the AVL Tree: ";
  tree.inorder();
  cout << endl;

  cout << "Removing element 20 from the AVL Tree..." << endl;
  tree.root = tree.remove(20);

  cout << "Inorder traversal after removing 20: ";
  tree.inorder();
  cout << endl;

  cout << "Removing element 10 from the AVL Tree..." << endl;
  tree.root = tree.remove(10);

  cout << "Inorder traversal after removing 10: ";
  tree.inorder();
  cout << endl;

  cout << "Removing element 30 from the AVL Tree..." << endl;
  tree.root = tree.remove(30);

  cout << "Inorder traversal after removing 30: ";
  tree.inorder();
  cout << endl;

  return 0;
}
