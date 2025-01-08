#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bigint
{
    char *num;  // 指向长整数的数组
    char minus; // 符号 1为正数，-1为负数
    int digit;  // 实际位数
} BIGINT;

typedef BIGINT *pBIGINT;

void BigIntTrim(pBIGINT num1)
{
    int i;
    for (i = num1->digit - 1; i >= 0; i--)
    {
        if (num1->num[i] != '0') // 找到第一位不为0的元素
            break;
    }
    if (i < 0)
    {
        num1->digit = 1;
        num1->num[0] = '0';
    }
    else
        num1->digit = i + 1;
}

void BigIntTrans(pBIGINT num1)
{
    char *temp;
    int i, k;
    int len;
    len = strlen(num1->num);
    if (!(temp = (char *)malloc(sizeof(char) * len)))
    {
        printf("内存分配失败\n");
        exit(0);
    }
    memset(temp, 0, len);
    i = 0;
    num1->minus = 1;
    if (num1->num[0] == '-')
    {
        num1->minus = -1;
        i++;
    }
    k = 0;
    while (num1->num[i] != '\0')
    {
        if (num1->num[i] >= '0' && num1->num[i] <= '9')
        {
            temp[k] = num1->num[i];
            k++;
        }
        i++;
    }

    for (i = 0; i < num1->digit; i++)
    {
        num1->num[i] = '0';
    }
    num1->digit = k;                   // 实际数字位数
    for (i = 0, k--; k >= 0; k--, i++) // temp中为倒序存储，转换为顺序
    {
        num1->num[i] = temp[k];
    }
    BigIntTrim(num1); // 整理输入的大整数
    free(temp);
}

void BigIntPrint(pBIGINT num1)
{
    int j;
    if (num1->minus == -1)
    {
        printf("-");
    }
    if (num1->digit == 1 && num1->num[0] == 0)
    {
        printf("0");
    }
    else
    {
        for (j = num1->digit - 1; j >= 0; j--)
        {
            printf("%c", num1->num[j]);
        }
    }
    printf("\n");
}

void initList(BIGINT *num)
{
    num->digit = strlen("123456789987654321");
    num->num = (char *)malloc(sizeof(char) * (num->digit + 1)); // 分配足够的内存，包括字符串结束符
    if (num->num == NULL)                                       // 检查内存分配是否成功
    {
        printf("内存分配失败");
        exit(EXIT_FAILURE);
    }
    strcpy(num->num, "000123456789987654321"); // 复制字符串到分配的内存
    num->minus = 1;                            // 初始化符号位为正数
}

int main(void)
{
    BIGINT *NUM;
    NUM = (BIGINT *)malloc(sizeof(BIGINT));
    initList(NUM);
    BigIntTrans(NUM);
    BigIntPrint(NUM);
    free(NUM->num); // 释放num的内存
    free(NUM);      // 释放NUM的内存
    return 0;
}