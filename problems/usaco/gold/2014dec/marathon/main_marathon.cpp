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

int main()
{
    scanf("%d%d", &N, &Q);
    for (int i=1; i<=N; ++i) scanf("%d%d", x+i, y+i);
    // init bit
    for (int i=2; i<=N; ++i) bu(i, dist(i, i-1));
    for (int i=1; i<=N; ++i) printf("%3d", bq(i, i)); printf("\n");
    // init segt
    for (D=1; D<N; D<<=1);
    for (int i=3; i<=N; ++i)
    {
        printf("%d..%d = %d\n", i-2, i, dist(i-2, i));
        tmax[D+i-1] = bq(i-2, i)-dist(i-2, i);
    }

	return 0;
}

