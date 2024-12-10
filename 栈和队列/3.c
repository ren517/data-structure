#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct stack
{
    ElemType data;
    struct stack *next;
} Stack;

Stack *initStack()
{
    Stack *head = (Stack *)malloc(sizeof(Stack));
    head->data = 0;
    head->next = NULL;
    return head;
}

void pull(Stack *L, ElemType e)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data = e;
    p->next = L->next;
    L->next = p;
}

void pop(Stack *L, ElemType *e)
{
    if (L->next == NULL)
    {
        printf("空的");
        return 0;
    }

    Stack *temp = (Stack *)malloc(sizeof(Stack));
    *e = L->next->data;
    temp = L->next;
    L->next = temp->next;
    free(temp);
}

void getTop(Stack *L, ElemType *e)
{
    if (L->next == NULL)
    {
        printf("空的");
        return 0;
    }

    *e = L->next->data;
}

int main(void)
{
    Stack *L;
    L = initStack();
    int e;
    pull(L, 10);
    pull(L, 20);
    pull(L, 30);
    pop(L, &e);
    printf("%d\n", e);
    getTop(L, &e);
    printf("%d\n", e);
    return 0;
}