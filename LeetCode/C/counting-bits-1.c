/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

static const struct {
    int shift;
    int mask;
} TABLE[] = {
    { 1, 0x55555555, },
    { 2, 0x33333333, },
    { 4, 0x0f0f0f0f, },
    { 8, 0x00ff00ff, },
    { 16, 0x0000ffff, },
};

int countBitsInInt(int num) {
    for (int i = 0; i < sizeof(TABLE) / sizeof(TABLE[0]); ++i) {
        num = ((num >> TABLE[i].shift) & TABLE[i].mask) + (num & TABLE[i].mask);
    }

    return num;
}

int* countBits(int num, int* returnSize) {
    int *ret = calloc(num + 1, sizeof(*ret));
    if (!ret) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i <= num; ++i) {
        ret[i] = countBitsInInt(i);
    }

    *returnSize = num + 1;
    return ret;
}
