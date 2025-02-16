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
  /*
  - Inserting the element in the hashmaps
  - key being the object and the value be the occurance
  - Before inserting each of the element make sure that such
  element exist or not in the hashmap
  - if it does exits then return the object else continue
   */

  ListNode* startCircle_1(ListNode* head) {
    ListNode* temp = head;

    map<ListNode*, int> hashmap;

    while (temp->next != nullptr) {
      if (hashmap.find(temp) != hashmap.end()) return temp;
      hashmap[temp] = 1;
      temp = temp->next;
    }
    return nullptr;
  }

  // Tortoise and Hare Approach
  // This approach containt two steps
  // 1. Check for loop
  // 2. Find the starting point
  // When we found the loop then place
  // slow pointer to the head and then move slow and fast by one
  // Until they meet again
  ListNode* startCircle_2(ListNode* head) {
    if (head == nullptr) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};