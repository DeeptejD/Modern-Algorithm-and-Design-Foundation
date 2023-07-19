// strass 4x4
#include <stdio.h>
#include <limits.h>

#define N 30
#define sint(x) scanf("%d", &x)

void get(int a[][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            sint(a[i][j]);
}

void copy(int a[][N], int b[][N], int r1, int r2, int c1, int c2)
{
    for (int i = r1, l = 0; i <= r2, l < 2; i++, l++)
        for (int j = c1, m = 0; j <= c2, m < 2; j++, m++)
            a[l][m] = b[i][j];
}

void sum(int a[][N], int b[][N])
{
}

void strassen(int a[][N], int b[][N], int c[][N], int n)
{
    if (n == 2)
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
    else if (n == 4)
    {
        int a11[2][2], a12[2][2], a21[2][2], a22[2][2];
        copy(a11, a, 0, 1, 0, 1);
        copy(a12, a, 0, 1, 2, 3);
        copy(a21, a, 2, 3, 0, 1);
        copy(a22, a, 2, 3, 2, 3);

        int b11[2][2], b12[2][2], b21[2][2], b22[2][2];
        copy(b11, b, 0, 1, 0, 1);
        copy(b12, b, 0, 1, 2, 3);
        copy(b21, b, 2, 3, 0, 1);
        copy(b22, b, 2, 3, 2, 3);

        int p[2][2], q[2][2], r[2][2], s[2][2], t[2][2], u[2][2], v[2][2];
    }
}

int main(int argc, char const *argv[])
{
    int a[4][4], b[4][4], c[4][4], n;
    printf("Enter the dimentions of the matrix (max 4): "), sint(n);
    printf("Enter a\n"),
        get(a);
    printf("Enter b\n"), get(b);
    strassen(a, b, c, n);
    return 0;
}