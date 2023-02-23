#include <stdio.h>
#include <stdlib.h>
#define sint(x) scanf("%d", &x);
#define schar(x) scanf(" %c", &x);
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
    int intsize, charsize;
    printf("Enter size: ");
    sint(intsize);
    int arr[intsize];

    printf("Enter size: ");
    sint(charsize);
    char charr[charsize];
    while (1)
    {
        printf("Choose an option\n1. Enter int array\n2. Enter char array\n3. Sort int array (reverse)\n4. Sort char array (ascending)\n5. Perform Binary Search\n6. Display arrays\n");
        int choice;
        sint(choice);

        switch (choice)
        {
        case 1:
        {

            for (int i = 0; i < intsize; i++)
                sint(arr[i]);
            break;
        }

        case 2:
        {

            for (int i = 0; i < charsize; i++)
                schar(charr[i]);
            break;
        }

        case 3:
        {
            intmergesort(arr, 0, intsize - 1);
            break;
        }

        case 4:
        {
            charmergesort(charr, 0, charsize - 1);
            break;
        }

        case 5:
        {
            int ch;
            printf("Enter the character to be searched: ");
            schar(ch);
            if (bs(charr, ch, 0, charsize - 1) == -1)
                printf("%c not found\n", ch);
            else
                printf("%c found\n", ch);
            break;
        }

        case 6:
            printArray(arr, intsize);
            charprintArray(charr, charsize);
            break;

        case 7:
            break;
        }
    }
    return 0;
}
