class Solution {
 public:
  int height(TreeNode* root) {
    if (root == nullptr) return -1;  // Height of an empty tree is -1.
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) +
           1;  // Height of current node is 1 + max of left and right heights
  }

  int diameterHelper(TreeNode* root, int& diameter) {
    if (root == nullptr) return 0;

    // Recursively calculate the height of the left and right subtrees
    int leftHeight = diameterHelper(root->left, diameter);
    int rightHeight = diameterHelper(root->right, diameter);

    // Update the diameter at each node: the longest path passes through the
    // node
    diameter = max(diameter, leftHeight + rightHeight);

    // Return the height of the current node
    return max(leftHeight, rightHeight) + 1;
  }

  int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    diameterHelper(
        root, diameter);  // Call the helper function that updates the diameter
    return diameter;
  }
};
