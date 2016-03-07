class Solution {
public:
    int myAtoi(string str) {
        //sign, overflow
        //valid integer
        long long result = 0;
        int sign = 1;
        int length = str.length();
        int i = 0;
        
        while(i < length && isspace(str[i])) i++; //ignore white space
        if(i < length && (str[i] == '+' || str[i] == '-')) { //sign
            if(str[i] == '-') sign = -1;
            i++;
        }
        while(i < length && isdigit(str[i])) { //num, if no digit, result = 0
            result = result * 10 + str[i] - '0';
            if(result > 3E9L) break;
            i++;
        }
        
        result = sign * result;
        if(result > (long long)INT_MAX) result = INT_MAX;
        else if(result < (long long)INT_MIN) result = INT_MIN;
        
        return result;
    }
};