#include <stdio.h>
int main(void)
{
    int arr[10];
    int i , j;

    for(i = 0 ; i < 10 ; i++)
    {
        scanf("%d",&arr[i]);
    }

    int temp;
    int min = 0;

    for(i = 0 ; i < 10 ; i++)
    {    
        min = i;

        for(j = i ; j < 10 ; j++)
        {
            if(arr[min] > arr[j])
            {
                //��min���ģ����Ҽ���Ѱ����������û�и�С��ֵ
                min = j;
            }
        }
        //��������˳�����е�һС���ڶ�С����
        temp = arr[min];
        arr[min] = arr[i];
        arr [i] = temp;
    }
    
    //�������
    for(i = 0 ; i < 10 ; i++)
    {
        printf("%d ",arr[i]);
    }   

    return 0;
}