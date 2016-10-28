void sortColors(int A[], int n) {
    int count[3] = { 0 };

    for (int i = 0; i < n; ++i) {
        ++count[A[i]];
    }

    for (int i = 0, color = 0; color < 3; ++color) {
        for (int j = 0; j < count[color]; ++j, ++i) {
            A[i] = color;
        }
    }
}
