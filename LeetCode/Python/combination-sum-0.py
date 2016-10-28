import copy

class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()

        print(candidates)

        table = {}
        table[(0, 0)] = [[]]

        for c in range(len(candidates)):
            for t in range(target + 1):
                res = []

                if t >= candidates[c]:
                    for item in table[(t - candidates[c], c)]:
                        item = copy.deepcopy(item)
                        item.append(candidates[c])
                        res.append(item)

                if c > 0:
                    res.extend(table[(t, c - 1)])

                if (t, c) != (0, 0):
                    table[(t, c)] = res

        return table[(target, len(candidates) - 1)]
