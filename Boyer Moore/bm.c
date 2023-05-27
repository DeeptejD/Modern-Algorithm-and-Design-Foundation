#include <stdio.h>
#include <string.h>
#define sint(x) scanf("%d", &x)
#define charnum 256

int fmin(int a, int b)
{
    return a < b ? a : b;
}

int lastc[charnum]; // carries last occurance of all the characters

void last(char p[charnum], int m)
{
    for (int i = 0; i < charnum; i++)
        lastc[i] = -1;
    for (int i = 0; i < m; i++)
        lastc[(int)p[i]] = i;
}

void bm(char t[], char p[], int n, int m)
{
    last(p, m);
    int i, j;
    i = m - 1;
    j = m - 1;
    do
    {
        // printf("%c %c\n", p[j], t[i]);
        if (p[j] == t[i])
        {
            if (!j)
            {
                printf("Pattern found at index %d\n", i);
                return;
            }
            else
                i -= 1, j -= 1;
        }
        else
        {
            i = i + m - fmin(j, 1 + lastc[(int)t[i]]);
            j = m - 1;
        }

    } while (i <= n - 1);
    printf("No substring\n");
}

int main(int argc, char const *argv[])
{
    char t[] = "abcaabaccabacabaabb";
    char p[] = "abacab";
    bm(t, p, strlen(t), strlen(p));
    return 0;
}
