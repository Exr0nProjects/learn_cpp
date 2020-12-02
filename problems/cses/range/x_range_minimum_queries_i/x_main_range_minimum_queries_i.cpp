/*
 * Problem range_minimum_queries_i (cses/range/range_minimum_queries_i)
 * Create time: Tue 01 Dec 2020 @ 21:42 (PST)
 * Accept time: Tue 01 Dec 2020 @ 22:14 (PST)
 *
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

inline ll pow(ll b, ll e, ll m)
{
    ll ret=1;
    for (; e; e>>=1, (b*=b)%=m)
        if (e&1) (ret *= b)%=m;
    return ret;
}

void setIO(const std::string &name = "range_minimum_queries_i")
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
const int MX = 2e5+11;

int N, Q, st[20][MX];

int main()
{
    sc(N, Q);
    F(i, N) sc(st[0][i]);
    for (int j=0; j<18; ++j) F(i, N-(1<<j)+1)
        st[j+1][i] = min(st[j][i], st[j][i+(1<<j)]);
    //for (int j=0; j<19; ++j) { F(i, N-(1<<(j))+1) printf("%3d", st[j][i]); printf("\n"); }
    F(i, Q)
    {
        int l, r; sc(l, r); ++r; // FIX: ++r because sparse table is inc exc
        //int d=0; for (; 1<<d+1 < r-l; ++d);
        int d = 31-__builtin_clz(r-l);
        //printf("d = %d (%d)\n", d, 1<<d);
        printf("%d\n", min(st[d][l], st[d][r-(1<<d)]));
    }
}

