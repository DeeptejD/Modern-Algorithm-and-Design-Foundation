#include <stdio.h>
#include <string.h>
#define sint(x) scanf("%d", &x)
#define N 256

int f[N];

int failure(char p[N], int m)
{
    int i, j;
    i = 1, j = 0;
    f[0] = 0;
    while (i < m)
    {
        if (p[j] == p[i])
        {
            f[i] = j + 1;
            i++, j++;
        }
        else if (j > 0)
            j = f[j - 1];
        else
        {
            f[i] = 0;
            i++;
        }
    }
}

void kmp(char t[N], char p[N], int n, int m)
{
    failure(p, m);
    int i, j;
    i = j = 0;
    while (i < n)
    {
        if (p[j] == t[i])
        {
            if (j == m - 1)
            {
                printf("Pattern %s found at index %d in %s\n", p, i - m + 1, t);
                return;
            }
            i++, j++;
        }
        else if (j > 0)
            j = f[j - 1];
        else
            i++;
    }
    printf("substring %s is not present in string %s\n", p, t);
    return;
}

int main(int argc, char const *argv[])
{
    char t[] = "abcaabaccabacabaabb";
    char p[] = "abacab";
    kmp(t, p, strlen(t), strlen(p));
    return 0;
}
