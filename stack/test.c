#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    SqStack S;
    int a[InitSize] = {1,2,3,4,6,9,123,34,24,34};
    int x = 0;
    InitSqStack(&S);
    PrintSqStack(&S);
    InitSqStackForTest(&S, a);
    PrintSqStack(&S);
    if(GetSqStackTop(&S,&x)){
        printf("Top Element: %d\n", x);
    }
    if(PopSqStack(&S, &x)){
        printf("Poped: %d\n", x);
    }
    PrintSqStack(&S);
    return 0;
}