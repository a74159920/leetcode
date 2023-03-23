class Solution:
    def longestPalindrome(self, s: str) -> str:
        answer_lptr = 0
        answer_rptr = 0
        max_length = 0
        for i, c in enumerate(s):
            lptr = rptr = i
            while rptr < len(s) - 1 and s[rptr+1] == c:
                rptr += 1
            while lptr > 0 and rptr < len(s) - 1:
                if s[lptr-1]  == s[rptr+1]:
                    lptr -= 1
                    rptr += 1
                else:
                    break
            current_length = rptr - lptr + 1
            if current_length > max_length:
                max_length = current_length
                answer_lptr = lptr
                answer_rptr = rptr

        return s[answer_lptr:answer_rptr+1]
    
s = 'bb'
solve = Solution().longestPalindrome(s)
print(solve)

        