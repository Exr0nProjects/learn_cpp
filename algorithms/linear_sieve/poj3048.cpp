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
    for (int i=0; i<N; ++i) printf("%3d\n", sieve[i]); return 0;
    //printf("n = %d\n", N);
    int ret=0;  // FIX: can't assume 2 is the smallest, maybe its just one cow labeled 1
    for (int i=0; i<N; ++i)
    {
        int d; scanf("%d", &d);
        //printf("%d->%d better than %d->%d\n", d, sieve[d], ret, sieve[ret]);
        if (sieve[d] > sieve[ret])
            ret = d;
    }
    printf("%d\n", ret);
    return 0;
}

