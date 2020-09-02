/*
 * Problem intest (spoj/intest)
 * Create time: Sun 30 Aug 2020 @ 11:26 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <bits/stdc++.h>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
//struct Edge { int f, t, n; } edges[-1]; int head[-1];

#define _gc getchar_unlocked
inline bool sc(ll &n)
{
    int neg = 1;
    register char c;
    do c = _gc(); while (isspace(c));
    if (c == '-') neg = -1, c = _gc();
    for (n=0; c >= '0' && c <= '9'; c=_gc())
        (n *= 10) += (c-'0');
    n *= neg;
    return c != EOF;
}
#define _ilb inline bool
_ilb sc(int &a) { ll x; bool b=sc(x); a=x; return b; }
_ilb sc(int &a, int &b) { return sc(a)&&sc(b); }
_ilb sc(int &a, int &b, int &c) { return sc(a, b)&&sc(c); }
_ilb sc(ll &a, ll &b) { return sc(a)&&sc(b); }
_ilb sc(ll &a, ll &b, int &c) { return sc(a, b)&&sc(c); }

using namespace std;
const int MX = 1011;

int N, M, C, val[MX], tot=0;
vector<int> head[MX];
//bool vis[MX][125000][64]; // y = 1000x - Cx^2
unordered_set<ll> vis;

void dfs(int cur, int lay, int sum=0)
{
    //if (vis[cur][sum-C*lay*lay][lay]) return;
    //vis[cur][sum-C*lay*lay][lay] = 1;
    if (vis.count((ll)cur*250000*512 + (sum-C*lay*lay)*512 + lay))
        return;
    else
        vis.insert((ll)cur*250000*512 + (sum-C*lay*lay)*512 + lay);
    //printf("%d after %d has %d\n", cur, lay, sum);
    sum += val[cur];
    if (cur == 1) tot = max(tot, sum - C*lay*lay);
    if (lay > 128) return;
    for (auto n : head[cur])
        dfs(n, lay+1, sum);
}

int main()
{
    sc(N, M, C);
    for (int i=1; i<=N; ++i) sc(val[i]);
    for (int i=0; i<M; ++i)
    {
        int u, v; sc(u, v);
        head[u].pb(v);
    }
    dfs(1, 0);
    printf("%d\n", tot);
}

