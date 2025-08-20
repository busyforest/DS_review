#include<stdbool.h>

#define MaxSize 10
#define InitSize 9

typedef struct{
    int data[MaxSize];
    int rear;
    int front;
}SqQueue;

typedef struct QNode{
    int data;
    struct QNode* next;
}QNode;

typedef struct{
    QNode* front;
    QNode* rear;
}LinkQueue;




// 一些基本操作

void InitSqQueue(SqQueue* Q);
bool IsSqQueueEmpty(SqQueue* Q);
bool EnSqQueue(SqQueue* Q, int x);
bool DeSqQueue(SqQueue* Q, int* x);
void PrintSqQueue(SqQueue* Q);
void InitSqQueueForTest(SqQueue* Q, int* a);
void InitLinkQueue(LinkQueue* Q);
bool IsLinkQueueEmpty(LinkQueue* Q);
bool EnLinkQueue(LinkQueue* Q, int x);
bool DeLinkQueue(LinkQueue* Q, int* x);
void PrintLinkQueue(LinkQueue* Q);
void InitLinkQueueForTest(LinkQueue* Q, int* a);
