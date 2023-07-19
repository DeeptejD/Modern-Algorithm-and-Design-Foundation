// god help me :)

// given the identifiers in increasing order and their probabilities our aim is to find the min cost of the optimal binary search tree for these identifiers

#include <stdio.h>
#include <limits.h>

#define N 30
#define sint(x) scanf("%d", &x)

struct key
{
    int w, r, c;
};

int find(struct key g[][N], int i, int j)
{
    int l, min = INT_MAX;
    for (int m = g[i][j - 1].r; m <= g[i + 1][j].r; m++)
    {
        if (g[i][m - 1].c + g[m][j].c < min)
            min = g[i][m - 1].c + g[m][j].c, l = m;
    }
    return l;
}

void obst(struct key g[][N], int p[N], int q[N], int n, char *a[N])
{
    // make the first 2 rows
    printf("\tw\tc\tr\n\n");
    for (int i = 0; i <= n - 1; i++)
    {
        g[i][i].w = q[i], g[i][i].r = g[i][i].c = 0;
        g[i][i + 1].w = q[i] + q[i + 1] + p[i + 1];
        g[i][i + 1].r = i + 1;
        g[i][i + 1].c = q[i] + q[i + 1] + p[i + 1];
        printf("%d%d\t%d\t%d\t%d\n", g[i][i].w, g[i][i].c, g[i][i].r, i, i);
    }
    g[n][n].w = q[n], g[n][n].r = 0, g[n][n].c = 0;
    printf("%d%d\t%d\t%d\t%d\n", n, n, g[n][n].w, g[n][n].c, g[n][n].r);
    printf("\n\n");

    for (int m = 2; m <= n; m++)
    {
        for (int i = 0; i <= n - m; i++)
        {
            int j = i + m;
            g[i][j].w = p[j] + q[j] + g[i][j - 1].w; // FORMULA
            // find that k
            int k = find(g, i, j);
            g[i][j].r = k;                                     // FORMULA
            g[i][j].c = g[i][j].w + g[i][k - 1].c + g[k][j].c; // FORMULA
            printf("%d%d\t%d\t%d\t%d\n", i, j, g[i][j].w, g[i][j].c, g[i][j].r);
        }
        printf("\n\n");
    }
}

int main(int argc, char const *argv[])
{
    char *a[N] = {"Apr", "Mar", "May", "Oct", "sept"};
    int p[N], q[N], n;
    printf("Enter the number of identifiers: "), sint(n);
    printf("Enter sucess probs\n");
    for (int i = 1; i <= n; i++)
        sint(p[i]);
    printf("Enter failure probs\n");
    for (int i = 0; i <= n; i++)
        sint(q[i]);
    struct key g[N][N];
    obst(g, p, q, n, a);
    return 0;
}