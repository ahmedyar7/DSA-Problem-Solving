# [82. Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/)

### Problem Setup:

- We have a singly linked list where each node has an integer value.
- The task is to remove duplicate nodes so that each node has a unique value in the list.

### The Code:

1. **Definition of `ListNode`:**
   This is the definition of a node in the linked list with:

   - `val`: stores the value of the node.
   - `next`: points to the next node in the list (or `nullptr` if it's the last node).

2. **Function `deleteDuplicates`:**
   - **Step 1:** If the list is empty (`!head`) or contains only one node (`!head->next`), we return the list as is.
   - **Step 2:** We use an `unordered_set<int>` to track the values that are duplicated.
   - **Step 3:** We perform two passes through the list:
     1. **First pass**: Find all duplicated values by comparing each node with the next.
     2. **Second pass**: Remove nodes with values found in the set of duplicates.

### Dry Run Example:

Given the linked list:  
**1 -> 1 -> 2 -> 3 -> 3**

#### **Step 1: Initial Setup**

- `head`: points to the first node (`1`).
- `duplicates`: an empty set `{}`.
- `current`: points to `head`.

#### **First Pass: Identify Duplicates**

1. **First iteration:**

   - `current` points to node `1`.
   - Compare `current->val` (1) with `current->next->val` (1).
   - They are equal, so add `1` to the `duplicates` set: `{1}`.
   - Move `current` to the next node (`1`).

2. **Second iteration:**

   - `current` points to node `1`.
   - Compare `current->val` (1) with `current->next->val` (2).
   - They are not equal, so no change to the set.
   - Move `current` to the next node (`2`).

3. **Third iteration:**

   - `current` points to node `2`.
   - Compare `current->val` (2) with `current->next->val` (3).
   - They are not equal, so no change to the set.
   - Move `current` to the next node (`3`).

4. **Fourth iteration:**
   - `current` points to node `3`.
   - Compare `current->val` (3) with `current->next->val` (3).
   - They are equal, so add `3` to the `duplicates` set: `{1, 3}`.
   - Move `current` to the next node (`3`).

Now, the `duplicates` set contains `{1, 3}`.

#### **Step 2: Removing Duplicates**

- Initialize a `dummy` node with value `0` and set `dummy.next` to `head` of the list. This simplifies the edge case where the first node is deleted.
- `prev`: points to the `dummy` node.
- `current`: points to the head node.

1. **First iteration:**

   - `current` points to node `1`.
   - Since `1` is in the `duplicates` set, remove it by setting `prev->next` to `current->next` (which points to the next `1`).
   - Delete the node `1` (no longer needed).
   - Move `current` to `prev->next`, which points to node `1`.

2. **Second iteration:**

   - `current` points to node `1` again.
   - Since `1` is in the `duplicates` set, remove it by setting `prev->next` to `current->next` (which points to `2`).
   - Delete the node `1`.
   - Move `current` to `prev->next`, which points to node `2`.

3. **Third iteration:**

   - `current` points to node `2`.
   - Since `2` is not in the `duplicates` set, move the `prev` pointer to the current node (`2`).
   - Move `current` to the next node (`3`).

4. **Fourth iteration:**

   - `current` points to node `3`.
   - Since `3` is in the `duplicates` set, remove it by setting `prev->next` to `current->next` (which points to the next `3`).
   - Delete the node `3`.
   - Move `current` to `prev->next`, which points to node `3`.

5. **Fifth iteration:**
   - `current` points to node `3` again.
   - Since `3` is in the `duplicates` set, remove it by setting `prev->next` to `current->next` (which is `nullptr`).
   - Delete the node `3`.
   - Move `current` to `nullptr`.

#### **Step 3: Return the New Head**

- The new head of the list is `dummy.next`, which points to node `2`.
- The list after removal of duplicates is:  
  **2**

### Final Output:

The linked list after the duplicates are removed is:  
**2**
