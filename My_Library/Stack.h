#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <stdbool.h>

typedef struct Stack{
    sNode* top;
    size_t size;
    DataType dataType;
} Stack;

Stack* createStack(DataType dataType);
bool empty_stack(Stack* stack);
int size_stack(Stack* stack);
void* top_stack(Stack* stack);
void push_stack(Stack* stack, Data data);
void* pop_stack (Stack* stack);
void swap_stack(Stack* goal, Stack* from);
void free_stack(Stack** stack);
void show_stack(Stack* stack);
#endif