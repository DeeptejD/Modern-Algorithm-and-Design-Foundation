// o/1 knapsack using DP
#include <stdio.h>
#include <limits.h>

#define N 30
#define sint(x) scanf("%d", &x)

int size, count = 0;

struct kp
{
    int w, p, o[N]; // o holds the zeroes and ones
};

void get(int a[], int n)
{
    for (int i = 0; i < n; i++)
        sint(a[i]);
}

void purge(struct kp s[N])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((s[i].p < s[j].p) && (s[i].w >= s[j].w))
                s[i].w = s[i].p = -1;
        }
        for (int j = i + 1; j < size; j++)
        {
            if (s[i].p == s[j].p && s[i].w == s[i].w)
                s[j].w = s[j].p = -1;
        }
    }
}

void knap(int p[], int w[], int n, int m)
{
    struct kp s[N];
    s[0].w = s[0].p = 0;
    for (int i = 0; i < n; i++)
        s[0].o[i] = 0;

    size = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0, k = size; j < size; k++, j++)
        {
            if (s[j].w == -1)
                continue;
            s[k].w = s[j].w + w[i];
            if (s[k].w > m)
            {
                s[k].w = s[k].p = -1;
                continue;
            }
            s[k].p = s[j].p + p[i];

            for (int z = 0; z < n; z++)
                s[k].o[z] = s[j].o[z];
            s[k].o[i] += 1;
        }
        purge(s);
        printf("S^%d = { ", count++);
        for (int i = 0; i < size; i++)
        {
            if (s[i].p == -1 && s[i].w == -1)
                continue;
            else
                printf("(%d, %d) ", s[i].p, s[i].w);
        }
        printf("}\n\n");
        size *= 2;
    }
    purge(s);
    int maxw = -1, maxp = -1, index;
    for (int i = 0; i < size; i++)
    {
        if (s[i].p < maxp)
            continue;
        else if (s[i].p > maxp)
            maxp = s[i].p, maxw = s[i].w, index = i;
        else if (s[i].p == maxp)
            if (s[i].w < maxw)
                maxw = s[i].w, index = i;
    }
    printf("Max profit: %d\nKnapsack filled at: %d\nObjects: ( ", maxp, maxw);
    for (int i = 0; i < n; i++)
    {
        if (s[index].o[i] != 1)
            printf("0 ");
        else
            printf("%d ", s[index].o[i]);
    }
    printf(")\n");
}

int main(int argc, char const *argv[])
{
    int m, n, p[N], w[N];
    printf("Enter the number of items: "), sint(n);
    printf("Enter the max profit: "), sint(m);
    printf("Enter the profits\n");
    get(p, n);
    printf("Enter the weights\n");
    get(w, n);
    knap(p, w, n, m);
    return 0;
}