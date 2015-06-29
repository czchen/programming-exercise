int majorityElement(int* nums, int numsSize) {
    int majority = nums[0];
    int count = 1;

    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] == majority) {
            ++count;
        } else if (count) {
            --count;
        } else {
            majority = nums[i];
            count = 1;
        }
    }

    return majority;
}
