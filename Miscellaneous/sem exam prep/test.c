#include <stdio.h>
#define sint(x) scanf("%d", &x)
#define N 20

int m, n; // n si the number of elements and m is the size

// pseudocode
// algo sos(s, k, r, w, x)
//      check if k is greater than n
//      

void sumofsub(int s, int k, int r, int w[N], int x[N])
{
    if (k > n)
        return;
    // set the answer node
    x[k] = 1;
    // immediate answer
    if (s + w[k] == m)
    {
        return;
    }
}
int main(int argc, char const *argv[])
{
    printf("Enter the number of elements: "), sint(n);
    // init r to zero (sum)
    int r = 0; // r holds the remainin weight, so initlaly all the weight
    int x[n + 1], w[n + 1];
    printf("Enter the elements\n");
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
        sint(w[i]);
        r += w[i];
    }
    sumofsub(0, 1, r, w, x);

    return 0;
}