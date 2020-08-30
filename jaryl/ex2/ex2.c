/*************************************
* Lab 1 Exercise 2
* Name: LOH FAH YAO, JARYL
* Student No: A0202023H
* Lab Group: B08
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

void run_instruction(FILE *fp, list *lst, int instr);

int main(int argc, char **argv) {
    if (argc != 2)
    {
        fprintf(stderr, "Error: expecting 1 argument, %d found\n", argc - 1);
        exit(1);
    }

    // we read in the file name provided as argument
    char *fname = argv[1];

    // updating the array of function pointers
    // do not remove this call 
    // (you may leave the function empty if you do not need it)
    update_functions();

    // rest of code logic here
    FILE *fp = fopen(fname, "r");
    int instr;
    list *lst = (list *)malloc(sizeof(list));
    lst -> head = NULL;
    lst -> tail = NULL;

    while(fscanf(fp, "%d", &instr) != EOF) {
    	run_instruction(fp, lst, instr);
    }

    fclose(fp);
    reset_list(lst);
    free(lst);
}

// takes an instruction enum and runs the corresponding function
// we assume input always has the right format (no input validation on runner)
void run_instruction(FILE *fp, list *lst, int instr) {
    int index, data;
    switch (instr) {
        case SUM_LIST:
	    sum_list(lst);
            break;
   	case INSERT_FROM_HEAD_AT:
            fscanf(fp, "%d %d", &index, &data);
            insert_node_from_head_at(lst, index, data);
            break;
    	case INSERT_FROM_TAIL_AT:
            fscanf(fp, "%d %d", &index, &data);
            insert_node_from_tail_at(lst, index, data);
            break;
    	case DELETE_FROM_HEAD_AT:
            fscanf(fp, "%d", &index);
            delete_node_from_head_at(lst, index);
            break;
    	case DELETE_FROM_TAIL_AT:
            fscanf(fp, "%d", &index);
            delete_node_from_tail_at(lst, index);
            break;
    	case RESET_LIST:
            reset_list(lst);
	    break;
        case MAP:
	    fscanf(fp, "%d", &index);
	    map(lst, func_list[index]);
    }
}
