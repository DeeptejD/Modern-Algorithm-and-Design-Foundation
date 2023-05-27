#include <stdio.h>
#include <string.h>
// #define sint(X) scanf("%d", &x)
#define N 256

int L[N][N];

int smax(int a, int b)
{
    return a > b ? a : b;
}

void lcs(char x[], char y[], int n, int m)
{
    for (int i = 0; i <= m; i++)
        L[i][0] = 0;
    for (int j = 0; j <= n; j++)
        L[0][j] = 0;
    for (int i = 1; i <= m; i++)
    {
        // printf("\n");
        for (int j = 1; j <= n; j++)
        {
            // printf("%c %c    ", y[i - 1], x[j - 1]);
            if (x[j - 1] == y[i - 1])
            {
                // printf("same adding 1 to %d\t", L[i - 1][j - 1]);
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else
            {
                // printf("not same\t");
                L[i][j] = smax(L[i - 1][j], L[i][j - 1]);
            }
            // printf("\tL[%d][%d]: %d\n", i - 1, j - 1, L[i][j]);
        }
    }
}

// void temp(int m, int n)
// {
//     for (int i = 0; i <= m; i++)
//     {
//         for (int j = 0; j <= n; j++)
//             printf("%3d", L[i][j]);
//         printf("\n");
//     }
// }

void sequence(int ss[], int m, int n)
{
    // stop when row value is zero
    int i = m, j = n, k = m;
    while (i > 0)
    {
        // printf("i: %d, j: %d, k: %d\nL[i][j]: %d, L[i-1][j]: %d\n", i, j, k, L[i][j], L[i - 1][j]);
        if (L[i][j] == L[i - 1][j])
        {
            ss[k] = 0;
            k--;
            i--;
        }
        else
        {
            ss[k] = 1;
            i--;
            j--;
            k--;
        }
    }
}

void show(char y[], int ss[], int m)
{
    for (int i = 1, j = 0; i <= m, j < m; i++, j++)
    {
        if (ss[i])
            printf("%c", y[j]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    char x[] = "010110110";
    char y[] = "10010101";
    int m = strlen(y), n = strlen(x);
    int ss[strlen(y)];
    lcs(x, y, n, m);
    // temp(m, n);
    sequence(ss, m, n);
    printf("Length of the longest common subsequence is: %d\n", L[m][n]);
    printf("The longest subsequence is: ");
    show(y, ss, m);
    return 0;
}
