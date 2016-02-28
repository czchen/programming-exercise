class Solution(object):
    def updateDeque(self, deque, entry):
        for i in range(len(deque) - 1, -1, -1):
            if deque[i][1] > entry[1]:
                deque.insert(i + 1, entry)
                deque = deque[:i + 2]
                return deque
        return [entry]

    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """

        if len(nums) == 0:
            return []

        deque = []
        ans = []

        for i in range(0, k):
            deque = self.updateDeque(deque, (i, nums[i]))
        ans.append(deque[0][1])

        for i in range(k, len(nums)):
            deque = self.updateDeque(deque, (i, nums[i]))
            if deque[0][0] <= i - k:
                deque = deque[1:]
            ans.append(deque[0][1])

        return ans
