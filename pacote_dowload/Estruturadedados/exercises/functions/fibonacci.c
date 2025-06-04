/*
Implement a function that returns the nth term of the Fibonacci series.
The Fibonacci series is given by: 11235 8 13 21..., that is, the first two terms are equal to 1 and each subsequent term is the sum of the two previous terms.
*/

#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num;

    // Get the position from the user
    printf("Enter the position of the Fibonacci sequence term: ");
    scanf("%d", &num);

    // Print the Fibonacci series
    printf("The Fibonacci term at position %d is %d\n", num, fibonacci(num));

    return 0;
}