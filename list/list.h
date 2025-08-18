#include<stdbool.h>

#define MaxSize 50
#define InitSize 10

// 用于初始化的数组
extern int a[10];

// 静态分配的顺序表
typedef struct{
    int data[MaxSize];
    int length;
}SqlList;

// 动态分配的顺序表
typedef struct{
    int* data;
    int length;
}SeqList;

// 链表节点
typedef struct Lnode{
    int data;
    struct Lnode* next;
}Lnode, * LinkList;

// 一些基本操作
void InitSqlListForTest(SqlList* L, int* a);
void printSqlList(SqlList* L);
void printSeqList(SeqList* L);
void PrintLinkList(LinkList L);
void PrintLinkListWithoutHeader(LinkList L);
void InitSqlList(SqlList* L);
void InitSeqList(SeqList* L);
bool SqlListInsert(SqlList* L, int i, int e);
bool SqlListDelete(SqlList* L, int i, int* e);
int LocateElem(SqlList* L, int e);
LinkList InitLinkListWithHeader(LinkList L);
LinkList InitLinkListWithoutHeader(LinkList L);
LinkList HeadInsert(LinkList L);
LinkList HeadInsertWithoutHeader(LinkList L);
LinkList TailInsert(LinkList L);
int Length(LinkList L);
Lnode* GetLinkListElem(LinkList L, int i);
Lnode* LocateLinkListElem(LinkList L, int e);
Lnode* GetLinkListElemWithoutHeader(LinkList L, int i);
bool LinkListInsert(LinkList L, int i, int e);
bool LinkListInsertWithoutHeader(LinkList L, int i, int e);
bool LinkListDelete(LinkList L, int i, int* e);

// 一些课后习题的尝试实现

void DelSqlListDupVal(SqlList* L);
void MergeSqlList(SqlList* L1, SqlList* L2, SqlList* L);
int* FindDupValInTriplet(int* a, int* b, int* c);