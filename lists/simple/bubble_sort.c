/*
Bubble sort algorithm with a list
*/

#include <stdio.h>

#define N 5

struct list {
    int value[N];
    int n;
} l;

void print(struct list l) {
    if (l.n == -1) {
        printf("List is empty\n");
        return;
    }
    for (int i = 0; i <= l.n; i++) {
        printf("%d ", l.value[i]);
    }
    printf("\n");
}

int main() {
    struct list l;
    int i, j, aux;

    l.n = -1;
    l.value[0] = 8;
    l.value[1] = 4;
    l.value[2] = 11;
    l.value[3] = 7;
    l.value[4] = 0;
    l.n = 4;

    for (i = 0; i < l.n; i++) {
        for (j = i + 1; j <= l.n; j++) {
            if (l.value[j] < l.value[i]) {
                aux = l.value[i];
                l.value[i] = l.value[j];
                l.value[j] = aux;
            }
        }
    }

    print(l);

    return 0;
}