int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }

    if (n == 2) {
        return 2;
    }

    int previous_2 = 1;
    int previous_1 = 2;
    int current;

    for (int i = 3; i <= n; ++i) {
        current = previous_2 + previous_1;
        previous_2 = previous_1;
        previous_1 = current;
    }

    return current;
}
