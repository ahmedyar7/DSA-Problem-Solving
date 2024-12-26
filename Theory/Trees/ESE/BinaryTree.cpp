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

  bool isBalanced() { return is_balanced(root); }
  int diameter() { return get_diameter(root); }

  Treenode* construct_tree(int inorder[], int preorder[], int& preorder_index,
                           int inorder_start, int inorder_end) {
    if (inorder_start > inorder_end) return nullptr;

    int rootvalue = preorder[preorder_index];
    Treenode* rootnode = new Treenode(rootvalue);

    if (inorder_start == inorder_end) return rootnode;
    int rootindex = find_index(inorder, inorder_start, inorder_end, rootvalue);

    rootnode->left = construct_tree(inorder, preorder, preorder_index,
                                    inorder_start, rootindex - 1);
    rootnode->right = construct_tree(inorder, preorder, preorder_index,
                                     rootindex + 1, inorder_end);

    return rootnode;
  }

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
      return find_node(node->right, target);
    } else {
      return find_node(node->left, target);
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

  bool is_balanced(Treenode* node) {
    if (node == nullptr) return true;
    bool left = is_balanced(node->left);
    bool right = is_balanced(node->right);
    bool diff = abs(get_height(node->left) - get_height(node->right) <= 1);
    if (left && right && diff) return true;
    return false;
  }

  int get_diameter(Treenode* node) {
    if (node == nullptr) return 0;

    int left_height = get_height(node->left);
    int right_height = get_height(node->right);

    int left_diameter = get_diameter(node->left);
    int right_diameter = get_diameter(node->right);

    return max(left_height + right_height + 1,
               max(left_diameter, right_diameter));
  }

  int find_index(int inorder[], int start, int end, int target) {
    for (int i = start; i <= end; i++) {
      if (inorder[i] == target) return i;
    }
    return -1;
  }
};

int main() {
  BinaryTree tree;

  // Insert nodes into the binary tree
  tree.insert(50);
  tree.insert(30);
  tree.insert(70);
  tree.insert(20);
  tree.insert(40);
  tree.insert(60);
  tree.insert(80);

  // 1. Inorder Traversal
  cout << "Inorder Traversal: ";
  tree.inorder();
  cout << endl;

  // 2. Preorder Traversal
  cout << "Preorder Traversal: ";
  tree.preorder();
  cout << endl;

  // 3. Postorder Traversal
  cout << "Postorder Traversal: ";
  tree.postorder();
  cout << endl;

  // 4. Level Order Traversal
  cout << "Level Order Traversal: ";
  tree.levelorder();
  cout << endl;

  // 5. Count Total Nodes
  cout << "Total nodes: " << tree.count_nodes() << endl;

  // 6. Count Leaf Nodes (Degree 0)
  cout << "Leaf nodes (degree 0): " << tree.deg0() << endl;

  // 7. Count Nodes with Degree 1
  cout << "Nodes with degree 1: " << tree.deg1() << endl;

  // 8. Count Nodes with Degree 2
  cout << "Nodes with degree 2: " << tree.deg2() << endl;

  // 9. Search for a specific node
  int target = 40;
  cout << "Searching for node " << target << ": ";
  if (tree.search(target)) {
    cout << "Found!" << endl;
  } else {
    cout << "Not Found!" << endl;
  }

  // 10. Delete a node
  int delete_val = 30;
  cout << "Deleting node " << delete_val << "..." << endl;
  tree.remove(delete_val);

  // 11. Inorder Traversal after Deletion
  cout << "Inorder Traversal after deletion: ";
  tree.inorder();
  cout << endl;

  // 12. Tree Height
  cout << "Height of the tree: " << tree.height() << endl;

  // 13. Check if the tree is balanced
  cout << "Is the tree balanced? " << (tree.isBalanced() ? "Yes" : "No")
       << endl;

  // 14. Diameter of the tree
  cout << "Diameter of the tree: " << tree.diameter() << endl;

  // 15. Construct Tree from Inorder and Preorder Arrays
  int inorder[] = {20, 30, 40, 50, 60, 70, 80};
  int preorder[] = {50, 30, 20, 40, 70, 60, 80};
  int preorder_index = 0;
  BinaryTree tree_from_arrays;
  tree_from_arrays.root =
      tree_from_arrays.construct_tree(inorder, preorder, preorder_index, 0, 6);

  cout << "Inorder Traversal of constructed tree: ";
  tree_from_arrays.inorder();
  cout << endl;

  return 0;
}
