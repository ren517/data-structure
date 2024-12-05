#include <stdio.h>
#include <malloc.h>
//����ָ�� �ҵ�������k���ڵ�
typedef int Elemtype;
typedef struct node
{
    Elemtype data;
    struct node* next;
}Node;

//��ʼ��
Node* initList()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head -> data = 0;
    head -> next = NULL;
    return head;
}

//β�巨
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

//����ָ��
void findNodeFS(Node* L, int k)
{
    Node* fast = L -> next;
    Node* slow = L -> next;
    for(int i = 0 ; i < k ; i++)
    {
        fast = fast -> next;
    }
    while(fast != NULL)
    {
        fast = fast -> next;
        slow = slow -> next;
    }
    printf("������%d���ڵ�ֵΪ: %d\n",k , slow -> data);
}


int main(void)
{
    Node* List = initList();
    Node *tail = get_tail(List);
    tail = insertTail(tail,10);
    tail = insertTail(tail,20);
    tail = insertTail(tail,30);
    tail = insertTail(tail,40);
    tail = insertTail(tail,50);
    tail = insertTail(tail,60);
    tail = insertTail(tail,70);
    tail = insertTail(tail,80);
    listNode(List);
    findNodeFS(List , 2);
    return 0;
}