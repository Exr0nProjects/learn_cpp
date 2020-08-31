/*
 * Problem intest (spoj/intest)
 * Create time: Sun 30 Aug 2020 @ 11:26 (PDT)
 * Accept time: [!meta:end!]
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
    register char c = getchar_unlocked();
    while ((c <  '0' || c >  '9') && c != '-'
            && c != '+' && c!=EOF)
        c = getchar_unlocked();
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

void setIO(const std::string &name = "array_description_down");

using namespace std;
const int MX = 1e5+11;
const int MXV = 110;
const int MOD = 1e9+7; // TODO

int N, M, arr[MX], dp[MX][MXV];

int kdp(int i, int j)
{
    if (j < 1 || j > M) return 0;
    if (i == 1) return !arr[i] || j == arr[i];
    if (i < 0) return 0;
    int &ret =  dp[i][j];
    if (ret > 0) return ret;
    ret = 0;
    if (!arr[i] || arr[i] == j)
        (ret += kdp(i-1, j-1)) %= MOD,
        (ret += kdp(i-1, j+1)) %= MOD,
        (ret += kdp(i-1, j  )) %= MOD;
    return ret;
}

int main()
{
    setIO();
    memset(dp, -1, sizeof dp);
    scanf("%d%d", &N, &M);
    F(i, N) sc(arr[i]);


    int tot=0;
    for (int i=1; i<=M; ++i) tot = (tot + kdp(N, i)) % MOD;
    //F(i, M) tot = (tot + kdp(N, i)) % MOD;
    //F(i, N) { F(j, M) printf("%3d", dp[i][j]); printf("\n"); }
    printf("%d\n", tot);

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

