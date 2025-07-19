/**
 * @file list.c
 * @brief Implementation of stack.
 * 
 * @author João Vitor Sampaio
 * @version 3.0
 * @date 2025-03-11 
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
             struct vector *l = malloc(sizeof(struct vector));
             if (l == NULL) {
                 printf("Memory allocation failed!\n");
                 return 1;
             }
 
             create_vector_list(l);
 
             do {
                 display_menu_vector_list();
                 scanf("%d", &opt2);
 
                 switch (opt2) {
                     case 1:
                         push_vector(l);
                         break;
                     case 2:
                         pop_vector(l);
                         break;
                     case 3:
                         search_vector_list(l);
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
             struct node *l = malloc(sizeof(struct node));  
             if (l == NULL) {
                 printf("Memory allocation failed!\n");
                 return 1;
             }
 
             create_linked_list(&l); 
 
             do {
                 display_menu_linked_list();
                 scanf("%d", &opt2);
 
                 switch (opt2) {
                     case 1:
                         push_linked_list(&l);
                         break;
                     case 2:
                         pop_linked_list(&l);
                         break;
                     case 3:
                         search_linked_list(&l);
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
             printf("Exiting program...\n");
             break;
         } 
         else {
             printf("Invalid option\n");
         }
     }
 
     return 0;
 }