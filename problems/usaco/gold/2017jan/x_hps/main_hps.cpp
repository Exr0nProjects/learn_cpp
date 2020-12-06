/*
 * Problem hps (usaco/gold/2017jan/hps)
 * Create time: Sun 06 Dec 2020 @ 13:25 (PST)
 * Accept time: [!meta:end!]
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

void setIO(const std::string &name = "hps")
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
const int MXK = 32;

int N, K, a[MX];
int dp[MX][MXK][4];

int main()
{
    setIO();
    sc(N, K); ++K;
    F(i, N)
    {
        char c = _gc(); _gc();
        if (c == 'H') a[i] = 2;
        else if (c == 'P') a[i] = 1;
        else a[i] = 0;
    }
    //F(i, N) printf("%3d", a[i]); printf("\n");

    memset(dp, 0x8f, sizeof dp);
    F(j, K+1) F(k, 3) dp[0][j-1][k-1] = 0;

    int ans = 0;
    F(i, N) F(j, K) F(k, 3)
    {
        dp[i][j][k-1] = dp[i-1][j][k-1] + (a[i] == k-1);
        if (j) F(pk, 3) dp[i][j][k-1] =
            max(dp[i][j][k-1], dp[i-1][j-1][pk-1] + (a[i] == k-1));
        ans = max(ans, dp[i][j][k-1]);
    }
    //for (int i=0; i<=N; ++i) { F(j, K) printf("%5d %3d %3d   ", dp[i][j][0], dp[i][j][1], dp[i][j][2]); printf("\n"); }
    printf("%d\n", ans);
}

