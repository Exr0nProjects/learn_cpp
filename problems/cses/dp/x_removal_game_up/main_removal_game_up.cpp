/*
 * Problem intest (spoj/intest)
 * Create time: Sun 30 Aug 2020 @ 11:26 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <bits/stdc++.h>

#define ll long long
#define dl double

#define pii pair<ll, ll>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb(x) ((x)&-(x))

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
//struct Edge { int f, t, n; } edges[-1]; int head[-1];

void setIO(const std::string &name = "removal_game_up")
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
const int MX = 5011;

int N, a[MX];
pii dp[MX][MX];

int main()
{
    sc(N);
    F(i, N) sc(a[i]);

    for (int ln=0; ln<N; ++ln) for (int l=1; l+ln<=N; ++l)
    {
        pii gl = dp[l+1][l+ln], gr = dp[l][l+ln-1];
        if (gl.s + a[l] > gr.s + a[l+ln])
            dp[l][l+ln] = mp(gl.s + a[l   ], gl.f);
        else
            dp[l][l+ln] = mp(gr.s + a[l+ln], gr.f);
        //printf("%d %d:  gl %d %d    gr %d %d  ->   %d %d\n", l, l+ln, gl.f, gl.s, gr.f, gr.s, dp[l][l+ln].f, dp[l][l+ln].s);
    }

    printf("%lld\n", dp[1][N].f); // FIX: array semantics-- array is dp[l][r] not dp[l][ln]

}

