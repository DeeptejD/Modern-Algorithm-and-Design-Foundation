#include <stdio.h>
int adj[100][100], cost[100][100];
struct EDGE
{
    int origin, destin, edgecost;
};
void init_adj(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
}
void init_cost(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            cost[i][j] = __INT32_MAX__;
}

int accept_graph(int n)
{
    int max_edges = n * (n - 1) / 2;
    int origin, destin, edgecost;
    int e = 0;
    printf("Enter the edges of the graph and their respective cost.\n");
    for (int i = 0; i < max_edges; i++)
    {
        printf("Enter the edge,( 0 0 randval) to quit :");
        scanf("%d %d %d", &origin, &destin, &edgecost);
        if ((origin == 0) && (destin == 0))
            break;
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            printf("Invalid edge.\n");
            i--;
        }
        else
        {
            adj[origin - 1][destin - 1] = 1;
            cost[origin - 1][destin - 1] = edgecost;
            adj[destin - 1][origin - 1] = 1;
            cost[destin - 1][origin - 1] = edgecost;
            e++;
        }
    }
    return e;
}
void display_arr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i] + 1);
    printf("\n");
}
void swap(struct EDGE *a, struct EDGE *b)
{
    struct EDGE temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(struct EDGE adj[], int e, int i)
{
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < e && adj[l].edgecost <= adj[smallest].edgecost)
        smallest = l;
    if (r < e && adj[r].edgecost <= adj[smallest].edgecost)
        smallest = r;
    if (smallest != i)
    {
        swap(&adj[i], &adj[smallest]);
        heapify(adj, e, smallest);
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
int kruskal(int n, int e, int t[][2])
{
    struct EDGE heap[e];
    int in = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i && cost[i][j] != __INT32_MAX__)
            {
                heap[in].origin = i;
                heap[in].destin = j;
                heap[in++].edgecost = cost[i][j];
            }
        }
    }
    for (int i = e / 2 - 1; i >= 0; i--)
        heapify(heap, e, i);
    int parent[n];
    for (int i = 0; i < n; i++)
        parent[i] = -1;
    int i = 1, mincost = 0;
    int u, v, j, k;
    while (i < n)
    {
        swap(&heap[0], &heap[e - 1]);
        struct EDGE minedge = heap[e - 1];
        e--;
        heapify(heap, e, 0);
        u = minedge.origin;
        v = minedge.destin;
        j = Find(parent, u);
        k = Find(parent, v);
        if (j != k)
        {

            t[i][0] = u, t[i][1] = v, mincost += cost[u][v];
            Union(parent, j, k);
            printf("(%d, %d) ", u + 1, v + 1);
            for (int l = 0; l < n; l++)
            {
                int val = 1;
                if (parent[l] == -1)
                    val = 0;
                printf("%d ", parent[l] + val);
            }
            printf("Cost: %d", mincost);
            printf("\n");
            i++;
        }
    }
    if (i != n)
        return -1;
    else
        return mincost;
}

int main()
{
    int e, n;
    printf("Enter the number of vertices of the graph.\n");
    scanf("%d", &n);
    int t[n][2];
    init_adj(n);
    init_cost(n);
    e = accept_graph(n);
    int mincost = kruskal(n, e, t);
    if (mincost != -1)
        printf("Mincost: %d\n", mincost);
    else
        printf("No MST.\n");
    return 0;
}