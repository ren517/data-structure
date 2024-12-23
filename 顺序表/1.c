#include <stdio.h>

#define MIXSIZE 100
//顺序表定义
typedef struct{
    int data[MIXSIZE];
    int length;
}SeqList;
//顺序表初始化
void initList(SeqList *L){
    L->length = 0;
}

int appendElem(SeqList *L,int e)
{
    if (L -> length>= MIXSIZE)
    {
        printf("顺序表已满\n");
        return 0;
    }
    L ->data[L->length] = e;
    L ->length++;
    return 1;
}

//打印顺序表
void listElem(SeqList *L)
{
    for(int i = 0; i < L -> length; i++)
    {
        printf("%d ",L ->data[i]);
    }
    printf("\n");
}

//插入顺序表
int insertElem(SeqList *L, int pos , int e)
{
    if (L -> length>= MIXSIZE)
    {
        printf("顺序表已满\n");
        return 0;
    }

    if(pos > L -> length || pos < 1)
    {
        printf("插入错误\n");
        return 0;
    }

    if(pos <= L ->length)
    {
        for( int i = L ->length-1 ; i >= pos ; i--)
        {
            L ->data [i+1] = L->data[i];
        }
        L -> data[pos-1] = e;
        L -> length++;
    }
    return 1;
}
/*
//删除顺序表
int deleteElem(SeqList *L, int pos)
{
    if(pos > L -> length || pos < 1)
    {
        printf("删除错误\n");
        return 0;
    }
    if(pos <= L ->length)
    {
        for(int i = pos-1 ; i < L ->length ; i++)
        {
            L -> data[i] = L -> data [i+1];
        }
        L -> length--;
    }
    return 1;
}
*/
//以上为自己写，能实现删除数据功能，缺点：不能让用户知道删除内容

int deleteElem(SeqList *L, int pos , int *e)
{
    if(pos > L -> length || pos < 1)
    {
        printf("删除错误\n");
        return 0;
    }
    *e = L ->data [pos-1];//用指针修改delData的地址，间接改数据
    if(pos <= L ->length)
    {
        for(int i = pos-1 ; i < L ->length ; i++)
        {
            L -> data[i] = L -> data [i+1];
        }
        L -> length--;
    }
    return 1;
}

int findElem(SeqList *L, int e)
{
    for (int i =0 ; i < L->length ; i++)
    {
        if(L->data[i] == e)
        {
            return i+1;
        }
    }
    return 0;
}

int main(void){

    SeqList list;
    initList(&list);
    printf("初始化成功，目前长度占用%d\n",list.length);
    printf("目前占用内存%zu字节\n",sizeof(list.data));

    appendElem(&list,88);
    appendElem(&list,82);
    appendElem(&list,33);
    appendElem(&list,22);
    appendElem(&list,10);
    appendElem(&list,60);
    listElem(&list);
    insertElem(&list,3,39);
    listElem(&list);
    int delData;
    deleteElem(&list,3,&delData);
    printf("被删除数据为%d\n",delData);
    listElem(&list);
    printf("60在第%d位上\n",findElem(&list,60));
    return 0;
}