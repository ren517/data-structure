#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node* next;
}Node;

Node *initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head -> data = 0;
    head -> next = NULL;
    return head;
}

//头插法
void insertHead(Node *L, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p -> data =e;
    p -> next = L ->next;
    L -> next = p;
}

//遍历
void listNode(Node *L)
{
    Node *p = L-> next;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p ->next;
    }
    printf("\n");
}

int main(void)
{
    Node *List = initList();
    insertHead( List , 10);
    insertHead( List , 20);
    insertHead( List , 30);
    listNode(List);

    return 0;
}