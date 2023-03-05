#include <stdio.h>
#define sint(x) scanf("%d", &x);

int size;

// utility functions

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
    dis(a, size);
    return i;
}

void ksmall(int a[], int l, int r, int x)
{
    if (r < x)
    {
        printf("out of bounds\n");
        return;
    }

    do
    {
        int p = part(a, l, r);
        printf("pivot: %d\n", p);
        if (p == x)
        {
            printf("The kth smallest element is: %d\n", ++x, a[p]);
            return;
        }
        else if (p > x)
            r = p - 1;
        else
            l = p + 1;

    } while (l <= r);

    printf("The kth smallest element is not present\n");
    return;

    //     if (l <= r)
    //     {
    //         int p = part(a, l, r);
    //         printf("pivot: %d\n", p);
    //         if (p == x)
    //         {
    //             printf("%dth smallest element is: %d\n", ++x, a[p]);
    //             return;
    //         }
    //         else if (p > x)
    //             ksmall(a, l, p - 1, x);
    //         else if (p < x)
    //             ksmall(a, p + 1, r, x);
    //     }
    //     else
    //         printf("The element is not present\n");
}

int main()
{
    int x;
    printf("Enter size of the array: ");
    sint(size);
    int a[size];
    for (int i = 0; i < size; i++)
        sint(a[i]);
    // int a[] = {42, 5, 90, 33, 28, 88, 56, 54, 11, 23, 76};
    // size = sizeof(a) / sizeof(a[0]);
    while (x != -1)
    {
        printf("Enter the kth value to be searched: ");
        sint(x);
        x--;
        ksmall(a, 0, size - 1, x);
    }
    return 0;
}
