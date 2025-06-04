/*
Allocate memory for a 2D array using malloc
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {
    int **a;
    int i;

    a = (int **) malloc(N * sizeof(int *)); // allocate memory for N pointers to integers
    if (!a) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        a[i] = (int *) malloc(N * sizeof(int)); // allocate memory for N integers
        if (!a[i]) {
            printf("Memory allocation failed\n");
            for (i = i - 1; i >= 0; i--) {
                free(a[i]);
            }
            return 1;           
        }
    }

    // fill the array with some values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = (i+1) * (j+1);
        }
    }

    // print the array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}