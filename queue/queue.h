#include<stdbool.h>

#define MaxSize 10
#define InitSize 9

typedef struct{
    int data[MaxSize];
    int rear;
    int front;
}SqQueue;


// 一些基本操作

void InitSqQueue(SqQueue* Q);
bool IsSqQueueEmpty(SqQueue* Q);
bool EnSqQueue(SqQueue* Q, int x);
bool DeSqQueue(SqQueue* Q, int* x);
void PrintSqQueue(SqQueue* Q);
void InitSqQueueForTest(SqQueue* Q, int* a);
