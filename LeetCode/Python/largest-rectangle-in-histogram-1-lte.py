import collections


class Solution(object):
    def _get_largest_rectangle_area(self, heights, sorted_heights, start, end):
        if end == start:
            return 0

        if end - start == 1:
            return heights[start]

        while not (start <= sorted_heights[0].pos < end):
            sorted_heights.pop(0)

        pos = sorted_heights[0].pos
        height = sorted_heights[0].height
        sorted_heights.pop(0)

        left = self._get_largest_rectangle_area(heights, sorted_heights[:], start, pos)
        right = self._get_largest_rectangle_area(heights, sorted_heights[:], pos + 1, end)

        return max(left, right, (end - start) * height)

    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """

        Entry = collections.namedtuple('Entry', ['pos', 'height'])

        sorted_heights = zip([i for i in range(len(heights))], heights)
        sorted_heights = map(lambda x: Entry(pos=x[0], height=x[1]), sorted_heights)
        sorted_heights = sorted(sorted_heights, key=lambda x: x.height)

        return self._get_largest_rectangle_area(heights, sorted_heights, 0, len(heights))
