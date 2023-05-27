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
    for (int i = 0; i <= n; i++)
        L[i][0] = 0;
    for (int j = 0; j <= m; j++)
        L[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i] == y[j])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = smax(L[i - 1][j], L[i][j - 1]);
        }
    }
}

int main(int argc, char const *argv[])
{
    char x[] = "010110110";
    char y[] = "10010101";
    int m = strlen(y), n = strlen(x);
    lcs(x, y, n, m);
    printf("Length of the longest common subsequence is: %d\n", L[n][m]);
    return 0;
}
