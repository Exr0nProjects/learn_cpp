#include <ctime>
#include <cstdio>
#include <cstdlib>
#define rand(l,h) (rand()%(h-l+1)+l)

int T = 10;
int K = 3;
//const int MXN = 50000;
//const int MXV = 10000;
const int MXN = 50000;
const int MXV = 100;

int main()
{
    srand(time(0));
    while (T--)
    {
        int N = rand(0, MXN);
        int M = rand(0, MXN);
        printf("%d %d %d\n", N, M, K);
        for (int i=0; i<N; ++i) printf("%d ", rand(0, MXV)); printf("\n");
        for (int i=0; i<M; ++i) printf("%d ", rand(0, MXV)); printf("\n");
    }

    return 0;
}

