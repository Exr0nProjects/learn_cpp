/*
 * Problem A-fibtree (contests/zju-icpc/2020summer3/A-fibtree)
 * Create time: Wed 29 Jul 2020 @ 13:32 (PDT)
 * Accept time: Wed 29 Jul 2020 @ 20:33 (PDT)
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <vector>

#define mp make_pair
#define pb push_back
#define f first
#define s second

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

