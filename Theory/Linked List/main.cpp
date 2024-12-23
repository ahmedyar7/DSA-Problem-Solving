#include <iostream>

#include "Node.h"

using namespace std;

#include <iostream>
using namespace std;

int main() {
  // Create a LinkedList object
  LinkedList<int> list;

  // Insert elements at the tail
  list.insert_at_tail(7);
  list.insert_at_tail(3);
  list.insert_at_tail(8);
  list.insert_at_tail(2);
  list.insert_at_tail(5);

  // Display the original list
  cout << "Original List: ";
  list.print();

  // Count the nodes
  list.count_nodes();

  // Find maximum and minimum
  list.max_n_min();

  // Reverse the list and display it
  cout << "Reversed List: ";
  list.reverse_node();
  list.print();

  // Find an element in the list
  int element_to_find = 8;
  cout << "Element " << element_to_find
       << (list.find_element(element_to_find) ? " is found\n"
                                              : " is not found\n");

  // Sort the list
  cout << "Sorted List: ";
  Node<int>* sorted_head = list.sort(list.reverse_node());
  LinkedList<int> sorted_list;
  sorted_list.insert_at_head(sorted_head->data);
  cout << endl;
}
