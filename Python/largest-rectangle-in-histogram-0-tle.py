class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """

        ans = 0

        for i in range(len(heights) - 1):
            for j in range(i + 1, len(heights)):
                area = min(heights[i:j + 1]) * (j - 1)
                ans = max(ans, area)

        return ans
