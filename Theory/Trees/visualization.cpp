#include <cmath>
#include <functional>  // For std::function
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// treenode class definition
class treenode {
 public:
  int data;
  treenode* left;
  treenode* right;

  treenode(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Helper Function: Converts tree to 2D grid for visualization
void build_tree_grid(treenode* root, vector<vector<string>>& grid, int row,
                     int col, int depth, int offset) {
  if (root == nullptr) return;

  // Place the root in the grid
  grid[row][col] = to_string(root->data);

  // Calculate positions for left and right children
  int child_offset = offset / 2;
  if (root->left) {
    grid[row + 1][col - child_offset] = "/";
    build_tree_grid(root->left, grid, row + 2, col - child_offset * 2, depth,
                    child_offset);
  }
  if (root->right) {
    grid[row + 1][col + child_offset] = "\\";
    build_tree_grid(root->right, grid, row + 2, col + child_offset * 2, depth,
                    child_offset);
  }
}

// Main Function: Visualizes the binary tree
void print_ascii_tree(treenode* root) {
  if (root == nullptr) {
    cout << "The tree is empty.\n";
    return;
  }

  // Determine depth of the tree
  function<int(treenode*)> tree_depth = [&](treenode* node) {
    if (node == nullptr) return 0;
    return 1 + max(tree_depth(node->left), tree_depth(node->right));
  };

  int depth = tree_depth(root);

  // Dimensions for the grid
  int rows = depth * 2 - 1;
  int cols = pow(2, depth) * 2;  // Space for nodes and edges

  // Initialize grid with spaces
  vector<vector<string>> grid(rows, vector<string>(cols, " "));

  // Build the grid representation of the tree
  build_tree_grid(root, grid, 0, cols / 2, depth, cols / 4);

  // Print the grid row by row
  for (const auto& row : grid) {
    for (const auto& cell : row) {
      cout << cell;
    }
    cout << endl;
  }
}
