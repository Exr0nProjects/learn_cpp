/*
 * Problem shortest_routes_i (cses/graph/shortest_routes_i)
 * Create time: Mon 07 Dec 2020 @ 20:13 (PST)
 * Accept time: [!meta:end!]
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

void setIO(const std::string &name = "shortest_routes_i")
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
const ll MX = 1e5+11;
struct Edge { ll t, w, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge(ll u=0, ll v=0, ll w=0, bool b=0)
{
    if (!u) sc(u, v, w);
    eg[ecnt] = { v, w, hd[u] };
    hd[u] = ecnt++;
    //if (b) addEdge(v, u, 0);
}

ll N, M;
ll dist[MX];
bool vis[MX];

int main()
{
    sc(N, M);
    F(i, M) addEdge();
    memset(dist, 0x3f, sizeof dist);
    //dist[1] = 0;

    gpq(pair<ll, ll>) q; q.push(mp(0, 1));
    while (q.size())
    {
        un(d, c) = q.top(); q.pop();
        //printf("at %d after %lld, cur %lld\n", c, d, dist[c]);
        //if (vis[c]) continue; vis[c] = 1;
        if (dist[c] <= d) continue;
        dist[c] = d;
        N(e, c) q.push(mp(d+eg[e].w, eg[e].t));
    }
    F(i, N) printf("%lld ", dist[i]); printf("\n");
}

