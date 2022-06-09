/* **************************************************
 * Filename: 2.3.7_6.cpp
 *   Create: 2022-06-09
 *   Author: Wulnut
 * *************************************************/

#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct  LNode {
    ElemType data;
    LNode *next;
} LNode, *LinkList;

void init_list(LinkList &L) {
    L = (LinkList) malloc(sizeof (LNode)); // 产生头节点，并使指向此节点
    if (!L) return ; // 存储分配失败
    L->next = nullptr; // 头节点为空
}

// 前插法
void create_list(LinkList &L, int n) {

    L = (LinkList) malloc(sizeof (LNode));
    L->next = nullptr;
    printf("输入%d个数字", n);

    for (int i = n; i > 0; i --) {
        auto p = (LinkList) malloc(sizeof (LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

void print(LinkList &L) {
    LinkList p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void my_sort(LinkList &L) {
    LNode *p = L->next, *pre; // p为什么要取L->next因为这是一个带头节点的链表
    LNode *r = p->next; //r保持*p后继结点指针，以保证不断链
    p->next = nullptr; //构造只含一个数据结点的有序表

    p = r;
    while (p != nullptr) {
        r = p->next; //保存*p的后继结点指针
        pre = L;
        while (pre->next != nullptr && pre->next->data < p->data) pre = pre->next; //在有序表中查找插入的前驱结点*pre
        p->next = pre->next; //将*p 插入到*pre 之后
        pre->next = p;
        p = r; //扫描原单链表中剩下的结点
    }
}

int main() {
    LinkList L;
    init_list(L);
    create_list(L, 5);
    my_sort(L);
    print(L);
    return 0;
}