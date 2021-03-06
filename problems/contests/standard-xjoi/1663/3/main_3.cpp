/*
 * Problem 3 (contests/standard-xjoi/1663/3)
 * Create time: Fri 27 Nov 2020 @ 12:03 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <set>
#include <map>
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
//struct Edge { int u, v, n; } eg[MX]; int hd[MX], ecnt=0;

inline ll pow(ll b, ll e, ll m)
{
    ll ret=1;
    for (; e; e>>=1, (b*=b)%=m)
        if (e&1) (ret *= b)%=m;
    return ret;
}

void setIO(const std::string &name = "3")
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

ll N, W, H, rx[MX], ry[MX];
int x[MX], y[MX], v[MX], ps[MX][MX];
map<ll, ll> dsx, dsy;

int main()
{
    sc(N, W, H);
    for (int i=1; i<=N; ++i)
        sc(rx[i], ry[i]), sc(v[i]),
        dsx[rx[i]], dsy[ry[i]];
    int cnt;
    cnt = 0; for (pair<const ll, ll>& p : dsx) p.s = ++cnt;
    cnt = 0; for (pair<const ll, ll>& p : dsy) p.s = ++cnt;
    //for (auto p : dsy) printf("%d -> %d\n", p.f, p.s);

    for (int i=1; i<=N; ++i)
        x[i] = dsx[rx[i]],
        y[i] = dsy[ry[i]],
        ps[x[i]][y[i]] += v[i];
    for (int i=1; i<=N; ++i) for (int j=1; j<=N; ++j)
        ps[i][j] += ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];

    //printf("idx  "); for (int i=1; i<=N; ++i) printf("%3d", i); printf("\n");
    //printf(" rx  "); for (int i=1; i<=N; ++i) printf("%3d", rx[i]); printf("\n");
    //printf(" ry  "); for (int i=1; i<=N; ++i) printf("%3d", ry[i]); printf("\n");
    //printf("  x  "); for (int i=1; i<=N; ++i) printf("%3d", x[i]); printf("\n");
    //printf("  y  "); for (int i=1; i<=N; ++i) printf("%3d", y[i]); printf("\n");
    //for (int i=dsy.size(); i; --i)
    //{
    //    for (int j=1; j<=dsx.size(); ++j)
    //        printf("%3d", ps[j][i]);
    //    printf("\n");
    //}

    int ans = 0;
    for (int i=1; i<=N; ++i)
    {
        auto bx = prev(dsx.lower_bound(rx[i] + W));
        auto by = prev(dsy.lower_bound(ry[i] + H));
        //printf("%d ends at %d (%d) and %d (%d)\n", i, bx->s, bx->f, by->s, by->f);
        ans = max(ans, ps[bx->s][by->s] - ps[bx->s][y[i]-1] - ps[x[i]-1][by->s] + ps[x[i]-1][y[i]-1]);
    }
    printf("%d\n", ans);
}

