// AlgorithmMergeSort(low >, high) 2
// a[low :high]is a globalarray to be sorted.
// Small(P)is true if thereis only one element to sort
// In this case the list is already sorted.
// if (low < high) then
// If there are more than one element
// {
//  // DivideP into subproblems.
//  // Find where to split the set.
//  mid:=[(low+high)/2\\; 11 // Solvethe subproblems
// MergeSort(low,mid);
// 13 MergeSort(mid+ I,high);
// Combinethe solutions.
//  Merge(low,mid,high); 16
// }
// }

#include <stdio.h>
#include <stdlib.h>

void charmerge(char arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid; // right minus mid because mid actually lies before the right part
    char L[n1], R[n2];
    // splitting the parent array
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; // for right half left is mid+1

    i = 0;
    j = 0;
    k = left;
    // entering elements from each subarray in a sorted manner while (i < n1 && j < n2)
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

    // remaining elements
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

void intmerge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid; // right minus mid because mid actually lies before the right part
    int L[n1], R[n2];
    // splitting the parent array
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; // for right half left is mid+1

    i = 0;
    j = 0;
    k = left;
    // entering elements from each subarray in a sorted manner while (i < n1 && j < n2)
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
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

    // remaining elements
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

void intmergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        intmergesort(arr, left, mid);
        intmergesort(arr, mid + 1, right);

        intmerge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}

void charprintArray(char arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%c, ", arr[i]);
    printf("\n");
}

int bs(char arr[], char item, int low, int up)
{
    int mid;
    if (low > up)
        return -1;
    mid = (low + up) / 2;
    if (item < arr[mid])
        bs(arr, item, low, mid - 1);
    else if (item > arr[mid])
        bs(arr, item, mid + 1, up);
    else
        return mid;
}

int main(int argc, char const *argv[])
{
    char charr[] = "JPNSOBVWKER";
    int arr[] = {65, 18, 40, 50, 80, 90, 110, 20, 25, -75, 20};
    int charsize = sizeof(charr) / sizeof(charr[0]), intsize = sizeof(arr) / sizeof(arr[0]);
    // sorting int arr in reverse and char arr in anti-reverse
    intmergesort(arr, 0, intsize - 1);
    charmergesort(charr, 0, charsize - 1);

    // printArray(arr, intsize);
    // charprintArray(charr, charsize);

    // searching 'o' using binary search in charr
    if (bs(charr, 0, charsize - 1, 'O') != -1)
        printf("Found 'O'\n");
    else
        printf("Not Found 'O'\n");
    return 0;
}
