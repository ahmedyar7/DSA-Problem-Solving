#include <cmath>
#include <functional>  // For std::function
#include <iomanip>     // For better formatting
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Node class definition
class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

// BinaryTree class definition
class BinaryTree {
 private:
  Node* root;

  // Helper Function to insert nodes
  Node* insert_node(Node* node, int value) {
    if (node == nullptr) return new Node(value);
    if (value < node->data) node->left = insert_node(node->left, value);
    if (value > node->data) node->right = insert_node(node->right, value);
    return node;
  }

  // Traversal functions
  void inorder_traversal(Node* root) {
    if (root == nullptr) return;
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
  }

  void preorder_traversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
  }

  void postorder_traversal(Node* root) {
    if (root == nullptr) return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
  }

  void clear_tree(Node* root) {
    if (root == nullptr) return;
    clear_tree(root->left);
    clear_tree(root->right);
    delete root;
  }

 public:
  // Constructor
  BinaryTree() : root(nullptr) {}

  // Insert function
  void insert(int value) { root = insert_node(root, value); }

  // Display tree traversals
  void display_traversals() {
    if (root == nullptr) {
      cout << "The tree is empty.\n";
      return;
    }
    cout << "Inorder Traversal: ";
    inorder_traversal(root);
    cout << "\nPreorder Traversal: ";
    preorder_traversal(root);
    cout << "\nPostorder Traversal: ";
    postorder_traversal(root);
    cout << endl;
  }

  // Return the root (used for ASCII visualization)
  Node* get_root() { return root; }

  // Destructor
  ~BinaryTree() { clear_tree(root); }
};

// Helper Function: Converts tree to 2D grid for ASCII visualization
void build_tree_grid(Node* root, vector<vector<string>>& grid, int row, int col,
                     int depth, int offset) {
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

// Function: Visualizes the binary tree using ASCII art
void print_ascii_tree(Node* root) {
  if (root == nullptr) {
    cout << "The tree is empty.\n";
    return;
  }

  // Determine depth of the tree
  function<int(Node*)> tree_depth = [&](Node* node) {
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
