class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int p1 = 0, p2 = 0; // [start, end) of substring
        int hash[256]; // occuring index of current character
        memset(hash, -1, sizeof(hash));
        
        int length = s.length();
        int maxLength = 0;
        for(int i = 0; i < length; ++i) {
            int chr = s[i];
            if(hash[chr] >= p1) { // contains dups, p1 needs to shift
                p1 = hash[chr] + 1;
            }
            hash[chr] = i;
            p2 = i + 1;
            maxLength = max(maxLength, p2 - p1);
        }
        
        return maxLength;
    }
};