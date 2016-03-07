class Solution {
public:
    string convert(string s, int numRows) {
        //search patterns
        //0 ~ row-1 ~ 2*(row-1) ~ ...
        int length = s.length();
        if(length <= 1 || numRows == 1) return s;
        
        char result[1000];
        int index = 0;
        
        for(int i = 0; i < numRows; ++i) {
            if(i == 0 || i == numRows - 1) { // The first and the last row
                int pos = i;
                while(pos < length) {
                    result[index++] = s[pos];
                    pos += 2 * (numRows - 1);
                }
            }
            else { // else
                int pos = i;
                while(true) {
                    if(pos >= length) break;
                    result[index++] = s[pos];
                    pos += 2 * (numRows - 1 - i);
                    if(pos >= length) break;
                    result[index++] = s[pos];
                    pos += 2 * i;
                }
            }
        }
        
        result[index] = '\0';
        
        return result;
    }
};