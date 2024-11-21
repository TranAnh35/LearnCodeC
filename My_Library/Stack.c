#include "Stack.h"

Stack* createStack(DataType dataType){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    stack->dataType = dataType;

    return stack;
}

bool empty_stack(Stack* stack){
    return (stack->size == 0);
}

int size_stack(Stack* stack){
    return stack->size;
}

void* top_stack(Stack* stack){
    if(empty_stack(stack)) return NULL;
    return returnForDataType(stack->top->data, stack->dataType);
}

void push_stack(Stack* stack, Data data){
    sNode* newNode = createSNode(data);
    if(!empty_stack(stack)){
        newNode->next = stack->top;
    }
    stack->top = newNode;
    stack->size++;
}

void* pop_stack (Stack* stack){
    if(empty_stack(stack)) return NULL;
    sNode* delete = stack->top;
    stack->top = delete->next;
    stack->size--;

    void* data = returnForDataType(delete->data, stack->dataType);
    freeSNode(delete, stack->dataType);
    return data;
}

void swap_stack(Stack* goal, Stack* from){
    sNode* temp = goal->top;
    goal->top = from->top;
    from->top = temp;
}

void show_stack(Stack* stack){
    if(stack == NULL){
        printf("*Top -> NULL\n");
        return;
    }
    sNode* current = stack->top;
    printf("*Top -> ");
    while(current != NULL){
        switch (stack->dataType) {
            case INT:
                printf("%d -> ", current->data.intValue);
                break;
            case LONG:
                printf("%ld -> ", current->data.longValue);
                break;
            case FLOAT:
                printf("%0.4g -> ", current->data.floatValue);
                break;
            case DOUBLE:
                printf("%0.11g -> ", current->data.doubleValue);
                break;
            case CHAR:
                printf("%c -> ", current->data.charValue);
                break;
            case STRING:
                printf("%s -> ", current->data.stringValue);
                break;
        }
        current = current->next;
    }
    printf("NULL\n");
}

void free_stack(Stack** stack){
    sNode* current = (*stack)->top;
    sNode* next;

    while (current != NULL) {
        next = current->next;
        freeSNode(current, (*stack)->dataType);
        current = next;
    }

    free(*stack);
    *stack = NULL;
}