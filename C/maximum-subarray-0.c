int max(int x, int y) {
    return x > y ? x : y;
}

int maxSubArray(int* nums, int numsSize) {
    int ans = nums[0];
    int curr = nums[0];

    for (int i = 1; i < numsSize; ++i) {
        if (curr < 0) {
            curr = 0;
        }

        curr += nums[i];
        ans = max(ans, curr);
    }

    return ans;
}
