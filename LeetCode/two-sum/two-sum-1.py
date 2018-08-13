class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        table = {}
        for i in range(len(nums)):
            needed = target - nums[i]
            if needed in table and table[needed] != i:
                return [table[needed], i]
            table[nums[i]] = i
