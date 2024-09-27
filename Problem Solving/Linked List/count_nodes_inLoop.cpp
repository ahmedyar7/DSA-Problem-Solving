#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
 public:
  // Function to find the length of a loop in the linked list.
  int countNodesinLoop(Node* head) {
    std::unordered_map<Node*, int> hashmap;
    Node* temp = head;
    int timer = 1;

    while (temp != nullptr) {
      if (hashmap.find(temp) != hashmap.end()) {
        int value = hashmap[temp];
        return abs(value - timer);
      }
      hashmap[temp] = timer;
      timer++;
      temp = temp->next;
    }

    return 0;
  }
};

/*
  Approach:
  1. Take the hashmap and then add the nodes to that hashmaps
     and before adding the nodes check wether that node already exits
     or not

  2. if yes then return the timer initialized as 1 and the absolute
  difference(value of that node and the timer) otherwise add that node and
  incrementing the timer and moving the node to the next node of the linked list

*/