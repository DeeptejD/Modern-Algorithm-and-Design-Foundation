#include <stdio.h>
#include <stdlib.h>
#define sint(x) scanf("%d", &x);
#define new printf("\n");
#define print(x) printf("%4d", x);
#define n 2

int a[n][n], b[n][n], c[n][n];

void take(int a[][n])
{
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sint(a[i][j])
}

void show(int a[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            print(a[i][j]);
        new;
    }
}

void strassen()
{
    int p, q, r, s, t, u, v;
    p = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    q = (a[1][0] + a[1][1]) * b[0][0];
    r = a[0][0] * (b[0][1] - b[1][1]);
    s = a[1][1] * (b[1][0] - b[0][0]);
    t = (a[0][0] + a[0][1]) * b[1][1];
    u = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    v = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
    c[0][0] = p + s - t + v;
    c[0][1] = r + t;
    c[1][0] = q + s;
    c[1][1] = p + r - q + u;
}

int main(int argc, char const *argv[])
{
    take(a), take(b);
    printf("matrix 1\n"), show(a), new;
    printf("matrix 2\n"), show(b), new;
    strassen(a, b, c);
    printf("product of the two matrices\n");
    show(c);
    return 0;
}
