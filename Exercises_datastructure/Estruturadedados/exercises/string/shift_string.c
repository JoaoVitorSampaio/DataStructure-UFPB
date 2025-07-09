/*
Implement a function that takes a string as a parameter and replaces all letters with their successors in the alphabet.
The letter z must be replaced by the letter a (and Z by A).
Characters other than letters must remain unchanged.
*/

// libraries
#include <stdio.h>
#include <string.h>

#define MAX 101

void shift_string(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'z') {
            str[i] = 'a';
            continue;
        }
        if (str[i] == 'Z') {
            str[i] = 'A';
            continue;
        }
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) {
            continue;
        }
        str[i] = str[i] + 1;
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    shift_string(str);

    printf("The new string is: %s", str);

    return 0;
}