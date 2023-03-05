#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}
int ksmallest(int arr[], int n, int k)
{
    int pivot = partition(arr, 0, n - 1);
    printf("Pivot:%d\n", pivot);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int low = 0;
    int high = n - 1;
    if (pivot == k - 1)
        return arr[pivot];
    else
    {
        do
        {
            if (pivot > k - 1)
                high = pivot - 1;
            else
                low = pivot + 1;

            pivot = partition(arr, low, high);
            // pivot=partition(arr,pivot+1,high);
            printf("Pivot:%d\n", pivot);
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");

        } while (pivot + 1 != k);

        return arr[pivot];
    }
}

int main()
{
    int arr[] = {42, 5, 90, 33, 28, 88, 66, 56, 11, 23, 76};
    // int arr[]={76,23,11,56,66,88,28,33,90,5,42};
    int n;
    int a[n];
    int k;
    printf("6th smallest element:%d\n", ksmallest(arr, 11, 6));

    printf("Enter the value of n\n");
    scanf("%d", &n);
    printf("Enter the array elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the value of k\n");
    scanf("%d", &k);
    printf("%dth smallest element:%d", k, ksmallest(arr, 11, 6));
}