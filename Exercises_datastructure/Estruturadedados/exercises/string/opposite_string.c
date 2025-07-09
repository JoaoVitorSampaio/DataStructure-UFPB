
/*
Implement a function that takes a string as a parameter and replaces the occurrences of a letter with its opposite in the alphabet, that is, az, by, cx, etc.
Characters other than letters must remain unchanged.
*/

#include <stdio.h>
#include <string.h>

#define MAX 101

void opposite_string(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + ('z' - str[i]);
        }
        else if ((str[i] >= 'A' && str[i] <= 'Z')) {
            str[i] = 'A' + ('Z' - str[i]);
        }
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    if (fgets(str, MAX, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    opposite_string(str);

    printf("The new string is: %s\n", str);

    return 0;
}
