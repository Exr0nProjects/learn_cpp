/*
 * Problem intest (spoj/intest)
 * Create time: Sun 30 Aug 2020 @ 11:26 (PDT)
 * Accept time: Sun 13 Sep 2020 @ 10:33 (PDT)
 *
 */

#include <bits/stdc++.h>

#define ll long long
#define dl double

#define pii pair<ll, ll>    // FIX: long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb(x) ((x)&-(x))

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
//struct Edge { int f, t, n; } edges[-1]; int head[-1];

void setIO(const std::string &name = "removal_game_down")
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
#define _ilb inline bool
_ilb sc(int &a) { ll x; bool b=sc(x); a=x; return b; }
_ilb sc(int &a, int &b) { return sc(a)&&sc(b); }
_ilb sc(int &a, int &b, int &c) { return sc(a, b)&&sc(c); }
_ilb sc(ll &a, ll &b) { return sc(a)&&sc(b); }
_ilb sc(ll &a, ll &b, int &c) { return sc(a, b)&&sc(c); }

using namespace std;
const int MX = 5101;

int N, a[MX];
pii dp[MX][MX];

pii kdp(int l, int r)
{
    if (l == r) return mp(a[l], 0);
    pii &ret = dp[l][r];
    if (ret.f || ret.s) return ret;
    pii gl = kdp(l+1, r), gr = kdp(l, r-1);
    if (gl.s + a[l] > gr.s + a[r])
        ret = mp(gl.s + a[l], gl.f);
    else
        ret = mp(gr.s + a[r], gr.f);
    return ret;
}

int main()
{
    sc(N);
    for (int i=1; i<=N; ++i) sc(a[i]);

    printf("%lld\n", kdp(1, N).f);
}

