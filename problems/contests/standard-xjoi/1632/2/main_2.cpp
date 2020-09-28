/*
 * Problem 2 (contests/standard-xjoi/1632/2)
 * Create time: Mon 28 Sep 2020 @ 12:24 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

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

void setIO(const std::string &name = "2")
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

int N, par[MX], dep[MX], cnt[MX];
vector<int> hd[MX];
ll ans[MX];

int scname()
{
    register char c = _gc();
    int ret=0;
    while (isspace(c)) c = _gc();
    while (!isspace(c)) c = _gc(), ++ret;
    return ret;
}

int kcnt(int c, int p)
{
    ll totw = 0;
    if (!hd[c].size()) cnt[c] = 1;
    else for (auto n : hd[c])
    {
        totw += kcnt(n, c) + cnt[n]*dep[n];
        cnt[c] += cnt[n];
    }
    //printf("cnt[%d] = %d\n", c, cnt[c]);
    return totw;
}

int dfs(int c, int p, int onpath=0, int backtrack=0, int lay=0)
{
    //dep[c] += dep[p];
    ans[c] = 3*backtrack - onpath;
    //(backtrack *= 2) += (cnt[p] - cnt[c]);

    //F(i, lay) printf("|   "); printf("%2d -> %2d at dep %2d", p, c, dep[c]);
    //F(i, 5-lay) printf("    "); printf("onpath %2d backtrack %2d\n", onpath, backtrack);

    for (auto n : hd[c])
        dfs(n, c, onpath+(dep[n])*cnt[n],
                backtrack*2 + cnt[c]-cnt[n], lay+1);
}

int main()
{
    //setIO();
    sc(N);
    for (int i=1; i<=N; ++i)
    {
        dep[i] = scname();
        //printf("name of len %d\n", dep[i]);
        if (int j=sc())
        {
            ++dep[i];
            hd[i].reserve(j);
            while (j--) hd[i].pb(sc());
        }
    }
    dep[1] = 0;

    ll totw = kcnt(1, 0);
    dfs(1, 0);
    ll mn = 1e9;
    F(i, N) mn = min(mn, ans[i]);
    printf("%lld\n", totw + mn);
    //for (int i=1; i<=N; ++i) printf("%3d %lld\n", i, ans[i]);
}

