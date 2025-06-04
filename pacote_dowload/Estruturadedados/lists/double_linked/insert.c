/**
 * @file insert.c
 * @brief Implementation of the functions to insert elements in a linked list.
 * 
 * @author João Vitor Sampaio
 * @version 1.0
 * @date 2025-02-24
 */

#include "insert.h" // Include the header file with the function prototypes

// inserts a new element at the beginning of the list
void insert_start(struct list **l) {
  struct node *new;
  create_node(&new); // create a new node

  int n;
  printf("Enter the value to insert: ");
  scanf("%d", &n); // read the data to be inserted

  // insert data into the new node
  new->data = n;

  // if the list is not empty, update the previous pointer of the next node
  if (!(is_empty(l))) {
      new->next = (*l)->begin;
      (*l)->begin->prev = new; 
      // update the head of the list
      (*l)->begin = new;
  }
  else {
      // if the list is empty, update the end pointer
      (*l)->begin = new;
      (*l)->end = new;
  }
}

// inserts a new element in the middle of the list
void insert_middle(struct list **l) {
  struct node *new, *aux;
  create_node(&new); // create a new node
  create_node(&aux); // create a new node

  int n, pos;
  printf("Enter the value to insert: ");
  scanf("%d", &n); // read the data to be inserted
  printf("Enter the position to insert: ");
  scanf("%d", &pos); // read the position to insert the data

  // insert data into the new node
  new->data = n;
  
  int i = 0;
  while (i < pos) {
      aux = aux->next;
      i++;
  }

  if (!(is_empty(l))) {
      new->prev = aux->prev;
      new->next = aux;
      new->prev->next = new;
      new->next->prev = new;
  }
  else {
      // if the list is empty, update the head pointer
      (*l)->begin = new;
      (*l)->end = new;
  }
}

// insert a new element in the end of the list
void insert_end(struct list **l) {
  struct node *new;
  create_node(&new); // create a new node

  int n;
  printf("Enter the value to insert: ");
  scanf("%d", &n); // read the data to be inserted

  // insert data into the new node
  new->data = n;

  // if the list is not empty, update the next pointer of the previous node
  if (!(is_empty(l))) {
      new->prev = (*l)->end;
      (*l)->end->next = new;
      (*l)->end = new;
  }
  else {
      // if the list is empty, update the head pointer
      (*l)->begin = new;
      (*l)->end = new;
  }
}