/*
 * Problem 1698_2 (hdu/1698_2)
 * Create time: Thu 06 Aug 2020 @ 10:38 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MX = 100010;
struct Node { int sum, set; } sgt[MX<<1];
int N, D;

void dump()
{
    int d = D+1;
    for (int i=1; i<D<<1; ++i)
    {
        if (__builtin_popcount(i) == 1) { printf("\n"); d>>=1; }
        printf("%3d =%-2d", sgt[i].sum, sgt[i].set);
        for (int i=1; i<=d; ++i) printf("       ");
    }
    printf("\n");
}

void update(int l, int r, int v)
{
    int d = 1;
    while (l <= r)
    {
        if ( l&1) sgt[l].sum = (sgt[l].set = v) * d;
        if (~r&1) sgt[r].sum = (sgt[r].set = v) * d;
        l <<= 1, r <<= 1, d >>= 1;
    }
}

int main()
{
    scanf("%d", &N);
    for (D=1; D<N; D<<=1);
    for (int i=0; i<N; ++i)
        scanf("%d", &sgt[D+i].sum);   // maybe this should be sgt[i].set?
    for (int i=D-1; i; --i)
        sgt[i].sum = sgt[i<<1].sum + sgt[i<<1|1].sum;
    dump();

	return 0;
}

