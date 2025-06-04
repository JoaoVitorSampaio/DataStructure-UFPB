/**
 * @file linked_list.c
 * @brief Linked list implementation in C
 *
 * This program implements a linked list in C.
 * It provides the interactive menu.
 *
 * @author João Vitor Sampaio
 * @version 2.0
 * @date 2025-02-24
 */

// include libraries
#include "create.h"
#include "insert.h"
#include "delete.h"
#include "route.h"

// function prototype
void display_menu(struct knot**);

int main() {
    struct knot *l; // pointer to the head of the list

    create(&l); // initialize the list
    display_menu(&l); // display menu and handle user options

    return 0;
}

// display menu and handle user options
void display_menu(struct knot **l) {
    int opt;
    do {
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
        scanf("%d", &opt); // read user option

        switch (opt) {
            case 1:
                insert_start(l); // insert a new element at the beginning of the list
                break;
            case 2:
                insert_middle(l); // insert a new element in the middle of the list
                break;
            case 3:
                insert_end(l); // insert a new element at the end of the list
                break;
            case 4:
                delete_start(l); // remove the element at the beginning of the list
                break;
            case 5:
                delete_middle(l); // remove an element in the middle of the list
                break;
            case 6:
                delete_end(l); // remove the element at the end of the list
                break;
            case 7:
                clean(l); // clean the list
                break;
            case 8:
                print(*l); // print the list
                break;
            case 9:
                search(*l); // search for an element
                break;
            case 10:
                clean(l); // clean the list before exiting
                break; // exit the program
            default:
                printf("Invalid option\n"); // handle invalid options
        }
    } while (opt != 10); // continue until the user chooses to exit
}