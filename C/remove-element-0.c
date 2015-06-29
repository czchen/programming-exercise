int swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int removeElement(int* nums, int numsSize, int val) {
   int pos = 0;

   while (pos < numsSize) {
       if (nums[pos] == val) {
           --numsSize;
           swap(&nums[pos], &nums[numsSize]);
       } else {
           ++pos;
       }
   }

   return numsSize;
}
