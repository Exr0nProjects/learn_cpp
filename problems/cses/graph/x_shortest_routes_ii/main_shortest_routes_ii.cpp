/*
 * Problem shortest_routes_ii (cses/graph/shortest_routes_ii)
 * Create time: Mon 07 Dec 2020 @ 20:52 (PST)
 * Accept time: [!meta:end!]
 *  floyd warshall
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

void setIO(const std::string &name = "shortest_routes_ii")
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

//struct Edge { int t, n; } eg[MX*MX]; int hd[MX], ecnt=2;
//void addEdge(int u=0, int v=0, bool b=1)
//{
//    if (!u) sc(u, v);
//    eg[ecnt] = { v, hd[u] };
//    hd[u] = ecnt++;
//    if (b) addEdge(v, u, 0);
//}

using namespace std;
const int MX = 511;

ll N, M, Q, dist[MX][MX];

int main()
{
    sc(N, M, Q);
    memset(dist, 0x3f, sizeof dist);
    F(i, M)
    {
        int y, x; sc(y, x);
        dist[y][x] = min(dist[y][x], sc()); // FIX: cant assume simple graph
    }

    F(i, N) F(j, N) dist[i][j] = min(dist[i][j], dist[j][i]);
    F(i, N) dist[i][i] = 0;

    F(k, N) F(i, N) F(j, N)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    F(i, Q)
    {
        int u, v; sc(u, v);
        printf("%lld\n", dist[u][v] < 1e18 ? dist[u][v] : -1);
    }
}

