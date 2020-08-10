#include <ctime>
#include <cstdio>
#include <cstdlib>
#define rand(l,h) (rand()%(h-l+1)+l)

const int T = 10;
const int MXC = 100000;
const int MXN = 10;
const int MXV = 1000;

int main()
{
    srand(time(0));

    for (int t=0; t<T; ++t)
    {
        int N = rand(0, MXN);
        printf("%5d %2d  ", rand(0, MXC), N);
        while (N--) printf("  %3d %3d", rand(0, MXV), rand(1, MXV));
        printf("\n");
    }

    return 0;
}

