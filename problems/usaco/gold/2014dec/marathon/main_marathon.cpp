/*
 * Problem marathon (usaco/gold/2014dec/marathon)
 * Create time: Fri 07 Aug 2020 @ 15:05 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 100111;

int N, Q, x[MX], y[MX];

int dist(int i, int j)
{
    return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}
// point update BIT
int bit[MX];
int bq(int l, int r)
{
    int sum=0;
    --l;
    for (; r>l; r-=r&-r)
        sum += bit[r];
    for (; l>r; l-=l&-l)
        sum -= bit[l];
    return sum;
}
int bu(int n, int v)
{
    for (; n<=N; n+=n&-n)
        bit[n] += v;
}
// point update max segtree
// TODO: init segtree
int D, tmax[MX<<1];
int sq(int ql, int qr, int k=1, int tl=1, int tr=D)
{
    if (tr < ql || qr < tl) return 0;
    if (ql <= tl && tr <= qr) return tmax[k];
    int mid = tl + (tr-tl>>1);
    return max(sq(ql, qr, k<<1, tl, mid), sq(ql, qr, k<<1|1, mid+1, tr));
}
void su(int q, int v, int k=1, int tl=1, int tr=D)
{
    //if (q < tl || tr < q) return;   // NOTE: not needed?
    if (tl == tr) tmax[k] = v;
    int mid = tl + (tr-tl>>1);
    if (q <= mid) su(q, v, k<<1, tl, mid);
    else su(q, v, k<<1|1, mid+1, tr);
    tmax[k] = max(tmax[k<<1], tmax[k<<1|1]);
}
void dump()
{
    printf("bit:\n");
    for (int i=1; i<=N; ++i) printf("%3d", bq(i, i)); printf("\nsegt:");
    int d = D-1;
    for (int i=1; i<D<<1; ++i)
    {
        if (__builtin_popcount(i) == 1) { d>>=1; printf("\n"); }
        printf("%5d", tmax[i]);
        for (int i=1; i<=d; ++i) printf("     ");
    }
    printf("\n");
}

int main()
{
    scanf("%d%d", &N, &Q);
    for (int i=1; i<=N; ++i) scanf("%d%d", x+i, y+i);
    // init bit
    for (int i=2; i<=N; ++i) bu(i, dist(i, i-1));
    // init segt
    for (D=1; D<N; D<<=1);
    for (int i=3; i<=N; ++i)
    {
        printf("%d..%d = %d - %d = %d\n", i-2, i, bq(i-1, i), dist(i-2, i), bq(i-1, i) - dist(i-2, i));
        tmax[D+i-1] = bq(i-1, i)-dist(i-2, i);  // FIX: fencepost--bq(i-1, i) not bq(i-2, i) since we want 2 things not 3
    }
    for (int i=D-1; i; --i)
        tmax[i] = max(tmax[i<<1], tmax[i<<1|1]);
    dump();

    // queries
    for (int q=0; q<Q; ++q)
    {
        char c; cin >> c;
        if (c == 'U')
        {
            int i, predist;
            scanf("%d", &i); scanf("%d%d", x+i, y+i);   // must be two statements otherwise i isn't inited
            predist = bq(i, i);
            bu(i, dist(i-1, i)-predist);             // update dist i-1..i
            bu(i+1, dist(i+1, i)-bq(i+1, i+1));    // update dist i..i+1
            su(i,   bq(i-1, i)-dist(i-2, i));           // update skip i-1
            su(i+1, bq(i, i+1)-dist(i-1, i+1));         // update skip i
            su(i+2, bq(i+1, i+2)-dist(i, i+2));         // update skip i+1
            dump();
        }
    }

	return 0;
}

