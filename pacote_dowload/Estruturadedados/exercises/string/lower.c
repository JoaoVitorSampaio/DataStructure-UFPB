/*
Implement a function that takes a string as a parameter and changes the occurrences of longer characters to shorter ones.
*/

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

char *lower(const char *str1) {
    char *str2 = malloc(strlen(str1) + 1); // allocate memory for the new string

    if (str2 == NULL) {
        return NULL; // return NULL if memory allocation fails
    }

    strcpy(str2, str1); // copy the string to the new string

    for (int i = 0; i < strlen(str2); i++) {
        if (str2[i] >= 'A' && str2[i] <= 'Z') {
            str2[i] = str2[i] + 32;
        }
    }

    return str2; // return the lowercase string
}

int main() {
    char str[MAX];

    // get the string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // call the function to convert the string to lowercase
    char *lower_str = lower(str);

    if (lower_str != NULL) {
        printf("The string in lowercase is: %s", lower(str));
        free(lower_str); // free the allocated memory
    }
    else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}