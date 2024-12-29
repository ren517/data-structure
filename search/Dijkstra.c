// 最短路径
#include <stdio.h>
#include <stdlib.h>

typedef int EdgeType;
typedef char VertexType; // 顶点

#define MAXSIZE 100
#define MAX 0X10000
#define MAXEDGE 200

typedef struct
{
    EdgeType vertex[MAXSIZE];
    EdgeType arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
} Mat_Grph;

void create_graph(Mat_Grph *G)
{
    G->vertex_num = 9;
    G->edge_num = 15;
    G->vertex[0] = 0;
    G->vertex[1] = 1;
    G->vertex[2] = 2;
    G->vertex[3] = 3;
    G->vertex[4] = 4;
    G->vertex[5] = 5;
    G->vertex[6] = 6;
    G->vertex[7] = 7;
    G->vertex[8] = 7;

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

    G->arc[0][1] = 1;
    G->arc[0][2] = 5;

    G->arc[1][2] = 3;
    G->arc[1][3] = 7;
    G->arc[1][4] = 5;

    G->arc[2][4] = 1;
    G->arc[2][5] = 7;

    G->arc[3][4] = 2;
    G->arc[3][6] = 3;

    G->arc[4][5] = 3;
    G->arc[4][6] = 6;
    G->arc[4][7] = 9;

    G->arc[5][7] = 5;

    G->arc[6][7] = 2;
    G->arc[6][8] = 7;

    G->arc[7][8] = 4;

    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = 0; j < G->vertex_num; j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }
}

int choose(int distance[], int found[], int vertex_num)
{
    int min = MAX;
    int minPos = -1; // 最小值的位置
    for (int i = 0; i < vertex_num; i++)
    {
        if (distance[i] < min && found[i] == 0)
        {
            min = distance[i];
            minPos = i;
        }
    }
    return minPos;
}

void dijkstra(Mat_Grph G, int begin)
{
    int found[MAXSIZE];    // 顶点是否走过
    int path[MAXSIZE];     // 路径
    int distance[MAXSIZE]; // begin到每个顶点的最短距离
    for (int i = 0; i < G.vertex_num; i++)
    {
        found[i] = 0;
        path[i] = -1;
        distance[i] = G.arc[begin][i];
    }

    found[begin] = 1;
    distance[begin] = 0;

    int next;
    for (int j = 0; j < G.vertex_num; j++)
    {
        next = choose(distance, found, G.vertex_num);
        // printf("%d ", next);
        found[next] = 1;
        for (int j = 0; j < G.vertex_num; j++)
        {
            if (found[j] == 0)
            {
                if (distance[next] + G.arc[next][j] < distance[j])
                {
                    distance[j] = distance[next] + G.arc[next][j];
                    path[j] = next;
                }
            }
        }
    }

    for (int i = 1; i < G.vertex_num; i++)
    {
        printf("V0 -> V%d: ", G.vertex[i]);

        int j = i;
        printf("V%d <-", i);
        while (path[j] != -1)
        {
            printf("V%d <-", path[j]);
            j = path[j];
        }
        printf("V0\n");
    }
}

int main(void)
{
    Mat_Grph G;
    create_graph(&G);
    int begin = 0;
    dijkstra(G, begin);

    return 0;
}