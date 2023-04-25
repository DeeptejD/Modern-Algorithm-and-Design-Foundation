#include <stdio.h>
#include <limits.h>
#define sint(x) scanf("%d", &x);
#define N 30
#define inf 99999

void fillinf(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = inf;
}

void fillz(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                a[i][j] = 0;
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

void allpair(int cost[][N], int a[][N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = a[i][j];
    fillz(cost, n);
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
    }
}

void showmat(int a[][N], int n)
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

/*
textbook
3
1 2 4
1 3 11
2 3 2
2 1 6
3 1 3
-1 -1
*/

/*
4
1 2 5
1 3 9
2 3 1
3 4 2
4 2 3
-1 -1
*/

/*
3
1 2 7
1 3 5
2 3 2
-1 -1
*/
