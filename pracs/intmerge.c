// merge sort on integer array

#include <stdio.h>
#include <stdlib.h>
#define sint(x) scanf("%d", &x)
#define N 30

void merge(int a[], int low, int mid, int high)
{
    int i, j, k, n1, n2, L[N], R[N];
    n1 = mid - low + 1, n2 = high - mid;

    for (int i = 0; i < n1; i++)
        L[i] = a[low + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[mid + 1 + i];

    i = j = 0, k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
            a[k] = L[i], i++;
        else
            a[k] = R[j], j++;

        k++;
    }

    // residual
    while (i < n1)
        a[k] = L[i], i++, k++;

    while (j < n2)
        a[k] = R[j], j++, k++;
}

void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);

        merge(a, low, mid, high);
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
    int n, a[N];
    printf("Enter the size: "), sint(n);

    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
        sint(a[i]);

    printf("Before sorting: "), disp(a, n);

    mergesort(a, 0, n - 1);

    printf("After sorting: "), disp(a, n);

    return 0;
}
