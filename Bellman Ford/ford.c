#include <stdio.h>
#include <limits.h>
#define N 30
#define inf 99999
#define sint(x) scanf("%d", &x);

void fillinf(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = inf;
}

void getmat(int a[][N], int n)
{
    int w, x, y;
    // printf("Enter -1 -1 to exit: ");
    for (int i = 0; i < n * (n - 1); i++)
    {
        sint(x);
        sint(y);
        if (x == -1 && y == -1)
            return;
        // printf("Enter weight: ");
        sint(w);
        a[--x][--y] = w;
    }
}

int _min(int a, int b)
{
    return a < b ? a : b;
}

void showmat(int a[N], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d", a[i]);
}

void bellman(int src, int cost[][N], int v, int e)
{
    int dist[v];
    for (int i = 0; i < v; i++)
        dist[i] = cost[src][i];
    dist[src] = 0;
    for (int i = 1; i <= v - 1; i++)
    {
        for(int u=0;i<v;u++)
        {
            if()
        }
    }
    showmat(dist, v);
}

int main(int argc, char const *argv[])
{
    int n, a[N][N], src, e;
    sint(n);
    sint(e);
    fillinf(a, n);
    getmat(a, n);
    sint(src);
    bellman(--src, a, n, e);
    return 0;
}

/*
5
9
1 2 4
1 4 5
2 4 -6
3 2 2
3 5 1
4 3 3
4 5 -2
5 4 -2
5 2 -3
-1 -1
1
*/