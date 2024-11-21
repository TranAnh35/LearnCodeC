#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h> 

typedef enum {
    INT,
    LONG,
    FLOAT,
    DOUBLE,
    CHAR,
    STRING
} DataType;

typedef union {
    int intValue;
    long longValue;
    float floatValue;
    double doubleValue;
    char charValue;
    char* stringValue;
} Data;

typedef struct dNode {
    Data data;
    struct dNode* next;
    struct dNode* prev;
} dNode;

typedef struct sNode {
    Data data;
    struct sNode* next;
} sNode;

dNode* createDNode(Data data);
sNode* createSNode(Data data);
void freeDNode(dNode* node, DataType dataType);
void freeSNode(sNode* node, DataType dataType);
void* returnForDataType(Data data, DataType dataType);
#endif