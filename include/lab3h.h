#include <stdio.h>
#include <stdlib.h>

#include "DataStructure.h"

/* 链式存储结构下线性表的基本操作 */

/*初始化链表：创建一空链表*/
void Initiate(list) List *list;
{
    list->pHead = NULL;
    list->Length = 0;
}

/*取链表的长度：共有几个结点*/
int Length(list)
List *list;
{
    return list->Length;
}

/*读取序号为I的结点（即链表中的第I个结点）的数据域*/
int *GetAt(list, I)
List *list;
int I;
{
    int k;
    Node *pNode = list->pHead;
    if ((I >= 1) && (I <= list->Length)) {
        for (k = 1; k < I; k++) {
            pNode = pNode->pNext;
        }
        return &pNode->Data;
    } else
        return NULL;
}

/*查找数据域为x的结点*/
Node *Find(list, x)
List *list;
int x;
{
    int k;
    Node *pNode = list->pHead;
    while (pNode != NULL) {
        if (pNode->Data == x)
            return pNode;
        pNode = pNode->pNext;
    }
    return NULL;
}

/*查找数据域为x的结点的前驱结点*/
Node *GetPrior(list, x)
List *list;
int x;
{
    int k;
    Node *pNode = list->pHead;
    if (!pNode)
        return NULL;
    if (pNode->pNext == NULL)
        return NULL;
    while (pNode->pNext != NULL) {
        if (pNode->pNext->Data == x)
            return pNode;
        pNode = pNode->pNext;
    }
    return NULL;
}

/*查找数据域为x的结点的后继结点*/
Node *GetNext(list, x)
List *list;
int x;
{
    Node *pNode = Find(list, x);
    if (!pNode)
        return NULL;
    else
        return pNode->pNext;
}

/*在链表的第I个结点位置插入数据域为x的结点*/
/*bool　Insert(list,I,x)*/
int Insert(list, I, x)
List *list;
int I;
int x;
{
    Node *pNewNode;
    Node *pPreNode;
    int i;

    if ((I > list->Length + 1) || (I <= 0))
        return 0;

    if (I == 1) {
        pNewNode = (Node *)malloc(sizeof(Node));
        pNewNode->Data = x;
        pNewNode->pNext = list->pHead;
        list->pHead = pNewNode;
        list->Length++;
        return 1;
    }

    pPreNode = list->pHead;
    for (i = 1; i < I - 1; i++) {
        pPreNode = pPreNode->pNext;
    }

    pNewNode = (Node *)malloc(sizeof(Node));
    pNewNode->Data = x;
    pNewNode->pNext = pPreNode->pNext;
    pPreNode->pNext = pNewNode;
    list->Length++;
    return 1;
}

/*删除链表的第I个结点*/
int Delete(list, I)
List *list;
int I;
{
    Node *pDelNode;
    Node *pPreNode;
    int i;

    if ((I > list->Length) || (I <= 0))
        return 0;

    if (I == 1) {
        pDelNode = list->pHead;
        list->pHead = pDelNode->pNext;
        free(pDelNode);
        list->Length--;
        return 1;
    }

    pPreNode = list->pHead;
    for (i = 1; i < I - 1; i++) {
        pPreNode = pPreNode->pNext;
    }

    pDelNode = pPreNode->pNext;
    pPreNode->pNext = pDelNode->pNext;
    free(pDelNode);
    list->Length--;
    return 1;
}

/*print the list*/
int PrintList(list)
List *list;
{
    Node *pNode;
    int i;

    pNode = list->pHead;
    printf("\n\t\t");
    for (i = 1; i <= Length(list); i++) {
        printf(" %d ->\t", pNode->Data);
        pNode = pNode->pNext;
    }
    printf("NULL\n");
}
