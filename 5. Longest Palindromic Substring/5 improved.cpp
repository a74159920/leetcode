#include <iostream>
#include <deque>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1, currentLen = 1;
        int lstart = 0;
        int slength = s.length();
        for (int i=0; i<slength; i++){
            int right = i;
            while (right < slength-1){
                if (s[i] == s[right+1])
                    right++;
                else    
                    break;
            }
            int lptr = i - 1, rptr = right + 1;
            while ((lptr > -1) && (rptr < slength)){
                if (s[lptr] == s[rptr]){
                    lptr--;
                    rptr++;
                }
                else
                    break;
            }
            lptr++;
            rptr--;
            currentLen = rptr - lptr + 1;
            if (currentLen > maxLen){
                maxLen = currentLen;
                lstart = lptr;
            }
        }
        return s.substr(lstart, maxLen);
    }
};

int main()
{
    Solution sol;
    cout << sol.longestPalindrome("babad") << endl;
}