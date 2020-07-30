/*
 * Problem A-fibtree (contests/zju-icpc/2020summer3/A-fibtree)
 * Create time: Wed 29 Jul 2020 @ 13:32 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
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
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
const int MX = 100111;
int N, M, fib[MX];
vector<pair<int, int> > ones, zeros;

int djs[MX], djf[MX];
int find(int n)
{
    if (djf[n] != n) djf[n] = find(djf[n]);
    return djf[n];
}
int merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    if (djs[a] < djs[b]) swap(a, b);
    djs[a] += djs[b];
    djf[b] = a;
    return 1;
}

int main()
{
    scanf("%d%d", &N, &M);
    if (!M) { printf("No\n"); return 0; }
    for (int i=0; i<M; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (w) ones.pb(mp(u, v));
        else zeros.pb(mp(u, v));
    }
    int zs=0, lo=0, hi=0;
    for (int i=0; i<MX; ++i) djf[i] = i, djs[i] = 0;
    for (auto p : zeros) zs += merge(p.f, p.s);
    for (auto p : ones) lo += merge(p.f, p.s);
    for (int i=0; i<MX; ++i) djf[i] = i, djs[i] = 0;
    for (auto p : ones) hi += merge(p.f, p.s);
    if (zs + lo + 1 != N) { printf("No\n"); return 0; }

    int a=1, b=1;
    bool ans = false;
    while (a <= hi<<1)
    {
        int c = b;
        b += a;
        a = c;
        //(a = b) += a; swap(a, b);  // FIX: don't do this to calculate fibonacci. it's undefined behavior (works locally but not on codeforces)
        if (lo <= a && a <= hi)
        { ans = 1; break; }
    }
    if (ans) printf("Yes\n");
    else printf("No\n");

	return 0;
}

