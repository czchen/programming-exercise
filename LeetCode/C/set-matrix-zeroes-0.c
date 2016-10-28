void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int *row = calloc(matrixRowSize, sizeof(*row));
    if (!row) {
        return;
    }

    int *column = calloc(matrixColSize, sizeof(*column));
    if (!column) {
        return;
    }

    for (int i = 0; i < matrixRowSize; ++i) {
        for (int j = 0; j < matrixColSize; ++j) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }

    for (int i = 0; i < matrixRowSize; ++i) {
        if (row[i]) {
            for (int j = 0; j < matrixColSize; ++j) {
                matrix[i][j] = 0;
            }
        }
    }


    for (int j = 0; j < matrixColSize; ++j) {
        if (column[j]) {
            for (int i = 0; i < matrixRowSize; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}
