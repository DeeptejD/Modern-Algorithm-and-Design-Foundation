#include <stdio.h>

// utility functions for qs

void sw(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j], a[j] = t;
}

void dis(int a[], int s)
{
    for (int i = 0; i < s; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int part(int a[], int l, int r)
{
    int piv = a[r], i = l - 1; // we choose the rightmost element is the pivot
    for (int j = l; j < r; j++)
    {
        if (a[j] < piv)
        {
            i++;
            sw(a, i, j);
        }
    }
    sw(a, i + 1, r);
    return i + 1; // returning the new pivot
}

void qs(int a[], int l, int r)
{
    // step 1: find the partition index
    if (l < r)
    {
        int p = part(a, l, r);
        qs(a, l, p - 1);
        qs(a, p + 1, r);
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {2, 3, 4, 6, 8, 9, 12, 22, 1};
    int s = sizeof(a) / sizeof(a[0]);
    dis(a, s);
    qs(a, 0, s - 1);
    dis(a, s);
    return 0;
}
