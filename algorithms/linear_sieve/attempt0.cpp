// 16 July 2020

#include <iostream>
const int MX = 1e5;
int sieve[MX], primes[MX], pcnt=0;

int main()
{
    for (int i=2; i<MX; ++i)
    {
        printf("i = %d\n", i);
        if (!sieve[i])
        {
            printf("    prime!\n");
            primes[pcnt++] = i;
        }
        for (int j=0; j<pcnt; ++j)
        {
            printf("    *primes[%d] = %d\n", j, i*primes[j]);
            sieve[i*primes[j]] = primes[j];
            if (i%primes[j]==0) break;
        }
    }
}

