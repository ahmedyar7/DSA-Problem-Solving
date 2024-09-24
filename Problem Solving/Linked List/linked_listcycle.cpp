#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    map<ListNode *, int> hashmap;
    ListNode *temp = head;

    while (temp != nullptr) {
      if (hashmap.find(temp) != hashmap.end()) {
        return temp;
      }
      hashmap[temp] = 1;
      temp = temp->next;
    }
    return nullptr;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  Solution solution;

  while (t--) {
    int n;
    cin >> n;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    vector<ListNode *> nodelist;
    for (int i = 0; i < n; i++) {
      int value;
      cin >> value;
      ListNode *new_node = new ListNode(value);
      nodelist.push_back(new_node);
    }

    ListNode *answer = solution.detectCycle(head);
    if (answer)
      cout << answer->val;
    else
      cout << answer->val;
  }

  return 0;
}