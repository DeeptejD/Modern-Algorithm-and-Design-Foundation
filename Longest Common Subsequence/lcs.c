#include <stdio.h>
#include <string.h>
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
        for (int j = 1; j <= n; j++)
        {
            if (x[j - 1] == y[i - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = smax(L[i - 1][j], L[i][j - 1]);
        }
    }
}

void sequence(int ss[], int m, int n)
{
    int i = m, j = n, k = m;
    while (i > 0)
    {
        if (L[i][j] == L[i - 1][j])
            ss[k] = 0, k--, i--;
        else
            ss[k] = 1, i--, j--, k--;
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
    char x[] = "010110110", y[] = "10010101";
    int m = strlen(y), n = strlen(x), ss[strlen(y)];
    lcs(x, y, n, m), sequence(ss, m, n);
    printf("Length of the longest common subsequence is: %d\nThe longest subsequence is: ", L[m][n]), show(y, ss, m);
    return 0;
}
