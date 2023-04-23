#include <stdio.h>
#include <limits.h>
#define sint(x) scanf("%d", &x)
#define N 200
#define obj 100

int size;

struct dp
{
    int p, w, o[obj];
    // here p = profit, w = weight and o array holds zeroes and ones, indicating whether the eobject has been included in the knapsack or not
};

void get(int a[N], int n)
{
    for (int i = 0; i < n; i++)
        sint(a[i]);
}

void purrrrrge(struct dp s[N])
// (=｀ω´=)...
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // a pair s is said to be dominant on another pair j if s has a lower weight and a heigher profit than j, in which which case, j can be eliminated (R.I.P. j)
            if (s[i].p < s[j].p && s[i].w > s[j].w)
                s[i].p = s[i].w = -1;
        }
    }
}

void knap(int m, int n, int p[N], int w[N])
// m is the max knapsack capacity
// n is the number of items
// p holds the profits
// w holds the weights
{
    struct dp s[N];
    s[0].w = s[0].p = 0; // this represents an empty knapsack ie. no profit, no weight
    for (int i = 0; i < n; i++)
        s[0].o[i] = 0;

    size = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0, k = size; j < size; j++, k++)
        // j represents the index of the entry in the prev row that is being copied
        // k represents the idex of the new entry that is beign created
        {
            // check if the entry in the prev row is valid
            if (s[j].w == -1)
                continue;

            s[k].w = s[j].w + w[i];

            // check if the weight exceeds the knapsack cap
            if (s[k].w > m)
            {
                s[k].w = s[k].p = -1;
                continue;
            }

            // if it does not exceed, we proceed to update the profits
            s[k].p = s[j].p + p[i];

            for (int z = 0; z < n; z++)
                s[k].o[z] = s[j].o[z];
            s[k].o[i] += 1;
        }
        size *= 2;
    }
    purrrrrge(s);
    int mw = -1, mp = -1, ind; // mp = max profit, mw = max weight, ind = index
    for (int i = 0; i < size; i++)
    {
        if (s[i].w < mw)
            continue;
        else if (s[i].w > mw)
            mw = s[i].w, mp = s[i].p, ind = i;
        else
        {
            if (s[i].p > mp)
                mp = s[i].p, ind = i;
        }
    }
    printf("Max Profit: %d\nKnapsack filled at: %d\nObjects: ( ", mp, mw);
    for (int i = 0; i < n; i++)
    {
        if (s[ind].o[i] != 1)
            printf("0 ");
        else
            printf("%d ", s[ind].o[i]);
    }
    printf(")\n");
}

int main(int argc, char const *argv[])
{
    int m, n; // m = max knapsack size, n = number of items
    printf("Enter the knapsack capacity: ");
    sint(m);
    printf("Enter the number of elements: ");
    sint(n);
    int p[n], w[n]; // p is the array holding the profits and w the weights
    printf("Enter the profit for each item\n");
    get(p, n);
    printf("Enter the weights for each item\n");
    get(w, n);
    knap(m, n, p, w);
    return 0;
}

/*
Textbook
6
3
1
2
5
2
3
4


Output
Enter the knapsack capacity: 6
Enter the number of elements: 3
Enter the profit for each item
1
2
5
Enter the weights for each item
2
3
4
Max Profit: 6
Knapsack filled at: 6
Objects: ( 1 0 1 )
*/

/*
Tutorial Test Case
15
7
15
14
16
21
17
14
13
3
2
3
4
5
2
3


Output
Enter the knapsack capacity: 15
Enter the number of elements: 7
Enter the profit for each item
15
14
16
21
17
14
13
Enter the weights for each item
3
2
3
4
5
2
3
Max Profit: 80
Knapsack filled at: 14
Objects: ( 1 1 1 1 0 1 0 )
*/