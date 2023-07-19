// mcoloring is an undirected graph
#include <stdio.h>
#include <limits.h>

#define N 30
#define sint(x) scanf("%d", &x)

int a[N][N];

void fillzeroes(int a[][N], int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = 0;
}

void getmat(int a[][N], int n)
{
    printf("Enter the source and the destination (-1 -1 to quit)\n");
    int s, d;
    for (int i = 1; i <= n * (n - 1) / 2; i++)
    {
        sint(s), sint(d);
        if (s == -1 && d == -1)
            return;
        if (s < 1 || s > n || d < 1 || d > n)
            printf("Invalid source or destination, try again\n"), i--;
        else
            a[s][d] = a[d][s] = 1;
    }
}

void show(int x[], int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d ", x[i]);
    printf("\n");
}

void nextval(int n, int colors, int x[], int k)
{
    do
    {
        x[k] = (x[k] + 1) % (colors + 1);
        if (!x[k])
            return;
        int j;
        for (j = 1; j <= n; j++)
        {
            if (a[k][j] != 0 && (x[k] == x[j]))
                break;
        }
        if (j == n + 1)
            return;
    } while (1);
}

void color(int n, int colors, int x[], int k)
{
    do
    {
        nextval(n, colors, x, k);
        if (!x[k])
            return;
        else if (k == n)
            show(x, n);
        else
            color(n, colors, x, k + 1);
    } while (1);
}

int main(int argc, char const *argv[])
{
    int n, x[N], colors;
    printf("Enter the number of nodes: "), sint(n);
    getmat(a, n);
    printf("Enter the number of colors: "), sint(colors);
    for (int i = 1; i <= n; i++)
        x[i] = 0;
    printf("\nThe possible ways to color the nodes of the graph are\n");
    color(n, colors, x, 1);
    return 0;
}