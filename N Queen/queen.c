// 211105017 Deeptej Dhauskar
#include <stdio.h>
#define sint(x) scanf("%d", &x)
#define new printf("\n")
#define N 20
int mat[N];

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
    new, new;
    for (int i = 1; i <= n; i++)
    {
        printf("\t%d", i);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("\n\n%d", i);
        for (int j = 1; j <= n; j++)
        {
            if (mat[i] == j)
                printf("\tQ"); // indicates that a queen has been placed
            else
                printf("\t_"); // queen not placed
        }
    };
    new, new;
}

void nqueen(int row, int n)
{
    for (int col = 1; col <= n; col++)
    {
        if (place(row, col))
        {
            mat[row] = col;
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
    printf("Enter the size: ");
    sint(n);
    nqueen(1, n);
    return 0;
}


// Enter the size: 
// 4


//         1       2       3       4

// 1       _       Q       _       _

// 2       _       _       _       Q

// 3       Q       _       _       _

// 4       _       _       Q       _



//         1       2       3       4

// 1       _       _       Q       _

// 2       Q       _       _       _

// 3       _       _       _       Q

// 4       _       Q       _       _