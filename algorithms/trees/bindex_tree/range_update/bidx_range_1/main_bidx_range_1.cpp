/*
 * Problem bidx_range_1 (../algorithms/trees/bindex_tree/range_update/bidx_range_1)
 * Create time: Sun 25 Oct 2020 @ 18:58 (PDT)
 * Accept time: [!meta:end!]
 * for problem BIT https://www.luogu.com.cn/problem/P3372
 */

#include <set>
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

void setIO(const std::string &name = "bidx_range_1")
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
#define gcd(_a, _b) ({auto a=_a;auto\
    b=_b;while(b)(a)%=(b),(a)^=(b)^=(a)^=(b);a;})

using namespace std;
const int MX = 1e5+11;

ll N, M, bd[MX], bp[MX];

void rbu(ll* b, ll x, ll v)
{
    for (; x<=N; x+=lb(x))
        b[x] += v;
}
ll rbq(ll *b, ll x)
{
    ll sum=0;
    for (; x; x-=lb(x))
        sum += b[x];
    return sum;
}

ll bq(ll l, ll r)
{
    --l;
    r = (r+1)*rbq(bd, r) - rbq(bp, r);
    l = (l+1)*rbq(bd, l) - rbq(bp, l);
    return r - l;
}
void bu(ll l, ll r, ll v)
{
    ++r;
    rbu(bd, l, v);
    rbu(bd, r, -v);
    rbu(bp, l, l*v);
    rbu(bp, r, r*-v);
}

int main()
{
    sc(N, M);
    for (ll i=1; i<=N; ++i)
        bu(i, i, sc());
    while (M--)
    {
        ll t, l, r, v; sc(t, l, r);
        if (t-1) printf("%lld\n", bq(l, r));
        else bu(l, r, sc());
    }
}

