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
// 找到链表环的入口
Node *findBegin(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            Node *p = fast;
            int count = 1;
            while (p->next != slow)
            {
                count++;
                p = p->next;
            }
            fast = head;
            slow = head;
            for (int i = 0; i < count; i++)
            {
                fast = fast->next;
            }

            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main(void)
{
    Node *List = initList();
    Node *tail = initList();
    tail = get_tail(List);
    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    Node *three = tail;

    tail = insertTail(tail, 4);
    tail = insertTail(tail, 5);
    tail = insertTail(tail, 6);
    tail = insertTail(tail, 7);
    tail = insertTail(tail, 8);
    tail->next = three;
    Node *p = findBegin(List);
    printf("链表中环的开始位置为：%d\n", p->data);
    listNode(List);
    return 0;
}