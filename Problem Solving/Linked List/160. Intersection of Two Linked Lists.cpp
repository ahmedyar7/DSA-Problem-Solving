#include <bits-stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;

    ListNode *tempA = headA;
    ListNode *tempB = headB;

    map<ListNode *, int> hmap;

    while (tempA != nullptr) {
      hmap[tempA] = 1;
      tempA = tempA->next;
    }

    while (tempB != nullptr) {
      if (hmap.find(tempB) != hmap.end()) {
        return tempB;
      } else {
        hmap[tempB] = 1;
        tempB = tempB->next;
      }
    }
    return nullptr;
  }
};