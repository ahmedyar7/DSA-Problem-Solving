#include <iostream>

#include "practice.cpp"
using namespace std;

int main() {
  // Create a graph with 5 vertices
  Graph g(5);

  // Add edges
  g.add_edges(0, 1);
  g.add_edges(0, 2);
  g.add_edges(1, 3);
  g.add_edges(1, 4);
  g.add_edges(3, 5);
  g.add_edges(5, 6);

  // Perform BFS from node 0
  cout << "BFS Traversal\n";
  g.bfs_traversal(0);

  cout << "\nDFS Traversal:\n";
  g.dfs_traversal(0);

  return 0;
}