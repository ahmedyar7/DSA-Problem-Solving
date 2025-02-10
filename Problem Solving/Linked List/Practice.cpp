#include <bits-stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}       // Default Constructor
  ListNode(int x) : val(x), next(nullptr) {}  // Parametrized constructor
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 private:
 public:
  ListNode* rotateLL(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr) return head;

    int len = 0;
    ListNode* temp = head;

    while (temp != nullptr) {
      len++;
      temp = temp->next;
    }

    k = k % len;
    if (k == 0) return head;

    ListNode* tailNode = head;
    while (tailNode->next != nullptr) {
      tailNode = tailNode->next;
    }
    tailNode->next = head;

    temp = head;
    for (int i = 0; i < len - k - 1; i++) {
      temp = temp->next;
    }
    ListNode* newhead = temp->next;
    temp->next = nullptr;

    return newhead;
  }
};