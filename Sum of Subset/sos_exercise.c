// 211105017 Deeptej Dhauskar
#include <stdio.h>
#define N 20
#define sint(x) scanf("%d", &x)

int n, m;

void show(int w[N], int k, int x[N])
{
    printf("( ");
    for (int i = 1; i <= k; i++)
        printf("%d, ", x[i]);
    printf(") ie. sum of the subset ( ");
    for (int i = 1; i <= k; i++)
    {
        if (x[i] == 1)
            printf("%d, ", w[i]);
    }
    printf(")\n");
}

// 'w' is an array of integers containing the elements of the set.
// 'x' is an array of integers used to store the binary values (0/1) of the elements in the subset. 'x' is initialized to all zeros outside of this function.
// 'S' is an integer that keeps track of the sum of the elements in the current subset.
// 'k' is an integer that represents the current index in 'w' being considered for inclusion in the subset.
// 'r' is an integer that keeps track of the sum of the remaining elements in the set.
void sumofsub(int s, int k, int r, int w[], int x[])
{
    if (k > n)
        return;
    x[k] = 1;
    // check if adding the first weight itself yields an answer
    if (s + w[k] == m)
        show(w, k, x);
    else if ((s + w[k] + w[k + 1]) <= m)
        sumofsub(s + w[k], k + 1, r, w, x);
    if (((s + r - w[k]) >= m) && (s + w[k + 1] <= m))
    {
        x[k] = 0; // exclude the current element
        sumofsub(s, k + 1, r, w, x);
    }
}

int main(int argc, char const *argv[])
{
    int r = 0; // m= target sum, n = number of elements, r = sum of all elements

    // printf("Enter the numberof elements: "), sint(n);
    n = 7;
    int w[n + 1], x[n + 1]; // w is the array of elements (weights), x is the solution array
    int weights[] = {5, 7, 10, 12, 15, 18, 20};
    // int weights[] = {20, 18, 15, 12, 10, 7, 5};
    // int weights[] = {15, 7, 20, 5, 18, 10, 12};
    // printf("Enter the elements\n");
    for (int i = 1, j = 0; i <= n; i++, j++)
    {
        x[i] = 0;
        // sint(w[i]);
        w[i] = weights[j];
        r += weights[j];
    }

    // printf("Enter max weight: "), sint(m);
    m = 35;
    sumofsub(0, 1, r, w, x);
    return 0;
}

/*
6
5
10
12
13
15
18
30


*/

/*
T1
7
5
7
10
12
15
18
20
35
*/

/*
7
20
18
15
12
10
7
5
35
*/

/*
7
15
7
20
5
18
10
12
35
*/