#include <stdio.h>
#include <limits.h>
#define sint(x) scanf("%d", &x)
#define N 30

void disp(int n, int a[N])
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void iswap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int highp1, int a[N])
{
    int pivot = a[low], i = low, j = highp1;
    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] < pivot);

        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
            iswap(&a[i], &a[j]);
    }
    iswap(&a[low], &a[j]);
    return j;
}

void quicksort(int low, int high, int a[N], int n)
{
    if (low < high)
    {
        disp(n, a);
        int j = partition(low, high + 1, a);
        printf("partition: %d\n", j + 1);
        quicksort(low, j, a, n);
        quicksort(j + 1, high, a, n);
    }
}

int main(int argc, char const *argv[])
{
    int a[N], n;
    printf("Enter the size: "), sint(n);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
        sint(a[i]);
    a[n] = INT_MAX;
    printf("The array: "), disp(n, a);
    printf("\nThe steps\n");
    quicksort(0, n, a, n);
    printf("The sorted array: "), disp(n, a);
    return 0;
}
