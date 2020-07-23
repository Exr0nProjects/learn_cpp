#include <ctime>
#include <cstdio>
#include <cstdlib>
#define rand(l,h) (rand()%(h-l+1)+l)

const int MX = 1000;

int main()
{
    srand(time(0));

    for (int i=0; i<MX; ++i) printf("%d\n", rand(2, (int)1e6));
    printf("0\n");

    return 0;
}

