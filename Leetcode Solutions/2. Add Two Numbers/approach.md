# [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/)

### Approach Explanation:

The task is to add two numbers represented by two linked lists where each node contains a single digit. The digits are stored in reverse order, meaning the ones place is at the head of the list.

The idea is to traverse both linked lists simultaneously, adding corresponding digits and keeping track of the carry (if the sum exceeds 9). If one list is longer than the other, we continue the addition until both lists are exhausted. If there is still a carry left at the end, we append a new node with that carry.

### Steps:

1. **Create a dummy node:** This helps simplify the process of managing the head of the resulting linked list.
2. **Initialize a carry variable to 0:** This will hold the carry-over value when the sum of two digits is 10 or greater.
3. **Traverse both lists:**
   - Add corresponding digits from both lists.
   - If one list is shorter, treat the missing value as 0.
4. **Update carry:** If the sum exceeds 9, set carry to 1, otherwise set it to 0.
5. **Append the result:** Create a new node with the current sum modulo 10.
6. **Handle remaining carry:** After the traversal, if there is a carry left, append a node with the carry value.

### Dry Run Example:

**Input:**

- `l1 = 2 -> 4 -> 3` (represents the number 342)
- `l2 = 5 -> 6 -> 4` (represents the number 465)

**Process:**

1. **Initialization:**

   - `dummy = -1`
   - `current = dummy`
   - `temp1 = l1 (2 -> 4 -> 3)`
   - `temp2 = l2 (5 -> 6 -> 4)`
   - `carry = 0`

2. **First Iteration (Adding 2 + 5):**

   - `sum = 2 + 5 + carry = 7`
   - New node: `7 % 10 = 7`
   - `carry = 7 / 10 = 0`
   - Move `current` to the new node `7`.
   - Move `temp1` to `4 -> 3` and `temp2` to `6 -> 4`.

3. **Second Iteration (Adding 4 + 6):**

   - `sum = 4 + 6 + carry = 10`
   - New node: `10 % 10 = 0`
   - `carry = 10 / 10 = 1`
   - Move `current` to the new node `0`.
   - Move `temp1` to `3` and `temp2` to `4`.

4. **Third Iteration (Adding 3 + 4 with carry 1):**

   - `sum = 3 + 4 + carry = 8`
   - New node: `8 % 10 = 8`
   - `carry = 8 / 10 = 0`
   - Move `current` to the new node `8`.
   - Move `temp1` to `nullptr` and `temp2` to `nullptr`.

5. **Final Check for carry:**
   - `carry = 0`, so no extra node is needed.

**Result:**

- The resulting linked list is `7 -> 0 -> 8`, which represents the number 807.

### Summary of Key Operations:

1. **Dummy node:** Simplifies list manipulation.
2. **Traversal:** Traverse both input lists and compute the sum digit by digit.
3. **Carry:** Keep track of carry for each iteration and propagate it to the next sum.
4. **Result:** The result is stored in the linked list formed from the dummy node’s next pointer.

### Final Output:

- The output linked list is `7 -> 0 -> 8`.
