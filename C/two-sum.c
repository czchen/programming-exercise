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

    for (int i = 0; i < numsSize; ++i) {
        int min = i + 1;
        int max = numsSize;

        while (min < max) {
            int idx = min + (max - min) / 2;
            int sum = array[i].num + array[idx].num;

            if (sum < target) {
                min = idx + 1;
            } else if (sum > target) {
                max = idx;
            } else {
                int *ret = malloc(sizeof(*ret) * 2);

                int x = array[i].index;
                int y = array[idx].index;

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
    }
    return 0;
}
