#include <stdio.h>
#include <malloc.h>
//���ٶ�̬�ڴ棬��˳�����ڶ���
#define MAXSIZE 100
//˳�����
typedef struct
{
    int *data;
    int length;
}SeqList;


int appendElem(SeqList *L,int e)
{
    if (L -> length>= MAXSIZE)
    {
        printf("˳�������\n");
        return 0;
    }
    L ->data[L->length] = e;
    L ->length++;
    return 1;
}

//��ӡ˳���
void listElem(SeqList *L)
{
    for(int i = 0; i < L -> length; i++)
    {
        printf("%d ",L ->data[i]);
    }
    printf("\n");
}

//����˳���
int insertElem(SeqList *L, int pos , int e)
{
    if (L -> length>= MAXSIZE)
    {
        printf("˳�������\n");
        return 0;
    }

    if(pos > L -> length || pos < 1)
    {
        printf("�������\n");
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
//ɾ��˳���
int deleteElem(SeqList *L, int pos)
{
    if(pos > L -> length || pos < 1)
    {
        printf("ɾ������\n");
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
//����Ϊ�Լ�д����ʵ��ɾ�����ݹ��ܣ�ȱ�㣺�������û�֪��ɾ������

int deleteElem(SeqList *L, int pos , int *e)
{
    if(pos > L -> length || pos < 1)
    {
        printf("ɾ������\n");
        return 0;
    }
    *e = L ->data [pos-1];//��ָ���޸�delData�ĵ�ַ����Ӹ�����
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

SeqList* initList()
{
     SeqList *L = (SeqList *)malloc(sizeof(SeqList));
     L ->data = (int*)malloc(sizeof(int) * MAXSIZE);
     L ->length =0;
     return L;
}

int main(void)
{
    SeqList *list = initList();
    printf("��ʼ���ɹ���Ŀǰ����ռ��%d\n",list->length);
    printf("Ŀǰռ���ڴ�%u�ֽ�\n",sizeof(list->data));

    appendElem(list,88);
    appendElem(list,82);
    appendElem(list,33);
    appendElem(list,22);
    appendElem(list,10);
    appendElem(list,60);
    listElem(list);
    insertElem(list,3,39);
    listElem(list);
    int delData;
    deleteElem(list,3,&delData);
    printf("��ɾ������Ϊ%d\n",delData);
    listElem(list);
    printf("60�ڵ�%dλ��\n",findElem(list,60));
    return 0;
}