/*
 * Problem projects_up (cses/dp/projects_up)
 * Create time: Mon 14 Sep 2020 @ 19:04 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
#include <numeric>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb(x) ((x)&-(x))

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
//struct Edge { int u, v, n; } edges[MX]; int head[MX], ecnt=0;

void setIO(const std::string &name = "projects_up")
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

using namespace std;
const int MX = 2e5+11;

ll N, a[MX], b[MX], p[MX], bit[MX], dp[MX], srt[MX];
map<ll, ll> dsc;

ll bq(ll x)
{
    ll ret=0;
    for (; x; x-=lb(x))
        ret = max(ret, bit[x]);
    return ret;
}
void bu(ll x, ll v)
{
    for (; x<=N; x+=lb(x))
        bit[x] = max(bit[x], v);
}

int main()
{
    sc(N);
    for (ll i=1; i<=N; ++i)
        sc(a[i], b[i], p[i]),
        dsc[a[i]], dsc[b[i]];
    ll i=1; for (auto &p : dsc) p.s = i++;

    iota(srt+1, srt+N+1, 1);    // FIX: missing logic--remember to sort
    sort(srt+1, srt+N+1, [](const int l, const int r) { return b[l] < b[r]; });
    //for (int i=1; i<=N; ++i) printf("%2d: %2d %2d %2d\n", srt[i], dsc[a[srt[i]]], dsc[b[srt[i]]], p[srt[i]]);
    //printf("segfault\n");

    ll ret=0;
    for (ll i=1; i<=N; ++i)
    {
        //printf("bq(%d) = %d => += %d\n", dsc[a[srt[i]]]-1, bq(dsc[a[srt[i]]]-1), p[srt[i]]);
        dp[srt[i]] = bq(dsc[a[srt[i]]]-1) + p[srt[i]];
        //printf("bu(%d, %d)\n", dsc[b[srt[i]]], dp[srt[i]]);
        bu(dsc[b[srt[i]]], dp[srt[i]]);
        ret = max(ret, dp[srt[i]]);
    }

    printf("%lld\n", ret);
}

