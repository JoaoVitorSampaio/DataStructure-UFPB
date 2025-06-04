/* Observe a lista ordenada abaixo e escreva todas as linhas de código necessárias
 para inserir o valor 18. Declare todas as variáveis que julgar necessárias.
 Suponha que a lista está implementada utilizando vetor estático.
 [3, 5, 8, 9, 15, 17, 21, 34, 60, 99,  ]
*/

/*
List with ordered elements
*/

#include <stdio.h>

#define T 11 // size of the array

struct list {
 int vector[T];
 int ctr;
};

void create(struct list *l) {
 l->ctr = -1;
}

void insert(struct list *l, int value) {
 if (l->ctr == T - 1) {
  printf("List is full\n");
  return;
 }

 int i;
 for (i = 0; i <= l->ctr; i++) {
  if (value < l->vector[i]) {
   break;
  }
 }
 for (int j = l->ctr; j >= i; j--) {
  l->vector[j + 1] = l->vector[j];
 }
 l->vector[i] = value;
 l->ctr++;
}

void print(struct list l) {
 for (int i = 0; i <= l.ctr; i++) {
  printf("%d ", l.vector[i]);
 }
 printf("\n");
}

int main() {
 struct list l;

 create(&l);

 insert(&l, 3);
 insert(&l, 5);
 insert(&l, 8);
 insert(&l, 9);
 insert(&l, 15);
 insert(&l, 17);
 insert(&l, 21);
 insert(&l, 34);
 insert(&l, 60);
 insert(&l, 99);
 insert(&l, 18);

 print(l);

 return 0;
}