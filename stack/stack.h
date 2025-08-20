#include<stdbool.h>

#define MaxSize 50
#define InitSize 10

// 顺序栈
typedef struct{
    int data[MaxSize];
    int top;
}SqStack;

// 链栈
typedef struct SNode{
    int data;
    struct SNode* next;
}SNode, * LinkStack;

// 一些基本操作

void PrintSqStack(SqStack* S);
void InitSqStackForTest(SqStack* S, int* a);
void InitSqStack(SqStack* S);
bool PushSqStack(SqStack* S, int x);
bool PopSqStack(SqStack* S, int* x);
bool GetSqStackTop(SqStack* S, int* x);
bool IsSqStackEmpty(SqStack* S);
void PrintLinkStack(LinkStack S);
LinkStack InitLinkStackForTest(LinkStack S, int* a);
LinkStack InitLinkStack(LinkStack S);
LinkStack PushLinkStack(LinkStack S, int x);
LinkStack PopLinkStack(LinkStack S, int* x);
bool GetLinkStackTop(LinkStack S, int* x);
bool IsLinkStackEmpty(LinkStack S);