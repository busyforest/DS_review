#include "queue.h"
#include <stdio.h>


// 初始化顺序队列(采用牺牲一个位置来判空和判满)
void InitSqQueue(SqQueue* Q){
    Q->front = 0;
    Q->rear = 0;
}

// 顺序队列入队
bool EnSqQueue(SqQueue* Q, int x){
    if(((Q->rear + 1) % MaxSize) == Q->front){
        return false;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    return true;
}

// 顺序队列出队
bool DeSqQueue(SqQueue* Q, int* x){
    if(IsSqQueueEmpty(Q)){
        return false;
    }
    (*x) = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    return true;
}

// 判断顺序队列是否为空
bool IsSqQueueEmpty(SqQueue* Q){
    return Q->front == Q->rear;
}

// 打印顺序队列
void PrintSqQueue(SqQueue* Q){
    if(IsSqQueueEmpty(Q)){
        printf("It's Empty.\n");
        return;
    }
    int i = Q->front;
    printf("Queue Status: \n");
    while(i != Q->rear){
        printf("%d ", Q->data[i]);
        i = (i + 1) % MaxSize;
    }
    printf("\n");
}

// 用a[]初始化顺序队列用于后续测试
void InitSqQueueForTest(SqQueue* Q, int* a){
    for(int i = 0; i < InitSize; i++){
        EnSqQueue(Q, a[i]);
    }
}