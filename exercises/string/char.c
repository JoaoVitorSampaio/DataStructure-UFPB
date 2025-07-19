/*
Implement a function that takes a string and a character as a parameter and returns as a result the number of occurrences of that character in the string.
*/

#include <stdio.h>
#include <ctype.h>

#define MAX 101

int count_char(const char *str, char c) {
    int count = 0;

    // normalize c
    c = tolower(c);

    while (*str) {
        if (tolower(*str) == c) {
            count++;
        }
        str++;
    }

    return count;
}

int main() {
    char str[MAX], c;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter a char: ");
    scanf("%c", &c);

    printf("Number of occurrences of that %c: %d\n", c, count_char(str, c));

    return 0;
}