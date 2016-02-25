int min(int x, int y) {
    if (x > y) return y;
    return x;
}

int maxArea(int* height, int heightSize) {
    int maxArea = 0;
    for (int i = 0; i < heightSize - 1; ++i) {
        for (int j = i + 1; j < heightSize; ++j) {
            int area = (j - i) * min(height[i], height[j]);

            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    return maxArea;
}
