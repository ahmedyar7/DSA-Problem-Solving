class Solution {
 public:
  bool isAnagram(string s, string t) {
    // If the lengths of the strings are different, they cannot be anagrams
    if (s.length() != t.length()) return false;

    // Create a hashmap to store the frequency of each character in string s
    unordered_map<char, int> hashmap;

    // Count the characters in string s
    for (char c : s) {
      hashmap[c]++;
    }

    // Subtract the character counts using string t
    for (char c : t) {
      if (hashmap.find(c) == hashmap.end() || hashmap[c] == 0) {
        return false;
      }
      hashmap[c]--;
    }

    // If all counts are zero, then s and t are anagrams
    return true;
  }
};