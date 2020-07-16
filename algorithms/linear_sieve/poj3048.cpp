// 16 July 2020

#include <cstdio>
const int MX = 2e4 + 100;
int N, sieve[MX];
int main()
{
    for (int i=2; i<MX; ++i)
    {
        if (!sieve[i])
            for (int j=1; i*j<MX; ++j)
                sieve[i*j] = i;
        //printf("%3d: %3d\n", i, sieve[i]);
    }
    scanf("%d", &N);
    //printf("n = %d\n", N);
    int ret=2;
    for (int i=0; i<N; ++i)
    {
        int d; scanf("%d", &d);
        //printf("%d->%d better than %d->%d\n", d, sieve[d], ret, sieve[ret]);
        if (sieve[d] > sieve[ret])
            ret = d;
    }
    printf("%d", ret);
    return 0;
}

