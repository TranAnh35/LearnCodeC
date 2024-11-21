#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <stdbool.h>

typedef struct Queue{
    DataType dataType;
    sNode* front;
    sNode* rear;
    size_t size;
} Queue;

Queue* createQueue(DataType dataType);
bool empty_queue(Queue* queue);
int size_queue(Queue* queue);
void enqueue(Queue* queue, Data data);
void* front_queue(Queue* queue);
void* dequeue(Queue* queue);
void* back_queue(Queue* queue);
void swap_queue(Queue* queue1, Queue* queue2);
void show_queue(Queue* queue);
void free_queue(Queue** queue);
#endif 