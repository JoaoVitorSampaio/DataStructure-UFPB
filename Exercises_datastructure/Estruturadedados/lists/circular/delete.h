#ifndef DELETE_H // checks if the header has already been included
#define DELETE_H // if not, define the header

#include "create.h" // for vector, linked list and double linked list

/**
 * @brief Deletes the first element of the vector.
 * @param l A pointer to the vector.
 * @return void 
 */
void delete_begin_vector(struct vector *L);

/**
 * @brief Deletes the middle element of the vector.
 * @param l A pointer to the vector.
 * @return void 
 */
void delete_middle_vector(struct vector *l);

/**
 * @brief Deletes the last element of the vector.
 * @param l A pointer to the vector.
 * @return void 
 */
void delete_end_vector(struct vector *l);

/**
 * @brief Deletes the first element of the linked list.
 * @param l A pointer to the head of the linked list.
 * @return void 
 */
void delete_begin_linked_list(struct node **l);

/**
 * @brief Deletes the middle element of the linked list.
 * @param l A pointer to the head of the linked list.
 * @return void 
 */
void delete_middle_linked_list(struct node **l);

/**
 * @brief Deletes the last element of the linked list.
 * @param l A pointer to the head of the linked list.
 * @return void 
 */
void delete_end_linked_list(struct node **l);

/**
 * @brief Deletes the first element of the double linked list.
 * @param l A pointer to the double linked list.
 * @return void 
 */
void delete_begin_double_linked_list(struct list **l);

/**
 * @brief Deletes the middle element of the double linked list.
 * @param l A pointer to the double linked list.
 * @return void 
 */
void delete_middle_double_linked_list(struct list **l);

/**
 * @brief Deletes the last element of the double linked list.
 * @param l A pointer to the double linked list.
 * @return void 
 */
void delete_end_double_linked_list(struct list **l);

#endif // end of the header guard
