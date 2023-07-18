#include <stdio.h>
#include <limits.h>
#define sint(x) scanf("%d", &x)
#define N 20

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

int partition(int a[N], int low, int high)
{
    int pivot = a[low], i = low, j = high;
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

void ksmall(int a[N], int low, int high, int n, int k)
{
    // int flag = 0;
    if (low < high)
    {
        int j = partition(a, low, high + 1);
        if (j == k)
        {
            printf("The %dth smallest element is: %d\n", j, a[j]);
            // flag = 1;
            return;
        }
        if (k < j)
            ksmall(a, low, j, n, k);
        else
            ksmall(a, j + 1, high, n, k);
    }

    printf("kth smallest element not found\n");
}

int main(int argc, char const *argv[])
{
    int n, a[N], k;
    printf("Enter the number of elements: "), sint(n);

    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
        sint(a[i]);
    a[n] = INT_MAX;
    disp(n, a);
    printf("Enter value of 'k': "), sint(k);
    ksmall(a, 0, n, n, k);
    return 0;
}
