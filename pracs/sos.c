// sumofsubset
#include <stdio.h>
#include <limits.h>

#define N 30
#define sint(x) scanf("%d", &x)

// global
int n, m;

void show(int w[], int k, int x[])
{
    printf("( ");
    for (int i = 1; i <= k; i++)
        printf("%d, ", x[i]);
    printf(")\n");
    printf("The sum of the elements: ( ");
    for (int i = 1; i <= n; i++)
        if (x[i])
            printf("%d, ", w[i]);
    printf(")\n");
}

void sos(int s, int k, int r, int w[], int x[])
{
    if (k > n)
        return;
    x[k] = 1;
    if (s + w[k] == m)
        show(w, k, x);
    else if ((s + w[k] + w[k + 1] <= m))
        sos(s + w[k], k + 1, r - w[k], w, x);
    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m))
    {
        x[k] = 0;
        sos(s, k + 1, r, w, x);
    }
}

int main(int argc, char const *argv[])
{
    int x[N], w[N], r;
    printf("Enter the number of elements: "), sint(n);
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
        sint(w[i]);
        r += w[i];
    }
    printf("Enter the subset size: "), sint(m);
    sos(0, 1, r, w, x);
    return 0;
}