#include <stdio.h>
void InsertSearch(int *arr, int n)
{
    int i;
    int j;
    int step;
    int temp;
    for (step = n / 2; step > 0; step /= 2)
    {
        for (i = 1; i < n; i += step)
        {
            temp = arr[i];
            for (j = i; j >= step && arr[j - step] > temp; j -= step)
            {
                arr[j] = arr[j - step];
            }
            arr[j] = temp;
        }
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