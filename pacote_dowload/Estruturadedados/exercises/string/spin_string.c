/*
Implement a function that takes a string as a parameter and shifts its characters one position to the right.
For example, the string “home" would be changed to “ehom”.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

char *spin_string(const char *str1) {
    char *str2 = malloc(strlen(str1) + 1); // allocate memory for the new string

    if (str2 == NULL) {
        return NULL; // return NULL if memory allocation fails
    }

    strcpy(str2, str1); // copy the string to the new string

    int len = strlen(str2); // get the length of the string

    // remove the newline character from the string
    if (str2[len - 1] == '\n') {
        str2[len - 1] = '\0';
        len--; // update the length of the string
    }

    if (len <= 1) return NULL; // if the string has 0 or 1 character, there is nothing to do

    char last = str2[len - 1]; // save the last character

    // shift the characters one position to the right
    for (int i = len - 1; i > 0; i--) {
        str2[i] = str2[i - 1];
    }

    str2[0] = last; // move the last character to the first position
}

int main() {
    char str[MAX];

    // get the string from the user
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading the string\n");
        return 1;
    }

    // call the function to convert the string
    char *new_str = spin_string(str);

    if (new_str != NULL) {
        printf("The new string is: %s", new_str);
        free(new_str); // free the allocated memory
    }
    else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}