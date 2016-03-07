class Solution {
public:
    int reverse(int x) {
        //case: negative numbers, overflow?
        int sign = 1;
        if(x < 0) {
            x = -x;
            sign = -1;
        }
        
        long long answer = 0;
        while(x > 0) {
            answer = answer * 10 + x % 10;
            x /= 10;
        }
        
        answer = answer * sign;
        if(answer > INT_MAX || answer < INT_MIN) answer = 0;
        
        return answer;
    }
};