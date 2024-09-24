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