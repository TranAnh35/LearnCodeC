#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Node.h"

typedef struct LinkedList {
    dNode* head;
    dNode* tail;
    size_t size;
    DataType dataType;
} LinkedList;

LinkedList* createLinkedList(DataType dataType);

// Capacity
bool empty_list(LinkedList* list);
int size_list(LinkedList* list);

// Element access
void* front_list(LinkedList* list);
void* back_list(LinkedList* list);

// Modifiers
void push_front_list(LinkedList* list, Data data);
void* pop_front_list(LinkedList* list); 
void push_back_list(LinkedList* list, Data data);
void* pop_back_list(LinkedList* list);
void insert_list(LinkedList* list, int index, Data data);
void erase_list(LinkedList* list, int index);
void swap_list(LinkedList* list1, LinkedList* list2);
void show_list(LinkedList* list);
void free_list(LinkedList** list);

// Operations
void splice_list(LinkedList* goal, int index, LinkedList* from);
void delete_list(LinkedList* list, Data data);
void unique_list(LinkedList* list);
void sort_list(LinkedList* list, int ascending);
void reverse_list(LinkedList* list);

#endif