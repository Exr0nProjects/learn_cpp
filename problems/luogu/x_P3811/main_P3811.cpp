/*
 * Problem P3811 (luogu/P3811)
 * Create time: Tue 27 Oct 2020 @ 18:43 (PDT)
 * Accept time: [!meta:end!]
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

void setIO(const std::string &name = "P3811")
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
const int MX = 3e6+11;

ll N, P, a[MX], p[MX], s[MX];

ll pow(ll b, ll e, ll m)
{
    ll ret=1;
    for (; e; e>>=1, (b*=b)%=m)
        if (e&1) (ret *= b)%=m;
    return ret;
}

int main()
{
    sc(N, P);
    for (int i=1; i<=N; ++i) a[i] = i;
    p[0] = s[N+1] = 1;
    for (int i=1; i<=N; ++i)
        p[i] = (a[i] * p[i-1])%P,
        s[N+1-i] = (a[N+1-i] * s[N+2-i])%P;
    ll inv = pow(p[N], P-2, P);
    //printf("%lld * %lld = %lld %%> %lld\n", p[N], inv, p[N]*inv, p[N]*inv % P);

    //for (int i=1; i<=N; ++i) printf("%8lld", a[i]); printf("\n");
    //for (int i=1; i<=N; ++i) printf("%8lld", p[i]); printf("\n");
    //for (int i=1; i<=N; ++i) printf("%8lld", s[i]); printf("\n");

    for (int i=1; i<=N; ++i) printf("%lld\n", p[i-1]*s[i+1]%P *inv % P);
}

