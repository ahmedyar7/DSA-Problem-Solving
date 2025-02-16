#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  // Function to find the kth node
  ListNode* findKthNode(ListNode* head, int k) {
    ListNode* temp = head;
    for (int i = 1; i < k && temp != nullptr; i++) temp = temp->next;
    return temp;
  }

  // Function for reversing the Linked list
  ListNode* reverse(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = nullptr;

    while (temp != nullptr) {
      ListNode* front = temp->next;
      temp->next = prev;
      prev = temp;
      temp = front;
    }

    return prev;
  }

  // Brute Force Approach & Optimal Approach
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k == 1) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prevGrpEnd = dummy;
    ListNode* temp = head;

    while (temp != nullptr) {
      ListNode* kthNode = findKthNode(temp, k);

      // If fewer than kth node exit
      if (kthNode == nullptr) break;

      ListNode* nextGrpStart = kthNode->next;
      kthNode->next = nullptr;  // detatch current k-grp

      // reverse k-grp
      ListNode* newHead = reverse(temp);

      // connect previous to new
      prevGrpEnd->next = newHead;

      prevGrpEnd = temp;
      prevGrpEnd->next = nextGrpStart;

      temp = nextGrpStart;
    }

    return dummy->next;
  }
};