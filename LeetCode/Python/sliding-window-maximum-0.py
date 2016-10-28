class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """

        if len(nums) == 0:
            return []

        ans = []
        for i in range(len(nums) - k + 1):
            ans.append(max(nums[i:i + k]))

        return ans
