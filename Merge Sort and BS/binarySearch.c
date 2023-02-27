// Enter the size of the array: 11
// Enter the character array
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
// Enter 1 to search
// 2 to exit
// 1
// Enter the character to be searched: O
// O found
// Enter 1 to search
// 2 to exit
// 1
// Enter the character to be searched: F
// F not found
// Enter 1 to search
// 2 to exit
// 2

#include <stdio.h>
#include <stdlib.h>

#define sint(x) scanf("%d", &x);
#define ch(x) scanf(" %c", &x);

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

int main()
{
    char ch;
    int charsize;
    printf("Enter the size of the array: ");
    sint(charsize);
    char charr[charsize];
    printf("Enter the character array\n");
    for (int i = 0; i < charsize; i++)
        ch(charr[i]);
    charmergesort(charr, 0, charsize - 1);

    while (1)
    {
        int c;
        printf("Enter 1 to search\n2 to exit\n");
        sint(c);
        if (c == 2)
            exit(1);
        else
        {
            printf("Enter the character to be searched: ");
            ch(ch);
            if (bs(charr, ch, 0, charsize - 1) == -1)
                printf("%c not found\n", ch);
            else
                printf("%c found\n", ch);
        }
    }

    return 0;
}
