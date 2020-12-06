/*
 * Problem lca_1 (spoj/lca_1)
 * Create time: Sat 05 Dec 2020 @ 22:30 (PST)
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

void setIO(const std::string &name = "lca_1")
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
using namespace std;
const int MX = 1e3+11;

int T, N, Q;

int bl[16][MX], dep[MX];
bool haspar[MX];

int kdep(int c) { if (!dep[c]) printf("dep %d: %d = %d\n", c, bl[0][c], kdep(bl[0][c])), dep[c] = kdep(bl[0][c])+1; return dep[c]; }

int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v); // u is lower
    for (int i=15; ~i; --i)
        if (dep[bl[i][u]] <= dep[v])
            u = bl[i][u];
    printf("u %d dep %d       v %d dep %d\n", u, dep[u], v, dep[v]);
    for (int i=15; ~i; --i)
        if (bl[i][u] != bl[i][v])
            u = bl[i][u], v = bl[i][v];
    printf("u %d v %d\n", u, v);
    return bl[0][u];
}

int main()
{
    sc(T);
    while (T--)
    {
        sc(N);
        F(i, N)
        {
            int t, v; sc(t);
            while (t--) bl[0][v = sc()] = i, haspar[v] = 1;
        }
        F(i, N) if (!haspar[i])
        { bl[0][i] = i, dep[i] = 1; break; }

        F(i, N) kdep(i);
        F(j, 16) F(i, N) bl[j][i] = bl[j-1][bl[j-1][i]];

        //F(i, N) printf("%3d", i); printf("\n");
        F(i, N) printf("%3d", kdep(i)); printf("\n");
        //F(j, N) { F(i, N) printf("%3d", bl[j][i]); printf("\n"); }

        sc(Q);
        while (Q--)
        {
            int u, v; sc(u, v);
            printf("%d\n", lca(u, v));
        }
    }
}

