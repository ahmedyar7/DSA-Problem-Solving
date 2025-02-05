# 234. Palindrome Linked List

### **Optimized Approach (Two-Pointer + Reversal)**

1. **Find the Middle:** Use **slow** and **fast** pointers; slow stops at the middle.
2. **Reverse the Second Half:** Reverse from `slow->next` (avoid reversing the middle in odd-length lists).
3. **Compare Both Halves:** Check if first and second halves match.
4. **Restore the List (Optional).**

**Time Complexity:** `O(N)`, **Space Complexity:** `O(1)`.  
More efficient than the stack-based approach. 🚀
