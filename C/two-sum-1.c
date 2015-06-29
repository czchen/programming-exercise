/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Array {
    int num;
    int index;
};

int compare(const void *x, const void *y)
{
    const struct Array *xx = (const struct Array *)x;
    const struct Array *yy = (const struct Array *)y;

    return xx->num - yy->num;
}

int* twoSum(int* nums, int numsSize, int target) {
    struct Array *array = malloc(sizeof(*array) * numsSize);
    if (!array) {
        return 0;
    }

    for (int i = 0; i < numsSize; ++i) {
        array[i].num = nums[i];
        array[i].index = i;
    }

    qsort(array, numsSize, sizeof(array[0]), compare);

    int i = 0;
    int j = numsSize - 1;

    while (i < j && i >= 0 && j < numsSize) {
        int sum = array[i].num + array[j].num;

        if (sum < target) {
            ++i;
        } else if (sum > target) {
            --j;
        } else {
            int *ret = malloc(sizeof(*ret) * 2);
            if (!ret) {
                return 0;
            }

            int x = array[i].index;
            int y = array[j].index;

            if (x < y) {
                ret[0] = x + 1;
                ret[1] = y + 1;
            } else {
                ret[0] = y + 1;
                ret[1] = x + 1;
            }

            return ret;
        }
    }

    return 0;
}
