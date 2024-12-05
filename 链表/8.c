//��ת����
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
    head ->data = 0;
    head -> next = NULL;
    return head;
}

//β�巨

Node * get_tail (Node *L)
{
    Node *p = L;
    while(p->next != NULL)
    {
        p = p -> next;
    }
    return p;
}

Node* insertTail(Node *L , ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p ->data =e;
    L -> next = p;
    p ->next =NULL;
    return p;

}

//����
void listNode(Node *L)
{
    while(L->next != NULL)
    {
        L = L -> next;
        printf("%d ", L->data);
    }
    printf("\n");
}

Node* reserveList(Node* head)
{
    Node* first = NULL;
    Node* second = head -> next;
    Node* third;
    while(second != NULL)
    {
        third = second -> next;
        second -> next = first;
        first = second;//first = first -> next
        second = third;//second = second -> next
    }
    Node* hd = initList();
    hd -> next = first;
    return hd;
}

int main(void)
{
    Node *List = initList();
    Node *tail = get_tail(List);
    tail = insertTail(tail,1);
    tail = insertTail(tail,2);
    tail = insertTail(tail,3);
    tail = insertTail(tail,4);
    tail = insertTail(tail,5);
    tail = insertTail(tail,6);
    listNode(List);
    //reserveList(List);
    //listNode(List);���о�Ϊ����д��
    Node* reserve = reserveList(List);
    listNode(reserve);

    return 0;
}