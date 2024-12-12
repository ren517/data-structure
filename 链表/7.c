// 利用空间换时间，删除绝对值相同的元素
#include <stdio.h>
#include <malloc.h>
#include <math.h>

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

// 删除绝对值相同的节点
void removeNode(Node *L, int n)
{
    Node *p = L;
    int index; // 用作数组下标
    int *q = (int *)malloc(sizeof(int) * (n + 1));

    for (int i = 0; i < n + 1; i++)
    {
        *(q + i) = 0;
        index = i;
    }
    free(q);

    while (p->next != NULL)
    {
        index = abs(p->next->data);
        if (*(q + index) == 0)
        {
            *(q + index) = 1;
            p = p->next;
        }

        else
        {
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
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

int main(void)
{
    Node *list = initList();
    Node *tail = get_tail(list);
    tail = insertTail(tail, 21);
    tail = insertTail(tail, -15);
    tail = insertTail(tail, -15);
    tail = insertTail(tail, -7);
    tail = insertTail(tail, 15);
    listNode(list);
    removeNode(list, 15);
    listNode(list);

    return 0;
}