/**
 * @file delete.c
 * @brief Implementation of the functions to delete elements in a linked list.
 * 
 * @author João Vitor Sampaio
 * @version 1.0
 * @date 2025-02-25
 */

#include "delete.h" // Include the header file with the function prototypes

// deletes the first element of the list
void delete_start(struct list **l) {
    struct node *aux;
    aux = (*l)->begin; // Creates a temporary node to store the first element

    if (!is_empty(l)) { // Checks if the list is not empty
        if ((*l)->begin == (*l)->end) { // Checks if there is only one element in the list
            (*l)->begin = NULL; // Sets the beginning of the list to NULL
            (*l)->end = NULL; // Sets the end of the list to NULL
        } 
        else {
            // update the head of the list
            (*l)->begin = aux->next; // Sets the beginning of the list to the next element
            (*l)->begin->prev = NULL; // Sets the previous node of the new beginning to NULL
        }

        free(aux); // Frees the memory allocated for the first element
    }
}

// delete a node in the middle of the list
void delete_middle(struct list **l) {
  struct node *aux;
  aux = (*l)->begin; // get the first element of the list

  int pos;
  printf("Enter the position to delete: ");
  scanf("%d", &pos); // read the position to delete the data

  int i = 0;
  while (i < pos) {
      aux = aux->next;
      i++;
  }

  if (!(is_empty(l))) {
      // if the node to be deleted is the first element
      if (aux == (*l)->begin) {
          delete_start(l);
      }
      // if the node to be deleted is the last element
      else if (aux == (*l)->end) {
          delete_end(l);
      }
      else {
          // update the pointers of the previous and next nodes
          aux->prev->next = aux->next;
          aux->next->prev = aux->prev;
          free(aux); // free the memory allocated for the node
      }
  }
}

// deletes the last element of the list
void delete_end(struct list **l) {
  struct node *aux;
  aux = (*l)->end; // get the last element of the list

  if (!(is_empty(l))) {
      // if the list has only one element
      if ((*l)->begin == (*l)->end) {
          (*l)->begin = NULL;
          (*l)->end = NULL;
      }
      else {
          // update the end of the list
          (*l)->end = aux->prev;
          (*l)->end->next = NULL;
      }
      free(aux); // free the memory allocated for the node
  }
}
