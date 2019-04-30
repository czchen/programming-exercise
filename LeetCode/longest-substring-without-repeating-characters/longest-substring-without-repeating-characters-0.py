class Solution(object):
    def get_longest(self, x, y):
        if len(x) > len(y):
            return x
        return y

    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        ans = ""
        curr = ""

        for c in s:
            if c in curr:
                ans = self.get_longest(ans, curr)
                curr = curr[curr.find(c)+1:]
            curr += c

        return len(self.get_longest(ans, curr))
