// knapsack
// 1 indexed
#include <stdio.h>
#include <limits.h>

#define N 20
#define sint(x) scanf("%d", &x)

int p[N], w[N], y[N], n, m, fp = -1, fw = -1, x[N];

void ratiosort(int p[N], int w[N], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n - i - 1 + 1; j++)
        {
            float prev, next;
            prev = p[j] / w[j], next = p[j + 1] / w[j + 1];
            if (prev >= next)
            {
                int tp, tw;
                tp = p[j], tw = w[j];
                p[j] = p[j + 1], w[j] = w[j + 1];
                p[j + 1] = tp, w[j + 1] = tw;
            }
        }
}

int bound(int k, int cp, int cw)
{
    int b, c;
    b = cp, c = cw;
    for (int i = k + 1; i <= n; i++)
    {
        c += w[i];
        if (c < m)
            b += p[i];
        else
            return b + (1 - (c - m) / w[i]) * p[i];
    }
    return b;
}

void get(int a[N], int n)
{
    for (int i = 1; i <= n; i++)
        sint(a[i]);
}

void show()
{
    printf("The optimal solution is\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", x[i]);
    printf("\n");
    printf("Optimal weight: %d\nOptimal profit: %d\n", fp, fw);
}

void knap(int k, int cp, int cw)
{
    // generate the left child
    if ((cw + w[k]) <= m)
    {
        y[k] = 1;
        if (k < n)
            knap(k + 1, cp + p[k], cw + w[k]);
        if ((cp + p[k]) > fp && k == n)
        {
            fp = cp + p[k], fw = cw + w[k];
            for (int j = 1; j <= n; j++)
                x[j] = y[j];
        }
    }

    // generate the right child
    if (bound(k, cp, cw) >= fp)
    {
        y[k] = 0;
        if (k < n)
            knap(k + 1, cp, cw);
        if ((cp > fp) && k == n)
        {
            fp = cp, fw = cw;
            for (int j = 1; j <= n; j++)
                x[j] = y[j];
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("Enter the number of items: "), sint(n);
    printf("Enter the knapsack cap: "), sint(m);
    get(p, n);
    get(w, n);
    ratiosort(p, w, n);
    knap(1, 0, 0);
    show();
    return 0;
}