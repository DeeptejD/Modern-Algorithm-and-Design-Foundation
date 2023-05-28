#include <stdio.h>
#define sint(x) scanf("%d", &x)
#define N 100

struct ITEM
{
    int w, p;
};

int m, n, currentsol[N], bestsol[N], cw, cp, bestp;
struct ITEM items[N];

void fillz()
{
    for (int i = 0; i < n; i++)
        currentsol[i] = bestsol[i] = 0;
}

int ub(int level, int w, int p)
{
    int r = m - w; // remaining knapsack cap
    int upperbound = p;

    for (int i = level; i < n; i++)
    {
        if (items[i].w <= r)
        {
            r -= items[i].w;
            upperbound += items[i].p;
        }
        else
        {
            upperbound += (r / items[i].w) * items[i].p; // fractional weight
            break;
        }
    }
    return upperbound;
}

void _sort()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((items[j].p / items[j].w) < (items[j + 1].p / items[j + 1].w))
            {
                int tempp = items[j].p, tempw = items[j].w;
                items[j].p = items[j + 1].p, items[j].w = items[j + 1].w;
                items[j + 1].p = tempp, items[j + 1].w = tempw;
            }
        }
    }
}

void bnb(int level, int w, int p)
{
    if (w <= m) // current weight is less than the knapsack cap
    {
        if (p > bestp)
        {
            bestp = p;
            for (int i = 0; i < n; i++)
                bestsol[i] = currentsol[i];
        }
    }

    if (level == n || ub(level, w, p) <= bestp) // if all the items are exhausted or the upper bound of the subtree is less than the current best p
        return;

    currentsol[level] = 1;
    bnb(level + 1, w + items[level].w, p + items[level].p); // including the item at the current level

    currentsol[level] = 0;
    bnb(level + 1, w, p); // exclusing the item at the current level
}

int main(int argc, char const *argv[])
{
    printf("Enter knapsack cap: "), sint(m);
    printf("Enter the number of items: "), sint(n);
    printf("Enter the weight and profit for each item\n");
    for (int i = 0; i < n; i++)
        sint(items[i].p), sint(items[i].w);
    cw = cp = bestp = 0;
    fillz();
    _sort();
    bnb(0, cw, cp);

    printf("Knapsack Solution\nMax Profit = %d\nItems Included: ", bestp);
    for (int i = 0; i < n; i++)
        printf(" %d", bestsol[i]);
    printf("\n");

    return 0;
}

/*
Test case

35
4
80 14
82 17
42 13
45 15

*/

/*
Output

Enter knapsack cap: 35
Enter the number of items: 4
Enter the weight and profit for each item
80 14
82 17
42 13
45 15
Knapsack Solution
Max Profit = 162
Items Included:  1 1 0 0
*/