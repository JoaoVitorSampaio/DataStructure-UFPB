/*
Implement a TAD, minimizing the memory space used, to represent an upper triangular matrix.
In an upper triangular matrix, all elements below the diagonal have zero value.
*/

// libraries
#include <stdio.h>
#include <stdlib.h>

// upper triangular matrix structure
typedef struct {
    int *data;
    int size;
} upper_triangular_matrix;

// functions
void create(upper_triangular_matrix *m, int size) {
    m->size = size;
    m->data = (int *) malloc(size * (size + 1) / 2 * sizeof(int));
}

void set(upper_triangular_matrix *m, int i, int j, int value) {
    if (i <= j) {
        m->data[i * (2 * m->size - i + 1) / 2 + j - i] = value;
    }
}

int get(upper_triangular_matrix *m, int i, int j) {
    if (i <= j) {
        return m->data[i * (2 * m->size - i + 1) / 2 + j - i];
    }
    return 0;
}

void print(upper_triangular_matrix *m) {
    for (int i = 0; i < m->size; i++) {
        for (int j = 0; j < m->size; j++) {
            printf ("%d ", get(m, i, j));
        }
        printf("\n");
    }
}

int main() {
    upper_triangular_matrix m;

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
    print(&m);

    return 0;
}