#ifndef CREATE_H // checks if the header has already been included
#define CREATE_H // if not, define the header

#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

#define SIZE 3 // size of the vector

/**
 * @brief Defines the structure for a queue in a vector.
 * @param n The number of elements in the vector.
 * @param start The index of the first element in the vector.
 * @param data The data stored in the vector.
 */
typedef struct queue Queue;

/**
 * @brief Initializes the queue to be empty.
 * @return A pointer to the queue.
 */
Queue *create_queue(void);

/**
 * @brief Checks if the queue is empty.
 * @param q A pointer to the queue.
 * @return int 1 if the queue is empty, 0 otherwise.
 */
int queue_empty(Queue *q);

/**
 * @brief Inserts an element at the end of the queue.
 * @param q A pointer to the queue.
 * @param x The element to be inserted.
 * @return void
 */
void insert_queue(Queue *q, float x); 

/**
 * @brief Removes an element from the front of the queue.
 * @param q A pointer to the queue.
 * @return The element removed.
 */
float remove_queue(Queue *q);

/**
 * @brief Clears the queue.
 * @param q A pointer to the queue.
 * @return void
 */
void clear_queue(Queue *q);

#endif // end of the header guard