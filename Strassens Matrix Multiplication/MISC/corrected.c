#include <stdio.h>
#define sint(x) scanf("%d", &x);
#define new printf("\n");
#define N 8

void sa(int a[N][N], int b[N][N], int c[N][N], int n, int x)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = x ? a[i][j] - b[i][j] : a[i][j] + b[i][j];
}

void copy(int a[N][N], int b[N][N], int r1, int r2, int c1, int c2)
{
    int size = r2 - r1;
    for (int i = r1, j = 0; i < r2 && j < size; i++, j++)
        for (int x = c1, y = 0; x < c2 && y < size; x++, y++)
            b[j][y] = a[i][x];
}

void combine(int C11[N][N], int C12[N][N], int C21[N][N], int C22[N][N], int C[N][N], int n)
{
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
            C[i][j] = C11[i][j];

    for (int i = 0; i < n / 2; i++)
        for (int j = 0, k = n / 2; j < n / 2 && k < n; j++, k++)
            C[i][k] = C12[i][j];

    for (int i = 0, k = n / 2; i < n / 2 && k < n; i++, k++)
        for (int j = 0; j < n / 2; j++)
            C[k][j] = C21[i][j];

    for (int i = 0, k = n / 2; i < n / 2 && k < n; i++, k++)
        for (int j = 0, l = n / 2; j < n / 2 && l < n; j++, l++)
            C[k][l] = C22[i][j];
}

void strassen(int a[N][N], int b[N][N], int c[N][N], int n)
{
    // printf("entered strassen\n");
    if (n == 2)
    {
        // printf("entered base case\n");
        int P = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
        int Q = (a[1][0] + a[1][1]) * b[0][0];
        int R = a[0][0] * (b[0][1] - b[1][1]);
        int S = a[1][1] * (b[1][0] - b[0][0]);
        int T = (a[0][0] + a[0][1]) * b[1][1];
        int U = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
        int V = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

        c[0][0] = P + S - T + V;
        c[0][1] = R + T;
        c[1][0] = Q + S;
        c[1][1] = P + R - Q + U;
    }
    else
    {
        // here we first find mid
        // then we make 4 new matrices each for a, b and c
        // we copy parts from the original matrix to these new matrices
        // we find p, q ...but call strassen fn on parts of these
        // finally combine into orig c

        int mid = n / 2;
        int a11[N][N], a12[N][N], a21[N][N], a22[N][N], b11[N][N], b12[N][N], b21[N][N], b22[N][N], c11[N][N], c12[N][N], c21[N][N], c22[N][N];
        int p[N][N], q[N][N], r[N][N], s[N][N], t[N][N], u[N][N], v[N][N];
        int t1[N][N], t2[N][N]; // temp matrices will be used to store intermediate results between recusive calls

        // copying part
        // here to copy for 11 and 12 the rows remain constant and the colms change
        copy(a, a11, 0, mid, 0, mid); // here the rows are 0 to mid because they are const and cols change
        copy(a, a12, 0, mid, mid, n);
        copy(a, a21, mid, n, 0, mid);
        copy(a, a22, mid, n, mid, n);

        // same for b
        copy(b, b11, 0, mid, 0, mid);
        copy(b, b12, 0, mid, mid, n);
        copy(b, b21, mid, n, 0, mid);
        copy(b, b22, mid, n, mid, n);

        sa(a11, a22, t1, mid, 0), sa(b11, b22, t2, mid, 0), strassen(t1, t2, p, mid); // P

        sa(a21, a22, t1, mid, 0), strassen(t1, b11, q, mid); // Q

        sa(b12, b22, t2, mid, 1), strassen(a11, t2, r, mid); // R

        sa(b21, b11, t2, mid, 1), strassen(a22, t2, s, mid); // S

        sa(a11, a12, t1, mid, 0), strassen(t1, b22, t, mid); // T

        sa(a21, a11, t1, mid, 1), sa(b11, b12, t2, mid, 0), strassen(t1, t2, u, mid); // U

        sa(a12, a22, t1, mid, 1), sa(b21, b22, t2, mid, 0), strassen(t1, t2, v, mid); // V

        // add to c11, c12 ...

        sa(p, s, t1, mid, 0), sa(v, t, t2, mid, 1), sa(t1, t2, c11, mid, 0); // c11

        sa(r, t, c12, mid, 0); // c12

        sa(q, s, c21, mid, 0); // c21

        sa(p, r, t1, mid, 0), sa(u, q, t2, mid, 1), sa(t1, t2, c22, mid, 0); // c22

        // now we combine the parts
        combine(c11, c12, c21, c22, c, n);
    }
}

int main()
{
    int n = 1;
    while (n % 2 != 0)
    {
        printf("Enter the size (order 2x): ");
        sint(n);
    }
    int a[N][N], b[N][N], c[N][N];
    printf("Enter the elements of matrix a\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sint(a[i][j]);

    printf("Enter the elements of matrix b\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sint(b[i][j]);

    strassen(a, b, c, n);

    printf("The product of the two matrices is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%4d", c[i][j]);
        new;
    }
}