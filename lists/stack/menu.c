/**
 * @file menu.c
 * @brief Menu display function to interact with the user
 * 
 * @author João Vitor Sampaio
 * @version 1.2
 * @date 2025-03-11
 */

 #include "menu.h"

 void menu() {
  printf("\n1. List with vectors");
  printf("\n2. List with linked list");
  printf("\n3. Exit");
  printf("\nOption: ");
}

void display_menu_vector_list() {
  printf("1. Insert at the end\n");
  printf("2. Remove from the end\n");
  printf("3. Consult\n");
  printf("4. Print\n");
  printf("5. Clear\n");
  printf("6. Exit\n");
  printf("Option: ");
}

void display_menu_linked_list() {
  printf("\n1 - Insert start");
  printf("\n2 - Delete start");
  printf("\n3 - Consult");
  printf("\n4 - Print");
  printf("\n5 - Clear");
  printf("\n6 - Exit");
  printf("\nOption: ");
}

