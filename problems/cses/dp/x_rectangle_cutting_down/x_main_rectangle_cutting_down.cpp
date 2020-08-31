/*
 * Problem intest (spoj/intest)
 * Create time: Sun 30 Aug 2020 @ 11:26 (PDT)
 * Accept time: Mon 31 Aug 2020 @ 08:10 (PDT)
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

void setIO(const std::string &name = "rectangle_cutting_down");

using namespace std;
const int MX = 511;

int N, M, dp[MX][MX];

int kdp(int i, int j)
{
    if (i == j) return 0;
    int &ret = dp[i][j];
    if (ret) return ret;
    ret = 1e9;
    for (int k=1; k<i; ++k)
        ret = min(ret, kdp(k, j) + kdp(i-k, j) + 1);
    for (int k=1; k<j; ++k)
        ret = min(ret, kdp(i, k) + kdp(i, j-k) + 1);
    return ret;
}

int main()
{
    setIO();
    sc(N, M);
    printf("%d\n", kdp(N, M));

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

