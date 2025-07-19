/**
* @file create.c
 * @brief Implementation of the function to create a linked list.
 *
 * @author João Vitor Sampaio
 * @version 1.0
 * @date 2025-02-24
 */

#include "create.h" // include the header file with the function prototypes

// initialize the list to be empty
void create(struct knot **l) {
    *l = NULL;
}

// checks if the list is empty
int is_empty(struct knot *l) {
    return l == NULL;
}

// creates a new knot with the given value