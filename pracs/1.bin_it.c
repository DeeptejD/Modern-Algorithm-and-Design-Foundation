#include <stdio.h>
#include <stdlib.h>
#define N 30
#define sint(x) scanf("%d", &x)

void swaps(int a[N], int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

// bubble sort
void bubble(int a[N], int n)
{
    int swapped = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swaps(a, j, j + 1), swapped = 1;
        }
        if (!swapped)
            return;
    }
}

int bs(int a[N], int n, int x)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == a[mid])
            return mid;
        else if (x < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

void display(int a[N], int n)
{
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int n, x;
    printf("Enter the number of elements: "), sint(n);

    int a[n];

    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
        sint(a[i]);

    bubble(a, n);
    display(a, n);

    printf("Enter the element to be searched: "), sint(x);

    if (bs(a, n, x) == -1)
        printf("Element is not present\n");
    else
        printf("%d found at index %d\n", x, bs(a, n, x));

    return 0;
}
