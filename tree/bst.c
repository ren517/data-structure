#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct BSTnode
{
    int key;
    int data;
    struct BSTnode *lchild;
    struct BSTnode *rchild;
} BSTtree;

// 定义 BSTtree 结构体指针
typedef BSTtree *BSTtreePtr;

Elemtype arr[] = {19, 17, 15, 12, 9, 0, 0, 13, 0, 0, 16, 0, 0, 18, 0, 0, 25, 22, 21, 0, 0, 23, 0, 0, 30, 26, 0, 0, 35, 0, 0};
Elemtype idx = 0;

// 创建二叉搜索树的函数
void createTree(BSTtreePtr *p)
{
    if (arr[idx] == 0)
    {
        *p = NULL;
    }
    else
    {
        *p = (BSTtree *)malloc(sizeof(BSTtree));
        if (*p == NULL)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        (*p)->data = arr[idx];
        idx++;
        createTree(&((*p)->lchild));
        idx++;
        createTree(&((*p)->rchild));
    }
}

// 中序遍历二叉搜索树的函数
void inOrder(BSTtreePtr L)
{
    if (L == NULL)
    {
        return;
    }
    inOrder(L->lchild);
    printf("%d ", L->data);
    inOrder(L->rchild);
}

// 迭代法搜索二叉搜索树的函数
BSTtreePtr BST_search(BSTtreePtr L, int key)
{
    while (L != NULL && key != L->data)
    {
        if (key > L->data)
        {
            L = L->rchild;
        }
        else
        {
            L = L->lchild;
        }
    }
    if (L == NULL)
    {
        printf("search fail\n");
        return NULL;
    }
    else
    {
        printf("BSTtree 中有 %d\n", L->data);
        return L;
    }
}

// 插入节点到二叉搜索树的函数
int BST_insert(BSTtreePtr *L, int data)
{
    if (*L == NULL)
    {
        *L = (BSTtree *)malloc(sizeof(BSTtree));
        if (*L == NULL)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        (*L)->data = data;
        (*L)->lchild = NULL;
        (*L)->rchild = NULL;
        return 1;
    }
    else if (data == (*L)->data)
    {
        printf("insert fail\n");
        return 0;
    }
    else if (data > (*L)->data)
    {
        return BST_insert(&((*L)->rchild), data);
    }
    else if (data < (*L)->data)
    {
        return BST_insert(&((*L)->lchild), data);
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    BSTtreePtr tree = NULL;

    createTree(&tree);
    inOrder(tree);
    printf("\n");
    BST_insert(&tree, 14);
    inOrder(tree);
    printf("\n");

    // int key;
    // scanf("%d", &key);
    // BSTtreePtr a = BST_search(tree, key);
    // if (a!= NULL) {
    //     printf("%d", a->data);
    // }

    return 0;
}