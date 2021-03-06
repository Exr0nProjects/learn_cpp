/*
 * Problem increasing_subsequence_up (cses/dp/increasing_subsequence_up)
 * Create time: Mon 14 Sep 2020 @ 17:31 (PDT)
 * Accept time: Mon 14 Sep 2020 @ 18:09 (PDT)
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>

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

void setIO(const std::string &name = "increasing_subsequence_up")
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

int N, a[MX], bit[MX], dp[MX];
map<int, int> dsc;

inline int id(int x)
{
    if (dsc[x]) return dsc[x];
    else return dsc.size();
}

int bq(int x)
{
    int ret=0;
    for (; x; x-=lb(x))
        ret = max(ret, bit[x]);
    return ret;
}
void bu(int x, int v)
{
    for (; x<=N; x+=lb(x))
        bit[x] = max(bit[x], v);
}

int main()
{
    sc(N);
    for (int i=1; i<=N; ++i) dsc[a[i] = sc()];
    int i=1; for (pair<const int, int> &p : dsc) p.s = i++;

    int ret=0;
    for (int i=1; i<=N; ++i)
    {
        dp[i] = bq(dsc[a[i]]) +1;   // FIX: equ--no need for N-i
        bu(dsc[a[i]]+1, dp[i]);
        ret = max(ret, dp[i]);
    }

    printf("%d\n", ret);
}

