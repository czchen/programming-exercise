int getMinimalHp(int curr, int nextMinimalHP) {
    int hp = nextMinimalHP - curr;
    if (hp <= 0) {
        hp = 1;
    }
    return hp;
}

int min(int x, int y) {
    if (x > y) return y;
    return x;
}

int calculateMinimumHP(int **dungeon, int m, int n) {

    // Use princess location to calculate final HP.
    if (dungeon[m-1][n-1] > 0) {
        dungeon[m-1][n-1] = 1;
    } else {
        dungeon[m-1][n-1] = 1 - dungeon[m-1][n-1];
    }

    for (int x = m - 2; x >= 0; --x) {
        dungeon[x][n-1] = getMinimalHp(dungeon[x][n-1], dungeon[x+1][n-1]);
    }

    for (int y = n - 2; y >= 0; --y) {
        dungeon[m-1][y] = getMinimalHp(dungeon[m-1][y], dungeon[m-1][y+1]);
    }

    for (int x = m - 2; x >= 0; --x) {
        for (int y = n - 2; y >= 0; --y) {
            int nextMinimalHp = min(dungeon[x+1][y], dungeon[x][y+1]);

            dungeon[x][y] = getMinimalHp(dungeon[x][y], nextMinimalHp);
        }
    }

    return dungeon[0][0];
}
