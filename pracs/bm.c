#include <stdio.h>
#include <limits.h>

#define N 30
#define sint(x) scanf("%d", &x)

struct item
{
    int p, w;
    float ratio;
};

int m, n;


int main(int argc, char const *argv[])
{
    printf("Number of items: "), sint(n), printf("Max cap: "), sint(m);
    
    return 0;
}