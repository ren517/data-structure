#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;

typedef struct ThreadNood
{
    Elemtype data;
    struct ThreadNood *lchild;
    struct ThreadNood *rchild;
    int ltag;
    int rtag;

} ThreadNood;

typedef ThreadNood *ThreadTree;

char str[] = "ABDH##I##EJ###CF##G##";
int idx = 0;

ThreadTree prev;

void createTree(ThreadTree *p)
{
    Elemtype ch;
    ch = str[idx++];
    if (ch == '#')
    {
        *p = NULL;
    }
    else
    {
        *p = (ThreadTree)malloc(sizeof(ThreadNood));
        (*p)->data = ch;

        createTree(&(*p)->lchild);
        if ((*p)->lchild != NULL)
        {
            (*p)->ltag = 0;
        }

        createTree(&(*p)->rchild);
        if ((*p)->rchild != NULL)
        {
            (*p)->rtag = 0;
        }
    }
}

void threading(ThreadTree T)
{
    if (T != NULL)
    {
        threading(T->lchild);
        if (T->lchild == NULL)
        {
            T->ltag = 1;
            T->lchild = prev;
        }
        if (prev->rchild == NULL)
        {
            prev->rtag = 1;
            prev->rchild = T;
        }
        prev = T;
        threading(T->rchild);
    }
}

void inOrderThreading(ThreadTree *head, ThreadTree L)
{
    *head = (ThreadTree)malloc(sizeof(ThreadNood));
    (*head)->ltag = 0;
    (*head)->rtag = 1;
    (*head)->rchild = (*head);

    if (L == NULL)
    {
        (*head)->lchild = *head;
    }
    else
    {
        (*head)->lchild = L;
        prev = (*head);

        threading(L);

        // 最后一个节点线索化
        prev->rchild = *head;
        prev->rtag = 1;

        // 头节点右孩子指向最后一个节点
        (*head)->rchild = prev;
    }
}

void inOrder(ThreadTree H)
{
    ThreadTree curr;
    curr = H->lchild;

    while (curr != H)
    {
        while (curr->ltag == 0)
        {
            curr = curr->lchild;
        }

        printf("%c ", curr->data);

        while (curr->rtag == 1 && curr->rchild != H)
        {
            curr = curr->rchild;
            printf("%c ", curr->data);
        }
        curr = curr->rchild; // 相当于链表里的next
    }
    printf("\n");
}
int main(void)
{
    ThreadTree head;
    ThreadTree T;
    createTree(&T);
    inOrderThreading(&head, T);
    inOrder(head);

    return 0;
}