int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return numsSize;
    }

    int removed = 0;

    for (int i = numsSize - 1; i > 0; --i) {
       if (nums[i - 1] == nums[i]) {
           memmove(&nums[i - 1], &nums[i], (numsSize - i) * sizeof(nums[0]));
           ++removed;
       }
    }

    return numsSize - removed;
}
