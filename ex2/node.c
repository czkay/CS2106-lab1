/*************************************
* Lab 1 Exercise 2
# Name: Chong Zi Kang
# Student No: A0189930R
# Lab Group: T10
*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"

// copy in your implementation of the functions from ex1
// there is on extra function called map which you have to fill up too
// feel free to add any new functions as you deem fit

// inserts a new node with data value at index (counting from the front
// starting at 0)
void insert_node_from_head_at(list *lst, int index, int data)
{
    node *curr = lst->head;
    node *new = (node*) malloc(sizeof(node));
    new->data = data;
    if (curr == NULL) {
        new->prev = NULL;
        new->next = NULL;
        lst->head = new;
        lst->tail = new;
    } else {
        int i = index;
        while (i != 0) {
            curr = curr->next;
            i--;
        }

        if (curr == NULL) {
            new->prev = lst->tail;
            new->next = NULL;
            new->prev->next = new;
            lst->tail = new;
        } else {
            new->prev = curr->prev;
            new->next = curr;
            if (new->prev != NULL) {
                new->prev->next = new;
            }
            new->next->prev = new;
            if (index == 0) {
                lst->head = new;
            }
        }
    }
}

// inserts a new node with data value at index (counting from the back
// starting at 0)
void insert_node_from_tail_at(list *lst, int index, int data)
{
    node *curr = lst->tail;
    node *new = (node*) malloc(sizeof(node));
    new->data = data;
    if (curr == NULL) {
        new->prev = NULL;
        new->next = NULL;
        lst->head = new;
        lst->tail = new;
    } else {
        int i = index;
        while (i != 0) {
            curr = curr->prev;
            i--;
        }
        if (curr == NULL) {
            new->prev = NULL;
            new->next = lst->head;
            new->next->prev = new;
            lst->head = new;
        } else {
            new->prev = curr;
            new->next = curr->next;
            new->prev->next = new;
            if (new->next != NULL) {
                new->next->prev = new;
            }
            if (index == 0) {
                lst->tail = new;
            }
        }
    }
}

// deletes node at index counting from the front (starting from 0)
// note: index is guaranteed to be valid
void delete_node_from_head_at(list *lst, int index)
{
    node *curr = lst->head;
    
    int i = index;
    while (i != 0) {
        curr = curr->next;
        i--;
    }

    if (curr->prev == NULL && curr->next == NULL) {
        lst->head = NULL;
        lst->tail = NULL;
        free(curr);
    } else if (curr->prev == NULL) {
        lst->head = curr->next;
        curr->next->prev = NULL;
        free(curr);
    } else if (curr->next == NULL) {
        lst->tail = curr->prev;
        curr->prev->next = NULL;
        free(curr);
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
    }
}

// deletes node at index counting from the back (starting from 0)
// note: index is guaranteed to be valid
void delete_node_from_tail_at(list *lst, int index)
{
    node *curr = lst->tail;
    
    int i = index;
    while (i != 0) {
        curr = curr->prev;
        i--;
    }

    if (curr->prev == NULL && curr->next == NULL) {
        lst->head = NULL;
        lst->tail = NULL;
        free(curr);
    } else if (curr->prev == NULL) {
        lst->head = curr->next;
        curr->next->prev = NULL;
        free(curr);
    } else if (curr->next == NULL) {
        lst->tail = curr->prev;
        curr->prev->next = NULL;
        free(curr);
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
    }
}

// resets list to an empty state (no nodes) and frees any allocated memory in
// the process
void reset_list(list *lst)
{
    node *curr = lst->head;
    while (curr != NULL) {
        node *tmp = curr;
        curr = curr->next;
        free(tmp);
        tmp = NULL;
    }
    lst->head = NULL;
    lst->tail = NULL;
}

// traverses list and applies func on data values of all elements in the list
void map(list *lst, int (*func)(int))
{
    node *curr = lst->head;
    while (curr != NULL) {
        int data = curr->data;
        data = func(data);
        // printf("new data: %d\n", data);
        curr->data = data;
        curr = curr->next;
    }
}

// traverses list and returns the sum of the data values of every node
// in the list
long sum_list(list *lst)
{
    long i = 0;
    node *curr = lst->head;
    while (curr != NULL) {
        i = i + curr->data;
        curr = curr->next;
    }
    
    return i;
}
