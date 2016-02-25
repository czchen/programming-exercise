class Solution(object):
    _memorization = {}

    def getAmount(self, coins, amount):
        if amount == 0:
            return 0

        if not coins:
            return -1

        key = (tuple(coins), amount)
        if key in self._memorization:
            return self._memorization[key]

        ans = []

        ans.append(self.getAmount(coins[:-1], amount))

        if coins[-1] <= amount:
            x = self.getAmount(coins, amount - coins[-1])
            if x != -1:
                ans.append(x + 1)

        ans = max(ans)

        self._memorization[key] = ans

        return ans

    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """

        coins = sorted(coins)

        return self.getAmount(coins, amount)
