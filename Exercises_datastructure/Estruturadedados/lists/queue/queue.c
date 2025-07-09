/**
 * @file queue.c
 * @brief Implementation of queue.
 * 
 * @author João Vitor Sampaio
 * @version 1.0
 * @date 2025-03-18 
 */

 #include "create.h" 
 #include "insert.h"
 #include "delete.h"
 #include "route.h"
 #include "menu.h"
 
 int main() {
     int opt1, opt2;
 
     while (1) {
         menu();
         scanf("%d", &opt1);
 
         if (opt1 == 1) { 
             struct vector *l;
 
             create_vector_list(&l);
 
             do {
                 display_menu_vector_list();
                 scanf("%d", &opt2);
 
                 switch (opt2) {
                     case 1: {
                         int value;
                         printf("Enter the value to be inserted: ");
                         scanf("%d", &value);
                         insert_vector(l, value);
                         break;
                     }
                     case 2:
                         printf("Deleted value: %d\n", remove_vector(l));
                         break;
                     case 3:
                         printf("First: %d\n", consult_vector_list(l));
                         break;
                     case 4:
                         print_vector_list(l);
                         break;
                     case 5:
                         clean_vector_list(l);
                         break;
                     case 6:
                         printf("Exiting vector list menu...\n");
                         break;
                     default:
                         printf("Invalid option\n");
                         break;
                 }
             } while (opt2 != 6);
 
             free(l);
         } 
         else if (opt1 == 2) { 
             struct queue *l;
 
             create_linked_list(&l); 
 
             do {
                 display_menu_linked_list();
                 scanf("%d", &opt2);
 
                 switch (opt2) {
                     case 1: {
                         int value;
                         printf("Enter the value to be inserted: ");
                         scanf("%d", &value);
                         insert_linked_list(&l, value);
                         break;
                     }
                     case 2:
                         printf("Deleted value: %d\n", remove_linked_list(l));
                         break;
                     case 3:
                         printf("First: %d\n", consult_linked_list(l));
                         break;
                     case 4:
                         print_linked_list(l);
                         break;
                     case 5:
                         clean_linked_list(&l);
                         break;
                     case 6:
                         printf("Exiting linked list menu...\n");
                         break;
                     default:
                         printf("Invalid option\n");
                         break;
                 }
             } while (opt2 != 6);
         } 
         else if (opt1 == 3) { 
             struct dqueue *l;
 
             create_doubly_linked_list(&l); 
 
             do {
                 display_menu_doubly_linked_list();
                 scanf("%d", &opt2);
 
                 switch (opt2) {
                     case 1: {
                         int value;
                         printf("Enter the value to be inserted: ");
                         scanf("%d", &value);
                         insert_doubly_linked_list(&l, value);
                         break;
                     }
                     case 2:
                         printf("Deleted value: %d\n", remove_doubly_linked_list(l));
                         break;
                     case 3:
                         printf("First: %d\n", consult_doubly_linked_list(l));
                         break;
                     case 4:
                         print_doubly_linked_list(l);
                         break;
                     case 5:
                         clean_doubly_linked_list(&l);
                         break;
                     case 6:
                         printf("Exiting linked list menu...\n");
                         break;
                     default:
                         printf("Invalid option\n");
                         break;
                 }
             } while (opt2 != 6);
         } 
         else if (opt1 == 4) {
             printf("Exiting program...\n");
             break;
         }
         else {
             printf("Invalid option\n");
         }
     }
 
     return 0;
 }
  