#include "queue.h"
#include <stdio.h>

int main(){

    // // 顺序队列部分
    // SqQueue Q;
    // int a[InitSize] = {1,2,3,4,5,6,7,8,9};
    // int x = 2147483647;
    // InitSqQueue(&Q);
    // PrintSqQueue(&Q);
    // InitSqQueueForTest(&Q, a);
    // PrintSqQueue(&Q);
    // if(EnSqQueue(&Q, 114)){
    //     PrintSqQueue(&Q);
    // }else{
    //     printf("It's Full.\n");
    // }
    // if(DeSqQueue(&Q, &x)){
    //     printf("DeQueue: %d\n", x);
    // }
    // PrintSqQueue(&Q);
    // if(EnSqQueue(&Q, 514)){
    //     PrintSqQueue(&Q);
    // }else{
    //     printf("It's Full.\n");
    // }

    // 链式队列部分
    LinkQueue Q;
    int a[InitSize] = {1,2,3,4,5,6,7,8,9};
    int x = 2147483647;
    InitLinkQueue(&Q);
    PrintLinkQueue(&Q);
    InitLinkQueueForTest(&Q, a);
    PrintLinkQueue(&Q);
    if(EnLinkQueue(&Q, 114)){
        PrintLinkQueue(&Q);
    }else{
        printf("It's Full.\n");
    }
    if(DeLinkQueue(&Q, &x)){
        printf("DeQueue: %d\n", x);
    }
    PrintLinkQueue(&Q);
    if(EnLinkQueue(&Q, 514)){
        PrintLinkQueue(&Q);
    }else{
        printf("It's Full.\n");
    }
    return 0;
}