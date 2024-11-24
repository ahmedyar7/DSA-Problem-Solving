#include <unordered_set>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next)
      return head;  // Empty list or single element, return as is

    unordered_set<int> duplicates;  // To store values that are duplicated
    ListNode* current = head;

    // First pass: Find all duplicates
    while (current && current->next) {
      if (current->val == current->next->val) {
        duplicates.insert(current->val);
      }
      current = current->next;
    }

    // Dummy node to simplify edge cases
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    current = head;

    // Second pass: Remove duplicates
    while (current) {
      if (duplicates.find(current->val) != duplicates.end()) {
        // Skip the current node if it's a duplicate
        prev->next = current->next;
        delete current;
      } else {
        // Move the prev pointer only if current node is not deleted
        prev = current;
      }
      current = prev->next;
    }

    return dummy.next;  // Return the new head, which is dummy.next
  }
};
