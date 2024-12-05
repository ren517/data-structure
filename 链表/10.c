#include <stdio.h>
#include <malloc.h>

typedef int Elemtype;

typedef struct node
{
    Elemtype data;
    struct node* next;
}Node;

Node *initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head ->data = 0;
    head -> next = NULL;
    return head;
}

Node* get_tail(Node* L)
{
    Node* p = L;
    while( p -> next != NULL)
    {
        p = p-> next;
    }
    return p;

}

Node* insertTail(Node* L , Elemtype i)
{
    Node* p = (Node*)malloc(sizeof(Node));
    L -> next = p;
    p -> data = i;
    p -> next = NULL;
    return p;
}

void listNode(Node* L)
{
    while(L -> next != NULL)
    {
        L = L -> next;
        printf("%d ",L -> data);
    }
    printf("\n");

}

//删除中间节点
int delMiddleNode(Node* head)
{
    Node* fast = head -> next;
    Node* slow = head;

    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    } 
    Node* q = slow -> next;
    slow -> next = q -> next;
    free(q);
    return 1;
}

void reOrderList(Node* head)
{
    Node* fast = head -> next;
    Node* slow = head;

    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    } 

    Node* first = NULL;
    Node* second = slow -> next;
    slow -> next = NULL;//打断链表
    Node* third = NULL;
    while(second != NULL)
    {
        third = second -> next;
        second -> next = first;
        first = second;
        second = third; 
    }

    Node* p1 = head -> next;
    Node* q1 = first;
    Node* p2 , *q2;
    
    while(p1 != NULL && q1 != NULL)
    {
        p2 = p1 -> next;
        q2 = q1 -> next;

        p1 -> next = q1;
        q1 -> next = p2;

        p1 = p2;
        q1 = q2;
    }

}

int main(void)
{
    Node* List = initList();
    Node* tail = initList();

    tail = get_tail(List);
    tail = insertTail(tail , 1);
    tail = insertTail(tail , 2);
    tail = insertTail(tail , 3);
    tail = insertTail(tail , 4);
    tail = insertTail(tail , 5);
    tail = insertTail(tail , 6);
    
    listNode(List);
    reOrderList(List);
    listNode(List);
    return 0;
}