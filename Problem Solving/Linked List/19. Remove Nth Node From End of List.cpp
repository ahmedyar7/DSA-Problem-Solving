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
  // Pointer Approach
  ListNode* removeNthFromEnd_1(ListNode* head, int n) {
    if (head == nullptr) return nullptr;

    // Calculating the Length of LL
    int length = 0;
    ListNode* temp = head;

    while (temp != nullptr) {
      length++;
      temp = temp->next;
    }

    // Indicate the node where we should stop
    int result = length - n;

    // Edge case when removing head node;
    if (result == 0) return head->next;

    temp = head;
    for (int i = 0; i < result - 1; i++) temp = temp->next;
    ListNode* delNode = temp->next;
    temp->next = temp->next->next;

    delete delNode;
    return head;
  }

  // Approach 2: Slow and fast pointer Apporach
  ListNode* removeNthFromEnd_2(ListNode* head, int n) {
    if (head == nullptr) return nullptr;

    ListNode* fast = head;
    for (int i = 0; i < n; i++) {
      fast = fast->next;
    }

    ListNode* slow = head;
    while (fast != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }

    ListNode* delNode = slow->next;
    slow->next = slow->next->next;

    delete delNode;
    return head;
  }
};