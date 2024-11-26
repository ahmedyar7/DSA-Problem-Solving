// class TreeNode {
// public:
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
// };

class Solution {
 public:
  // Helper function to find the index of a value in the inorder array
  int find_index(vector<int>& inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
      if (inorder[i] == value) {
        return i;
      }
    }
    return -1;
  }

  // Recursive function to construct the binary tree
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // The index of preorder is kept as a reference to move through the preorder
    // list
    int preorder_index = 0;
    return buildTreeHelper(preorder, inorder, preorder_index, 0,
                           inorder.size() - 1);
  }

  // Helper function to build the tree recursively
  TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,
                            int& preorder_index, int inorder_start,
                            int inorder_end) {
    // Base case: if the start index exceeds the end, there's no subtree
    if (inorder_start > inorder_end) return nullptr;

    // Get the root value from preorder (preorder_index keeps track of the
    // current root)
    int root_val = preorder[preorder_index++];
    TreeNode* root = new TreeNode(root_val);

    // Find the root value in the inorder array to split the inorder list into
    // left and right subtrees
    int inorder_index =
        find_index(inorder, inorder_start, inorder_end, root_val);

    // Recursively build the left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, preorder_index,
                                 inorder_start, inorder_index - 1);
    root->right = buildTreeHelper(preorder, inorder, preorder_index,
                                  inorder_index + 1, inorder_end);

    return root;
  }
};
