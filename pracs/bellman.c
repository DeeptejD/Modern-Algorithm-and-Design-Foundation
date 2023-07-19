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

void showdist(int dist[N], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);
    printf("\n");
}

void bellman(int cost[][N], int dist[N], int n, int v)
{
    for (int i = 0; i < n; i++)
        dist[i] = cost[v][i];
    dist[v] = 0;
    for (int i = 1; i < n - 1; i++)
    {
        showdist(dist, n);
        for (int j = 0; j < n; j++)
        {
            if (j != v)
                for (int k = 0; k < n; k++)
                    if (cost[k][j] != INT_MAX)
                        dist[j] = (dist[j] < cost[k][j] + dist[k]) ? dist[j] : cost[k][j] + dist[k];
        }
    }
}

int main(int argc, char const *argv[])
{
    int cost[N][N], n, v, dist[N];
    printf("Enter the number of nodes: "), sint(n);
    fillinf(cost, n);
    getmat(cost, n);
    printf("enter source: "), sint(v);
    bellman(cost, dist, n, --v);
    return 0;
}

// 7
// 1 2
// 6
// 1 3
// 5
// 1 4
// 5
// 2 5
// -1
// 3 2
// -2
// 3 5
// 1
// 4 3
// -2
// 4 6
// -1
// 5 7
// 3
// 6 7
// 3
// -1
// -1
// 1