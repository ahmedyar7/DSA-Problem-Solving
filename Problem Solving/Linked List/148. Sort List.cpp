#include <iostream>
#include <vector>
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
  // Brute Force Approach
  ListNode* sortList(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode* temp = head;
    vector<int> vec;

    while (temp != nullptr) {
      vec.push_back(temp->val);
      temp = temp->next;
    }

    // Sorting
    sort(vec.begin(), vec.end());

    temp = head;
    int it = 0;
    while (temp != nullptr) {
      temp->val = vec[it];
      it++;
      temp = temp->next;
    }

    return head;
  }
};