int min(int x, int y) {
    if (x > y) return y;
    return x;
}

int max(int x, int y) {
    if (x > y) return x;
    return y;
}

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;

    int maxArea = 0;

    while (left < right) {
        maxArea = max(maxArea, (right - left) * min(height[left], height[right]));

        int diff = height[left] - height[right];
        if (diff < 0) {
            ++left;

        } else if (diff > 0) {
            --right;

        } else {
            ++left;
            --right;
        }
    }

    return maxArea;
}
