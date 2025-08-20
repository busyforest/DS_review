#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 测试用的值
int a[10] = {1,2,5,6,7,13,4,8,9,20};
int b[10] = {1,2,3,4,5,5,5,6,6,8};

/* 辅助函数 */

int min(int x, int y){
    return x < y ? x : y;
}

// 用a[]数组初始化顺序表来测试
void InitSqlListForTest(SqlList* L, int* a){
    for(int i = 0;i < InitSize;i++){
        L->data[i] = a[i];
        L->length++;
    }
}

// 打印静态顺序表
void printSqlList(SqlList* L){
    printf("List Status: ");
    if(L->length == 0){
        printf("It's empty.\n");
        return;
    }
    for(int i = 0; i < L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

// 打印动态顺序表
void printSeqList(SeqList* L){
    printf("List Status: ");
    if(L->length == 0){
        printf("It's empty.\n");
        return;
    }
    for(int i = 0; i < L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

// 打印带头节点的链表
void PrintLinkList(LinkList L){
    printf("LinkList Status: ");
    while(L->next != NULL){
        printf("%d ", L->next->data);
        L = L->next;
    }
    printf("\n");
}

// 打印不带头节点的链表
void PrintLinkListWithoutHeader(LinkList L){
    printf("LinkList Status: ");
    while(L != NULL){
        printf("%d ", L->data);
        L = L->next;
    }
    printf("\n");
}

// 初始化静态顺序表
void InitSqlList(SqlList* L){
   L->length = 0;
}

// 初始化动态顺序表
void InitSeqList(SeqList* L){
    L->data = (int*)malloc(sizeof(int)*InitSize);
    L->length = 0;
}

// 在静态顺序表的第i处插入元素e
bool SqlListInsert(SqlList* L, int i, int e){
    if(i < 1 || i > L->length + 1){
        return false;
    }
    if(L->length >= MaxSize){
        return false;
    }
    for(int j = L->length;j > i - 1;j--){
        L->data[j] = L->data[j - 1];
    }
    L->data[i] = e;
    L->length++;
    return true;
}

// 删除静态顺序表的第i个元素
bool SqlListDelete(SqlList* L, int i, int* e){
    if(i < 1 || i > L->length){
        e = NULL;
        return false;
    }
    *e = L->data[i - 1];
    for(int j = i - 1; j < L->length - 1;j++){
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    return true;
}

// 按值查找
int LocateElem(SqlList *L, int e){
    for(int i = 0;i < L->length; i++){
        if(L->data[i] == e){
            return i + 1;
        }
    }
    return 0;
}

// 初始化带头节点的链表
LinkList InitLinkListWithHeader(LinkList L){
    L = (Lnode*)malloc(sizeof(Lnode));
    L->next = NULL;
    return L;
}

// 初始化不带头节点的链表
LinkList InitLinkListWithoutHeader(LinkList L){
    L = NULL;
    return L;
}

// 采用头插法建立带头节点的链表
LinkList HeadInsert(LinkList L){
    for(int i = 0;i < InitSize; i++){
        Lnode* s = (Lnode*)malloc(sizeof(Lnode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
    return L;
}

// 采用头插法建立不带头节点的链表
LinkList HeadInsertWithoutHeader(LinkList L){
    for(int i = 0;i < InitSize; i++){
        Lnode* s = (Lnode*)malloc(sizeof(Lnode));
        s->data = a[i];
        s->next = L;
        L = s;
    }
    return L;
}

// 采用尾插法建立带头节点的链表
LinkList TailInsert(LinkList L){
    Lnode* r = L;
    for(int i = 0; i < InitSize; i++){
        Lnode* s = (Lnode*)malloc(sizeof(Lnode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return L;
}

// 求带头节点链表的表长
int Length(LinkList L){
    int res = 0;
    while(L->next != NULL){
        res++;
        L = L->next;
    }
    return res;
}

// 获取带头节点链表中第i个Lnode
Lnode* GetLinkListElem(LinkList L, int i){
    int j = 1;
    while(L->next != NULL){
        if(j == i){
            return L->next;
        }
        j++;
        L=L->next;
    }
    return NULL;
}

// 按值查找带头节点链表
Lnode* LocateLinkListElem(LinkList L, int e){
    while(L->next != NULL){
        if(L->next->data == e){
            return L->next;
        }
        L=L->next;
    }
    return NULL;
}

// 获取不带头节点链表的第i个Lnode
Lnode* GetLinkListElemWithoutHeader(LinkList L, int i){
    int j = 1;
    while(L != NULL){
        if(j == i){
            return L;
        }
        j++;
        L = L->next;
    }
    return NULL;
}

// 向带头节点的链表中第i个位置插入一个新数据e
bool LinkListInsert(LinkList L, int i, int e){
    Lnode* p = L;
    int j = 0;
    while(p != NULL && j < i - 1){
        j++;
        p = p->next;
    }
    if(p == NULL){
        return false;
    }
    Lnode* s = (Lnode*)malloc(sizeof(Lnode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 向不带头节点的链表中第i个位置插入数据e
bool LinkListInsertWithoutHeader(LinkList L, int i, int e){
    if(i == 1){
        Lnode* s = (Lnode*)malloc(sizeof(Lnode));
        s->next = L->next;
        L->next = s;
        int temp = L->data;
        L->data = e;
        s->data = temp;
        return true;
    }
    int j = 1;
    Lnode* p = L;
    while(p != NULL && j < i - 1){
        j++;
        p = p->next;
    }
    if(p == NULL){
        return false;
    }
    Lnode* s = (Lnode*)malloc(sizeof(Lnode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 删除带头节点链表中的第i个元素
bool LinkListDelete(LinkList L, int i, int* e){
    int j = 0;
    Lnode* p = L;
    while(p != NULL && j < i - 1){
        j++;
        p = p->next;
    }
    if(p == NULL){
        return false;
    }
    *e = p->next->data;
    Lnode* s = p->next;
    p->next = p->next->next;
    free(s);
    return true;
}

// 释放链表(带头节点)
bool FreeLinkList(LinkList L){
    if(L == NULL){
        return false;
    }
    Lnode* temp;
    while(L != NULL){
        temp = L->next;
        free(L);
        L = temp;
    }
    free(temp);
    return true;
}


/* 一些课后习题 */


// 删除有序顺序表中的所有重复元素
void DelSqlListDupVal(SqlList* L){
    for(int i = 0; i < L->length; i++){
        int cnt = 0;
        // 统计重复值的个数
        for(int j = i + 1; j < L->length; j++){
            if(L->data[j] != L->data[i]){
                break;
            }
            cnt++;
        }
        for(int k = i + 1; k < L->length; k++){
            L->data[k] = L->data[k + cnt];
        }
        L->length -= cnt;
    }
}

// 合并两个有序链表
void MergeSqlList(SqlList* L1, SqlList* L2, SqlList* L){
    if(L1->length + L2->length > MaxSize){
        perror("Merge Failed: Out of MaxSize.");
        return;
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < L1->length && j < L2->length){
        if(L1->data[i] < L2->data[j]){
            L->data[k++] = L1->data[i++];
        }else{
            L->data[k++] = L2->data[j++];
        }
    }
    while(i < L1->length){
        L->data[k++] = L1->data[i++];
    }
    while(j < L2->length){
        L->data[k++] = L2->data[j++];
    }
    L->length = L1->length + L2->length;
}

// 找出三个有序顺序表中的共同元素
void FindDupValInTriplet(SqlList* L1, SqlList* L2, SqlList* L3, SqlList* L){
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    while(i < L1->length && j < L2->length && k < L3->length){
        if((L1->data[i] == L2->data[j]) && (L1->data[i] == L3->data[k])){
            L->data[m++] = L1->data[i];
            L->length++;
            i++;
            j++;
            k++;
        }else if(L1->data[i] <= min(L2->data[j], L3->data[k])){
            i++;
        }else if(L2->data[j] <= min(L1->data[i], L3->data[k])){
            j++;
        }else if(L3->data[k] <= min(L1->data[i], L2->data[j])){
            k++;
        }
    }
}