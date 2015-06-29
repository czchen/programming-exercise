class Solution:
    # @param num, a list of integers
    # @return an integer
    def majorityElement(self, num):
        cand = 0
        cnt = 0

        for x in num:
            if cnt == 0:
                cand = x
                cnt += 1
            else:
                if cand == x:
                    cnt += 1
                else:
                    cnt -= 1

        return cand
