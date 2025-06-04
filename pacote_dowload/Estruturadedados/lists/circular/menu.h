/**
 * @file menu.c
 * @brief Menu display function to interact with the user
 * 
 * @author João Vitor Sampaio
 * @version 1.0
 * @date 2025-03-01
 */

 #include "create.h"

 void menu() {
     printf("\n1. List with vectors");
     printf("\n2. List with linked list");
     printf("\n3. List with double linked list");
     printf("\n4. Exit");
 }
 
 void display_menu_vector_list() {
     printf("1. Insert at the end\n");
     printf("2. Insert at the beginning\n");
     printf("3. Remove from the end\n");
     printf("4. Remove from the beginning\n");
     printf("5. Consult\n");
     printf("6. Print\n");
     printf("7. Clear\n");
     printf("8. Exit\n");
 }
 
 void display_menu_linked_list() {
     printf("\n1 - Insert start");
     printf("\n2 - Insert middle");
     printf("\n3 - Insert end");
     printf("\n4 - Delete start");
     printf("\n5 - Delete middle");
     printf("\n6 - Delete end");
     printf("\n7 - Clean");
     printf("\n8 - Print");
     printf("\n9 - Search");
     printf("\n10 - Exit");
     printf("\nOption: ");
 }
 
 void display_menu_double_linked_list() {
     printf("\n1 - Insert start");
     printf("\n2 - Insert middle");
     printf("\n3 - Insert end");
     printf("\n4 - Delete start");
     printf("\n5 - Delete middle");
     printf("\n6 - Delete end");
     printf("\n7 - Clean");
     printf("\n8 - Print (begin -> end)");
     printf("\n9 - Print (end -> begin)");
     printf("\n10 - Search");
     printf("\n11 - Exit");
     printf("\nOption: ");
 }