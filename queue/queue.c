#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


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
    printf("Queue Status: ");
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

// 初始化链式队列(带头节点)
void InitLinkQueue(LinkQueue* Q){
    Q->front = (QNode*)malloc(sizeof(QNode));
    Q->rear = (QNode*)malloc(sizeof(QNode));
    Q->front->next = NULL;
}

// 链式队列入队
bool EnLinkQueue(LinkQueue* Q, int x){
    // 链式队列很难满，所以要出错大概是malloc出错，可以在这里加
    QNode* p = (QNode*)malloc(sizeof(QNode));
    // 初始队列为空的时候，把队头指针指向新入队的节点
    if(Q->front->next == NULL){
        Q->front->next = p;
    }
    p->data = x;
    p->next = Q->rear->next;
    Q->rear->next = p;
    Q->rear = p;
    return true;
}

// 链式队列出队
bool DeLinkQueue(LinkQueue* Q, int* x){
    if(IsLinkQueueEmpty(Q)){
        return false;
    }
    QNode* temp = Q->front->next;
    *x = temp->data;
    Q->front->next = temp->next;
    free(temp);
    return true;
}

// 判断链式队列是否为空
bool IsLinkQueueEmpty(LinkQueue* Q){
    return Q->front->next == NULL;
}

// 打印链式队列
void PrintLinkQueue(LinkQueue* Q){
    if(IsLinkQueueEmpty(Q)){
        printf("It's Empty.\n");
        return;
    }
    QNode* p = Q->front->next;
    printf("Queue Status: ");
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 用a[]初始化链式队列用于测试
void InitLinkQueueForTest(LinkQueue* Q, int* a){
    for(int i = 0; i < InitSize; i++){
        EnLinkQueue(Q, a[i]);
    }
}