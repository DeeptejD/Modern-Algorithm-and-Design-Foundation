// our aim is to get a mst and store it in 1x2 arr t
#include <stdio.h>
#define sint(x) scanf("%d", &x);
#define N 10

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

int prim(int e[][N], int cost[][N], int n, int t[][2])
{
    int k, l, min = __INT_MAX__;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (e[i][j] == 1 && cost[i][j] < min)
            {
                min = cost[i][j];
                k = i, l = j;
            }
        }
    }
    int mincost = cost[k][l];
    // printf("mincost: %d\nk: %d\nl: %d\n", mincost, k, l);
    t[0][0] = k, t[0][1] = l;

    // intializing near array
    int near[N];
    for (int i = 0; i < n; i++)
    {
        if (cost[i][l] < cost[i][k])
            near[i] = l;
        else
            near[i] = k;
    }
    near[k] = near[l] = -1;

    for (int i = 1; i < n - 1; i++)
    {
        // find an index j such that near[j]!=0 and cost[j, near[j]] is minimum
        int j;
        min = __INT_MAX__;
        for (int k = 0; k < n; k++)
        {
            if (near[k] != -1 && cost[k][near[k]] < min)
            {
                min = cost[k][near[k]];
                j = k;
            }
        }
        // we got j
        t[i][0] = j, t[i][1] = near[j];
        mincost += cost[j][near[j]];
        near[j] = -1;

        // updating near
        for (int x = 0; x < n; x++)
        {
            if ((near[x] != -1) && (cost[x][near[x]] > cost[x][j]))
                near[x] = j;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    return mincost;
}

int main()
{
    // Getting the input for cost and e matrices
    int n;
    printf("Enter the number of nodes: ");
    sint(n);
    int e[N][N], cost[N][N], t[N][2];
    fillzeroes(e, n), fillinf(cost, n);
    getmat(cost, e, n);
    showmat(cost, n), showmat(e, n);

    // finding an edge (k, l) st it has the min cost
    int mincost = prim(e, cost, n, t);
    printf("mincost: %d\n", mincost);
    return 0;
}

// 8
// 0 1
// 12
// 0 2
// 11
// 1 3
// 4
// 2 3
// 14
// 1 4
// 5
// 3 4
// 3
// 3 6
// 6
// 3 5
// 8
// 5 6
// 15
// 6 7
// 10
// 4 7
// 17