#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
// 栈定义
typedef struct
{
    int *data;
    int top;
} Stack;
// 栈初始化
Stack *initStack()
{
    Stack *L = (Stack *)malloc(sizeof(Stack));
    L->data = (int *)malloc(sizeof(int) * MAXSIZE);
    L->top = -1;
    return L;
}

int push(Stack *L, int e)
{
    if (L->top >= MAXSIZE - 1)
    {
        printf("满了\n");
        return 0;
    }

    L->top++;
    L->data[L->top] = e;
    return 1;
}

int pop(Stack *L, int *e)
{
    if(L->top==-1)
    {
        printf("空的");
        return 0;
    }
    *e = L->data[L->top]; // 用指针修改delData的地址，间接改数据
    L->top--;
    return 1;
}

int getTop(Stack *L, int *e)
{
    if (L->top == -1)
    {
        printf("空的");
    }
    *e = L->data[L->top];
    return 0;
}

int main(void)
{

    Stack *s;
    s = initStack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    int e;
    pop(s, &e);
    printf("%d\n", e);
    getTop(s, &e);
    printf("%d\n", e);
    return 0;
}