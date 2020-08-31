/*
 * Problem intest (spoj/intest)
 * Create time: Sun 30 Aug 2020 @ 11:26 (PDT)
 * Accept time: Mon 31 Aug 2020 @ 08:06 (PDT)
 *
 */

#include <bits/stdc++.h>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
inline bool sc(ll &n)
{
    n = 0;
    int neg = 1;
    register char c;
    do c = getchar_unlocked();
    while ((c <  '0' || c >  '9') && c != '-'
            && c != '+' && c!=EOF);
    if (c == '-') neg = -1, c = getchar_unlocked();
    //while ((c <  '0' || c >  '9') && c!=EOF)
    //    c = getchar_unlocked();
    while ( c >= '0' && c <= '9'  && c!=EOF)
        (n *= 10) += (c-'0'), c = getchar_unlocked();
    n *= neg;
    return c != EOF;
}
#define _ilb inline bool
_ilb sc(int &a) { ll x; bool b=sc(x); a=x; return b; }
_ilb sc(int &a, int &b) { return sc(a)&&sc(b); }
_ilb sc(int &a, int &b, int &c) { return sc(a, b)&&sc(c); }
_ilb sc(ll &a, ll &b) { return sc(a)&&sc(b); }
_ilb sc(ll &a, ll &b, int &c) { return sc(a, b)&&sc(c); }
//struct Edge { int f, t, n; } edges[-1]; int head[-1];

void setIO(const std::string &name = "rectangle_cutting_up");

using namespace std;
const int MX = 511;

int N, M, dp[MX][MX];

int main()
{
    setIO();
    sc(N, M);

    memset(dp, 0x3f, sizeof dp);
    for (int i=1; i<=min(N, M); ++i) dp[i][i] = 0;
    for (int i=1; i<=N; ++i) for (int j=1; j<=M; ++j)
    {
        for (int k=1; k<i; ++k)
            dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
        for (int k=1; k<j; ++k)
            dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
    }
    printf("%d\n", dp[N][M]);

    return 0;
}

void setIO(const string &name)
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen((name + ".in").c_str(), "r") != 0) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w+", stdout);
    }
}

