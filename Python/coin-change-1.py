class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """

        ans = [-1 for _ in range(amount + 1)]

        ans[0] = 0

        for i in range(1, amount + 1):
            for coin in coins:
                if i - coin >= 0:
                    cand = ans[i - coin] + 1

                    if ans[i] == -1:
                        ans[i] = cand
                    else:
                        ans[i] = min(cand, ans[i])

        return ans[amount]
