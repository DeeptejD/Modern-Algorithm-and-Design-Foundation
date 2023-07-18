#include <stdio.h>
int a[100], n;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void disp_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int Partition(int m, int p)
{
    int v = a[m], i = m, j = p;
    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] <= v);
        do
        {
            j--;
        } while (a[j] > v);
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[m], &a[j]);
    return j;
}
void quicksort(int p, int q)
{
    if (p < q)
    {
        disp_array(a, n);
        int j = Partition(p, q + 1);
        printf("j=%d\n", j + 1);
        quicksort(p, j);
        quicksort(j + 1, q);
    }
}
int main()
{
    printf("Enter the size of the array.\n");
    scanf("%d", &n);
    printf("Enter the elements.\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    a[n] = __INT32_MAX__;
    printf("The quicksort steps are:\n");
    quicksort(0, n);
    printf("The sorted elements are:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}