#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    ListNode* temp = head;
    std::stack<int> st;

    while (temp != nullptr) {
      st.push(temp->val);
      temp = temp->next;
    }

    temp = head;
    while (temp != head) {
      if (temp->val != st.top()) {
        return false;
      }
      temp = temp->next;
      st.pop();
    }
    return true;
  }
};

/*
  Approach # 1 :
  1. Take a stack of integer data type and puch all the element of the
     linked list into the stack

  2.The again traverse the linked list then this time check the stack value
    and the stack top element if the are same the pop out the element of the
    stack if they are not same the return false(NOT PALINDRIOM)

  3. Else they linked list is palindriom
*/