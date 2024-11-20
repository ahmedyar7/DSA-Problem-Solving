#include <iostream>
using namespace std;

struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Queue {
 public:
  TreeNode** arr;
  int front;
  int rear;
  int capacity;

  Queue(int size) {
    arr = new TreeNode*[size];
    front = 0;
    rear = 0;
    capacity = size;
  }

  ~Queue() { delete[] arr; }

  bool isEmpty() { return front == rear; }

  void enqueue(TreeNode* node) {
    if (rear < capacity) {
      arr[rear++] = node;
    }
  }

  TreeNode* dequeue() {
    if (!isEmpty()) {
      return arr[front++];
    }
    return nullptr;
  }
};

TreeNode* buildTree(int values[], int n) {
  if (n == 0) return nullptr;

  // Create the root node
  TreeNode* root = new TreeNode(values[0]);

  // Initialize a queue to hold nodes
  Queue q(n);
  q.enqueue(root);

  // Variable to keep track of which value to insert next
  int i = 1;

  while (i < n) {
    TreeNode* current = q.dequeue();

    // Add left child if the next value exists
    if (i < n) {
      current->left = new TreeNode(values[i++]);
      q.enqueue(current->left);
    }

    // Add right child if the next value exists
    if (i < n) {
      current->right = new TreeNode(values[i++]);
      q.enqueue(current->right);
    }
  }

  return root;
}

void inorderTraversal(TreeNode* root) {
  if (root == nullptr) return;
  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

int main() {
  // Array of values to insert into the binary tree
  int values[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(values) / sizeof(values[0]);

  // Build the tree
  TreeNode* root = buildTree(values, n);

  // Print the in-order traversal
  cout << "In-order traversal of the tree: ";
  inorderTraversal(root);  // Output: 4 2 5 1 6 3 7

  return 0;
}
