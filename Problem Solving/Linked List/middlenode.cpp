#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};

/*
  - This problem is solved by the Tortois and Hare method
  - In thie method we make two pointer fast and slow pointers
  - Both initially pointing towards the head of the linked list
  - We move slow by one step and fast by two step
  - When fast moves towards the end in odd number linked list we stop and see
  that the slow is pointing toward the middle elements.
*/