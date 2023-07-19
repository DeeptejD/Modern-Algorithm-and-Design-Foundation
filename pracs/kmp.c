#include <stdio.h>
#include <limits.h>

#define N 30
#define sint(x) scanf("%d", &x)

int f[N];

int failure(int p[N], int m)
{
    int i, j;
    i = 0, j = 1;
    f[0] = 0;
    while (i < m)
    {
        if (p[i] == p[j])
        {
            f[i] = j + 1;
            i++, j++;
        }
        else if (j > 0)
            j = f[j - 1];
        else
            f[i] = 0, i++;
    }
}

int kmp(char p[N], char t[N], int m, int n)
{
    failure(p, m);
    int i, j;
    i = j = 0;
    while (i < n)
    {
        if (p[j] == t[i])
        {
            if (j == m)
                return i - j + i;
            else
                i++, j++;
        }
        else
        {
            if (j > 0)
                j = f[j - 1];
            else
                i++;
        }
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}