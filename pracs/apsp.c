#include <stdio.h>
#include <limits.h>
#define sint(x) scanf("%d", &x)
#define N 30

void fillinf(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = INT_MAX;
}

void fillz(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                a[i][j] = 0;
}

int _min(int a, int b)
{
    return a < b ? a : b;
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

void showmat(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == INT_MAX)
                printf("x ");
            else
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void allpair(int cost[][N], int a[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = a[i][j];
    fillz(cost, n); // zeroes in the principle diagonal
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cost[i][j] = (cost[i][k] + cost[k][j] < cost[i][j]) ? cost[i][k] + cost[k][j] : cost[i][j];
}

int main(int argc, char const *argv[])
{
    int cost[N][N], a[N][N], n;
    sint(n);
    fillinf(a, n);
    getmat(a, n);
    allpair(cost, a, n);
    printf("The shortest path matrix is\n");
    showmat(cost, n);
    return 0;
}
