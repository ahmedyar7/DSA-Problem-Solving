#include <iostream>
using namespace std;

// Maximum number of vertices in the graph
const int MAX_VERTICES = 10;

// Graph class
class Graph {
 private:
  int adjMatrix[MAX_VERTICES][MAX_VERTICES];  // Adjacency matrix
  int vertices;                               // Number of vertices

 public:
  // Constructor
  Graph(int v) : vertices(v) {
    // Initialize adjacency matrix to 0
    for (int i = 0; i < MAX_VERTICES; i++) {
      for (int j = 0; j < MAX_VERTICES; j++) {
        adjMatrix[i][j] = 0;
      }
    }
  }

  // Add edge between u and v
  void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;  // Directed edge
    adjMatrix[v][u] = 1;  // Uncomment for undirected graph
  }

  // BFS Function
  void BFS(int start) {
    bool visited[MAX_VERTICES] = {false};  // Visited array
    int queue[MAX_VERTICES];               // Array-based queue
    int front = 0, rear = 0;               // Queue pointers

    // Mark the starting node as visited and enqueue it
    visited[start] = true;
    queue[rear++] = start;

    cout << "BFS Traversal: ";
    while (front < rear) {
      // Dequeue a vertex
      int current = queue[front++];
      cout << current << " ";

      // Enqueue all unvisited neighbors
      for (int i = 0; i < vertices; i++) {
        if (adjMatrix[current][i] == 1 && !visited[i]) {
          visited[i] = true;
          queue[rear++] = i;
        }
      }
    }
    cout << endl;
  }

  // DFS Function (Recursive)
  void DFSRecursive(int start) {
    bool visited[MAX_VERTICES] = {false};
    cout << "DFS Traversal (Recursive): ";
    dfsUtil(start, visited);
    cout << endl;
  }

  // DFS Utility Function
  void dfsUtil(int node, bool visited[]) {
    visited[node] = true;
    cout << node << " ";

    // Visit all unvisited neighbors
    for (int i = 0; i < vertices; i++) {
      if (adjMatrix[node][i] == 1 && !visited[i]) {
        dfsUtil(i, visited);
      }
    }
  }

  // DFS Function (Iterative)
  void DFSIterative(int start) {
    bool visited[MAX_VERTICES] = {false};
    int stack[MAX_VERTICES];  // Array-based stack
    int top = -1;             // Stack pointer

    // Push the starting node onto the stack
    stack[++top] = start;

    cout << "DFS Traversal (Iterative): ";
    while (top >= 0) {
      // Pop a vertex from the stack
      int current = stack[top--];

      if (!visited[current]) {
        visited[current] = true;
        cout << current << " ";

        // Push all unvisited neighbors onto the stack
        for (int i = vertices - 1; i >= 0;
             i--) {  // Reverse order for correct traversal
          if (adjMatrix[current][i] == 1 && !visited[i]) {
            stack[++top] = i;
          }
        }
      }
    }
    cout << endl;
  }
};

int main() {
  int vertices = 6;  // Example graph with 6 vertices
  Graph g(vertices);

  // Add edges (Example graph)
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 5);

  // Perform BFS and DFS
  g.BFS(0);
  g.DFSRecursive(0);
  g.DFSIterative(0);

  return 0;
}
