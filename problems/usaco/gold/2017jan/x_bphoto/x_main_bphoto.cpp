/*
 * Problem bphoto (usaco/gold/2017jan/bphoto)
 * Create time: Sun 06 Dec 2020 @ 13:02 (PST)
 * Accept time: Sun 06 Dec 2020 @ 13:16 (PST)
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

void setIO(const std::string &name = "bphoto")
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
const int MX = 1e5+11;

int N, h[MX];
int l[MX], r[MX], bit[MX];

map<int, int> desc;

void bu(int x)
{
    for (; x<=N; x+=lb(x))
        ++bit[x];
}
int bq(int x)
{
    int ret=0;
    for (; x; x-=lb(x))
        ret += bit[x];
    return ret;
}

int main()
{
    setIO();
    sc(N); F(i, N) sc(h[i]), desc[h[i]];
    int cnt=0; for (auto& p : desc) p.s = ++cnt;
    F(i, N) h[i] = desc[h[i]];

    F(i, N) l[i] = i-bq(h[i])-1, bu(h[i]);
    memset(bit, 0, sizeof bit);
    R(i, N) r[i] = (N-i)-bq(h[i]), bu(h[i]);

    //F(i, N) printf("%3d", h[i]); printf("\n");
    //F(i, N) printf("%3d", l[i]); printf("\n");
    //F(i, N) printf("%3d", r[i]); printf("\n");
    int ret = 0;
    F(i, N) if (max(l[i], r[i]) > 2*min(l[i], r[i])) ++ret;
    printf("%d\n", ret);
}

