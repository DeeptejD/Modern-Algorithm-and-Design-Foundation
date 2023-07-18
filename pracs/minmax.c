#include <stdio.h>
#include <stdlib.h>
#define sint(x) scanf("%d", &x)
#define N 30

void minmax(int a[], int low, int high, int *min, int *max)
{
    int lmin, lmax, rmin, rmax;
    if (low == high)
        *min = *max = a[low];
    else if (low == high - 1)
        a[low] < a[high] ? (*min = a[low], *max = a[high]) : (*min = a[high], *max = a[low]);
    else
    {
        int mid = (low + high) / 2;
        minmax(a, low, mid, &lmin, &lmax);
        minmax(a, mid + 1, high, &rmin, &rmax);
        *min = (lmin < rmin ? lmin : rmin), *max = (lmax > rmax ? lmax : rmax);
    }
}

void disp(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int n, a[N], min, max;
    printf("Enter the size: "), sint(n);

    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
        sint(a[i]);

    printf("array: "), disp(a, n);

    minmax(a, 0, n - 1, &min, &max);

    printf("Min: %d\nMax: %d\n", min, max);
    return 0;
}
