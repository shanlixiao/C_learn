class Solution:
    def lengthOfLongestSubstring(self, s):
        length = len(s)
        i = 5
        max = 1
        m = 1
        for i in range(1,len(s)):
            for j in range(m,i + 1):
                for k in range(m-1,j):
                    if s[k] == s[j]:
                        break
                if k < j - 1:
                    if k + 1 - m - 1 > max:
                        max = k + 1 - m - 1
                        m = m + 1
                else:
                    if j + 1 - m - 1 > max:
                        max = j + 1 - m - 1
                print(max)
        return max

string = Solution()
c = string.lengthOfLongestSubstring('abcd')
# print(c)
