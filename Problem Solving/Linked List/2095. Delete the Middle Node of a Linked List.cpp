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
  // Formula based Approach
  ListNode* deleteMiddle_1(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    int length = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
      length++;
      temp = temp->next;
    }

    int midpoint = (length / 2);

    temp = head;
    for (int i = 0; i < midpoint - 1; i++) {
      temp = temp->next;
    }

    ListNode* delNode = temp->next;
    temp->next = temp->next->next;

    delete delNode;
    return head;
  }

  // Tortoise and Hare Approach
  ListNode* deleteMiddle_2(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* deleteNode = prev->next;
    prev->next = prev->next->next;
    delete deleteNode;

    return head;
  }
};