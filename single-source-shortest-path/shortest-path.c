#include <stdio.h>
#define sint(x) scanf("%d", &x);
#define N 10
#define false 0
#define true 1

void fillzeroes(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
}

void fillinf(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = __INT_MAX__;
}

void getmat(int a[][N], int e[][N], int n)
{
    int s, d, w;
    for (int i = 0; i <= (n * (n - 1)) / 2; i++)
    {
        printf("Enter edges\nEnter -1 -1 to exit\n");
        scanf("%d %d", &s, &d);
        printf("Enter weight: ");
        sint(w);
        if (s == -1 && d == -1)
            return;
        else if (s < 0 || d >= n)
        {
            printf("Invalid source or destination\n");
            n++;
        }
        else
        {
            a[s][d] = w, e[s][d] = 1;
            a[d][s] = w, e[d][s] = 1;
        }
    }
}

void showmat(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == __INT_MAX__)
                printf("x ");
            else
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void shortestpath(int v, int cost[][N], int dist[], int n)
{
    // making dist have the length of the shortest path from  vertex v to j in a directed graph G
    int s[N];
    for (int i = 0; i < n; i++)
    {
        s[i] = false, dist[i] = cost[v][i];
    }
    s[v]=true, dist[v]=0.0;
    for(int i=1;i<n-1;i++)
    {
        // determine n-1 paths from vertex v
        s[u]=true;
        
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
