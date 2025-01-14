#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int temp[], int lpos, int rpos, int rightEnd)
{
    int i, leftEnd, numElements, tempPos;
    leftEnd = rpos - 1;
    tempPos = lpos;
    numElements = rightEnd - lpos + 1;

    while (lpos <= leftEnd && rpos <= rightEnd)
    {
        if (arr[lpos] <= arr[rpos])
        {
            temp[tempPos++] = arr[lpos++];
        }
        else
        {
            temp[tempPos++] = arr[rpos++];
        }
    }

    while (lpos <= leftEnd) // 复制剩余的左半部分
    {
        temp[tempPos++] = arr[lpos++];
    }
    while (rpos <= rightEnd) // 复制剩余的右半部分
    {
        temp[tempPos++] = arr[rpos++];
    }

    for (i = 0; i < numElements; i++, rightEnd--) // 将合并后的数组复制回原数组
    {
        arr[rightEnd] = temp[rightEnd];
    }
}

void meSort(int arr[], int temp[], int left, int right)
{
    int center;

    if (left < right)
    {
        center = (left + right) / 2;
        meSort(arr, temp, left, center);
        meSort(arr, temp, center + 1, right);
        merge(arr, temp, left, center + 1, right);
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[10] = {8, 7, 10, 12, 13, 15, 14, 16, 11, 19};
    int *temp = (int *)malloc(10 * sizeof(int));
    meSort(arr, temp, 0, 9);

    print(arr, 10);

    free(temp);

    return 0;
}