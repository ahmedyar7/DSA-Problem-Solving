#include <iostream>
using namespace std;

//   Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return nullptr;

    int length = 0;
    ListNode* temp = head;

    while (temp != nullptr) {
      length++;
      temp = temp->next;
    }

    k = k % length;
    if (k == 0) return head;

    // Finding tail node
    ListNode* tailNode = head;
    temp = head;

    while (tailNode->next != nullptr) {
      temp = temp->next;
      tailNode = tailNode->next;
    }

    // Pointing tail node to head
    tailNode->next = head;

    temp = head;
    for (int i = 0; i < length - k - 1; i++) {
      temp = temp->next;
    }

    ListNode* newHead = temp->next;
    temp->next = nullptr;

    return newHead;
  }
};