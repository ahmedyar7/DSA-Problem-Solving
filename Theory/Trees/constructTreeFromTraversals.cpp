#include <iostream>
using namespace std;

// Define the structure of a tree node
struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to find the index of a value in an array
int findIndex(int arr[], int start, int end, int value) {
  for (int i = start; i <= end; ++i) {
    if (arr[i] == value) return i;
  }
  return -1;  // Should not happen if input is valid
}

// Recursive function to construct the binary tree
TreeNode* constructTree(int preorder[], int inorder[], int& preorderIndex,
                        int inorderStart, int inorderEnd) {
  if (inorderStart > inorderEnd) return nullptr;

  // The current element in preorder is the root of this subtree
  int rootValue = preorder[preorderIndex++];
  TreeNode* root = new TreeNode(rootValue);

  // If there's no subtree, return the root
  if (inorderStart == inorderEnd) return root;

  // Find the root index in the inorder array
  int rootIndex = findIndex(inorder, inorderStart, inorderEnd, rootValue);

  // Recursively construct the left and right subtrees
  root->left = constructTree(preorder, inorder, preorderIndex, inorderStart,
                             rootIndex - 1);
  root->right = constructTree(preorder, inorder, preorderIndex, rootIndex + 1,
                              inorderEnd);

  return root;
}

// Utility function to print the tree in inorder to verify the result
void printInorder(TreeNode* root) {
  if (root == nullptr) return;

  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}
