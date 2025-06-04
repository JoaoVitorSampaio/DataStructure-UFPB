/*
Implement a TAD, minimizing the memory space used, to represent a lower triangular matrix.
In this type of matrix, all elements above the diagonal have a value of zero.
*/

// libraries
#include <stdio.h>
#include <stdlib.h>

// lower triangular matrix structure
typedef struct {
    int *data;
    int size;
} lower_triangular_matrix;

// functions
void create(lower_triangular_matrix *m, int size) {
    m->size = size;
    m->data = (int *) malloc(size * (size + 1) / 2 * sizeof(int));
}

void set(lower_triangular_matrix *m, int i, int j, int value) {
    if (i >= j) {
        m->data[i * (i + 1) / 2 + j] = value;
    }
}

int get(lower_triangular_matrix *m, int i, int j) {
    if (i >= j) {
        return m->data[i * (i + 1) / 2 + j];
    }
    return 0;
}

void print(lower_triangular_matrix *m) {
    for (int i = 0; i < m->size; i++) {
        for (int j = 0; j < m->size; j++) {
            printf("%d ", get(m, i, j));
        }
        printf("\n");
    }
}

int main() {
    lower_triangular_matrix m;

    // define the size of the matrix
    printf("Define the size of the matrix: ");
    scanf("%d", &m.size);

    // create the matrix
    create(&m, m.size);

    // set the values of the matrix
    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            int value;
            printf("Enter the value of the element (%d, %d): ", i, j);
            scanf("%d", &value);
            set(&m, i, j, value);
        }
    }

    // print the matrix
    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            printf("%d ", get(&m, i, j));
        }
        printf("\n");
    }

    return 0;
}