#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *initList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 1;
    head->next = head;
    return head;
}

void insertHead(Node *L, int e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
    if (L == L->next)
    {
        p->next = p;
    }
    else
    {
        Node *tail = L;
        while (tail->next != L)
        {
            tail = tail->next;
        }
        tail->next = p;
    }
}

void deleteNode(Node *prev)
{
    Node *temp = prev->next;
    prev->next = temp->next;
    free(temp);
}

int main(void)
{
    Node *p;
    p = initList();
    // 创建一个包含 10 个人的循环链表
    for (int i = 2; i <= 10; i++)
    {
        insertHead(p, i);
    }
    // int m = 10;
    int n = 3;
    int k = 0;
    Node *current = p;
    do
    {
        k++;
        if (k == n)
        {
            // 输出出列的人的编号
            printf("%d ", current->next->data);
            deleteNode(current);
            k = 0;
        }
        else
        {
            current = current->next;
        }
    } while (current->next != current);
    return 0;
}
