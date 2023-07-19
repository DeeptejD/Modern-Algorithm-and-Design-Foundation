// hamiltonian
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

void show(int x[], int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d ", x[i]);
    printf("\n");
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

void nextval(int x[N], int n, int k)
{
    do
    {
        x[k] = (x[k] + 1) % (n + 1);
        if (!x[k])
            return;
        if (a[x[k - 1]][x[k]] != 0)
        {
            int j;
            for (j = 1; j <= k - 1; j++)
                if (x[k] == x[j])
                    break;
            if (j == k)
                if ((k < n) || (k == n && a[x[n]][x[1]] != 0))
                    return;
        }
    } while (1);
}

void ham(int x[N], int n, int k)
{
    do
    {
        nextval(x, n, k);
        if (!x[k])
            return;
        if (k == n)
            show(x, n);
        else
            ham(x, n, k + 1);
    } while (1);
}

int main(int argc, char const *argv[])
{
    int n, x[N], colors, v;
    printf("Enter the number of nodes: "), sint(n);
    getmat(a, n);
    printf("Enter the starting vertex: "), sint(v);
    // we want to make the first vertex as the starting vertex
    x[1] = v;
    for (int i = 2; i <= n; i++)
        x[i] = 0;
    printf("The poss hamiltonian cycles are\n");
    ham(x, n, 2);
    return 0;
}

// 8
// 1 2
// 1 7
// 8 2
// 8 7
// 2 3
// 7 6
// 3 6
// 3 4
// 6 5
// 5 4
// 1 3
// -1 -1
// 1
 