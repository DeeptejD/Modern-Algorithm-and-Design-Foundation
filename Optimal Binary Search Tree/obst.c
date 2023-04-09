#include <stdio.h>
#include <limits.h>
#include <string.h>
#define sint(x) scanf("%d", &x);
#define N 20
#define inf INT_MAX

struct key
{
    int w, r, c;
};

void get0(int a[N], int n)
{
    for (int i = 0; i <= n; i++)
        sint(a[i]);
}

void get1(int a[N], int n)
{
    for (int i = 1; i <= n; i++)
        sint(a[i]);
}

void get1s(int a[N], int n)
{
    for (int i = 1; i <= n; i++)
        gets(a[i]);
}

int find(struct key g[][N], int i, int j)
{
    int min = inf, l;
    for (int m = g[i][j - 1].r; m <= g[i + 1][j].r; m++)
    {
        if ((g[i][m - 1].c + g[m][j].c) < min)
        {
            min = g[i][m - 1].c + g[m][j].c;
            l = m;
        }
    }
    return l;
}

void obst(struct key g[][N], int q[N], int p[N], int n, char *a[N])
{
    int k;
    for (int i = 0; i <= n - 1; i++)
    {
        // init
        g[i][i].w = q[i], g[i][i].r = g[i][i].c = 0;
        g[i][i + 1].w = q[i] + q[i + 1] + p[i + 1];
        g[i][i + 1].r = i + 1;
        g[i][i + 1].c = q[i] + q[i + 1] + p[i + 1];
    }
    g[n][n].w = q[n], g[n][n].r = g[n][n].c = 0;
    for (int m = 2; m <= n; m++)
    {
        for (int i = 0; i <= n - m; i++)
        {
            int j = i + m;
            g[i][j].w = g[i][j - 1].w + p[j] + q[j];
            k = find(g, i, j);
            g[i][j].c = g[i][j].w + g[i][k - 1].c + g[k][j].c;
            g[i][j].r = k;
        }
    }
    printf("c[%d][%d] = %d\nw[%d][%d] = %d\nr[%d][%d] = %d\nMinimum cost of the BST is: %d\nroot: %s\n", 0, n, g[0][n].c, 0, n, g[0][n].w, 0, n, g[0][n].r, g[0][n].c, a[g[0][n].r - 1]);
}

int main(int argc, char const *argv[])
{
    int n;
    char *a[N] = {"Apr", "Mar", "May", "Oct", "Sept"};
    int p[N], q[N];
    struct key g[N][N];
    printf("Enter the number of identifiers: ");
    sint(n);
    // printf("Enter the identifiers: ");
    // get1s(a, n);
    printf("Enter the probabilities for a succesfull search: ");
    get1(p, n);
    printf("Enter the probablities for an unsuccesfull search: ");
    get0(q, n);
    obst(g, q, p, n, a);
    return 0;
}

/*
textbook 5.18
4
3
3
1
1
2
3
1
1
1
*/

/*
textbook 5.17
3
1
1
1
1
1
1
1
*/

/*
tutorial
5
3
4
3
2
4
4
4
5
4
5
4
*/
