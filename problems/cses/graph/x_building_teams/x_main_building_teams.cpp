/*
 * Problem building_teams (cses/graph/building_teams)
 * Create time: Sun 06 Dec 2020 @ 17:57 (PST)
 * Accept time: Sun 06 Dec 2020 @ 18:14 (PST)
 *
 */

#include <set>
#include <map>
#include <tuple>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

#define ll long long
#define dl double

#define gpq(...) priority_queue<__VA_ARGS__, deque<__VA_ARGS__>, greater<__VA_ARGS__> >
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mt make_tuple
#define un(...) ll __VA_ARGS__; tie(__VA_ARGS__)
#define lb(x) ((x)&-(x))

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
#define N(e,c) for (int e=hd[c]; e; e=eg[e].n)
#define TN(e,c,p) N(e,c) if (eg[e].t != p)

inline ll pow(ll b, ll e, ll m)
{
    ll ret=1;
    for (; e; e>>=1, (b*=b)%=m)
        if (e&1) (ret *= b)%=m;
    return ret;
}

void setIO(const std::string &name = "building_teams")
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen((name + ".in").c_str(), "r") != 0)
        freopen((name + ".in").c_str(), "r", stdin),
        freopen((name + ".out").c_str(), "w+", stdout);
}
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
inline ll sc() { ll x; sc(x); return x; }
#define _ilb inline bool
_ilb sc(int&a){ll x;bool b=sc(x);a=x;return b;}
_ilb sc(int&a,int&b){return sc(a)&&sc(b);}
_ilb sc(int&a,int&b,int&c){return sc(a,b)&&sc(c);}
_ilb sc(int&a,int&b,int&c,int&d){return sc(a,b)&&sc(c,d);}
_ilb sc(ll&a,ll&b){return sc(a)&&sc(b);}
_ilb sc(ll&a,ll&b,ll&c){return sc(a,b)&&sc(c);}
_ilb sc(ll&a,ll&b,ll&c,ll&d){return sc(a,b)&&sc(c,d);}
ll gcd(ll a, ll b) { while (b^=a^=b^=a%=b); return a; }

using namespace std;
const int MX = 1e5+11;

int N, M, ans[MX];
struct Edge { int t, n; } eg[MX<<2]; int hd[MX], ecnt=2;
void addEdge(int u=0, int v=0, bool b=1)
{
    if (!u) sc(u, v);
    eg[ecnt] = { v, hd[u] };
    hd[u] = ecnt++;
    if (b) addEdge(v, u, 0);
}

void dfs(int c, int t)
{
    //printf("at %d %d\n", c, t);
    if (~ans[c])    // FIX: default is -1 so need to check ~ans[c] not just truthyness
    {
        if (ans[c] != t)
            //printf("bad news bears %d from %d = %d\n", ans[c], c, t),
            N = -1;
        return;
    }
    ans[c] = t;
    N(e, c) dfs(eg[e].t, !t);
}

int main()
{
    sc(N, M);
    F(i, M) addEdge();

    memset(ans, -1, sizeof ans);
    F(i, N) if (ans[i]<0) dfs(i, !ans[i-1]);
    if (N < 0) printf("IMPOSSIBLE\n");
    F(i, N) printf("%d ", ans[i]+1); printf("\n");
}

