/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 private:
  TreeNode* find_min_node(TreeNode* node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else {
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
      } else if (root->left == nullptr) {
        TreeNode* temp = root->right;
        delete root;
        return temp;
      } else if (root->right == nullptr) {
        TreeNode* temp = root->left;
        delete root;
        return temp;
      } else {
        TreeNode* inorder_succesor = find_min_node(root->right);
        root->val =
            inorder_succesor->val;  // Copy the inorder successor's value
        root->right = deleteNode(root->right, inorder_succesor->val);
      }
    }
    return root;
  }
};