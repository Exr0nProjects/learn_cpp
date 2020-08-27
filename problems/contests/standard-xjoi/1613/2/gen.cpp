#include <ctime>
#include <cstdio>
#include <cstdlib>
#define rand(l,h) (rand()%(h-l+1)+l)

//const int MXN = 2e5;
const int MXN = 1000;

int main(int argc, char** argv)
{
    srand(argc > 1 ? strtol(argv[1], 0, 0) : time(0));
    int N = rand(1, MXN), M = rand(1, MXN);
    printf("%d %d\n", N, M);
    while (M--)
        printf("%d %d\n", rand(1, N), rand(1, N));

    return 0;
}

