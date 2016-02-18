class Solution {
public:
    void find_best(int& maxLength, int& bstart, int j, int k) {
        //palindrome [start, end]
        int start = j + 1, end = k - 1;
        
        if(end - start + 1 > maxLength) {
            maxLength = end - start + 1;
            bstart = start;
        }
    }
    
    string longestPalindrome(string s) {
        int length = s.length();
        if(length <= 1) return s;
        
        int maxLength = 0;
        int bstart = 0; //best start
        
        //palindrome with odd char
        for(int i = 0; i < length; ++i) {
            int j, k;
            for(j = i-1, k = i+1; j >= 0 && k < length; --j, ++k) {
                if(s[j] != s[k]) break;
            }
            find_best(maxLength, bstart, j, k);
        }
        
        //palindrome with even char
        for(int i = 0; i < length; ++i) {
            int j, k;
            for(j = i-1, k = i; j >= 0 && k < length; --j, ++k) {
                if(s[j] != s[k]) break;
            }
            find_best(maxLength, bstart, j, k);
        }
        
        return s.substr(bstart, maxLength);
    }
};