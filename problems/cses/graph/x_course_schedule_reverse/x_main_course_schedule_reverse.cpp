/*
 * Problem course_schedule_reverse (cses/graph/course_schedule_reverse)
 * Create time: Sat 05 Dec 2020 @ 20:31 (PST)
 * Accept time: Sat 05 Dec 2020 @ 20:57 (PST)
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

void setIO(const std::string &name = "course_schedule_reverse")
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

struct Edge { int t, n; } eg[MX<<1]; int hd[MX], ecnt=2;
void addEdge()
{
    int u, v; sc(u, v);
    eg[ecnt] = { u, hd[v] };
    hd[v] = ecnt++;
}
int N, M, ans[MX], acnt=0;
int vis[MX]; // -1 = unvisited, 1 = active, 0 = done

int topo(int c)
{
    if (~vis[c]) return vis[c];
    vis[c] = 1;
    for (int e=hd[c]; e; e=eg[e].n)
        if (topo(eg[e].t)) return 1;
    vis[c] = 0;
    ans[++acnt] = c;
    return 0;
}

int main()
{
    sc(N, M);
    F(i, M) addEdge();
    memset(vis, -1, sizeof vis);
    F(i, N) if (topo(i))
    { printf("IMPOSSIBLE\n"); return 0; }
    F(i, N) printf("%d ", ans[i]); printf("\n");
}

