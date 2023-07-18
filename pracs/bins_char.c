// character binary search and merge sort

#include <stdio.h>
#include <stdlib.h>
#define sint(x) scanf("%d", &x)
#define schar(x) scanf(" %c", &x)
#define N 30

void char_merge(char a[N], int low, int mid, int high)
{
    int i, j, k, n1, n2;

    // size of left array
    n1 = mid - low + 1;
    // size of the right array
    n2 = high - mid;

    char L[n1], R[n2];

    // copying the left and right subarrays
    for (int i = 0; i < n1; i++)
        L[i] = a[low + i];

    for (int i = 0; i < n2; i++)
        R[i] = a[mid + 1 + i];

    i = j = 0, k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
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

void char_mergesort(char a[N], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        char_mergesort(a, low, mid);
        char_mergesort(a, mid + 1, high);

        char_merge(a, low, mid, high);
    }
}

int char_bs(char a[N], int low, int high, char c)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (c == a[mid])
            return mid;
        else if (c < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

void display(char a[N], int n)
{
    for (int i = 0; i < n; i++)
        printf("%c ", a[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int n, index;
    char a[N], c;
    printf("Enter the number of characters: "), sint(n);

    printf("Enter the characters: ");
    for (int i = 0; i < n; i++)
        schar(a[i]);

    char_mergesort(a, 0, n - 1);

    printf("Sorted array: "), display(a, n);

    printf("Enter the element to be searched: "), schar(c);

    if ((index = char_bs(a, 0, n - 1, c)) == -1)
        printf("%c is not present\n", c);
    else
        printf("%c is present at index %d\n", c, index);

    return 0;
}
