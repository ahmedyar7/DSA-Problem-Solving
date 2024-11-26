# [160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)

### Approach to the Problem:

The problem requires finding the intersection node of two singly linked lists. The intersection node is where two linked lists meet (i.e., they share the same node in memory). The two lists may or may not intersect, and if they do, the point of intersection is the same for both lists.

Here’s the approach using a **hash map** to detect the intersection:

1. **Traverse the first list (headA):** Store all the nodes in a hash map. The key is the node's address (memory location), and the value is just a marker (like `1`).
2. **Traverse the second list (headB):** For each node in list B, check if it already exists in the hash map (which was populated by list A).
3. **Return the intersection node:** If a node from list B exists in the hash map, it means that node is the intersection point. Return that node.
4. **If no intersection is found:** Return `nullptr`.

### Dry Run Example:

**Given:**

- `headA = 1 -> 2 -> 3 -> 4 -> 5`
- `headB = 6 -> 7 -> 3 -> 4 -> 5`
- The intersection node is `3` (starting from `headA` and `headB`).

### Dry Run:

1. **Initialize:**

   - `hashmap = {}` (empty map).
   - `temp = headA (1 -> 2 -> 3 -> 4 -> 5)`.

2. **Traverse `headA`:**

   - Visit node `1`: Add `1` to the hash map: `hashmap = {1: 1}`.
   - Visit node `2`: Add `2` to the hash map: `hashmap = {1: 1, 2: 1}`.
   - Visit node `3`: Add `3` to the hash map: `hashmap = {1: 1, 2: 1, 3: 1}`.
   - Visit node `4`: Add `4` to the hash map: `hashmap = {1: 1, 2: 1, 3: 1, 4: 1}`.
   - Visit node `5`: Add `5` to the hash map: `hashmap = {1: 1, 2: 1, 3: 1, 4: 1, 5: 1}`.

3. **Move to `headB` and Traverse:**

   - Visit node `6`: It’s not in the hash map, so move to the next node.
   - Visit node `7`: It’s not in the hash map, so move to the next node.
   - Visit node `3`: It **is** in the hash map (`hashmap.find(temp) != hashmap.end()`), so return node `3`.

4. **Return Intersection:**
   - The intersection node is `3`, so the function returns `3`.

### Edge Cases:

1. **No intersection:**
   - If no nodes from `headB` are found in the hash map, return `nullptr`.
2. **Identical lists:**
   - If both lists are identical from the start, the first node (`headA`) itself will be the intersection point.
3. **One list is empty:**
   - If either `headA` or `headB` is `nullptr`, return `nullptr`.

### Time and Space Complexity:

- **Time Complexity:**
  - O(N + M), where N and M are the lengths of the two linked lists (`headA` and `headB`). This is because we traverse both lists once.
- **Space Complexity:**
  - O(N), where N is the number of nodes in `headA` because we store all nodes of `headA` in the hash map.

### Conclusion:

This approach uses extra space to store the nodes of one list, making it efficient in terms of time complexity. However, it uses O(N) space for the hash map, which could be avoided by using other techniques like the two-pointer method.
