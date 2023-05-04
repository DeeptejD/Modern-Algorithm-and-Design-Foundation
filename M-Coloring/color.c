// 211105017 Deeptej Dhauskar
#include <stdio.h>
#define sint(x) scanf("%d", &x)
#define N 20
#define line printf("\n------------------------------------------------------\n")
int G[N][N], count = 0;

int c[7] = {'V', 'I', 'B', 'G', 'Y', 'O', 'R'};

void show(int x[N], int nodes)
{
    printf("%d.\t", ++count);
    for (int i = 1; i <= nodes; i++)
        printf("%c ", c[x[i]]); // we can simply print the int value of x[i] also but just adding some rizz
    printf("\n");
}

void nextval(int x[N], int nodes, int colors, int k)
{
    do
    {
        x[k] = (x[k] + 1) % (colors + 1); // next highest color
        if (!x[k])                        // all colors have been used
            return;
        int j;
        for (j = 1; j <= nodes; j++)
        {
            // checking that the color is distinct from the adjacent colors
            if ((G[k][j] != 0) && (x[k] == x[j]))
                break; // if <k, j> is an edge and if the adjacent vertices have the same color
        }
        if (j == nodes + 1)
            return; // new color found
    } while (1);
}

void color(int x[N], int nodes, int colors, int k)
{
    do
    {
        // generate all legal assignments for k
        nextval(x, nodes, colors, k); // assign x[k] to a legal color
        if (!x[k])
            return; // no new color possible
        if (k == nodes)
            show(x, nodes);
        else
            color(x, nodes, colors, k + 1);

    } while (1);
}

int main(int argc, char const *argv[])
{
    int nodes, edges, colors, o, d, x[N];
    printf("Enter the number of nodes: "), sint(nodes);

    for (int i = 1; i <= nodes; i++)
        for (int j = 1; j <= nodes; j++)
            G[i][j] = 0;

    printf("Enter the number of edges: "), sint(edges);

    printf("Enter origin and destination\n");
    for (int i = 0; i < edges; i++)
        sint(o), sint(d), G[o][d] = G[d][o] = 1;

    printf("Enter the number of colors: "), sint(colors);
    for (int i = 1; i <= nodes; i++)
        x[i] = 0;
    line, printf("The possible ways to color the nodes of the graph are"), line;
    color(x, nodes, colors, 1);
    return 0;
}

/*
Textbook test case
5
7
1 2
1 5
1 3
2 3
2 5
3 4
4 5
3


*/

/*
Tutorial Test case

8
13
1 6
1 5
1 4
1 2
1 8
2 5
2 6
5 6
7 6
7 3
6 3
3 8
8 4
4
*/