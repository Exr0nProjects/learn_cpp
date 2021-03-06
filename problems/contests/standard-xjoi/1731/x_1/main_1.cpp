/*
 * Problem 1 (contests/standard-xjoi/1731/1)
 * Create time: Sun 18 Oct 2020 @ 15:12 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

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

void setIO(const std::string &name = "1")
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

ll N, M;
pair<ll, ll> iv[MX];

bool check(ll d)
{
    ll p=0, c=1, cnt=0;
    while (p <= iv[M].s && c <= M && cnt <= N)
    {
        if (iv[c].f <= p && p <= iv[c].s)
            ++cnt, p += d;  // it counts
        else if (p < iv[c].f) p = iv[c].f;
        else ++c;
    }
    //printf("d %lld -> %d\n", d, cnt >= N);
    return cnt >= N;
}

int main()
{
    sc(N, M);
    for (ll i=1; i<=M; ++i) sc(iv[i].f, iv[i].s);
    sort(iv+1, iv+M+1);

    //for (ll i=1; i<=M; ++i) printf("%lld..%lld\n", iv[i].f, iv[i].s);

    ll tl=0, tr=1e18;
    for (int i=1; i<=70; ++i)
    {
        ll mid = tl + (tr-tl>>1);
        if (check(mid)) tl = mid;
        else tr = mid;
    }
    printf("%lld\n", tl);
}

