class Solution {
public:
    int lens, lenp;
    
    bool search(string& s, string& p, int ss, int pp) {
        if(ss == lens && pp == lenp) {
            return true;
        }
        else if(pp == lenp) { //not fully match
            return false;
        }
        else {
            bool searched = false;
            
            if(pp+1 < lenp && p[pp+1] == '*') {
                searched |= search(s, p, ss, pp+2); //* match zero character
                int tempss = ss;
                while(tempss < lens && !searched) {
                    if(p[pp] == s[tempss] || p[pp] == '.') { //* match one or more characters
                        searched |= search(s, p, tempss+1, pp+2);
                        tempss++;
                    }
                    else { //not match
                        break;
                    }
                }
            }
            else if(s[ss] == p[pp] || p[pp] == '.') { //match specfic/any character
                searched |= search(s, p, ss+1, pp+1);
            }
            else {
                searched |= false;
            }
            
            return searched;
        }
    }
    
    bool isMatch(string s, string p) {
        lens = s.length();
        lenp = p.length();

        return search(s, p, 0, 0);
    }
};