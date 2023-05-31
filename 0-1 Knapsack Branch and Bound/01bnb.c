#include <stdio.h>
#include <limits.h>
#include <math.h>
#define sint(x) scanf("%d", &x)
#define N 50

struct item
{
    int p, w;
    float ratio;
};

int m, n, upper = INT_MAX, maxp, maxw, y[N], x[N], z[N];

void _sort(struct item k[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (k[j].ratio < k[j + 1].ratio)
            {
                struct item temp = k[j];
                k[j] = k[j + 1];
                k[j + 1] = temp;
            }
        }
    }
}

int bound(int curr_index, int cp, int cw, struct item k[])
{
    // calculates the fractional upper bound
    int b = cp, c = cw;
    for (int i = curr_index; i < n; i++)
    {
        c += k[i].w;
        if (c < m)
            b += k[i].p;
        else
            return (-1) * (b + (int)ceil((1 - (c - m) / (float)k[i].w) * k[i].p));
    }
    return -b;
}

int ubound(int curr_index, int cp, int cw, struct item k[])
{
    int b = cp, c = cw;
    for (int i = curr_index; i < n; i++)
    {
        if (c + k[i].w <= m)
        {
            c += k[i].w;
            b += k[i].p;
        }
    }
    return -b;
}

void bnb(int curr_index, int cp, int cw, struct item k[])
{
    // calc fractional bound
    int c = bound(curr_index, cp, cw, k);
    // calc non fractional bound
    int u = ubound(curr_index, cp, cw, k);

    if (u < upper && cw <= m)
        upper = u;

    // left child
    if (c <= upper)
    {
        y[curr_index] = 1;      // included current element in the sol
        if (curr_index < n - 1) // more items to consider
            if (cw <= m)
                bnb(curr_index + 1, cp + k[curr_index].p, cw + k[curr_index].w, k);

        // last node
        if (curr_index == n - 1)
        {
            if (cw + k[curr_index].w <= m)
            {
                maxp = cp + k[curr_index].p, maxw = cw + k[curr_index].w;

                for (int j = 0; j < curr_index; j++)
                    x[j] = y[j];
                x[curr_index] = 1;
            }
        }
    }
    // right child
    if (c <= upper)
    {
        y[curr_index] = 0;      // excluding the current element
        if (curr_index < n - 1) // more items left to explore
            bnb(curr_index + 1, cp, cw, k);

        if (curr_index == n - 1) // last item
        {
            int c = bound(curr_index, cp - k[curr_index].p, cw - k[curr_index].w, k);
            int b = ubound(curr_index, cp - k[curr_index].p, cw - k[curr_index].w, k);
            if (cw <= m && c <= upper)
            {
                maxp = cp, maxw = cw;
                for (int j = 0; j < curr_index; j++)
                    x[j] = y[j];
                x[curr_index] = 0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("Number of items: "), sint(n), printf("Max cap: "), sint(m);
    struct item knapsack[n + 1];
    int p[N], w[N];
    printf("Enter Profits and Weights\n");
    for (int i = 0; i < n; i++)
        sint(p[i]), sint(w[i]);
    // init_knapsack(p, w, knapsack);
    for (int i = 0; i < n; i++)
        knapsack[i].p = p[i], knapsack[i].w = w[i], knapsack[i].ratio = (float)(knapsack[i].p / knapsack[i].w);
    _sort(knapsack);
    maxp = -1;
    bnb(0, 0, 0, knapsack);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (p[i] == knapsack[j].p && w[i] == knapsack[j].w)
            {
                if (x[j])
                    z[i] = 1;
                else
                    z[i] = 0;
            }

    printf("Solution\n");
    for (int i = 0; i < n; i++)
        printf("%d ", z[i]);
    printf("\n");
    printf("Max profit: %d\nMax weight: %d\n", maxp, maxw);
    return 0;
}

/*
Testcase

4
35
80 14
82 17
45 15
42 13

*/

/*
Output

Number of items: 4
Max cap: 35
Enter Profits and Weights
80 14
82 17
45 15
42 13
Solution
1 1 0 0
Max profit: 162
Max weight: 31
*/
