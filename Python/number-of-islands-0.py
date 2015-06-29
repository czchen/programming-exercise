class Solution:
    # @param {character[][]} grid
    # @return {integer}
    def find_group_leader(self, group, i):
        ans = i
        while group[ans] != ans:
            ans = group[ans]
        return ans

    def numIslands(self, grid):
        if len(grid) == 0:
            return 0

        num_island = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (grid[i][j] == '1'):
                    num_island += 1
                    grid[i][j] = num_island
                else:
                    grid[i][j] = 0

        group = [i for i in range(num_island+1)]

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    if i > 0 and grid[i-1][j]:
                        group[self.find_group_leader(group, grid[i][j])] = self.find_group_leader(group, grid[i-1][j])

                    if j > 0 and grid[i][j-1]:
                        group[self.find_group_leader(group, grid[i][j])] = self.find_group_leader(group, grid[i][j-1])

        num_island = 0
        for i in range(1, len(group)):
            if group[i] == i:
                num_island += 1

        return num_island
