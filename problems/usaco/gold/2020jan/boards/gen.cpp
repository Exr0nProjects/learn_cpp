#include <ctime>
#include <cstdio>
#include <cstdlib>
#define rand(l,h) (rand()%(h-l+1)+l)

const int N = 1e9;
const int P = 3e1;
//const int N = 1e9;
//const int P = 1e5;

int main()
{
    srand(time(0));
    printf("%d\n", rand(0, (int)1e9));

    //printf("%d %d\n", N, P);
    //for (int i=1; i<=P; ++i)
    //{
    //    int x = rand(1, N), y = rand(1, N);
    //    printf("%d %d %d %d\n", x, y, rand(x, N), rand(y, N));
    //}

    return 0;
}

