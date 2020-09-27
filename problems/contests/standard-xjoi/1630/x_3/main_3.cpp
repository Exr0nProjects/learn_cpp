/*
 * Problem 3 (contests/standard-xjoi/1630/3)
 * Create time: Wed 23 Sep 2020 @ 19:19 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

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
#define gcd(_a, _b) ({auto a=_a;auto\
    b=_b;while(b)(a)%=(b),(a)^=(b)^=(a)^=(b);a;})

using namespace std;
const int MX = 251;
const int MXV = 1000;

int N, W, v[MX], w[MX];
ll dp[MXV];

bool check(ll x)
{
    //printf("x = %d\n", x);
    memset(dp, 0x8f, sizeof dp);    // FIX: init to inf because we check if it's greater than zero
    dp[0] = 0;
    for (int i=1; i<=N; ++i)
    {
        //printf("val = %d\n", 1000*v[i]-x*w[i]);
        for (int j=W; ~j; --j)
        {
            int k = min(W, j+w[i]);
            dp[k] = max(dp[k], dp[j] + 1000LL*(ll)v[i]-x*(ll)w[i]);
        }
        //for (int j=0; j<=W; ++j) printf("%13d", dp[j]); printf("\n");
    }
    return dp[W] >= 0;
}

int main()
{
    sc(N, W);
    F(i, N) sc(w[i], v[i]);

    int l=0, r=1e9;
    F(i, 40) {
        int mid = l+(r-l>>1);
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%d\n", l);

    //int mxv = N*1000;
    //
    //memset(dp, 0x3f, sizeof dp);
    //dp[0] = 0;  // FIX: base case
    //for (int i=1; i<=N; ++i)
    //    for (int j=MXV; j>=v[i]; --j)
    //        dp[j] = min(dp[j], dp[j-v[i]]+w[i]);
    //
    //ll ratio = 0;
    //for (int j=0; j<MXV; ++j)
    //{
    //    //printf("dp[%5d] = %d\n", j, dp[j]);
    //    if (dp[j] > W)  // FIX: weight must be greater than W not value
    //        ratio = max(ratio, 1000LL*(ll)j/(ll)dp[j]);
    //    //if (j/dp[j] > 0) printf("%10d j %d w %d\n", 1000*j/dp[j], j, dp[j]);
    //}
    //printf("%lld\n", ratio);
}

