#include <stdio.h>
#include <limits.h>
#define N 20
#define sint(x) scanf("%d", &x)

void fillzeroes(int a[][N], int nodes)
{
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            a[i][j] = 0;
}

void fillinf(int a[][N], int nodes)
{
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            a[i][j] = INT_MAX;
}



int main(int argc, char const *argv[])
{
    int nodes, edges, t[N][2], e[N][N], cost[N][N];
    printf("Enter the number of vertices: "), sint(nodes);

    fillzeroes(e, nodes), fillinf(cost, nodes);

    return 0;
}
