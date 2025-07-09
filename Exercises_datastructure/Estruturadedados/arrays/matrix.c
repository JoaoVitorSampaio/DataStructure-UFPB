/*
Matrix multiplication
*/

#include <stdio.h>

#define N 10

int main() {
    int b[N][N];

    // initialize the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            b[i][j] = (i+1) * (j+1);
    }

    // print the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}