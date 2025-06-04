/*
Implement a function that takes as a parameter a vector of integers (vec) of size 'n and reverses the order of the elements stored in this vector.
*/

#include <stdio.h>

void reverse(int n, int *vec) {
    int temp; // variable to store the value of the element to be swapped

    // vector inversion
    for (int i = 0; i < n/2; i++) {
        temp = vec[i];
        vec[i] = vec[n-i-1];
        vec[n-i-1] = temp;
    }

    // print the reversed vector
    for (int i = 0; i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
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

    // reverse the elements
    reverse(n, v);

    return 0;
}