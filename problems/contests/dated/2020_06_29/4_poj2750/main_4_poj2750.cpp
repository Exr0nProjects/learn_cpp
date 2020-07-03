/*
 * Problem 4_poj2750 (contests/dated/2020_06_29/4_poj2750)
 * Create time: Fri 03 Jul 2020 @ 10:19 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <tuple>
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
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 100111;
int N, D, M, arr[MX];
multiset<int> vals;
struct Node
{
    int tot;
    int max, lmax, rmax;
    int min, lmin, rmin;
    void set(int v)
    {
        tot = v;
        max = lmax = rmax = v;
        min = lmin = rmin = v;
    }
} nd[MX];

void dump()
{
    int d = D+1;
    for (int k=1; k<2<<D; ++k)
    {
        if (__builtin_popcount(k) == 1) { --d; printf("\n"); }
        printf("%2d (%2d %2d %2d) (%2d %2d %2d)   ", nd[k].tot,
                nd[k].lmax, nd[k].max, nd[k].rmax,
                nd[k].lmin, nd[k].min, nd[k].rmin);
        for (int i=1; i<1<<d; ++i) printf("                           ");
    }
    printf("\n");
}

void comb(int k)
{
    const Node &lc = nd[k<<1], &rc = nd[k<<1|1];
    nd[k].tot = lc.tot + rc.tot;
    nd[k].max = max(max(lc.max, rc.max), lc.rmax + rc.lmax);
    nd[k].lmax = max(lc.lmax, lc.tot + rc.lmax);
    nd[k].rmax = max(rc.rmax, rc.tot + lc.rmax);
    nd[k].min = min(min(lc.min, rc.min), lc.rmin + rc.lmin);
    nd[k].lmin = min(lc.lmin, lc.tot + rc.lmin);
    nd[k].rmin = min(rc.rmin, rc.tot + lc.rmin);
}

void update(int q, int v, int k=1, int tl=1, int tr=1<<D)
{
    //printf("update %d to %d @ %d(%d..%d)\n", q, v, k, tl, tr);
    if (tl == tr)
    { nd[k].set(v); return; }                   // FIX: return after applying

    int mid = tl + (tr-tl>>1);
    if (q <= mid) update(q, v, k<<1, tl, mid);
    else update(q, v, k<<1|1, mid+1, tr);

    if (mid+1 > N) nd[k] = nd[k<<1];            // FIX: don't combine with out of range
    else comb(k);
}

int getmax()
{
    int best = max(nd[1].max, nd[1].tot - nd[1].min);
    if (*vals.begin() > 0) best -= *vals.begin();
    return best;
}

int main()
{
    scanf("%d", &N);
    while (1<<D<N) ++D;
    for (int i=1; i<=N; ++i)
    {
        scanf("%d", &arr[i]);
        update(i, arr[i]);
        vals.insert(arr[i]);
    }
        //dump();
        //memset(arr, 0, sizeof arr);
        //memset(nd, 0, sizeof nd);
        //vals.clear();

    scanf("%d", &M);
    for (int i=0; i<M; ++i)
    {
        int q, v; scanf("%d%d", &q, &v);

        auto it = vals.find(arr[q]);    // erase one from multiset
        if (it != vals.end())
            vals.erase(it);

        arr[q] = v;                     // update arr
        vals.insert(arr[q]);            // add new value to multiset
        update(q, v);                   // update segtree

        //dump();
        printf("%d\n", getmax());
    }

	return 0;
}

