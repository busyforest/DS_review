#include "stack.h"
#include <stdio.h>

// 打印顺序栈
void PrintSqStack(SqStack* S){
    if(IsSqStackEmpty(S)){
        printf("It's Empty.\n");
        return;
    }
    printf("Stack Status:\n");
    printf("%d <- top\n", S->data[S->top]);
    for(int i = S->top - 1; i >= 0; i--){
        printf("%d\n", S->data[i]);
    }
}

// 用数组a[]初始化顺序栈用于测试
void InitSqStackForTest(SqStack* S, int* a){
    for(int i = 0; i < InitSize; i++){
        PushSqStack(S, a[i]);
    }
}

// 初始化顺序栈
// 初始栈顶指针设为-1
void InitSqStack(SqStack* S){
    S->top = -1;
}

// 顺序栈入栈
bool PushSqStack(SqStack* S, int x){
    if(S->top == MaxSize - 1){
        return false;
    }
    S->data[++S->top] = x;
    return true;
}

// 顺序栈出栈
bool PopSqStack(SqStack* S, int* x){
    if(S->top == -1){
        return false;
    }
    *x = S->data[S->top--];
    return true;
}

// 获取顺序栈栈顶元素
bool GetSqStackTop(SqStack* S, int* x){
    if(S->top == -1){
        return false;
    }
    *x = S->data[S->top];
    return true;
}

// 判断顺序栈是否为空
bool IsSqStackEmpty(SqStack* S){
    return S->top == -1;
}