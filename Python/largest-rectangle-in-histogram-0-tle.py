import collections

class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """

        if not heights:
            return 0

        Entry = collections.namedtuple('Entry', ['pos', 'height'])

        ans = heights[0]
        queue = []
        queue.append(Entry(pos=0, height=heights[0]))

        for pos in range(1, len(heights)):
            if heights[pos] > queue[-1].height:
                queue.append(Entry(pos=pos, height=heights[pos]))
            elif heights[pos] < queue[-1].height:
                for i in range(len(queue)):
                    if queue[i].height > heights[pos]:
                        queue[i] = Entry(pos=queue[i].pos, height=heights[pos])
                        queue = queue[:i + 1]
                        break

            for entry in queue:
                ans = max(ans, (pos - entry.pos + 1) * entry.height)

        return ans
