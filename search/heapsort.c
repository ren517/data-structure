#include <stdio.h>

// 此处修改值，如修改地址，只是将 p 和 q 这两个指针变量的值（即它们存储的地址）进行了交换。无法改变 *p 和 *q 的值
// 如要修改arr[3] = arr[7]
//  | | |8| | | |12|
// 0 1 2 3 4 5 6  7
// 用地址传递
//  | | |12| | | |8|
// 0 1 2  7 4 5 6 3
// 没有修改arr[3]和arr[7]的值
//  void swap(int *p, int *q)
//  {
//      int *temp;
//      temp = p;
//      p = q;
//      q = temp;
//  }

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

void heap_spot(int arr[], int n)
{
    // 建堆
    int i;
    for (i = n / 2; i >= 0; i--) // n/2取到最大父节点4，依次遍历
    {
        heapity(arr, n, i);
    }
    // 排序
    for (i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]); // 删除arr[i]
        heapity(arr, i, 0);
    }
}

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