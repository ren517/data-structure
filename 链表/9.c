#include <stdio.h>
#include <malloc.h>

typedef int Elemtype;

typedef struct node
{
    Elemtype data;
    struct node *next;
} Node;

Node *initList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

Node *get_tail(Node *L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

Node *insertTail(Node *L, Elemtype i)
{
    Node *p = (Node *)malloc(sizeof(Node));
    L->next = p;
    p->data = i;
    p->next = NULL;
    return p;
}

void listNode(Node *L)
{
    while (L->next != NULL)
    {
        L = L->next;
        printf("%d ", L->data);
    }
    printf("\n");
}

// 删除中间节点
void delMiddleNode(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *q = slow->next;
    slow->next = q->next;
    free(q);
}
int main(void)
{
    Node *List = initList();
    Node *tail = initList();
    tail = get_tail(List);
    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);
    tail = insertTail(tail, 7);
    listNode(List);
    delMiddleNode(List);
    listNode(List);
    return 0;
}