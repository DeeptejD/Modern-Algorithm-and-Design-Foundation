#include <stdio.h>
#include <limits.h>
#define sint(x) scanf("%d", &x)
#define N 20

void setEdge(int edge[N][N], int src, int dst, int wt, int n)
{
    if (src > 0 && src <= n && dst > 0 && dst <= n)
        edge[src][dst] = wt, edge[dst][src] = wt;
    else
        printf("invalid edge\n");
}

struct EDGE
{
    int src, dst, wt;
};

void Swap(struct EDGE *a, struct EDGE *b)
{
    struct EDGE temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct EDGE arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].wt < arr[smallest].wt)
        smallest = l;
    else if (l < n && arr[l].wt == arr[smallest].wt && arr[l].src < arr[smallest].src)
        smallest = l;

    if (r < n && arr[r].wt < arr[smallest].wt)
        smallest = r;
    else if (r < n && arr[r].wt == arr[smallest].wt && arr[r].src < arr[smallest].src)
        smallest = r;

    if (smallest != i)
    {
        Swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

int Find(int parent[], int u)
{
    while (parent[u] != -1)
        u = parent[u];
    return u;
}

int Union(int parent[], int u, int v)
{
    parent[u] = v;
}

int kruskal(int cost[N][N], int n, int t[N][2], int e)
{
    struct EDGE heap[N];
    int index = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i < j && cost[i][j] != INT_MAX)
                heap[index].src = i, heap[index].dst = j, heap[index++].wt = cost[i][j];

    // Build heap
    for (int i = e / 2 - 1; i >= 0; i--)
        heapify(heap, e, i);

    // initialize parent
    int parent[N];
    for (int i = 1; i <= n; i++)
        parent[i] = -1;
    int i = 1, mincost = 0;

    int hi = 0; // heap index
    while (i < n && hi != n)
    {
        // put smallest element at end and re-heapify
        Swap(&heap[0], &heap[e - 1]);
        struct EDGE mc_edge = heap[e - 1];
        e--, heapify(heap, e, 0);

        int u = mc_edge.src, v = mc_edge.dst;
        int j = Find(parent, u), k = Find(parent, v);

        if (j != k) // valid edge
        {
            t[i][1] = u;
            t[i][2] = v;
            mincost += cost[u][v];
            Union(parent, j, k), i++;
        }
    }

    if (i != n)
    {
        printf("no mst\n");
        return -1;
    }
    else
        return mincost;
}

int main()
{
    // the size of arrays must be >= n + 1; due to one based indexing
    int E[N][N], cost[N][N], t[N][2], n, e;
    sint(n), sint(e);

    // initialize E
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            E[i][j] = 0;

    // accept edges
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        sint(s), sint(d), sint(w);
        setEdge(E, s, d, w, n);
    }

    // create cost adj matrix
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cost[i][j] = (E[i][j] == 0 ? INT_MAX : E[i][j]);

    int mincost = kruskal(cost, n, t, e);
    if (mincost == -1)
        return 0;
    printf("\nmincost is %d\n", mincost);
    printf("MST is:\n");
    for (int i = 1; i <= n - 1; i++)
        printf("edge %d is: %d -> %d\n", i, t[i][1], t[i][2]);

    return 0;
}

/*
TEST CASE
8 11
1 2 12
1 3 11
3 4 14
2 4 4
4 6 8
2 5 5
4 5 3
4 7 6
6 7 15
5 8 17
7 8 10
*/
