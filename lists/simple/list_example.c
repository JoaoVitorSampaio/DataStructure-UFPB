#include <stdio.h>

#define T 5 // size of the array

struct list {
    int vector[T];
    int ctr;
};

void create(struct list *l) {
    l->ctr = -1;
}

int sum(struct list *l) {
    int i, sum = 0;
    for (i = 0; i <= l->ctr; i++) {
        sum += l->vector[i];
    }
    return sum;
}

int main() {
    struct list l;
    int i;
    create(&l);
    for (i = 0; i < T; i++) {
        l.vector[i] = i;
        l.ctr++;
    }
    printf("Sum: %d\n", sum(&l));
    return 0;
}