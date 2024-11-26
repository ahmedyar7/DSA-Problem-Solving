# [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/description/)

The `isAnagram` function checks if two strings `s` and `t` are anagrams by comparing their character frequencies.

1. **Length Check:** If the strings have different lengths, return `false`.
2. **Character Counting:** Count the frequency of each character in `s` using a hashmap.
3. **Frequency Comparison:** For each character in `t`, decrement its count in the hashmap. If a character isn't found or its count is zero, return `false`.
4. **Final Check:** If all counts are zero, return `true`, indicating the strings are anagrams.

### **Dry Run:**

For `s = "anagram"` and `t = "nagaram"`, the function:

- Counts characters in `s`: `{ 'a': 3, 'n': 1, 'g': 1, 'r': 1, 'm': 1 }`
- Subtracts frequencies using `t`:
  - After processing `t`, all counts are zero, so the function returns `true`.

### **Conclusion:**

The function returns `true` because the strings are anagrams.
