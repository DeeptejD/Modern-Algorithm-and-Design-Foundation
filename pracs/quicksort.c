// quicksort (ma'ams method)

#include <stdio.h>
#include <stdlib.h>
#define N 30
#define sint(x) scanf("%d", &x)

int partition(int a[], int low, int mid, int high)
{
}

quicksort(int a[], int n)
{
    
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

    printf("array: "), disp(a, n);
    return 0;
}
