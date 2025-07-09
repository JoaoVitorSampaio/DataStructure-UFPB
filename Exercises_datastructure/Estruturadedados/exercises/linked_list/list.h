#ifndef LIST_H // checks if the header has already been included
#define LIST_H // if not, define the header

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Defines the structure for a node in the linked list.
 * @param data The data stored in the node.
 * @param next A pointer to the next node.
 */
struct list {
    int data;
    struct list *next;
};

/**
 * @brief Initializes the linked list to be empty. 
 * @param l A double pointer to the head of the linked list.
 * @return void
 */
void create(struct list **l);

/**
 * @brief Checks if the list is empty
 * @param  A pointer to the head of the linked list.
 * @return int Returns 1 if the list is empty, 0 otherwise. * 
 */
int is_empty(struct list *l);

/**
 * @brief Inserts a node at the end of the list
 * @param l A double pointer to the head of the linked list.
 * @return void
 */
void insert_end(struct list **l);

/**
 * @brief Removes a node from the end of the list
 * @param l A double pointer to the head of the linked list.
 * @return void
 */
void remove_end(struct list **l);

/**
 * @brief Displays the list
 * @param l A pointer to the head of the linked list.
 * @return void
 */
void display(struct list *l);

#endif // end of the header guard