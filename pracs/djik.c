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

void getmat(int cost[][N], int n, int e)
{
    printf("Enter the elements\n");
    int s, d, w;

    for (int i = 0; i < e; i++)
    {
        sint(s), sint(d);
        if (s < 1 || s > n || d < 1 || d > n)
            printf("Invalid source or destination\nEnter again\n"), i--;
        else
        {
            printf("Enter weight: "), sint(w);
            cost[s][d] = w;
        }
    }
}

enum
{
    false,
    true
};

int findu(int dist[N], int s[N], int n)
{
    int min = INT_MAX, u;
    for (int i = 1; i <= n; i++)
    {
        if ((s[i] == false && dist[i] < min))
        {
            min = dist[i], u = i;
        }
    }
    return u;
}

void showdist(int dist[N], int n)
{
    for (int i = 1; i <= n; i++)
        printf("dist[%d] = %d\n", i, dist[i]);
}

int shortestpath(int cost[][N], int dist[N], int n, int v)
{
    int s[N];
    for (int i = 1; i <= n; i++)
        s[i] = false, dist[i] = cost[v][i];

    s[v] = true, dist[v] = 0;

    printf("Iteration - 1\n");
    showdist(dist, n);

    for (int i = 2; i <= n - 1; i++)
    {
        // we find a u such that s[u]=false and dist[u] is min
        int u = findu(dist, s, n);
        s[u] = true;
        for (int j = 1; j <= n; j++)
        {
            if (s[j] == false && cost[u][j] != INT_MAX)
                dist[j] = (dist[j] < dist[u] + cost[u][j]) ? dist[j] : dist[u] + cost[u][j];
        }
        printf("Iteration - %d\n", i);
        showdist(dist, n);
    }
}

int main(int argc, char const *argv[])
{
    int n, cost[N][N], dist[N], v, e;
    printf("Enter the n of nodes: "), sint(n);
    printf("Enter the n of edges: "), sint(e);
    fillinf(cost, n);
    getmat(cost, n, e);
    printf("Enter the source: "), sint(v);
    shortestpath(cost, dist, n, v);
    printf("Final shortest paths from %d to all the vertices are\n", v);
    showdist(dist, n);
    return 0;
}