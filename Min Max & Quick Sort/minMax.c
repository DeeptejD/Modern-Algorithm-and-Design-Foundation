// Enter size of the array: 9
// 86
// 23
// 10
// 44
// 90
// 5
// -12
// 55
// 37
// min: 23, max: 86
// min: 10, max: 10
// min: 10, max: 86
// min: 44, max: 90
// min: 10, max: 90
// min: -12, max: 5
// min: 37, max: 55
// min: -12, max: 55
// -12: min
// 90: max

#include <stdio.h>
#define sint(x) scanf("%d", &x);

void minMax(int a[], int l, int r, int *min, int *max)
{
    int lmin, rmin, lmax, rmax;

    if (l == r)
        *min = a[l], *max = a[l];
    else if (r == l + 1)
        a[l] < a[r] ? (*min = a[l], *max = a[r]) : (*min = a[r], *max = a[l]);
    else
    {
        int mid = (l + r) / 2;
        minMax(a, l, mid, &lmin, &lmax);
        printf("min: %d, max: %d\n", lmin, lmax);
        minMax(a, mid + 1, r, &rmin, &rmax);
        printf("min: %d, max: %d\n", rmin, rmax);
        *min = (lmin < rmin) ? lmin : rmin, *max = (lmax > rmax) ? lmax : rmax;
    }
}

int main(int argc, char const *argv[])
{
    int size, min, max;
    printf("Enter size of the array: ");
    sint(size);
    int a[size];
    for (int i = 0; i < size; i++)
        sint(a[i]);

    minMax(a, 0, size - 1, &min, &max);

    printf("%d: min\n%d: max\n", min, max);
    return 0;
}
