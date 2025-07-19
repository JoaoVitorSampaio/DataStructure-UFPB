/*
Implement a function that takes as a parameter a vector of integers (vet) of size and returns how many even numbers are stored in that vector.
*/

#include <stdio.h>

int even_num(int n, int *vec) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i] % 2 == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;

    // read the number of elements
    printf("Enter the size of the vector: ");
    scanf("%d", &n);

    int v[n];

    // read the elements
    for (int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i+1);
        scanf("%d", &v[i]);
    }

    // print the number of even numbers
    printf("The number of even numbers is: %d\n", even_num(n, v));

    return 0;
}