#include <stdio.h>
#include <string.h>
#define sint(x) scanf("%d", &x)
#define N 100

void bruteforce(char t[N], char p[N], int n, int m)
{
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && t[i + j] == p[j])
            j++;
        if (j == m)
        {
            printf("Present at %d\n", i);
            return;
        }
    }
    printf("Not present\n");
    return;
}

int main(int argc, char const *argv[])
{
    char t[] = {'a', 'b', 'c', 'a', 'a', 'b', 'a', 'c', 'c', 'a', 'b', 'a', 'c', 'a', 'b', 'a', 'a', 'b', 'b'};
    char p[] = {'a', 'b', 'a', 'c', 'a', 'b'};
    // char t[] = {'a', 'b', 'c', 's', 'a'}, p[] = {'c', 's', 'a'};
    bruteforce(t, p, sizeof(t) / sizeof(t[0]), sizeof(p) / sizeof(p[0]));
    return 0;
}