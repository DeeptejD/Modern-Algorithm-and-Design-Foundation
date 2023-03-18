#include <stdio.h>
#include <limits.h>
#define N 10
#define sint(x) scanf("%d", &x)

// we create a struct that stores the source dest and weight so that we can create an array fo this struct and use it to build the heap
struct EDGE
{
    int s, d, w;
};

void fillzeroes(int e[][N], int nodes)
{
    for (int i = 1; i <= nodes; i++)
        for (int j = 1; j <= nodes; j++)
            e[i][j] = 0;
}

void fillinf(int cost[][N], int nodes)
{
    for (int i = 1; i <= nodes; i++)
        for (int j = 1; j <= nodes; j++)
            cost[i][j] = INT_MAX;
}

void getmat(int e[][N], int cost[][N], int n, int edges)
{
    for (int i = 1; i <= edges; i++)
    {
        int s, d, w;
        sint(s), sint(d), sint(w);
        if (s > 0 && s <= n && d > 0 && d <= n)
            e[s][d] = e[d][s] = 1, cost[s][d] = cost[d][s] = w;
    }
}

void showmat(int a[][N], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            a[i][j] == INT_MAX ? printf("x ") : printf("%d ", a[i][j]);
        printf("\n");
    }
}

void sw(struct EDGE *a, struct EDGE *b)
{
    struct EDGE temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct EDGE e[N], int edges, int i)
{
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < edges && e[l].w < e[smallest].w)
        smallest = l;

    if (r < edges && e[r].w < e[smallest].w)
        smallest = r;

    if (smallest != i)
    {
        sw(&e[i], &e[smallest]);
        // rec call heapify
        heapify(e, edges, smallest);
    }
}

int Find(int parent[], int u)
{
    while (parent[u] != -1)
        u = parent[u];
    return u;
}

void Union(int parent[N], int u, int v)
{
    parent[u] = v;
}

int kruskal(int e[][N], int cost[][N], int nodes, int t[][2], int edges)
{
    struct EDGE heap[N];
    // now we scan the entire cost matrix and when we encounter a cost we update it into the heap array of struct EDGE
    // we also maintain an index to store into the heap elements
    int in = 0;
    for (int i = 1; i <= nodes; i++)
        for (int j = 1; j <= nodes; j++)
            if (j > i && cost[i][j] != INT_MAX) // i.e. if the edge exists between i and j
                heap[in].s = i, heap[in].d = j, heap[in++].w = cost[i][j];

    // now we start building the heap
    // since the heap contains edges we find the last non leaf edge using the formula: edges/2-1
    for (int i = edges / 2 - 1; i >= 0; i--)
        heapify(heap, edges, i); // we are sending edges and not nodes because the heap struct is of edges and not nodes

    // init parent
    int parent[N];
    for (int i = 1; i <= nodes; i++)
        parent[i] = -1;
    int i = 1, mincost = 0; // I TAKEN AS 0 INSTEAD OF 1

    while (i < nodes)
    {
        // delete the min edge (the root) from the heap and reheapify
        sw(&heap[0], &heap[edges - 1]);        // swap with the last
        struct EDGE minedge = heap[edges - 1]; // store the min cost edge
        edges--;                               // reduce the size of e;
        heapify(heap, edges, 0);               // sending zero because we need to reheapify the entire heap again

        // storing the source and destination of the mincost edge in u and v
        int u = minedge.s, v = minedge.d, j = Find(parent, u), k = Find(parent, v);
        if (j != k) // ie they dont have the same parent
        {
            t[i][1] = u, t[i][2] = v, mincost += cost[u][v];
            Union(parent, j, k);
            i++;
        }
    }
    if (i != nodes)
        return -1;
    else
        return mincost;
}

int main(int argc, char const *argv[])
{
    int cost[N][N], e[N][N], t[N][2], edges, nodes;
    sint(nodes), sint(edges);
    fillzeroes(e, nodes), fillinf(cost, nodes);
    getmat(e, cost, nodes, edges);
    int mincost = kruskal(e, cost, nodes, t, edges);
    if (mincost != -1)
    {
        printf("mincost: %d\n", mincost);
        printf("MST\n");
        for (int i = 1; i <= nodes - 1; i++)
            printf("%d %d\n", t[i][1], t[i][2]);
    }
    else
        printf("no mst\n");
    return 0;
}

/*
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