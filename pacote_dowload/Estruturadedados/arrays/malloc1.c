/*
Memory allocation with malloc for a 2D array
*/

#include <stdio.h>
#include <stdlib.h>

#define N 9

int main() {
    int **m;
    int i;

    m = (int **)malloc(N * sizeof(int *)); // request memory for N pointers
    if (!m) {
        printf("Memory allocation failed\n");
        return 1;
    }


    for (i = 0; i < N; i++) {
        m[i] = (int *)malloc(N *sizeof(int)); // request memory for N integers
        if (!m[i]) {
            for (i = i - 1; i >= 0; i--) {
                free(m[i]);
            }
            i = N + 1;
        }
    }

    if (i == N) {
        printf("Memory allocation successful\n");
    } 
    else {
        printf("Memory allocation failed\n");
    }

    return 0;
}