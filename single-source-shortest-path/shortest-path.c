#include <stdio.h>
#include <limits.h>
#define sint(x) scanf("%d", &x)
#define new printf("\n")
#define N 10
typedef enum
{
    false,
    true
};

void fillinf(int cost[][N], int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cost[i][j] = INT_MAX;
}

void fillzeroes(int e[][N], int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            e[i][j] = 0;
}

void getmat(int cost[][N], int n, int e)
{
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        sint(s), sint(d), sint(w);
        if (s >= 1 && s <= n && d >= 1 && d <= n)
            cost[s][d] = w;
    }
}

void showmat(int a[][N], int n)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= n; j++)
            a[i][j] == INT_MAX ? printf("x ") : printf("%d ", a[i][j]);
        new;
    }
    new;
}

void shortestpath(int cost[][N], int dist[N], int n, int v)
{
    int s[N];
    for (int i = 1; i <= n; i++)
        s[i] = false, dist[i] = cost[v][i];
    s[v] = true, dist[v] = 0;
    printf("Iteration 1\n");
    for (int i = 1; i <= n; i++)
        printf("dist[%d] = %d\n", i, dist[i]);
    new;
    for (int i = 2; i <= n - 1; i++)
    {
        int u, min = INT_MAX;
        for (int k = 1; k <= n; k++)
            if (s[k] == false && dist[k] < min)
                min = dist[k], u = k;
        printf("u: %d\n", u);
        s[u] = true;
        for (int j = 1; j <= n; j++)
        {
            if (cost[u][j] != INT_MAX && s[j] == false)
                if (dist[j] > dist[u] + cost[u][j])
                    dist[j] = dist[u] + cost[u][j];
        }
        printf("Iteration %d\n", i);
        for (int i = 1; i <= n; i++)
            printf("dist[%d] = %d\n", i, dist[i]);
        new;
    }
}

int main(int argc, char const *argv[])
{
    int cost[N][N], dist[N], n, v, e;
    printf("Enter the number of nodes: ");
    sint(n);
    printf("Enter the number of edges: ");
    sint(e);
    fillinf(cost, n);
    getmat(cost, n, e);
    sint(v);

    shortestpath(cost, dist, n, v);
    new;
    printf("Starting vertex: %d\n", v);
    for (int i = 1; i <= n; i++)
        printf("dist[%d] = %d\n", i, dist[i]);
    return 0;
}

/*
8
20
1 2 15
1 3 12
3 2 12
2 4 13
4 3 13
4 5 12
4 7 16
2 5 17
3 7 19
5 7 15
7 5 5
5 8 17
8 5 10
5 6 18
7 8 32
8 6 13
6 8 10
8 7 20
1 5 20
1 7 10
1
*/