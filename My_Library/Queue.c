#include "Queue.h"

Queue* createQueue(DataType dataType){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->dataType = dataType;
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

bool empty_queue(Queue* queue){
    return (queue->size == 0);
}

int size_queue(Queue* queue){
    return (queue->size);
}

void enqueue(Queue* queue, Data data){
    sNode* newNode = createSNode(data);
    if(empty_queue(queue)){
        queue->rear = newNode;
    } else {
        newNode->next = queue->front;
    }
    queue->front = newNode;
    queue->size++;
}

void* dequeue(Queue* queue){
    if(empty_queue(queue)) return NULL;
    sNode* newNode = queue->front;
    while(newNode->next != queue->rear){
        newNode = newNode->next;
    }
    void* data = returnForDataType(queue->rear->data, queue->dataType);
    newNode->next = NULL;
    queue->rear = newNode;
    queue->size--;

    return data;
}
void* front_queue(Queue* queue){
    if(empty_queue(queue)) return NULL;
    return returnForDataType(queue->front->data, queue->dataType);
}

void* back_queue(Queue* queue){
    if(empty_queue(queue)) return NULL;
    return returnForDataType(queue->rear->data, queue->dataType);
}

void swap_queue(Queue* queue1, Queue* queue2){
    sNode* temp;
    temp = queue1->front;
    queue1->front = queue2->front;
    queue2->front = temp;

    temp = queue1->rear;
    queue1->rear = queue2->rear;
    queue2->rear = temp;
}

void show_queue(Queue* queue){
    if(queue == NULL){
        printf("NULL\n");
        return;
    }

    sNode* current = queue->front;
    
    while(current != NULL){
        switch (queue->dataType) {
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

void free_queue(Queue** queue){
    sNode* current = (*queue)->front;
    sNode* next;

    while (current != NULL) {
        next = current->next;
        freeSNode(current, (*queue)->dataType);
        current = next;
    }

    free(*queue);
    *queue = NULL;
}