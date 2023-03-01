// there is something wrong, on hold for now

#include <stdio.h>
#define sint(x) scanf("%d", &x);
#define sintalt(x) scanf("%d", x);
#define pint(x) printf("%3d", x);
#define new printf("\n");
#define dummy 10

void show(int m[][dummy], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            pint(m[i][j]);
        new;
    }
}

void takeorder(int *m1, int *n1, int *m2, int *n2)
{
    printf("Enter the order of matrix one\nrow: ");
    sintalt(m1);
    printf("col: ");
    sintalt(n1);
    printf("Enter the order of matrix two\n");
    printf("row: ");
    sintalt(m2);
    printf("col: ");
    sintalt(n2);
}

int main(int argc, char const *argv[])
{

    int m1, n1, m2, n2;
    do
    {
        takeorder(&m1, &n1, &m2, &n2);
    } while (n1 != m2);

    int a[m1][n1], b[m2][n2], c[m1][n2];
    printf("Enter the elements\n");
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n1; j++)
            sint(a[i][j]);
    printf("Enter the elements\n");
    for (int i = 0; i < m2; i++)
        for (int j = 0; j < n2; j++)
            sint(b[i][j]);

    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n2; k++)
                c[i][j] += a[i][k] * b[k][j];
        }

    show(c, m1, n2);
    return 0;
}