#include "LinkedList.h"
#include "Node.h"

LinkedList* createLinkedList(DataType dataType) {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->dataType = dataType;

    return list;
}

// Capacity
bool empty_list(LinkedList* list){
    return (list->size == 0);
}

int size_list(LinkedList* list){
    return list->size;
}

// Element access
void* front_list(LinkedList* list){
    if(empty_list(list)){
        return NULL;
    }
    return returnForDataType(list->head->data, list->dataType);
}

void* back_list(LinkedList* list){
    if(empty_list(list)){
        return NULL;
    }
    return returnForDataType(list->head->data, list->dataType);
}

// Modifiers
void push_front_list(LinkedList* list, Data data){
    dNode* newNode = createDNode(data);
    if(empty_list(list)){
        list->tail = newNode;
    } else{
        list->head->prev = newNode;
    }
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void* pop_front_list(LinkedList* list){
    if(empty_list(list)) return NULL;

    dNode* temp = list->head;
    dNode* mustDelete;
    void* data = returnForDataType(temp->data, list->dataType);
    
    if(list->head->next == NULL){
        list->tail = NULL;
    } else {
        list->head->next->prev = NULL;
    }
    mustDelete = list->head;
    list->head = list->head->next;
    list->size--;
    freeDNode(mustDelete, list->dataType);
    return data;
}

void push_back_list(LinkedList* list, Data data){
    dNode* newNode = createDNode(data);
    if(empty_list(list)){
        list->head = newNode;
    } else{
        list->tail->next = newNode;
        newNode->prev = list->tail;
    }
    list->tail = newNode;
    list->size++;
}

void* pop_back_list(LinkedList* list){
    if(empty_list(list)) return NULL;

    dNode* temp = list->tail;
    dNode* mustDelete;
    void* data = returnForDataType(temp->data, list->dataType);

    if(list->tail->prev == NULL){
        list->head = NULL;
    } else {
        list->tail->prev->next = NULL;
    }
    list->tail = list->tail->prev;
    list->size--;

    return data;
}

void insert_list(LinkedList* list, int index, Data data){
    if(index < 0) return;

    if(index == 0){
        push_front_list(list, data);
        return;
    }

    if(index >= size_list(list)){
        push_back_list(list, data);
        return;
    }

    dNode* ptr = list->head;
    while(--index != 0){
        ptr = ptr->next;
    }

    dNode* newNode = createDNode(data);
    if(newNode == NULL) return;

    dNode* prev = ptr->prev;
    prev->next = newNode;
    newNode->next = ptr;
    ptr->prev = newNode;
    newNode->prev = prev;
    list->size++;
}

void erase_list(LinkedList* list, int index){
    if(index < 0) return;

    if(index == 0){
        pop_front_list(list);
        return;
    }

    if(index >= list->size - 1){
        pop_back_list(list);
        return;
    }

    dNode* ptr = list->head;
    while(index-- != 0){
        ptr = ptr->next;
    }

    dNode* prev = ptr->prev;
    dNode* next = ptr->next;
    prev->next = next;
    next->prev = prev;
    ptr->next = NULL;
    ptr->prev = NULL;
    freeDNode(ptr, list->dataType);
    list->size--;
}

void swap_list(LinkedList* list1, LinkedList* list2){
    dNode* tempHead = list1->head;
    dNode* tempTail = list1->tail;

    list1->head = list2->head;
    list1->tail = list2->tail;

    list2->head = tempHead;
    list2->tail = tempTail;
}

void show_list(LinkedList* list){
    if(list == NULL){
        printf("NULL\n");
        return;
    }

    dNode* current = list->head;
    
    while(current != NULL){
        switch (list->dataType) {
            case INT:
                printf("%d <-> ", current->data.intValue);
                break;
            case LONG:
                printf("%ld <-> ", current->data.longValue);
                break;
            case FLOAT:
                printf("%0.4g <-> ", current->data.floatValue);
                break;
            case DOUBLE:
                printf("%0.11g <-> ", current->data.doubleValue);
                break;
            case CHAR:
                printf("%c <-> ", current->data.charValue);
                break;
            case STRING:
                printf("%s <-> ", current->data.stringValue);
                break;
        }
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(LinkedList** list) {
    dNode* current = (*list)->head;
    dNode* next;

    while (current != NULL) {
        next = current->next;
        freeDNode(current, (*list)->dataType);
        current = next;
    }

    free(*list);
    *list = NULL;
}

// Operations
void splice_list(LinkedList* goal, int index, LinkedList* from){
    if(index <= 0) {
        from->tail->next = goal->head;
        goal->head->prev = from->tail;
        goal->head = from->head;
        goal->size += from->size;
        from->head = NULL;
        from->tail = NULL;
        from->size = 0;
        return;
    }

    if(index >= 0){
        goal->tail->next = from->head;
        from->head->prev = goal->tail;
        goal->tail = from->tail;
        goal->size += from->size;
        from->head = NULL;
        from->tail = NULL;
        from->size = 0;
        return;
    }

    dNode* temp = goal->head;
    while(--index != 0){
        temp = temp->next;
    }

    dNode* ptr = temp->next;
    temp->next = from->head;
    from->head->prev = temp;
    ptr->prev = from->tail;
    from->tail->next = ptr;

    goal->size += from->size;
    from->head = NULL;
    from->tail = NULL;
    from->size = 0;
}

void delete_list(LinkedList* list, Data data) {
    dNode* current = list->head;

    while (current != NULL) {
        int match = 0;
        switch (list->dataType) {
            case INT:
                match = (data.intValue == current->data.intValue);
                break;
            case LONG:
                match = (data.longValue == current->data.longValue);
                break;
            case FLOAT:
                match = (data.floatValue == current->data.floatValue);
                break;
            case DOUBLE:
                match = (data.doubleValue == current->data.doubleValue);
                break;
            case CHAR:
                match = (data.charValue == current->data.charValue);
                break;
            case STRING:
                match = (strcmp(data.stringValue, current->data.stringValue) == 0);
                break;
        }
        if (match) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;
            }

            if (list->dataType == STRING) {
                free(current->data.stringValue);
            }
            free(current);
            list->size--;
            return;
        }
        current = current->next;
    }
}

int compareData(Data a, Data b, DataType dataType, int ascending) {
    switch (dataType) {
        case INT:
            return ascending ? (a.intValue - b.intValue) : (b.intValue - a.intValue);
        case LONG:
            return ascending ? ((a.longValue > b.longValue) - (a.longValue < b.longValue)) : ((a.longValue < b.longValue) - (a.longValue > b.longValue));
        case FLOAT:
            return ascending ? ((a.floatValue > b.floatValue) - (a.floatValue < b.floatValue)) : ((a.floatValue < b.floatValue) - (a.floatValue > b.floatValue));
        case DOUBLE:
            return ascending ? ((a.doubleValue > b.doubleValue) - (a.doubleValue < b.doubleValue)) : ((a.doubleValue < b.doubleValue) - (a.doubleValue > b.doubleValue));
        case CHAR:
            return ascending ? (a.charValue - b.charValue) : (b.charValue - a.charValue);
        case STRING:
            return ascending ? (strcmp(a.stringValue, b.stringValue)) : (strcmp(b.stringValue, a.stringValue));
        default:
            return 0;
    }
}


void unique_list(LinkedList* list) {
    if (list->head == NULL || list->head->next == NULL) return;

    dNode* ptr = list->head;
    while (ptr->next != NULL) {
        if (compareData(ptr->data, ptr->next->data, list->dataType, 1) == 0) {
            dNode* temp = ptr->next;
            ptr->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = ptr;
            } else {
                list->tail = ptr;
            }
            if (list->dataType == STRING) {
                free(temp->data.stringValue);
            }
            free(temp);
            list->size--;
        } else {
            ptr = ptr->next;
        }
    }
}

dNode* merge(dNode* left, dNode* right, DataType dataType, int ascending) {
    if (!left) return right;
    if (!right) return left;

    if (compareData(left->data, right->data, dataType, ascending) <= 0) {
        left->next = merge(left->next, right, dataType, ascending);
        left->next->prev = left;
        left->prev = NULL;
        return left;
    } else {
        right->next = merge(left, right->next, dataType, ascending);
        right->next->prev = right;
        right->prev = NULL;
        return right;
    }
}

dNode* mergeSort(dNode* head, DataType dataType, int ascending) {
    if (!head || !head->next) return head;

    dNode* middle = head;
    dNode* fast = head->next;

    while (fast && fast->next) {
        middle = middle->next;
        fast = fast->next->next;
    }

    dNode* left = head;
    dNode* right = middle->next;
    middle->next = NULL;

    left = mergeSort(left, dataType, ascending);
    right = mergeSort(right, dataType, ascending);

    return merge(left, right, dataType, ascending);
}

void sort_list(LinkedList* list, int ascending) {
    if (!list->head) return;

    list->head = mergeSort(list->head, list->dataType, ascending);

    dNode* temp = list->head;
    while (temp->next) {
        temp = temp->next;
    }
    list->tail = temp;
}

void reverse_list(LinkedList* list) {
    if (list == NULL || empty_list(list)) return;

    dNode* current = list->head;
    dNode* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        list->head = temp->prev;
    }
}