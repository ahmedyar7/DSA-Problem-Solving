class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    // Traverse the list, linking odd nodes together and even nodes together
    while (even && even->next) {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }

    // Connect the end of odd list to the head of even list
    odd->next = evenHead;

    return head;
  }
};
