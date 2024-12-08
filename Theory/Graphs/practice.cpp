#include <iostream>
using namespace std;

// Max Number of vertices
const int MAX_VERTICES = 10;

class Graph {
 public:
  int vertices;  // Actual no.vertices
  int adj_matrix[MAX_VERTICES][MAX_VERTICES];

  Graph(int vertices) {
    this->vertices = vertices;

    // initialization of adjacency matrix
    for (int i = 0; i < MAX_VERTICES; i++) {
      for (int j = 0; j < MAX_VERTICES; j++) {
        adj_matrix[i][j] = 0;
      }
    }
  }

  // Adding edges
  void add_edges(int u, int v) {
    adj_matrix[u][v] = 1;  // for directed graph
    adj_matrix[v][u] = 1;  // comment for directed graph
  }

  // BFS function
  int bfs_traversal(int start_node) {
    bool visited_set[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0;
    int rear = 0;

    // Adding the start node
    visited_set[start_node] = true;
    queue[rear++] = start_node;

    while (front < rear) {
      // Dequeue the first nodes
      int current_node = queue[front++];
      cout << current_node << " ";

      // check neighbors
      for (int i = 0; i < vertices; i++) {
        /*
            1. When the vertix ith and jth is marked as 1
            2. When the vertix is not in visited set
            3. Then mark node as True in visited and increment the rear pointer
        */
        if (adj_matrix[current_node][i] == 1 && visited_set[i] == false) {
          visited_set[i] = true;
          queue[rear++] = i;
        }
      }
    }
  }

  // DFS Traversal
  void dfs_traversal(int start_node) {
    bool visited_set[MAX_VERTICES] = {false};
    dfs_calls(start_node, visited_set);
    cout << endl;
  }

 private:
  void dfs_calls(int node, bool visited_set[]) {
    visited_set[node] = true;
    cout << node << " ";
    for (int i = 0; i < vertices; i++) {
      if (adj_matrix[node][i] == 1 && visited_set[i] == false) {
        dfs_calls(i, visited_set);
      }
    }
  }
};