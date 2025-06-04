/*
Allocate memory for N integers using malloc.
Initialize the array with values 0 to N-1.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {
    int *p; // pointer to int
    int i;

    p = (int *) malloc(N *sizeof(int)); // allocate memory for N integers
    for (i = 0; i < N; i++) {
        p[i] = i; // initialize array
    }

    for (i = 0; i < N; i++) {
        printf("%d\t", p[i]); // print array
    }
    printf("\n");

    return 0;
}