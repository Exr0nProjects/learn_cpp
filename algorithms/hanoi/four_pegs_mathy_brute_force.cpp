/*
what the teacher said
6 oct 2019
f4(n) = min[f4(k)*2+f3(n-k) for k in [0:n]]
*/

#include <bits/stdc++.h>
#define cn const int
#define ull unsigned long long
using namespace std;
cn MAXSZ = 50;
ull best3[MAXSZ];
ull bestk[MAXSZ];
ull best4[MAXSZ];

inline void out(cn s, cn d) { printf("%c->%c\n", s + 65, d + 65); }

void print3(cn n, cn s = 0, cn d = 2, int aux[] = {})
{
    if (n > 1)
        print3(n - 1, s, 3 - s - d, aux);
    out(s, d);
    if (n > 1)
        print3(n - 1, 3 - s - d, d, aux);
}

void print4(cn n, cn s = 0, cn d = 3, int aux[] = {})
{
}

int main()
{
    ull n;
    scanf("%lld", &n);
    for (ull i = 0; i <= n; ++i)
    {
        best3[i] = (1 << i) - 1;
        best4[i] = -1;
    }
    printf("\n");

    best4[0] = 0;
    best4[1] = 1;

    for (ull i = 1; i <= n; ++i)
    {
        for (ull k = 1; k < i; ++k)
        {
            //d*/printf("%d-%d=%d => (%d %d) %d\n", i, k, i-k, best4[k], best3[i-k], best4[k]*2 + best3[i - k]);
            if (best4[k] * 2 + best3[i - k] < best4[i])
            {
                bestk[i] = k;
                best4[i] = best4[k] * 2 + best3[i - k];
            }
        }
        //printf("%lld: %lld\n", i, best4[i]);
    }
    print3((int)n);
    print4((int)n);
}
