int searchInsert(int* nums, int numsSize, int target) {
    int start = 0;
    int end = numsSize;

    while (start < end) {
        int middle = start + (end - start) / 2;

        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] > target) {
            end = middle;
        } else {
            start = middle + 1;
        }
    }

    return start;
}
