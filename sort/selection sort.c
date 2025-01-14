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
                //将min更改，并且继续寻找数组中有没有更小的值
                min = j;
            }
        }
        //交换，按顺序排列第一小，第二小……
        temp = arr[min];
        arr[min] = arr[i];
        arr [i] = temp;
    }
    
    //遍历输出
    for(i = 0 ; i < 10 ; i++)
    {
        printf("%d ",arr[i]);
    }   

    return 0;
}