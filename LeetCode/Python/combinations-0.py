class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        if k == 0 or n == 0 or k > n:
            return [[]]

        first = filter(lambda x: x, self.combine(n - 1, k))
        second = map(lambda x: x + [n], self.combine(n - 1, k - 1))

        return first + second
