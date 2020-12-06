/*
 * Problem cstreet2 (spoj/cstreet2)
 * Create time: Sat 05 Dec 2020 @ 17:01 (PST)
 * Accept time: Sat 05 Dec 2020 @ 17:07 (PST)
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

#define gpq(T) priority_queue<T, deque<T>, greater<T> >
#define CMA , // https://stackoverflow.com/q/13842468/10372825
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
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

void setIO(const std::string &name = "cstreet2")
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
const int MX = 1e3+11;
const int MXM = 3e5+10;

ll T, P, N, M;
bool vis[MX];
struct Edge { int f, t, w, n; } eg[MXM]; int hd[MX], ecnt=2;
void addEdge(int u, int v, int w, bool b=1)
{
    eg[ecnt] = { u, v, w, hd[u] };
    hd[u] = ecnt++;
    if (b) addEdge(v, u, w, 0);
}

int main()
{
    sc(T);
    while (T--)
    {
        sc(P, N, M);
        memset(eg, 0, sizeof eg);
        memset(hd, 0, sizeof hd);
        memset(vis, 0, sizeof vis);
        ecnt = 2;
        F(i, M) { int u, v, w; sc(u, v, w); addEdge(u, v, w); }

        gpq(pii) pq; pq.push(mp(0, 1));
        ll sum = 0;
        while (pq.size())
        {
            int d, c;
            tie(d, c) = pq.top(); pq.pop();
            if (vis[c]) continue; vis[c] = 1;
            sum += d;
            N(e, c) if (!vis[eg[e].t])
                pq.push(mp(eg[e].w, eg[e].t));
        }
        printf("%lld\n", sum*P);
    }
}

