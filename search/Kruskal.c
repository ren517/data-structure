#include <stdio.h>
#include <stdlib.h>

typedef int EdgeType;
typedef char VertexType; // 顶点

#define MAXSIZE 100
#define MAX 0X7fffffff
#define MAXEDGE 200

typedef struct
{
    VertexType vertex[MAXSIZE];
    EdgeType arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
} Mat_Grph;

typedef struct
{
    int begin;
    int end;
    int weight;
} Edge;

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

void swap(Edge *edges, int j)
{
    // swap begin
    int temp;
    temp = edges[j].begin;
    edges[j].begin = edges[j + 1].begin;
    edges[j + 1].begin = temp;

    // swap weight
    temp = edges[j].weight;
    edges[j].weight = edges[j + 1].weight;
    edges[j + 1].weight = temp;

    // swap end
    temp = edges[j].end;
    edges[j].end = edges[j + 1].end;
    edges[j + 1].end = temp;
}

void shotedge(Edge edges[], int edge_num)
{
    // 冒泡
    for (int i = 0; i < edge_num; i++)
    {
        for (int j = 0; j < edge_num - 1 - i; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                swap(edges, j);
            }
        }
    }
}

int find(int *parent, int index)
{
    while (parent[index] > 0)
    {
        index = parent[index];
    }
    return index;
}

void Kruskal(Mat_Grph G)
{
    Edge edges[MAXEDGE];
    int k = 0;

    // create edge[]
    for (int i = 0; i < G.vertex_num; i++)
    {
        for (int j = i + 1; j < G.vertex_num; j++)
        {
            if (G.arc[i][j] < MAX)
            {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G.arc[i][j];
                k++;
            }
        }
    }
    // 排序
    shotedge(edges, G.edge_num);
    // int a = 0;
    // while (a < 15)
    // {
    //     printf("edge[%d] %d %d %d\n", a, edges[a].begin, edges[a].end, edges[a].weight);
    //     a++;
    // }
    int parent[MAXSIZE];

    for (int i = 0; i < G.vertex_num; i++)
    {
        parent[i] = 0;
    }

    // kruskal算法
    int n, m;
    for (int i = 0; i < G.edge_num; i++)
    {
        n = find(parent, edges[i].begin);
        m = find(parent, edges[i].end);

        if (n != m)
        {
            parent[n] = m;
            // printf("%d %d %d\n", edges[i].begin, edges[i].end, edges[i].weight);
            printf("%c %c %d\n", G.vertex[edges[i].begin], G.vertex[edges[i].end], edges[i].weight);
        }
    }
}

int main(void)
{
    Mat_Grph G;
    create_graph(&G);
    Kruskal(G);
    return 0;
}