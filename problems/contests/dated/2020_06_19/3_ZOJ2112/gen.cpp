#include <cstdio>
#include <cstdlib>
//const int T = 4
//const int N = 500000
//const int M = 100000
//const int MX = 1e9

const int T = 4;
const int N = 50000;
const int M = 10000;
const int MX = 1000;

int main()
{
    printf("%d\n", T);
    for (int t=0; t<T; ++t)
    {
        printf("%d %d\n", N, M);
        for (int i=0; i<N; ++i)
            printf("%d ", rand()%MX);

        for (int i=0; i<M; ++i)
        {
            char cmd = rand()%2 ? 'Q' : 'C';
            printf("%c ", cmd);
            if (cmd == 'Q')
            {
                int l = rand()%N +1;
                int r = rand()%(N-l)+l+1;
                printf("%d %d %d\n", l, r, rand()%(r-l)+1);
            }
            else
                printf("%d %d\n", rand()%N+1, rand()%MX+1);
        }
    }
}

