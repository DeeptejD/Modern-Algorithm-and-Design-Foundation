#include <stdio.h>
#include <limits.h>
#define sint(x) scanf("%d", &x)
#define inf INT_MAX
#define N 15

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
        printf("Enter weight: ");
        sint(w);
        a[--x][--y] = w;
    }
}

int min_(int a, int b)
{
    return (a = a < b ? a : b);
}

int fgraph(int a[][N], int n)
{
    int dist[N]; // dist[i] will store the min distance from node i to the destination ie. node n-1
    dist[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        dist[i] = inf;

        // now check in front
        for (int j = i; j < n; j++)
        {
            if (a[i][j] == inf)
                continue;
            else
                dist[i] = min_(dist[i], a[i][j] + dist[j]);
        }
    }
    return dist[0];
}

int bgraph(int a[][N], int n)
{
    int dist[N];
    dist[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dist[i] = inf;
        for (int j = i; j >= 0; j--)
        {
            if (a[j][i] == inf)
                continue;
            else
            {
                dist[i] = min_(dist[i], dist[j] + a[j][i]);
            }
        }
    }
    return dist[n - 1];
}

int main(int argc, char const *argv[])
{
    int n, a[N][N];
    printf("Enter the number of vertices: ");
    sint(n);
    fillinf(a, n);
    getmat(a, n);
    int mincost = fgraph(a, n);
    printf("The shortest path from 1 to %d using the forward approach is: %d\n", n, mincost);
    mincost = 0;
    mincost = bgraph(a, n);
    printf("The shortest path from 1 to %d using the backward approach is: %d\n", n, mincost);
    return 0;
}

/*
12
1 2 3
1 3 8
1 4 4
1 5 5
2 6 4
2 7 3
3 6 5
3 7 4
4 7 3
4 8 2
5 7 2
5 8 1
6 9 3
6 10 4
7 9 4
7 10 7
7 11 6
8 10 8
8 11 7
9 12 3
10 12 1
11 12 4
-1 -1
*/
