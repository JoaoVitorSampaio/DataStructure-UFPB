/*
Consider the existence of an abstract type Queue of real numbers, whose interface is defined in the file queue.h as follows:

typedef struct queue Queue;
Queue* create_queue(void);
void insert_queue(Queue* q, float v);
float remove_queue(Queue* q);
int queue_empty(Queue* q);
void clear_empty(Queue* q);

Without knowing the internal representation of this abstract type and using only the functions declared in the interface file, implement a function that receives three queues, fores, f1 and f2, and alternately transfers the elements of f1 and f2 to fores.
Note that, at the end of this function, queues f1 and f2 will be empty, and queue f_res will contain all the values ​​originally in f1 and f2 (initially f_res may or may not be empty). 
This function must obey the prototype:
void combines_queues(Queue* q_res, Queue* q1, Queue* q2);
*/

#include "queue.h" // include the queue header file

// Define the structure for the queue
typedef struct queue {
    int n;      // Number of elements in the queue
    int start;  // Index of the first element in the queue
    int size;   // Total capacity of the queue
    float *data; // Dynamic array to store the data
} Queue;

// Function to create a queue with the specified capacity
Queue *create_queue(void) {
    Queue *q = (Queue *)malloc(sizeof(Queue));  // Allocate memory for the queue
    q->n = 0;  // Initialize the number of elements in the queue
    q->start = 0;  // Initialize the index of the first element in the queue
    q->size = SIZE * 2;  // Set q_res capacity to hold double the size of q1 or q2 (6 elements)
    q->data = (float *)malloc(q->size * sizeof(float)); // Allocate memory for the data array
    return q;  // Return the pointer to the queue
}

// Function to check if the queue is empty
int queue_empty(Queue *q) {
    return q->n == 0;  // Return 1 if the queue is empty, 0 otherwise
}

// Function to insert an element into the queue
void insert_queue(Queue *q, float x) {
    if (q->n == q->size) {  // If the queue is full
        printf("Queue overflow! Cannot insert element.\n");
        exit(1);  // Exit the program on overflow
    }
    q->data[(q->start + q->n) % q->size] = x;  // Insert the element at the end of the queue
    q->n++;  // Increment the number of elements in the queue
}

// Function to remove an element from the queue
float remove_queue(Queue *q) {
    if (queue_empty(q)) {  // If the queue is empty
        printf("Queue underflow! Cannot remove element.\n");
        exit(1);  // Exit the program on underflow
    }
    float value = q->data[q->start];  // Store the value to return
    q->start = (q->start + 1) % q->size;  // Move the start index forward
    q->n--;  // Decrease the number of elements in the queue
    return value;  // Return the removed value
}

// Function to clear the queue and free the allocated memory
void clear_empty(Queue *q) {
    free(q->data);  // Free the memory allocated for the data array
    free(q);  // Free the memory allocated for the queue structure
}

// Function to combine two queues (q1 and q2) alternately into a result queue (q_res)
void combines_queues(Queue *q_res, Queue *q1, Queue *q2) {
    while (!queue_empty(q1) || !queue_empty(q2)) {  // While either queue is not empty
        if (!queue_empty(q1)) {  // If q1 is not empty
            insert_queue(q_res, remove_queue(q1));  // Remove from q1 and insert into q_res
        }
        if (!queue_empty(q2)) {  // If q2 is not empty
            insert_queue(q_res, remove_queue(q2));  // Remove from q2 and insert into q_res
        }
    }
}

int main() {
    // Create the queues with the specified capacities
    Queue* q1 = create_queue();  // q1 with a capacity of SIZE (3)
    Queue* q2 = create_queue();  // q2 with a capacity of SIZE (3)
    Queue* q_res = create_queue();  // q_res with a capacity of SIZE*2 (6)

    // Insert elements into q1 and q2
    insert_queue(q1, 2.1);
    insert_queue(q1, 4.5);
    insert_queue(q1, 1.0);

    insert_queue(q2, 7.2);
    insert_queue(q2, 3.1);
    insert_queue(q2, 9.8);

    printf("Combining queues...\n");

    // Combine q1 and q2 into q_res alternately
    combines_queues(q_res, q1, q2);

    // Print the combined queue
    while (!queue_empty(q_res)) {
        printf("%.1f ", remove_queue(q_res));  // Print each element in q_res
    }
    printf("\n");

    // Free the memory of all the queues
    clear_empty(q_res);
    clear_empty(q1);
    clear_empty(q2);

    return 0;
}