# [25. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

### Approach Explanation:

We are given a singly linked list and a number `k`. The task is to reverse the nodes in the linked list in groups of `k`. If there are fewer than `k` nodes in the last group, the nodes should remain in their original order.

Here is the step-by-step approach:

1. **Helper Functions:**
   - **`reverseLinkedList`:** Reverses the entire linked list or a part of it.
   - **`getKthNode`:** Returns the `k`-th node from a given node. This helps in identifying the `k`-th node for each group.
2. **Main Function `reverseKGroup`:**
   - Traverse the list and reverse groups of `k` nodes.
   - For each group, reverse the nodes and link them with the previous group.
   - If a group contains fewer than `k` nodes, leave it unchanged.

### Detailed Dry Run:

**Example Linked List:**
`1 -> 2 -> 3 -> 4 -> 5`

**Given `k = 3`, we want to reverse the list in groups of 3 nodes.**

#### **Initialization:**

- `temp = head` (points to `1`)
- `prevLast = NULL`

#### **First Iteration:**

- Call `getKthNode(temp, 3)`:
  - We get the 3rd node: `3`.
- The 3rd node (`3`) exists, so we proceed to reverse the group.
- Store the next node (`4`) into `nextNode`.
- Disconnect the 3rd node (`3`) from the list.
- Call `reverseLinkedList(temp)` to reverse the first group (`1 -> 2 -> 3`):
  - After reversal: `3 -> 2 -> 1`
- Update the head of the list to `kThNode` (which is `3`).
- `prevLast = temp` (which points to `1`).
- Move `temp` to the next group starting at `4`.

**List so far:**
`3 -> 2 -> 1 -> 4 -> 5`

#### **Second Iteration:**

- Call `getKthNode(temp, 3)` (with `temp` pointing to `4`):
  - We get the 3rd node: `5`.
- The 3rd node (`5`) exists, so we proceed to reverse the group.
- Store `nextNode = NULL` (since there are no more nodes).
- Disconnect the 3rd node (`5`) from the list.
- Call `reverseLinkedList(temp)` to reverse the second group (`4 -> 5`):
  - After reversal: `5 -> 4`
- Link the previous group's last node (`1`) to the new reversed group (`5`).
- `prevLast = temp` (which points to `4`).
- `temp` moves to `nextNode`, which is `NULL`, ending the loop.

**Final List:**
`3 -> 2 -> 1 -> 5 -> 4`

### **Edge Cases:**

- **Less than `k` nodes:** If there are fewer than `k` nodes left, the group is not reversed and remains in its original order.
- **Exact multiples of `k`:** The list is fully reversed in groups of `k`.

### Final Code Summary:

1. Reverse nodes in groups of `k`.
2. Ensure the head is updated if the first group is reversed.
3. Link the reversed groups together to maintain the list's integrity.
