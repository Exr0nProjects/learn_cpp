#include <cstdio>
#include <cstdlib>
#include <ctime>

const int MXN = 1e5;
const int MX = 400;
const int MXM = 5e4;

//const int MXN = 3;
//const int MX = 10;
//const int MXM = 6;

int main()
{
    srand(time(NULL));
    for (int i=0; i<1; ++i)
    {
        int N = rand() % MXN +1;
        printf("%d\n", N);
        for (int i=0; i<N; ++i)
        {
            if (i) printf(" ");
            printf("%d", rand()%MX+1);
        }
        int M = rand() % MXM +1;
        printf("\n%d\n", M);
        for (int i=0; i<M; ++i)
        {
            if (i) printf(" ");
            printf("%d", rand()%MX+1);
        }
        printf("\n");
    }
}

