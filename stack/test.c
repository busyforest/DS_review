#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    // // 顺序栈部分
    // SqStack S;
    // int a[InitSize] = {1,2,3,4,6,9,123,34,24,34};
    // int x = 0;
    // InitSqStack(&S);
    // PrintSqStack(&S);
    // InitSqStackForTest(&S, a);
    // PrintSqStack(&S);
    // if(GetSqStackTop(&S,&x)){
    //     printf("Top Element: %d\n", x);
    // }
    // if(PopSqStack(&S, &x)){
    //     printf("Poped: %d\n", x);
    // }
    // PrintSqStack(&S);

    // 链栈部分
    LinkStack S = NULL;
    int a[InitSize] = {1,2,3,4,6,9,123,34,24,34};
    int x = 0;
    S = InitLinkStack(S);
    PrintLinkStack(S);
    S = InitLinkStackForTest(S, a);
    PrintLinkStack(S);
    if(GetLinkStackTop(S,&x)){
        printf("Top Element: %d\n", x);
    }
    S = PopLinkStack(S, &x);
    printf("Poped: %d\n", x);
    PrintLinkStack(S);

    return 0;
}