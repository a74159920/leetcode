#include <deque>
class Solution {
public:
    string longestPalindrome(string s) {
        deque<char> deq;
        int len = s.length();
        string output;
        int currentLen = 0, maxLen = 0, lptr = 0, rptr = 0;
        for (int i=0; i<len; i++){
            for (int y=0; y<2; y++){
                deq.push_back(s[i]);
                currentLen = 1;
                lptr = i;
                rptr = i;
                if (y == 1){
                    if ((i+1) <= (len-1)){
                        if (s[i] == s[i+1]){
                            deq.push_back(s[i]);
                            currentLen = 2;
                            rptr++;
                        }
                    }
                    else
                        break;
                }
                while ((--lptr >= 0) && (++rptr <= (len-1)))
                {
                    if (s[lptr] == s[rptr]){
                        currentLen += 2;
                        deq.push_front(s[lptr]);
                        deq.push_back(s[rptr]);
                    }
                    else 
                        break;
                }
                if (currentLen > maxLen){
                    maxLen = currentLen;
                    output.clear();
                    while (!deq.empty()){
                        output += deq.front();
                        deq.pop_front();
                    }

                }
                deq.clear();
            }
        }
        return output;
    }
};