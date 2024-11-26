# [328. Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)

### Problem Explanation:

The task is to rearrange a singly linked list such that all nodes at odd indices come before nodes at even indices, while preserving their relative order. This does not involve changing node values but reordering the pointers.

---

### Approach:

1. **Initial Checks**: If the list is empty (`head == nullptr`) or has only one node (`head->next == nullptr`), return the list as it is already in the required format.
2. **Separate Odd and Even Nodes**:
   - Use two pointers:
     - `odd` to track the current odd-indexed node.
     - `even` to track the current even-indexed node.
   - Store the head of the even list in `evenHead` for later connection.
3. **Traverse the List**:
   - Update `odd->next` to point to the next odd node (`even->next`).
   - Move the `odd` pointer forward.
   - Update `even->next` to point to the next even node (`odd->next`).
   - Move the `even` pointer forward.
4. **Connect Lists**:
   - After traversing, connect the last odd node to the head of the even list (`evenHead`).
5. **Return Modified List**:
   - Return the head of the rearranged list.

---

### Dry Run:

#### Input:

`head = [1, 2, 3, 4, 5]`

#### Step-by-Step Execution:

1. **Initialization**:

   - `odd = head` → Points to `1`.
   - `even = head->next` → Points to `2`.
   - `evenHead = even` → Points to `2`.

2. **First Iteration**:

   - Update `odd->next = even->next`:
     - `odd->next = 3` → Links `1` to `3`.
   - Move `odd = odd->next`:
     - `odd` now points to `3`.
   - Update `even->next = odd->next`:
     - `even->next = 4` → Links `2` to `4`.
   - Move `even = even->next`:
     - `even` now points to `4`.

   **List after this step**:

   - Odd: `1 → 3`
   - Even: `2 → 4`
   - Remaining: `5`

3. **Second Iteration**:

   - Update `odd->next = even->next`:
     - `odd->next = 5` → Links `3` to `5`.
   - Move `odd = odd->next`:
     - `odd` now points to `5`.
   - Update `even->next = odd->next`:
     - `even->next = nullptr` → Ends the even list.
   - Move `even = even->next`:
     - `even` now points to `nullptr`.

   **List after this step**:

   - Odd: `1 → 3 → 5`
   - Even: `2 → 4`

4. **Connect Odd and Even Lists**:

   - Update `odd->next = evenHead`:
     - Connects the last odd node (`5`) to the even list (`2`).

   **Final List**:
   `1 → 3 → 5 → 2 → 4`

#### Output:

`[1, 3, 5, 2, 4]`

---

### Key Points:

- **Time Complexity**: O(N), where N is the number of nodes, as we traverse the list once.
- **Space Complexity**: O(1), as no extra space is used besides pointers.
- **Edge Cases**:
  - Empty list (`head = nullptr`).
  - List with one node (`head = [1]`).
  - List with two nodes (`head = [1, 2]`).

---

This approach efficiently rearranges the list in place without additional memory allocation.
