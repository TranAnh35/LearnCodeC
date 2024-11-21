#include "Node.h"
#include <string.h>

dNode* createDNode(Data data){
    dNode* node = (dNode*)malloc(sizeof(dNode));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

sNode* createSNode(Data data){
    sNode* node = (sNode*)malloc(sizeof(sNode));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void freeDNode(dNode* node, DataType dataType) {
    if (node == NULL) return;

    if (dataType == STRING && node->data.stringValue != NULL) {
        free(node->data.stringValue);
        node->data.stringValue = NULL;
    }

    free(node);
}

void freeSNode(sNode* node, DataType dataType) {
    if (node == NULL) return;

    if (dataType == STRING && node->data.stringValue != NULL) {
        free(node->data.stringValue);
        node->data.stringValue = NULL;
    }

    free(node);
}

void* returnForDataType(Data data, DataType dataType) {
    switch (dataType) {
        case INT: {
            int* result = malloc(sizeof(int));
            *result = data.intValue;
            return result;
        }
        case LONG: {
            long* result = malloc(sizeof(long));
            *result = data.longValue;
            return result;
        }
        case FLOAT: {
            float* result = malloc(sizeof(float));
            *result = data.floatValue;
            return result;
        }
        case DOUBLE: {
            double* result = malloc(sizeof(double));
            *result = data.doubleValue;
            return result;
        }
        case CHAR: {
            char* result = malloc(sizeof(char));
            *result = data.charValue;
            return result;
        }
        case STRING:
            return data.stringValue;
        default:
            return NULL;
    }
}