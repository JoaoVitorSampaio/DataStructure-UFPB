/*
Returns the factorial of a number, using recursion.
*/

#include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;

    // Get the number from the user
    printf("Enter a number: ");
    scanf("%d", &n);

    // Print the factorial
    printf("The factorial of %d is %d\n", n, factorial(n));

    return 0;
}