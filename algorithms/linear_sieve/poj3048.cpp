// 16 July 2020

#include <cstdio>
const int MX = 2e4 + 100;
int N, sieve[MX];
int main()
{
    for (int i=2; i<MX; ++i)
        if (!sieve[i])
            for (int j=1; i*j<MX; ++j)
                sieve[i*j] = i;
    scanf("%d", &N);
    int ret=1;  // FIX: can't assume 2 is the smallest, maybe its just one cow labeled 1
    for (int i=0; i<N; ++i)
    {
        int d; scanf("%d", &d);
        if (sieve[d] > sieve[ret])
            ret = d;
    }
    printf("%d", ret);
    return 0;
}

