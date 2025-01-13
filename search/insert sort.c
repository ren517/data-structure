#include <stdio.h>
void InsertSearch(int *arr, int n)
{
    int i;
    int j;
    int temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; j--)
        {
            arr[j] = arr[j - 1]; // 1 2 3 4 5 6 0 所有元素向前移动
        }
        arr[j] = temp;
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
    int arr[10] = {2, 1, 3, 5, 4, 0, 6, 8, 9, 7};
    InsertSearch(arr, 10);
    print(arr);

    return 0;
}