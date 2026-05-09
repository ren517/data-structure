/*********************************************************************
程序名:
    版权:
    作者:郑仪群
    日期: 2025-11-13 22:38
    说明:
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;
typedef char ElemType;
typedef struct  treeNood
{
    struct treeNood *lchild;
    struct treeNood *rchild;
    ElemType data;
} TreeNood;

// tree string tree = "ABDH#K###E##CFI###G#J##";
string tree = "ABDH#K###E##CFI###G#J##";
typedef TreeNood *BiTree;
int idx = 0;
void creatTree(BiTree *L)
{
    if(tree[idx] == '#')
    {
        *L = NULL;
    }
    else
    {
        *L = new TreeNood;
        (*L)->data = tree[idx];
        idx++;
        creatTree(&(*L)->lchild);
        idx++;
        creatTree(&(*L)->rchild);
    }
}

void preOrder(BiTree L)
{
    if (L == NULL)
    {
        return;
    }
    else
    {
        cout << L->data << ' ';
        preOrder(L->lchild);
        preOrder(L->rchild);
    }
}

void inOrder(BiTree L)
{
    if (L == NULL)
    {
        return;
    }
    else
    {
        inOrder(L->lchild);
        cout << L->data << ' ';
        inOrder(L->rchild);
    }
}

void postOrder(BiTree L)
{
    if (L == NULL)
    {
        return;
    }
    else
    {
        postOrder(L->lchild);
        postOrder(L->rchild);
        cout << L->data << ' ';
    }
}
int main(void)
{
    BiTree my_tree;
    creatTree(&my_tree);
    cout << "The preOrder is " << endl;
    preOrder(my_tree);
    cout << endl;
    cout << "The inOrder is " << endl;
    inOrder(my_tree);
    cout << endl;
    cout << "The postOrder is " << endl;
    postOrder(my_tree);
    cout << endl;

    return 0;
}