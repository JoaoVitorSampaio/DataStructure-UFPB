/*
Implement a function to test whether an integer is prime or not.
This function must obey the following prototype and have a return value of 1 if
n is prime and O otherwise.
*/

#include <stdio.h>

int is_prime(int n) {
    if (n < 2) {
        return 0;        // Numbers less than 2 are not prime
    }
    if (n == 2 || n == 3)
        return 1;        // 2 and 3 are prime numbers
    }
    if (n % 2 == 0 || n % 3 == 0)
        return 0;        // Eliminates multiples of 2 and 3
    }

    // Loop to check divisibility for numbers of the form 6k ± 1
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;

    // Get input from the user
    printf("Enter a number: ");
    scanf("%d", &n);

    // Check if the number is prime
    if (is_prime(n)) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}