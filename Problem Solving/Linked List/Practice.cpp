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

  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* temp = head;
    vector<int> vec;

    while (temp != nullptr) {
      vec.push_back(temp->val);
      temp = temp->next;
    }

    sort(vec.begin(), vec.end());

    int it = 0;
    temp = head;
    while (temp != nullptr) {
      temp->val = vec[it];
      it++;
      temp = temp->next;
    }

    return head;
  }
  ListNode* deleteMidNode(ListNode* head) {
    if (head == nullptr) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* delNode = prev->next;
    delete delNode;

    return head;
  }

  ListNode* removeFromEnd(ListNode* head, int k) {
    if (head == nullptr) return nullptr;

    int len = 0;
    ListNode* temp = head;

    while (temp != nullptr) {
      len++;
      temp = temp->next;
    }

    temp = head;
    for (int i = 0; i < len - k - 1; i++) {
      temp = temp->next;
    }

    ListNode* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;

    return head;
  }

  ListNode* intersectionOfLL(ListNode* head1, ListNode* head2) {
    if (head1 == nullptr || head2 == nullptr) return nullptr;

    map<ListNode*, int> hmap;

    ListNode* temp = head1;
    while (temp != nullptr) {
      hmap[temp] = 1;
    }

    temp = head2;
    while (temp != nullptr) {
      if (hmap.find(temp) != hmap.end()) {
        return temp;
      }
      hmap[temp] = 1;
      temp = temp->next;
    }

    return nullptr;
  }
};