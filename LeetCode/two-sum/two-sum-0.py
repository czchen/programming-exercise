class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        map_ = {}

        for i in range(len(nums)):
            map_[target - nums[i]] = i

        for i in range(len(nums)):
            j = map_.get(nums[i])
            if j is not None and i != j:
                return [i, j]
