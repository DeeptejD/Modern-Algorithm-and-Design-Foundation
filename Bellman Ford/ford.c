#include <stdio.h>
#include <limits.h>
#define N 50
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
    {
        if (a[i] == inf)
            printf("inf\t");
        else
            printf("%d\t", a[i]);
    }
}

int incoming(int u, int a[][N], int v)
{
    for (int i = 0; i < v; i++)
        if (a[i][u] != inf)
            return 1;
    return 0;
}

void show2dmat(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == inf)
                printf("inf ");
            else
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void bellman(int src, int cost[][N], int v)
{
    int dist[N];
    for (int i = 0; i < v; i++)
        dist[i] = cost[src][i]; // init dist arr
    dist[src] = 0;              // dist to src is zero
    // printf("The cost matrix\n");
    // show2dmat(cost, v);
    // printf("\n");
    printf("k = 1: ");
    showmat(dist, v);
    printf("\n");
    for (int k = 2; k <= v - 1; k++) // this for loop is for the times
    {
        // printf("entered the k for loop\nk = %d\n", k);
        for (int u = 0; u < v; u++)
        {
            // printf("entered the u for loop\nu = %d\n", u);
            if (u != src && incoming(u, cost, v) == 1)
            {
                // printf("entered the if condition inside thee u for loop\n");
                for (int i = 0; i < v; i++)
                {
                    // printf("entered the i for loop\ni = %d\n", i);
                    if (cost[i][u] != inf)
                    {
                        // printf("entered the if condition inside the i for loop\n");
                        if (dist[u] > dist[i] + cost[i][u])
                            dist[u] = dist[i] + cost[i][u];
                        // printf("k=%d  u=%d  i=%d\n", k, u, i);
                    }
                    // showmat(dist, v);
                    // printf("\n");
                }
            }
            // showmat(dist, v);
            // printf("\n");
        }
        printf("k = %d: ", k);
        showmat(dist, v);
        printf("\n");
    }
    // showmat(dist, v);
}

int main(int argc, char const *argv[])
{
    int n, a[N][N], src;
    sint(n);
    fillinf(a, n);
    getmat(a, n);
    sint(src);
    bellman(--src, a, n);
    return 0;
}

/*
(sus test case)
5
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

/*
textbook (working test case)
7
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3
-1 -1
1
*/
