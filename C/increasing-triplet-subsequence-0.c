bool increasingTriplet(int* nums, int numsSize) {
    if (numsSize < 3) {
        return false;
    }

    int smallest_seq_one = nums[0];
    bool has_smallest_seq_two = false;
    int smallest_seq_two = -1;

    for (int i = 1; i < numsSize; ++i) {
        if (has_smallest_seq_two) {
            if (smallest_seq_two < nums[i]) {
                return true;
            }

            if (smallest_seq_one < nums[i]) {
                smallest_seq_two = nums[i];
            } else {
                smallest_seq_one = nums[i];
            }
        } else {
            if (smallest_seq_one < nums[i]) {
                has_smallest_seq_two = true;
                smallest_seq_two = nums[i];
            } else {
                smallest_seq_one = nums[i];
            }
        }
    }

    return false;
}
