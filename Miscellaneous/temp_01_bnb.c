#include <stdio.h>
#define sint(x) scanf("%d", &x)
#define N 20

int w[N], p[N], n, m, x[N], fp, fw, y[N];

void ratiosort(int p[], int w[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n - i - 1 + 1; j++)
        {
            float prev = p[j] / w[j], next = p[j + 1] / w[j + 1];
            if (prev <= next)
            {
                int tp = p[j], tw = w[j];
                p[j] = p[j + 1];
                w[j] = w[j + 1];
                p[j + 1] = tp;
                w[j + 1] = tw;
            }
        }
    }
}

int ubound(int cp, int cw, int k, int m)
{
    int b = cp, c = cw;
    for (int i = k + 1; i <= n; i++)
    {
        if (c + w[i] <= m)
            c = c + w[i], b = b - p[i];
    }
    return b;
}

void knap(int k, int cp, int cw)
{
    // Generate Left Child
    if (cw + w[k] <= m)
    {
        y[k] = 1;
        if (k < n)
            knap(k + 1, cp + p[k], cw + w[k]);
        if ((cp + p[k] > fp) && (k == n))
        {
            fp = cp + p[k], fw = cw + w[k];
            for (int j = 1; j <= k; j++)
                x[j] = y[j];
        }
    }
    // Generate Right Child
    if (ubound(cp, cw, k, m) >= fp)
    {
        y[k] = 0;
        if (k < n)
            knap(k + 1, cp, cw);
        if ((cp > fp) && (k == n))
        {
            fp = cp, fw = cw;
            for (int j = 1; j <= k; j++)
                x[j] = y[j];
        }
    }
}

void show()
{
    printf("The optimal solution is: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", x[i]);
    printf("\n");
    printf("The optimal profit is: %d\n", fp);
    printf("The optimal weight is: %d\n", fw);
}

int main(int argc, char const *argv[])
{
    printf("Enter the number of objects: ");
    sint(n);
    printf("Enter the capacity of the knapsack: ");
    sint(m);

    printf("Enter the weights: ");
    for (int i = 1; i <= n; i++)
        sint(w[i]);
    printf("Enter the profits: ");
    for (int i = 1; i <= n; i++)
        sint(p[i]);
    ratiosort(p, w, n);
    // zeroes(n);
    knap(1, 0, 0);
    show();
    return 0;
}