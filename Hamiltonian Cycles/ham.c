// 211105017 Deeptej Dhauskar
#include <stdio.h>
#define sint(x) scanf("%d", &x)
#define N 100
#define line printf("\n--------------------------------------------------------\n")
int G[N][N], count = 0;

void show(int x[N], int nodes)
{
    printf("%d.\t", ++count);
    for (int i = 1; i <= nodes; i++)
        printf("%d -> ", x[i]);
    printf("%d", x[1]);
    printf("\n");
}

void nextval(int x[N], int nodes, int k)
{
    do
    {
        // printf("nextval do while\n");
        x[k] = (x[k] + 1) % (nodes + 1); // next vertex
        // printf("xk val %d\n", x[k]);
        if (!x[k])
            return;
        // printf("x[k]!=0\n");
        // printf("g val %d\n", G[x[k - 1]][x[k]]);
        if (G[x[k - 1]][x[k]] != 0)
        {
            int j;
            for (j = 1; j <= k - 1; j++)
                if (x[j] == x[k])
                    break;
            if (j == k)
                if ((k < nodes) || ((k == nodes && G[x[nodes]][x[1]] != 0)))
                    return;
        }
    } while (1);
}

void ham(int x[N], int nodes, int k)
{
    do
    {
        // printf("ham do while\n");
        // Generate values for x[k]
        nextval(x, nodes, k);
        if (!x[k])
            return;
        if (k == nodes)
            show(x, nodes);
        else
            ham(x, nodes, k + 1);
    } while (1);
}

int main()
{
    int nodes, edges, o, d, x[N];
    printf("Enter the number of nodes: "), sint(nodes);

    for (int i = 1; i <= nodes; i++)
        for (int j = 1; j <= nodes; j++)
            G[i][j] = 0;

    printf("Enter the number of edges: "), sint(edges);

    printf("Enter origin and destination\n");
    for (int i = 0; i < edges; i++)
        sint(o), sint(d), G[o][d] = G[d][o] = 1;
    int k;
    printf("Enter the starting vertex: "), sint(k);
    x[1] = k; // here we can assign '1' if we always want to start from vertex 1 or we can assign k value to start from a different vertex
    for (int i = 2; i <= nodes; i++)
        x[i] = 0;
    line, printf("The possible Hamiltonian Cycles starting from node %d are", k), line;
    ham(x, nodes, 2);
    return 0;
}

/*
Textbook
8
11
1 2
1 7
8 2
8 7
2 3
7 6
3 6
3 4
6 5
5 4
1 3


/*
6
10
1 2
1 3
1 4
2 3
2 5
2 6
3 4
3 5
4 5
5 6
*/