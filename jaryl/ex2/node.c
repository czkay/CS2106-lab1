/*************************************
* Lab 1 Exercise 2
* Name: LOH FAH YAO, JARYL
* Student No: A0202023H
* Lab Group: B08
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
void insert_node_from_head_at(list *lst, int index, int data) {
    node *new_node = (node *)malloc(sizeof(node)); //allocate node
    new_node -> data = data;

    if(lst -> head == NULL) {
        lst -> head = new_node;
        lst -> tail = new_node;

        new_node -> next = NULL;
        new_node -> prev = NULL;
    } else {
        if(index == 0) { //add new node at the front
            node *temp = lst -> head;
            lst -> head = new_node;
            temp -> prev = new_node;

            new_node -> next = temp;
            new_node -> prev = NULL;
        } else { //if iterating to the correct position is required
            node *target_node = lst -> head;
            node *shadow_node = NULL;
            int i = index;

            while(i > 0) {
                if(target_node == NULL) {
                    break;
                } else {
                    shadow_node = target_node;
                    target_node = target_node -> next; //move down until the target node
                    i--;
                }
            }
            if(target_node == NULL) { //target node being the last node on lst
                lst -> tail = new_node;
                shadow_node -> next = new_node;

                new_node -> next = NULL;
                new_node -> prev = shadow_node;

            } else {
                node *temp = target_node -> prev;
                temp -> next = new_node;
                target_node -> prev = new_node;

                new_node -> next = target_node;
                new_node -> prev = temp;
            }
        }                                                                                                                                          }
}

// inserts a new node with data value at index (counting from the back
// starting at 0)
void insert_node_from_tail_at(list *lst, int index, int data) {
    int length = 1;
    node *new_node = (node *)malloc(sizeof(node)); //allocate node
    new_node -> data = data;
    
    if(lst -> head != NULL) {
        node *temp = lst -> head;
        while(temp != lst -> tail) {
            temp = temp -> next;
            length++;
        }
        
        insert_node_from_head_at(lst, length - index, data);
        
    } else {
        lst -> head = new_node;
        lst -> tail = new_node;
        
        new_node -> next = NULL;
        new_node -> prev = NULL;
    }
}

// deletes node at index counting from the front (starting from 0)
// note: index is guaranteed to be valid
void delete_node_from_head_at(list *lst, int index) {
    int i = index;
    node *delete_node = (node *)malloc(sizeof(node));
        
    if(lst -> head != NULL) {
        delete_node = lst -> head;
        while(i > 0) {
            delete_node = delete_node -> next;
            i--;
        }
        
        if(delete_node == lst -> head) {
            lst -> head = delete_node -> next;
        } else if(delete_node == lst -> tail) {
            lst -> tail = delete_node -> prev;  
        }
        
        if (delete_node -> next != NULL) 
            delete_node -> next -> prev = delete_node -> prev; 
  
        if (delete_node -> prev != NULL) 
            delete_node -> prev -> next = delete_node -> next;
        
        free(delete_node);
    }
}

// deletes node at index counting from the back (starting from 0)
// note: index is guaranteed to be valid
void delete_node_from_tail_at(list *lst, int index) {
    int length = 0;

    if(lst -> head != NULL) {
        node *temp = lst -> head;
        while(temp != lst -> tail) {
            temp = temp -> next;
            length++;
        }
        
        delete_node_from_head_at(lst, length - index);
    }
}

// resets list to an empty state (no nodes) and frees any allocated memory in
// the process
void reset_list(list *lst) {
    while(lst -> head != NULL) {
        delete_node_from_head_at(lst, 0);
    }
    // lst->head = NULL;
    // lst->tail = NULL;
}

// traverses list and applies func on data values of all elements in the list
void map(list *lst, int (*func)(int)) {
    node *curr = lst -> head; //start at first node
    while (curr != NULL) { //break after traversing past the last node
	curr -> data = func(curr -> data);
    	curr = curr -> next; //traverse list
    }
}

// traverses list and returns the sum of the data values of every node
// in the list
long sum_list(list *lst) {
    int sum = 0;
    node *curr = lst -> head;
    while (curr != NULL) {
	sum += curr -> data;
        curr = curr -> next;
    }
    printf("%d\n", sum);
    return sum;
}
