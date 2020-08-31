/*************************************
* Lab 1 Exercise 2
# Name: Chong Zi Kang
# Student No: A0189930R
# Lab Group: T10
*************************************/

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "function_pointers.h"

// the runner is empty now! Modify it to fulfill the requirements of the
// exercise. You can use ex1.c as a template

// macros
#define SUM_LIST 0
#define INSERT_FROM_HEAD_AT 1
#define INSERT_FROM_TAIL_AT 2
#define DELETE_FROM_HEAD_AT 3
#define DELETE_FROM_TAIL_AT 4
#define RESET_LIST 5
#define MAP 6

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Error: expecting 1 argument, %d found\n", argc - 1);
        exit(1);
    }

    // we read in the file name provided as argument
    char *fname = argv[1];

    // printf("Before updating functions...\n");
    // updating the array of function pointers
    // do not remove this call 
    // (you may leave the function empty if you do not need it)
    update_functions();

    // rest of code logic here
    list *lst = (list *)malloc(sizeof(list));
    lst->head = NULL;
    lst->tail = NULL;

    // printf("Before file opening...\n");
    FILE* file = fopen(fname, "r");

    if (!file) {
        printf("Invalid file; exiting program...");
        printf("\n");
        return 0;
    }

    int instr;
    while (fscanf(file, "%d", &instr) != EOF) {
        int index, data;
        switch (instr)
        {
        case SUM_LIST:
            printf("%ld\n", sum_list(lst));
            break;
        case INSERT_FROM_HEAD_AT:
            fscanf(file, "%d %d", &index, &data);
            // printf("index: %d data: %d\n", index, data);
            insert_node_from_head_at(lst, index, data);
            break;
        case INSERT_FROM_TAIL_AT:
            fscanf(file, "%d %d", &index, &data);
            // printf("index: %d data: %d\n", index, data);
            insert_node_from_tail_at(lst, index, data);
            break;
        case DELETE_FROM_HEAD_AT:
            fscanf(file, "%d", &index);
            // printf("index: %d\n", index);
            delete_node_from_head_at(lst, index);
            break;
        case DELETE_FROM_TAIL_AT:
            fscanf(file, "%d", &index);
            // printf("index: %d\n", index);
            delete_node_from_tail_at(lst, index);
            break;   
        case RESET_LIST:
            reset_list(lst);
            break;
        case MAP:
            fscanf(file, "%d", &index);
            // printf("index: %d\n", index);
            map(lst, func_list[index]);
        }
    }

    fclose(file);
    reset_list(lst);
    free(lst);
}