int reverse(int x) {
    int is_negative = 0;
    if (x < 0) {
        is_negative = 1;
        x = -x;
    }

    int ans = 0;

    while (x) {
        if (ans > INT_MAX / 10) {  // overflow
            return 0;
        }
        ans *= 10;

        int add = x % 10;
        if (INT_MAX - ans < add) {  // overflow
            return 0;
        }
        ans += add;

        x /= 10;
    }


    if (is_negative) {
        ans = -ans;
    }

    return ans;
}
