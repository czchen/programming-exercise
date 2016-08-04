class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        max_x = len(board)
        if max_x == 0:
            return

        max_y = len(board[0])
        if max_y == 0:
            return

        def get_live(x, y):
            if x < 0 or x >= max_x or y < 0 or y >= max_y:
                return 0
            return board[x][y] & 1 # Don't forget & 1

        def set_next_live(x, y, val):
            board[x][y] |= val << 1 # Use |= instead of =

        for x in range(max_x):
            for y in range(max_y):
                neighbers_live = (
                    get_live(x - 1, y - 1) +
                    get_live(x - 1, y    ) +
                    get_live(x - 1, y + 1) +
                    get_live(x    , y - 1) +
                    # Don't add get_live(x, y) here
                    get_live(x    , y + 1) +
                    get_live(x + 1, y - 1) +
                    get_live(x + 1, y    ) +
                    get_live(x + 1, y + 1)
                )

                if get_live(x, y):
                    if 2 <= neighbers_live <= 3:
                        set_next_live(x, y, 1)
                    else:
                        set_next_live(x, y, 0)

                else:
                    if neighbers_live == 3:
                        set_next_live(x, y, 1)

        # Don't forget to shift
        for x in range(max_x):
            for y in range(max_y):
                board[x][y] >>= 1
