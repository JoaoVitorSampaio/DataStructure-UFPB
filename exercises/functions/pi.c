/*
Implement a function that returns an approximation of the value of pi, according to Leibniz's formula.
*/

#include <stdio.h>
#include <math.h>

double pi(int n) {
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += (pow(-1, i)) / (2 * i + 1);
    }

    return 4 * sum;
}

int main() {
    int num;

    // Read input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Print result
    printf("PI: %lf\n", pi(num));

    return 0;
}