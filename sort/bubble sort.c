#include <stdio.h>
void bubble(int arr[])
{
    int i;
    int temp;
    for (i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main(void)
{
    int arr[10] = {8, 7, 10, 12, 13, 15, 14, 16, 11, 19};

    bubble(arr);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}