/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    int *ret = calloc(num + 1, sizeof(*ret));
    if (!ret) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i <= num; ++i) {
        int x = i;
        int count = 0;

        while (x) {
            count += x % 2;
            x >>= 1;
        }

        ret[i] = count;
    }

    *returnSize = num + 1;
    return ret;
}
