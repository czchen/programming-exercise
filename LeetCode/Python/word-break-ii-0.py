class Solution(object):
    def wordBreakInternal(self, s, wordDict):
        if s == '':
            return [[]]

        if s in self._cache:  # memorization
            return self._cache[s]

        ret = []

        for word in wordDict:
            if s.startswith(word):

                def merger(x):
                    ans = [word]
                    ans.extend(x)
                    return ans

                l = list(map(merger, self.wordBreakInternal(s[len(word):], wordDict)))
                ret.extend(l)

        self._cache[s] = ret

        return ret

    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: List[str]
        """

        self._cache = {}

        ret = self.wordBreakInternal(s, wordDict)

        ret = list(map(lambda x: ' '.join(x), ret))

        return ret
