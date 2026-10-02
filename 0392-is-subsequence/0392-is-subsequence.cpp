class Solution {
public:
        bool isSubsequence(string s, string t) {
    // Initialize pointer for s
    int i = 0;

    // Traverse through t
    for (int j = 0; j < t.length(); j++) {
        // If we found all characters in s
        if (i == s.length()) {
            return true;
        }
        // If characters match, move pointer in s
        if (s[i] == t[j]) {
            i++;
        }
    }

    // Check if we found all characters
    return i == s.length();
        
    }
};