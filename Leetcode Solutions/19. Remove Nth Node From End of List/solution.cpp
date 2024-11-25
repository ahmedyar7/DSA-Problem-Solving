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
  ListNode* removeNthFromEnd(ListNode*& head, int n) {
    int counter = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
      counter++;
      temp = temp->next;
    }
    if (counter == n) {
      ListNode* del_node = head;
      head = head->next;
      delete del_node;
      return head;
    } else {
      temp = head;
      for (int i = 0; i < counter - n - 1; i++) {
        temp = temp->next;
      }

      ListNode* del_node = temp->next;
      temp->next = temp->next->next;
      delete del_node;
      return head;
    }
    return head;
  }
};