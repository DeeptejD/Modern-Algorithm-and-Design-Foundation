#include <stdio.h>
#include <limits.h>
#define N 20
#define sint(x) scanf("%d", &x)

void fillzeroes(int a[][N], int nodes)
{
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            a[i][j] = 0;
}

void fillinf(int a[][N], int nodes)
{
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            a[i][j] = INT_MAX;
}

int getmat(int e[][N], int cost[][N], int nodes)
{
    int max_edges = nodes * (nodes - 1) / 2;
    int s, d, w, edges = 0;
    for (int i = 0; i < max_edges; i++)
    {
        sint(s), sint(d);
        if (s == -1 && d == -1)
            break;
        else if (s < 1 || s > nodes || d < 1 || d > nodes)
            printf("Invalid edge\n"), i--;
        else
        {
            sint(w);
            e[s - 1][d - 1] = e[d - 1][s - 1] = 1;
            cost[s - 1][d - 1] = cost[d - 1][s - 1] = w;
            edges++;
        }
    }
    return edges;
}

struct EDGE
{
    int s, d, w;
};

void iswap(struct EDGE *a, struct EDGE *b)
{
    struct EDGE temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct EDGE heap[], int edges, int i)
{
    int smallest = i, left = i * 2 + 1, right = i * 2 + 2;
    if (left < edges && heap[left].w < heap[smallest].w)
        iswap(&heap[left], &heap[smallest]);

    if (right < edges && heap[right].w < heap[smallest].w)
        iswap(&heap[right], &heap[smallest]);

    if (i != smallest)
    {
        iswap(&heap[i], &heap[smallest]);
        heapify(heap, edges, smallest);
    }
}

int Find(int parent[], int u)
{
    while (parent[u] != -1)
        u = parent[u];
    return u;
}

void Union(int parent[], int u, int v)
{
    parent[u] = v;
}

int kruskal(int nodes, int edges, int e[][N], int t[][2], int cost[][N])
{
    // creatign a heap array with the number of edges
    struct EDGE heap[edges];
    int in = 0;
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            if (j > i && cost[i][j] != INT_MAX)
            {
                heap[in].s = i, heap[in].d = j, heap[in++].w = cost[i][j];
            }
        }
    }

    for (int i = edges / 2 - 1; i >= 0; i--)
        heapify(heap, edges, i);

    int parent[nodes];
    for (int i = 0; i < nodes; i++)
        parent[i] = -1;
    int i = 1, mincost = 0;
    while (i < nodes)
    {
        iswap(&heap[0], &heap[edges - 1]);
        struct EDGE minedge = heap[edges - 1];
        edges--;

        heapify(heap, edges, 0);
        int u = minedge.s, v = minedge.d, j = Find(parent, u), k = Find(parent, v);
        if (j != k)
        {
            t[i][0] = u, t[i][1] = v, mincost += cost[u][v];
            Union(parent, j, k);
            printf("%d %d\n", t[i][0] + 1, t[i][1] + 1);
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
    int nodes, edges, t[N][2], e[N][N], cost[N][N];
    printf("Enter the number of vertices: "), sint(nodes);

    fillzeroes(e, nodes), fillinf(cost, nodes);

    edges = getmat(e, cost, nodes);
    int mincost = kruskal(nodes, edges, e, t, cost);

    printf("Mincost: %d\n", mincost);

    return 0;
}


