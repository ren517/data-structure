#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXSIZE 8
#define ElemType int
// 队列的最大空间
// 队列初始化
typedef struct queue
{
    ElemType *base; // 指向队列空间的基址
    int front;      // 头指针
    int rear;       // 尾指针
} Queue;

void InitQueue(Queue *Q)
{
    // 为队列分配存储空间
    Q->base = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    assert(Q->base != NULL);
    // 初始时队列为空，头指针和尾指针都指向0位置
    Q->front = Q->rear = 0;
}

// 入队
void EnQueue(Queue *Q, ElemType x)
{
    // 判断循环队列是否已满
    if (((Q->rear + 1) % MAXSIZE) == Q->front)
        return;
    // 队列未满，将数据入队
    Q->base[Q->rear] = x;
    // 更改尾指针的指向
    Q->rear = (Q->rear + 1) % MAXSIZE;
}

// 出队
ElemType DeQueue(Queue *Q)
{
    // 判断循环队列是否为空
    if (Q->front == Q->rear)
    {
        return 0;
    }
    // 如果非空，实现可循环出队
    Q->front = (Q->front + 1) % MAXSIZE;
    ElemType e = Q->base[Q->front];
    return e;
}

// 获得头元素
void GetHdad(Queue *Q, ElemType *v)
{
    // 判断循环队列是否为空
    if (Q->front == Q->rear)
        return;
    // 如果队列不为空，获取队头元素
    *v = Q->base[Q->front];
}

int main(void)
{
    Queue Q;
    InitQueue(&Q);
    EnQueue(&Q, 10);
    EnQueue(&Q, 20);
    EnQueue(&Q, 30);
    printf("%d\n", DeQueue(&Q));
    int Head;
    GetHdad(&Q, &Head);
    printf("%d\n", Head);
}