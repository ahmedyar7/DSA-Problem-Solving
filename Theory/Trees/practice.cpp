#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
 private:
 public:
  int data;
  TreeNode* right;
  TreeNode* left;

  TreeNode(int data) {
    this->data = data;
    right = nullptr;
    left = nullptr;
  }
};

// function to find the index in inorder array
int find_index(int inorder_arr[], int start, int end, int value) {
  for (int i = start; i <= end; i++) {
    if (inorder_arr[i] == value) return i;
  }
  return -1;
}

// Function to construct the tree using Recusive calls
TreeNode* construct_tree(int preorder_arr[], int inorder_arr[],
                         int& preorder_index, int inorder_start,
                         int inorder_end) {
  if (inorder_start > inorder_end) {
    return nullptr;
  }

  // Root Node
  int root_value = preorder_arr[preorder_index++];
  TreeNode* rootnode = new TreeNode(root_value);

  // Recursion base condition
  if (inorder_start == inorder_end) return rootnode;

  int rootindex =
      find_index(inorder_arr, inorder_start, inorder_end, root_value);

  // Recursive  calling the left subtree
  rootnode->left = construct_tree(preorder_arr, inorder_arr, preorder_index,
                                  inorder_start, rootindex - 1);
  // Recursive  calling the right subtree
  rootnode->right = construct_tree(preorder_arr, inorder_arr, preorder_index,
                                   rootindex + 1, inorder_end);
  return rootnode;  // return finaltree
}

// Implementation of inorder Traversal
void inorder_traversal(TreeNode* root) {
  if (root == nullptr) return;

  inorder_traversal(root->left);
  cout << root->data << " ";
  inorder_traversal(root->right);
}

// Implementation of inorder traversal
void preorder_traversal(TreeNode* root) {
  if (root == nullptr) return;

  cout << root->data << " ";
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

// Implementation of postorder traversal
void postorder_traversal(TreeNode* root) {
  if (root == nullptr) return;

  postorder_traversal(root->left);
  postorder_traversal(root->right);
  cout << root->data << " ";
}

// Implementation of level order traversal
void levelorder_traversal(TreeNode* root) {
  if (root == nullptr) {
    return;
  }

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* current = q.front();
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