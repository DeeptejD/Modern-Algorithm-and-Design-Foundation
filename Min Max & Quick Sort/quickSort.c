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
// Original Array: 86 23 10 44 90 5 -12 55 37
// pass 1: 23 10 5 -12 37 86 44 55 90
// pass 2: -12 10 5 23 37 86 44 55 90
// pass 3: -12 10 5 23 37 86 44 55 90
// pass 4: -12 5 10 23 37 86 44 55 90
// pass 5: -12 5 10 23 37 86 44 55 90
// pass 6: -12 5 10 23 37 44 55 86 90
// Sorted Array: -12 5 10 23 37 44 55 86 90

#include <stdio.h>
#define sint(x) scanf("%d", &x);
// utility functions for qs
int size, count = 1;

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
    int piv = a[r], i = l; // we choose the rightmost element is the pivot
    for (int j = l; j < r; j++)
    {
        if (a[j] < piv)
        {
            sw(a, i, j);
            i++;
        }
    }
    sw(a, i, r);
    return i;
}

void qs(int a[], int l, int r)
{
    // step 1: find the partition index
    if (l < r)
    {
        int p = part(a, l, r);
        printf("pass %d: ", count), count++;
        dis(a, size);
        qs(a, l, p - 1);
        qs(a, p + 1, r);
    }
}

int main()
{
    printf("Enter size of the array: ");
    sint(size);
    int a[size];
    for (int i = 0; i < size; i++)
        sint(a[i]);
    printf("Original Array: ");
    dis(a, size);
    qs(a, 0, size - 1);
    printf("Sorted Array: ");
    dis(a, size);
    return 0;
}
