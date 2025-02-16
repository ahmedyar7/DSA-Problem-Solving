#include <iostream>
#include <map>
using namespace std;

class ListNode {
 public:
  int data;
  ListNode* next;

  ListNode(int data) {
    this->data = data;
    next = nullptr;
  }

  // Hashmap Approach
  bool containCycles_1(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return false;

    ListNode* temp = head;

    map<ListNode*, int> hashmap;

    while (temp->next != nullptr) {
      if (hashmap.find(temp) != hashmap.end()) return true;
      hashmap[temp] = 1;
      temp = temp->next;
    }
    return false;
  }

  // Tortoise and Hare Approach
  bool containCycles_2(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return false;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) return true;
    }
    return false;
  }
};

/*
Hashmap Approach:-
1. We would store the head in a temp variable such that we don't hampers the
head of list
2. We then make a map having key = ListNode* and value equal number of
occuracnces
3. Then we would Ittreate over the list
4. Before entering the ListNode check if ListNode already exists or not
5. Continure moving towards the next.
*/

/*
Tortoise and Hare Approach:
1. We would make slow and fast pointer
2. Then when both the slow and fast pointer meet there is loop.
*/