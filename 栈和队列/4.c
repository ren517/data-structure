#include <stdio.h>
#define MAXSIZE 100
// 队定义
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
} Queue;

// 初始化队列
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

// 出队
ElemType dequeue(Queue *Q)
{
    if (Q->front == Q->rear)
    {
        printf("空的");
        return 0;
    }
    ElemType e = Q->data[Q->front];
    Q->front++;
    return e;
}

// 调整队列
int queueFull(Queue *Q)
{
    if (Q->front > 0)
    {
        int step = Q->front;
        for (int i = Q->front; i <= Q->rear; i++)
        {
            Q->data[i - step] = Q->data[i];
        }
        Q->front = 0;
        Q->rear = Q->rear - step;
        return 1;
    }
    else
    {
        printf("满了\n");
        return 0;
    }
}

// 入队
ElemType equeue(Queue *Q, ElemType e)
{
    if (Q->rear >= MAXSIZE)
    {
        if (!queueFull(Q))
        {
            return 0;
        }
    }
    Q->data[Q->rear] = e;
    Q->rear++;
    return 1;
}

// 获取队头数据
ElemType getHead(Queue *Q)
{
    if (Q->front == Q->rear)
    {
        printf("空的");
        return 0;
    }

    int e = Q->data[Q->front];
    return e;
}

int main(void)
{
    Queue Q;
    initQueue(&Q);
    equeue(&Q, 10);
    equeue(&Q, 20);
    equeue(&Q, 30);
    int data = dequeue(&Q);
    printf("%d\n", data);
    data = getHead(&Q);
    printf("%d\n", data);
    
    return 0;
}