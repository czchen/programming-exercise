import collections


class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """

        if not heights:
            return 0

        Entry = collections.namedtuple('Entry', ['pos', 'height', 'left'])

        ans = 0
        queue = []

        for pos in range(len(heights)):
            if not queue or queue[-1].height < heights[pos]:
                queue.append(Entry(pos=pos, height=heights[pos], left=pos))

            elif heights[pos] <= queue[-1].height:
                while queue and queue[-1].height > heights[pos]:
                    ans = max(ans, queue[-1].height * (pos - queue[-1].left))
                    queue.pop()

                if queue:
                    if queue[-1].height < heights[pos]:
                        queue.append(Entry(pos=pos, height=heights[pos], left=queue[-1].pos + 1))

                    else:
                        queue[-1] = Entry(pos=pos, height=queue[-1].height, left=queue[-1].left)
                else:
                    queue.append(Entry(pos=pos, height=heights[pos], left=0))

        while queue:
            ans = max(ans, queue[-1].height * (len(heights) - queue[-1].left))
            queue.pop()

        return ans
