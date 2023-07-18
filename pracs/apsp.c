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

int main(int argc, char const *argv[])
{
    
    return 0;
}
