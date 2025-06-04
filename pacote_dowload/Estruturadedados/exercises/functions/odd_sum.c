/*
Implement a function that returns the sum of the first n odd natural numbers.
*/

#include <stdio.h>

int odd_sum(int n) {
    int sum = 0;

    if (n < 0) {
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        sum += 2 * i - 1;
    }

    return sum;
}

int main() {
    int num;

    // Read the number of odd numbers to add
    printf("Enter the number of odd numbers you want to add: ");
    scanf("%d", &num);

    // Print the sum of the first n odd numbers
    printf("The sum of the first %d odd numbers is: %d\n", num, odd_sum(num));

    return 0;
}