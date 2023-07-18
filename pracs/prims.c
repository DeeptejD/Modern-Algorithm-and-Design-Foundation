// prims (our aim ni prims is to get a MST and store it in 1x2 array t)

#include <stdio.h>
#include <limits.h>
#define N 20
#define sint(x) scanf("%d", &x)

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
            a[i][j] = INT_MAX;
}

void getmat(int e[][N], int c[][N], int n)
{
    int s, d, w;
    printf("Enter the edges and weights (-1 -1 to exit)\n");
    for (int i = 0; i <= (n * (n - 1)) / 2; i++)
    {
        sint(s), sint(d);
        if (s == -1 && d == -1)
            return;
        else if (s < 0 || d >= n)
        {
            printf("Invalid edge\n");
            i--;
        }
        else
        {
            printf("Weight: "), sint(w);
            e[s][d] = e[d][s] = 1;
            c[s][d] = c[d][s] = w;
        }
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

int prims(int e[][N], int c[][N], int t[][2], int n)
{
    // s1: find a min cost edge
    int min = INT_MAX, k, l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (e[i][j] != 0 && c[i][j] < min)
                min = c[i][j], k = i, l = j;

    int mincost = c[k][l];
    t[0][0] = k, t[0][1] = l;

    // init near array
    int near[N];
    for (int i = 0; i < n; i++)
        near[i] = (c[i][k] < c[i][l]) ? k : l;

    near[k] = near[l] = -1;

    // n-2 more times
    for (int i = 1; i < n - 1; i++)
    {
        int j; // j is an index such that near[j]!=-1 and cost[j][near[j]] is min
        min = INT_MAX;
        for (int k = 0; k < n; k++)
            if ((near[k] != -1) && (c[k][near[k]] < min))
                min = c[k][near[k]], j = k;

        t[i][0] = j, t[i][1] = near[j], mincost += c[j][near[j]];
        near[j] = -1;

        // update near
        for (int x = 0; x < n; x++)
            if ((near[x] != -1) && ((c[x][near[x]]) > c[x][j]))
                near[x] = j;
    }

    // print the mst
    printf("MST\n");
    for (int i = 0; i < n - 1; i++)
        printf("%d %d\n", t[i][0], t[i][1]);

    return mincost;
}

int main(int argc, char const *argv[])
{
    int n, e[N][N], c[N][N], t[N][2];
    printf("Enter the number of nodes: "), sint(n);
    fillzeroes(e, n);
    fillinf(c, n);
    getmat(e, c, n);
    printf("Edge matrix\n");
    showmat(e, n);
    printf("\n");
    printf("Cost matrix\n");
    showmat(c, n);
    printf("\n");

    // actual prims logic
    printf("The mincost is: %d\n", prims(e, c, t, n));
    return 0;
}
