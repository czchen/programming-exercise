class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums = nums1 + nums2
        nums = sorted(nums)
        nums_len = len(nums)

        if nums_len % 2 == 0:
            return float(nums[nums_len / 2] + nums[nums_len / 2 - 1]) / 2
        return nums[nums_len / 2]
