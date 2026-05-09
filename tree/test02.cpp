/*********************************************************************
程序名:
    版权:
    作者:郑仪群
    日期: 2025-11-13 22:38
    说明:
*********************************************************************/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct HTNode
{
    int m_parent;
    int m_leftNode;
    int m_rightNode;
    int m_wight;
};

struct HTree
{
    HTNode *m_base;
    int m_length;
};

void initHTree(HTree &tree, int numOfLeaf)
{
    int num = numOfLeaf * 2 - 1;
    tree.m_base = new HTNode[num];

    if(tree.m_base)
    {
        tree.m_length = 0;
        for (int i = 0; i < numOfLeaf; i++)
        {
            tree.m_base[i].m_parent = -1;
            tree.m_base[i].m_leftNode = -1;
            tree.m_base[i].m_rightNode = -1;

            cout << "Pls input the weight of node" << endl;
            int weight;
            cin >> weight;
            tree.m_base[i].m_wight = weight;

            tree.m_length++;
        }
        for (int i = numOfLeaf; i < num; i++)
        {
            tree.m_base[i].m_parent = -1;
            tree.m_base[i].m_leftNode = -1;
            tree.m_base[i].m_rightNode = -1;
            tree.m_base[i].m_wight = -1;
            tree.m_length++;
        }
    }
    else
    {
        cout << "out of memory" << endl;
    }
}

void showTree(HTree tree)
{
    for (int i = 0; i < tree.m_length; i++)
    {
        cout << tree.m_base[i].m_wight << endl;
    }
}
int findMindRoot(HTree tree, int pos)
{
    int w = 1000;
    int min;
    for (int i = 0; i < pos; i++)
    {
        if(tree.m_base[i].m_parent == -1 && tree.m_base[i].m_wight < w)
        {
            w = tree.m_base[i].m_wight;
            min = i;
        }
    }
    tree.m_base[min].m_parent = 1;
    return min;
}

void constructHTree(HTree &tree)
{
    int root1, root2;
    for (int i = (tree.m_length + 1) / 2; i < tree.m_length; i++)
    {
        root1 = findMindRoot(tree, i);
        root2 = findMindRoot(tree, i);

        tree.m_base[i].m_leftNode = root1;
        tree.m_base[i].m_rightNode = root2;
        tree.m_base[i].m_wight = tree.m_base[root1].m_wight + tree.m_base[root2].m_wight;
        tree.m_base[root1].m_parent = i;
        tree.m_base[root2].m_parent = i;
    }
}

void HCoding(HTree tree, char ** &code)
{
    code = new char *[(tree.m_length + 1) / 2];

    if(!code)
    {
        cout << "out of menory" << endl;
        exit(-1);
    }
    char *temp = new char[(tree.m_length + 1) / 2];
    if (!temp)
    {
        cout << "out of menory" << endl;
        exit(-1);
    }
    temp[(tree.m_length + 1) / 2] = '\0';
    for (int i = 0; i < (tree.m_length + 1) / 2; i++)
    {
        int start = (tree.m_length + 1) / 2 - 1;
        int pos = i;
        int parent = tree.m_base[i].m_parent;
        while(parent != -1)
        {
            if(tree.m_base[parent].m_leftNode == pos)
            {
                temp[--start] = '0';
            }
            else
            {
                temp[--start] = '1';
            }
            pos = parent;
            parent = tree.m_base[parent].m_parent;
        }
        code[i] = new char[(tree.m_length + 1) / 2 - start];
        strcpy((code[i]), &temp[start]);
    }
    delete temp;
}

void showHCode(char **code, HTree tree)
{
    for (int i = 0; i < (tree.m_length + 1) / 2; i++)
    {
        cout << "the   " << i << "node     code is " << code[i] << endl;
    }
}

int main(void)
{
    HTree mytree;
    initHTree(mytree, 6);
    showTree(mytree);
    cout << "****************************" << endl;
    constructHTree(mytree);
    showTree(mytree);
    cout << "****************************" << endl;
    char **mycode;
    HCoding(mytree, mycode);
    showTree(mytree);
    showHCode(mycode, mytree);
    return 0;
}