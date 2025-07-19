/*
Implement one version of a function, following the different strategies discussed for matrix allocation, that determines whether a matrix is ​​square symmetric or not.
*/

// libraries
#include <stdio.h>
#include <stdlib.h>

int is_symmetric(int **matrix, int rows, int cols) {
    if (rows != cols) {
        return 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int rows, cols;

    // read the number of rows and columns
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // allocate memory for the matrix
    int **matrix = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int));
    }

    // read the matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // check if the matrix is symmetric
    if (is_symmetric(matrix, rows, cols)) {
        printf("The matrix is symmetric.\n");
    }
    else {
        printf("The matrix is not symmetric.\n");
    }

    // free the allocated memory
    free(matrix);

    return 0;
}