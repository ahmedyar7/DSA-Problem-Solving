#include <iostream>

#include "Node.h"

using namespace std;

int main() {
  LinkedList<int> list;

  // Inserting elements at the tail
  list.insert_at_tail(10);
  list.insert_at_tail(20);
  list.insert_at_tail(30);
  list.insert_at_tail(40);
  list.insert_at_tail(50);

  cout << "List after inserting at tail:\n";
  list.print();  // Expected Output: 10 20 30 40 50 end

  // Inserting element at the head
  list.insert_at_head(5);
  cout << "\nList after inserting 5 at head:\n";
  list.print();  // Expected Output: 5 10 20 30 40 50 end

  // Inserting element at a specific position
  list.insert_at_position(3, 15);  // Insert 15 at position 3
  cout << "\nList after inserting 15 at position 3:\n";
  list.print();  // Expected Output: 5 10 15 20 30 40 50 end

  // Finding the maximum and minimum values
  cout << "\nFinding the maximum and minimum values:\n";
  list.max_n_min();  // Expected Output: Max: 50, Min: 5

  // Counting the total number of nodes
  cout << "\nCounting total number of nodes:\n";
  list.count_nodes();  // Expected Output: Total Nodes: 7

  cout << "\nReversing\n";
  list.reverse_node();
  list.print();

  return 0;
}
