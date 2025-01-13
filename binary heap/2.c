#include <stdio.h>

// 交换两个指针所指向元素的值
void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

// 维护堆的性质(下沉)
// n为数组个数
// i为父节点
void heapity(int arr[], int n, int i)
{
    int largest = i;
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;
    if (lchild < n && arr[lchild] > arr[largest])
    {
        largest = lchild;
    }
    if (rchild < n && arr[rchild] > arr[largest])
    {
        largest = rchild;
    }
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapity(arr, n, largest);
    }
}

// 堆排序函数
void heap_spot(int arr[], int n)
{
    // 建堆
    int i;
    for (i = n / 2; i >= 0; i--)
    {
        heapity(arr, n, i);
    }
    // 排序
    for (i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapity(arr, i, 0);
    }
}

// 打印数组元素
void print(int arr[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(void)
{
    int arr[10] = {8, 7, 10, 12, 13, 15, 14, 16, 11, 19};
    heap_spot(arr, 10);
    print(arr);

    return 0;
}