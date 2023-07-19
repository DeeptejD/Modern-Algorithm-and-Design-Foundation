#include <stdio.h>
#include <limits.h>

#define N 30
#define sint(x) scanf("%d", &x)

void fillinf(int cost[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = INT_MAX;
}

void getmat(int cost[][N], int n)
{
    int s, d, w;
    for (int i = 1; i <= n * (n - 1); i++)
    {
        sint(s), sint(d);
        if (s == -1 && d == -1)
            return;
        else if (s < 1 || s > n || d < 1 || d > n)
            printf("Invalid source or destination, try again\n"), i--;
        else
        {
            printf("Weight: "), sint(w);
            cost[--s][--d] = w;
        }
    }
}

int fgraph(int cost[][N], int n)
{
    int dist[N];
    dist[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        dist[i] = INT_MAX;
        // look ahead (forward)
        for (int j = i; j < n; j++)
            if (cost[i][j] != INT_MAX)
                dist[i] = (dist[i] < cost[i][j] + dist[j]) ? dist[i] : cost[i][j] + dist[j];
    }
    return dist[0];
}

int bgraph(int cost[][N], int n)
{
    int dist[N];
    dist[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dist[i] = INT_MAX;
        for (int j = i; j >= 0; j--)
            if (cost[j][i] != INT_MAX)
                dist[i] = (dist[i] < cost[j][i] + dist[j]) ? dist[i] : cost[j][i] + dist[j];
    }
    return dist[n - 1];
}

int main(int argc, char const *argv[])
{
    int n, cost[N][N];
    printf("Enter the number of nodes: "), sint(n);
    fillinf(cost, n);
    getmat(cost, n);
    int mincost = fgraph(cost, n);
    printf("mincost of path (forward approach): %d\n", mincost);
    mincost = bgraph(cost, n);
    printf("mincost of path (forward approach): %d\n", mincost);
    return 0;
}