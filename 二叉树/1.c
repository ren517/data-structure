#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct treeNood
{
    struct treeNood *lchild;
    struct treeNood *rchlid;
    ElemType data;
} TreeNood;

typedef TreeNood *BiTree;

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;
// 前序遍历
void preOrder(BiTree L)
{
    if (L == NULL)
    {
        return;
    }
    printf("%c ", L->data);
    preOrder(L->lchild);
    preOrder(L->rchlid);
}

void inOrder(BiTree L)
{
    if (L == NULL)
    {
        return;
    }
    inOrder(L->lchild);
    printf("%c ", L->data);
    inOrder(L->rchlid);
}

void postOrder(BiTree L)
{
    if (L == NULL)
    {
        return;
    }
    postOrder(L->lchild);
    postOrder(L->rchlid);
    printf("%c ", L->data);
}

void createTree(BiTree *L)
{
    ElemType ch;
    ch = str[idx];
    if (ch == '#')
    {
        *L = NULL;
    }
    else
    {
        *L = (BiTree)malloc(sizeof(TreeNood));
        (*L)->data = ch;
        idx++;
        createTree(&(*L)->lchild);
        idx++;
        createTree(&(*L)->rchlid);
    }
}
int main(void)
{
    BiTree p;
    createTree(&p);
    preOrder(p);
    printf("\n");
    inOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");

    return 0;
}