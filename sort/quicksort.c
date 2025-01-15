#include <stdio.h>
#include <stdlib.h>

#define N 10

int searchMid(int a, int b, int c)
{
  int max = a > b ? a : b;
  max = max > c ? max : c;
  int min = a < b ? a : b;
  min = min < c ? min : c;
  int second = a + b + c - max - min;
  return second;
}

void quick_sort(int arr[], int low, int last)
{
  int i = low;
  int j = last;
  int key = searchMid(arr[low], arr[last], arr[(low + last) / 2]);

  while (i < j)
  {
    while (i < j && arr[j] >= key)
    {
      j--;
    }
    arr[i] = arr[j];

    while (i < j && arr[i] <= key)
    {
      i++;
    }
    arr[j] = arr[i];
  }
  arr[i] = key;

  if (i - 1 > low)
  {
    quick_sort(arr, low, i - 1);
  }

  if (i + 1 < last)
  {
    quick_sort(arr, i + 1, last);
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

  quick_sort(arr, 0, N - 1);
  print(arr);

  return 0;
}