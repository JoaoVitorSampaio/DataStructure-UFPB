/*
Implement a function that takes a string as a parameter and returns the number of vowels in that string as a result.
*/

// libraries
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int count_vowels(const char *str) {
    int count = 0;

    while (*str) {
        char c = tolower(*str);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
        str++;
    }

    return count;
}

int main() {
    char test_str[MAX];

    // test
    printf("Enter a string: ");
    fgets(test_str, sizeof(test_str), stdin);

    printf("Number of vowels: %d\n", count_vowels(test_str));

    return 0;
}