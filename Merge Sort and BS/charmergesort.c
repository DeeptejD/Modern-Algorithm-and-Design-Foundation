// Enter character array
// J
// P
// N
// S
// O
// B
// V
// W
// K
// E
// R
// Array after merge sort
// B, E, J, K, N, O, P, R, S, V, W,

#include <stdio.h>
#include <stdlib.h>
#define schar(x) scanf(" %c", &x);
#define sint(x) scanf("%d", &x);

void charmerge(char arr[], int left, int mid, int right)
{

    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    char L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void charmergesort(char arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        charmergesort(arr, left, mid);
        charmergesort(arr, mid + 1, right);

        charmerge(arr, left, mid, right);
    }
}

void charprintArray(char arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%c, ", arr[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int charsize;
    printf("Enter size: ");
    sint(charsize);
    char charr[charsize];
    printf("Enter character array\n");
    for (int i = 0; i < charsize; i++)
        schar(charr[i]);
    charmergesort(charr, 0, charsize - 1);
    printf("Array after merge sort\n");
    charprintArray(charr, charsize);
    return 0;
}
