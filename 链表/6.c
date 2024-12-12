// 找到相同的后缀
#include <stdio.h>
#include <malloc.h>
// 快慢指针 找到倒数第k个节点
typedef char Elemtype;
typedef struct node
{
    Elemtype data;
    struct node *next;
} Node;

// 初始化
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

Node *insertTail(Node *L, Elemtype i)
{
    Node *p = (Node *)malloc(sizeof(Node));
    L->next = p;
    p->data = i;
    p->next = NULL;
    return p;
}

// 遍历
void listNode(Node *L)
{
    while (L->next != NULL)
    {
        L = L->next;
        printf("%c", L->data);
    }
    printf("\n");
}

// 快慢指针
void findNodeFS(Node *L, int k)
{
    Node *fast = L->next;
    Node *slow = L->next;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    printf("倒数第%d个节点值为: %d\n", k, slow->data);
}

Node *initListWithElem(Elemtype e)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;
    return node;
}

Node *initListWithNode(Node *tail, Node *node)
{
    tail->next = node;
    node->next = NULL;
    return node;
}

Node *findIntersectionNode(Node *headA, Node *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    Node *p = headA;
    int lenA = 0;
    int lenB = 0;
    while (p != NULL)
    {
        p = p->next;
        lenA++;
    }
    p = headB;
    while (p != NULL)
    {
        p = p->next;
        lenB++;
    }
    Node *fast;
    Node *slow;
    int step;
    if (lenA > lenB)
    {
        step = lenA - lenB;
        fast = headA;
        slow = headB;
    }
    else
    {
        step = lenB - lenA;
        fast = headB;
        slow = headA;
    }
    for (int i = 0; i < step; i++)
    {
        fast = fast->next;
    }
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}

int main(void)
{
    Node *ListA = initList();
    Node *ListB = initList();
    Node *tailA = get_tail(ListA);
    Node *tailB = get_tail(ListB);
    tailA = insertTail(tailA, 'l');
    tailA = insertTail(tailA, 'o');
    tailA = insertTail(tailA, 'a');
    tailA = insertTail(tailA, 'd');
    tailB = insertTail(tailB, 'b');
    tailB = insertTail(tailB, 'e');

    Node *nodeI = initListWithElem('i');
    tailA = initListWithNode(tailA, nodeI);
    tailB = initListWithNode(tailB, nodeI);

    Node *nodeN = initListWithElem('n');
    tailA = initListWithNode(tailA, nodeN);
    tailB = initListWithNode(tailB, nodeN);

    Node *nodeG = initListWithElem('g');
    tailA = initListWithNode(tailA, nodeG);
    tailB = initListWithNode(tailB, nodeG);

    listNode(ListA);
    listNode(ListB);

    printf("%c\n", findIntersectionNode(ListA, ListB)->data);
    return 0;
}