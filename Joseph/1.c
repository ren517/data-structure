// 约瑟夫环，用数组实现
#include <stdio.h>
int main(void)
{
    int arr[41] = {0};
    int M = 10; // 共10人
    int N = 3;  // 数到三出局
    int alive = M;
    int die = 0;
    int i = 0, k = 0;
    while (die != M)
    {
        i++;
        if (arr[i] == 0)
        {
            k++;
            if (k == N)
            {
                arr[i] = 1;
                die++;
                alive--;
                printf("%d ", i);
                k = 0;
            }
        }
        if (i > M)
        {
            i = 1;
        }
    }
    printf("\n");

    return 0;
}