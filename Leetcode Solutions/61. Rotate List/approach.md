# 61. Rotate List

A **simpler approach** to rotating a linked list to the right by `k` places can be achieved in **three steps**:

### **Approach**

1. **Find the length of the linked list**

   - Count the number of nodes and store the last node (tail).

2. **Find the new head after rotation**

   - Since rotating by `k` is the same as rotating by `k % length`, update `k`.
   - Find the new tail node at `length - k - 1` position.

3. **Update links to rotate**
   - Make the new tail's `next` pointer `nullptr`.
   - Point the old tail’s `next` to the old head.
   - The new head is `newTail->next`.
