#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    // 顺序表部分
    SqlList L, L1, L2, L3;  
    int a[10] = {1,2,3,4,5};
    int b[10] = {-1,1,3,4,5,8};
    int c[10] = {-2,0,2,4,6};
    InitSqlList(&L);
    InitSqlList(&L1);
    InitSqlList(&L2);
    InitSqlList(&L3);
    InitSqlListForTest(&L1, a);
    InitSqlListForTest(&L2, b);
    InitSqlListForTest(&L3, c);
    printSqlList(&L);
    FindDupValInTriplet(&L1, &L2, &L3, &L);
    printSqlList(&L);
    // if(SqlListInsert(&L, 7, 234)){
    //     printSqlList(&L);
    // }
    // int e = 2147483647;
    // if(SqlListDelete(&L, 7, &e)){
    //     printf("Deleted: %d\n", e);
    //     printSqlList(&L);
    // }
    // printf("Locate %d at: %d\n", 234, LocateElem(&L, 234));

    // // 单链表部分
    // LinkList L = NULL;

    // L = InitLinkListWithHeader(L);
    // // L = HeadInsert(L);
    // L = TailInsert(L);
    // PrintLinkList(L);
    // printf("LinkList Length: %d\n", Length(L));
    // printf("Get %d at: %d\n", GetLinkListElem(L, 5)->data, 5);
    // if(LinkListInsert(L, 5, 234)){
    //     PrintLinkList(L);
    // }
    // int e = 2147483647;
    // if(LinkListDelete(L, 5, &e)){
    //     printf("Deleted: %d\n", e);
    //     PrintLinkList(L);
    // }

    // L = InitLinkListWithoutHeader(L);
    // L = HeadInsertWithoutHeader(L);
    // PrintLinkListWithoutHeader(L);
    // printf("Get %d at: %d\n", GetLinkListElemWithoutHeader(L, 5)->data, 5);
    // if(LinkListInsertWithoutHeader(L, 1, 234)){
    //     PrintLinkListWithoutHeader(L);
    // }
    
    return 0;
}