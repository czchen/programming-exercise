class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        grouped = {}

        strs = sorted(strs)

        for s in strs:
            anagram_signature = ''.join(sorted(s))
            if anagram_signature not in grouped:
                grouped[anagram_signature] = []
            grouped[anagram_signature].append(s)

        ret = []

        for anagram_signature in grouped.keys():
            ret.append(grouped[anagram_signature])

        return ret
