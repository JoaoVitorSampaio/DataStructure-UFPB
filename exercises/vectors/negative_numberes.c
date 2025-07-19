/*
Implement a function that takes as a parameter a vector of real numbers (vet) of size n and returns how many negative numbers are stored in that vector.
*/

#include <stdio.h>

int negatives(int *v, int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] < 0) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;

    // read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int v[n];

    // read the elements
    for (int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i+1);
        scanf("%d", &v[i]);
    }

    // print the number of negative numbers
    printf("The number of negative numbers is: %d\n", negatives(v, n));

    return 0;
}