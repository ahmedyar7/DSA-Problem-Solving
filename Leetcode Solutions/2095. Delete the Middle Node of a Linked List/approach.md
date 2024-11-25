# [2095. Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

### Problem Explanation:

The task is to delete the middle node of a singly linked list. If there are two middle nodes (in case of an even number of nodes), the second middle node is deleted. The goal is to do this in a single pass through the linked list.

### Approach:

1. **Edge Case Handling**: If the linked list has 0 or 1 node, return `nullptr` because there is no middle node to delete.
2. **Use Two Pointers (Slow and Fast)**:
   - **Slow Pointer**: This pointer will move one step at a time.
   - **Fast Pointer**: This pointer will move two steps at a time.
   - **Prev Pointer**: This pointer will keep track of the node just before the `slow` pointer, so we can link it to the node after the middle node (thus deleting the middle node).
3. **Move Pointers**: As the fast pointer moves two steps at a time, the slow pointer will reach the middle node when the fast pointer reaches the end of the list.
4. **Delete the Middle Node**: Once the slow pointer reaches the middle node, adjust the `prev->next` to point to `slow->next`, effectively deleting the middle node.
5. **Return the Modified List**: After the middle node is removed, return the head of the list.

### Dry Run Example:

#### Given Linked List:

- `head = 1 -> 2 -> 3 -> 4 -> 5`

#### Steps:

1. **Initialize Pointers**:
   - `slow = head` (points to node `1`)
   - `fast = head` (points to node `1`)
   - `prev = nullptr`
2. **First Iteration**:
   - `fast` moves two steps, now points to node `3`.
   - `slow` moves one step, now points to node `2`.
   - `prev` moves one step, now points to node `1`.
   - Now, the state is:
     - `slow = 2`
     - `fast = 3`
     - `prev = 1`
3. **Second Iteration**:

   - `fast` moves two steps, now points to node `5`.
   - `slow` moves one step, now points to node `3`.
   - `prev` moves one step, now points to node `2`.
   - Now, the state is:
     - `slow = 3`
     - `fast = 5`
     - `prev = 2`

4. **Third Iteration**:

   - `fast` moves two steps, now `fast = nullptr` (end of the list).
   - `slow` moves one step, now points to node `4`.
   - `prev` moves one step, now points to node `3`.
   - Now, the state is:
     - `slow = 4` (middle node to delete)
     - `fast = nullptr`
     - `prev = 3`

5. **Delete the Middle Node**:

   - `prev->next = slow->next` means `prev->next` (node `3`) will now point to `slow->next` (node `5`), thus deleting node `4`.
   - Now, the list becomes:
     - `1 -> 2 -> 3 -> 5`

6. **Return the Modified List**:
   - The modified list is `1 -> 2 -> 3 -> 5`.

#### Conclusion:

- The `slow` pointer ends up pointing to the middle node.
- The `prev` pointer adjusts the `next` pointer to skip the middle node, effectively deleting it.
- The algorithm runs in O(N) time, where N is the number of nodes in the linked list, since we only traverse the list once using the two-pointer technique.

### Edge Cases:

1. **Empty List**: If `head == nullptr`, return `nullptr`.
2. **Single Node List**: If the list has only one node, deleting the middle node results in `nullptr`.
3. **Two Node List**: The middle node will be the second node, which will be deleted.

### Time and Space Complexity:

- **Time Complexity**: O(N), where `N` is the number of nodes in the list. We traverse the list once.
- **Space Complexity**: O(1), since we only use a constant amount of extra space (three pointers).
