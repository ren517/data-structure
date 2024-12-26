#include <stdio.h>

typedef int EdgeType;
typedef char VertexType; // 顶点

#define MAXSIZE 100
int visited[MAXSIZE];
int front = 0;
int rear = 0;
int queue[MAXSIZE];

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
            G->arc[i][j] = 0;
        }
    }

    G->arc[0][1] = 1;
    G->arc[0][5] = 1;

    G->arc[1][2] = 1;
    G->arc[1][6] = 1;
    G->arc[1][8] = 1;

    G->arc[2][3] = 1;
    G->arc[2][8] = 1;

    G->arc[3][4] = 1;
    G->arc[3][6] = 1;
    G->arc[3][7] = 1;
    G->arc[3][8] = 1;

    G->arc[4][5] = 1;
    G->arc[4][7] = 1;

    G->arc[5][6] = 1;
    G->arc[6][7] = 1;

    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = 0; j < G->vertex_num; j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }
}

void bfs(Mat_Grph G)
{
    int i = 0;
    visited[i] = 1;
    printf("%c\n", G.vertex[i]);
    queue[rear] = i;
    rear++;
    while (front != rear)
    {
        i = queue[front];
        front++;
        for (int j = 0; j < G.vertex_num; j++)
        {
            if (G.arc[i][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                printf("%c\n", G.vertex[j]);
                queue[rear] = j;
                rear++;
            }
        }
    }
}

int main(void)
{
    Mat_Grph G;
    create_graph(&G);
    for (int i = 0; i < G.vertex_num; i++)
    {
        visited[i] = 0;
    }
    bfs(G);
    return 0;
}