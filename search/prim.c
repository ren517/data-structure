#include <stdio.h>
#include <stdlib.h>

typedef int EdgeType;
typedef char VertexType; // 顶点

#define MAXSIZE 100
#define MAX 0X7fffffff

typedef struct
{
    VertexType vertex[MAXSIZE];
    EdgeType arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
} Mat_Grph;

void create_graph(Mat_Grph *G)
{
    G->vertex_num = 9;
    G->edge_num = 15;
    G->vertex[0] = 'A';
    G->vertex[1] = 'B';
    G->vertex[2] = 'C';
    G->vertex[3] = 'D';
    G->vertex[4] = 'E';
    G->vertex[5] = 'F';
    G->vertex[6] = 'G';
    G->vertex[7] = 'H';
    G->vertex[8] = 'I';

    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = 0; j < G->vertex_num; j++)
        {
            if (i == j)
            {
                G->arc[i][j] = 0;
            }
            else
            {
                G->arc[i][j] = MAX;
            }
        }
    }

    G->arc[0][1] = 10;
    G->arc[0][5] = 11;

    G->arc[1][2] = 18;
    G->arc[1][6] = 16;
    G->arc[1][8] = 12;

    G->arc[2][3] = 22;
    G->arc[2][8] = 8;

    G->arc[3][4] = 20;
    G->arc[3][6] = 24;
    G->arc[3][7] = 16;
    G->arc[3][8] = 21;

    G->arc[4][5] = 26;
    G->arc[4][7] = 7;

    G->arc[5][6] = 17;
    G->arc[6][7] = 19;

    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = 0; j < G->vertex_num; j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }
}

void prim(Mat_Grph *G)
{
    int i, j, k;
    int min;
    int weight[MAXSIZE];    // 候选边
    int vex_index[MAXSIZE]; // 值从出发点开始，下标表示到达点，数组值表示出发点

    weight[0] = 0;
    vex_index[0] = 0;

    for (i = 0; i < G->vertex_num; i++)
    {
        weight[i] = G->arc[0][i];
        vex_index[i] = 0;
    }

    // 找到
    for (i = 1; i < G->vertex_num; i++)
    {
        min = MAX;
        j = 0;
        k = 0;
        // 找到最小权值
        while (j < G->vertex_num)
        {
            if (weight[j] != 0 && weight[i] < min)
            {
                min = weight[j];
                k = j;
            }
            j++;
        }

        // printf("(%d , %d) ", vex_index[k], k);
        printf("第%d次连接 (%c , %c)\n", i, G->vertex[vex_index[k]], G->vertex[k]);
        weight[k] = 0;

        for (j = 0; j < G->vertex_num; j++)
        {
            if (weight[j] != 0 && G->arc[k][j] < weight[j])
            {
                weight[j] = G->arc[k][j];
                vex_index[j] = k;
            }
        }
    }
}

int main(void)
{
    Mat_Grph G;
    create_graph(&G);
    prim(&G);

    return 0;
}