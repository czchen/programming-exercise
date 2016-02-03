double myPow(double x, int n) {
    if (n == 0) {
        return 1;
    }

    long long n1 = n;
    int is_negative = 0;
    if (n1 < 0) {
        n1 = -n1;
        is_negative = 1;
    }

    double ret = 1;
    double base = x;

    for (; n1; n1 >>= 1, base *= base) {
        if (n1 % 2) {
            ret *= base;
        }
    }

    if (is_negative) {
        ret = 1 / ret;
    }

    return ret;
}
