// nqueens
#include <stdio.h>
#include <limits.h>

#define N 30
#define sint(x) scanf("%d", &x)

// global
int mat[N];

int abs(int a)
{
    return a < 0 ? -a : a;
}

int place(int row, int col)
{
    for (int i = 1; i <= row - 1; i++)
    {
        if (mat[i] == col)
            return 0;
        else if (abs(mat[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void show(int n)
{
    for (int i = 1; i <= n; i++)
        printf("\t%d", i);
    for (int i = 1; i <= n; i++)
    {
        printf("\n\n%d", i);
        for (int j = 1; j <= n; j++)
        {
            if (mat[i] == j)
                printf("\tQ");
            else
                printf("\t-");
        }
    }
    printf("\n\n");
}

void nqueen(int row, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(row, i))
        {
            mat[row] = i;
            if (row == n)
            {
                show(n);
                return;
            }
            else
                nqueen(row + 1, n);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the size: "), sint(n);
    nqueen(1, n);

    return 0;
}