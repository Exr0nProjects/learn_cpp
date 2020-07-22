#include <ctime>
#include <cstdio>
#include <cstdlib>

//const int MXT = 10;
//const int MXS = 8;
//const int MXM = 20;
//const int MXN = 100;
//const int MXC = 40000;

const int MXT = 100;
const int MXS = 8;
const int MXM = 20;
const int MXN = 100;
const int MXC = 40000;

int main()
{
    srand(time(0));
    for (int t=0; t<MXT; ++t)
    {
        int S = rand()%MXS+1;
        int M = rand()%MXM+1;
        int N = rand()%MXN+1;
        printf("%d %d %d\n", S, M, N);
        for (int i=0; i<M+N; ++i)
        {
            //printf("%d", rand()%MXC +1e4+1);
            printf("%d", rand()%MXC+1);
            for (int i=1; i<=S; ++i) if (rand()%2)
                printf(" %d", i);
            printf("\n");
        }
    }
    printf("0 0 0\n");
}

