#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
} Node;

Node *initList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

// 尾插法

Node *get_tail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

Node *insertTail(Node *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    L->next = p;
    p->next = NULL;
    return p;
}

// 插入到指定地点
void insertlist(ElemType e, ElemType a, Node *L)
{
    Node *p = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < e - 1; i++)
    {
        L = L->next;
    }
    p->data = a;
    p->next = L->next;
    L->next = p;
}

// 遍历
void listNode(Node *L)
{
    while (L->next != NULL)
    {
        L = L->next;
        printf("%d ", L->data);
    }
    printf("\n");
}

// 删除数据
void deliteList(Node *L, int e)
{
    Node *p = L;
    for (int i = 0; i < e - 1; i++)
    {
        p = p->next;
    }
    Node *temp = (Node *)malloc(sizeof(Node));
    // q指向要删除的节点
    temp = p->next;
    // 让要删除节点的前驱指向要删除节点的后继
    p->next = temp->next; // q ->next == p ->next ->next 缺点为不能删除数据，只是不能遍历输出，浪费空间且不安全
    free(temp);
}

int main(void)
{
    Node *List = initList();
    Node *tail = get_tail(List);
    tail = insertTail(tail, 10);
    tail = insertTail(tail, 20);
    tail = insertTail(tail, 30);
    insertlist(2, 40, List);
    listNode(List);
    deliteList(List, 2);
    listNode(List);

    return 0;
}