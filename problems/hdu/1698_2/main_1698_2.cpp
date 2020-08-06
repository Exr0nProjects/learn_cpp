/*
 * Problem 1698_2 (hdu/1698_2)
 * Create time: Thu 06 Aug 2020 @ 10:38 (PDT)
 * Accept time: [!meta:end!]
 * ack -i iterative segment tree inpmelementation (segtree impl) from CPH
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MX = 100010;
struct Node { int sum, set; } sgt[MX<<1];
int N, D, Q;

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

void update(int l, int r, int v)    // zero indexed inc inc
{
    l += D; r += D;
    int d = 1, k;
    while (l <= r)
    {
        printf("    l %d, r %d\n", l, r);
        k = l;  // remember where we came from, could be k=r too since this last happens when l == r
        if ( l&1) sgt[l].sum = (sgt[l].set = v) * d, ++l;
        if (~r&1) sgt[r].sum = (sgt[r].set = v) * d, --r;
        l >>= 1, r >>= 1, d <<= 1;
    }
    printf("l %d r %d k %d\n", l, r, k);
    k >>= 1;
    while (k) { sgt[k].sum = sgt[k<<1].sum + sgt[k<<1|1].sum;
        printf("modify %d to %d\n", k, sgt[k].sum); k>>=1;}
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

    scanf("%d", &Q);
    for (int i=0; i<Q; ++i)
    {
        int l, r, v;
        scanf("%d%d%d", &l, &r, &v);
        update(l-1, r-1, v);
        dump();
    }


	return 0;
}

