/*
 * Problem time (usaco/gold/2020jan/time)
 * Create time: Sat 05 Dec 2020 @ 13:58 (PST)
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
#define N(e,c) for (int e=hd[c]; e; e=eg[e].n)
#define TN(e,c,p) N(e,c) if (eg[e].t != p)

inline ll pow(ll b, ll e, ll m)
{
    ll ret=1;
    for (; e; e>>=1, (b*=b)%=m)
        if (e&1) (ret *= b)%=m;
    return ret;
}

void setIO(const std::string &name = "time")
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

using namespace std;
const int MX = 1e3+11;
//const int MX = 10+11;

struct Edge { int f, t, n; } eg[MX<<2]; int hd[MX], ecnt=2;
void addEdge()
{
    // insert edges backwards
    int u = sc(); int v = sc();
    eg[ecnt] = { v, u, hd[v] };
    hd[v] = ecnt++;
}

ll N, M, C, m[MX];
ll dp[MX][MX], ans=0;  // day, city

int main()
{
    setIO();
    sc(N, M, C);

    for (int i=1; i<=N; ++i) sc(m[i]);
    for (int i=1; i<=M; ++i) addEdge();

    //F(i, MX) F(c, N) N(e, c)
    memset(dp, -1, sizeof dp);
    dp[0][1] = 0; // FIX: basecase-- only start at city 1

    for (int i=1; i<MX; ++i)
    {
        for (int e=2; e<ecnt; ++e)
        {
            if (dp[i-1][eg[e].t] >= 0)
                dp[i][eg[e].f] = max(dp[i][eg[e].f], dp[i-1][eg[e].t] + m[eg[e].f]);    // FIX: typo-- take from dp[i-1] not dp[i]
        }
        ans = max(ans, dp[i][1] - C*i*i);
        //printf("%d - %d = %d\n", dp[i][1], C*i*i, dp[i][1] - C*i*i);
    }
        //for (int c=1; c<=N; ++c)
        //{
        //    //printf("c = %d, hd[c] = %d\n", c, hd[c]);
        //    for (int e=hd[c]; e; e=eg[e].n) if (dp[i-1][eg[e].t] >= 0)
        //    {
        //        //printf("at %d on %d going %d\n", c, i, eg[e].t);
        //        dp[i][c] = max(dp[i][c], dp[i-1][eg[e].t] + m[c]);
        //    }
        //    //printf("at %d on %d got %d\n", c, i, dp[i][c]);
        //    if (c == 1)
        //    {
        //        //if (C*i*i < dp[i][c]) printf("%d - %d = %d\n", dp[i][c], C*i*i, dp[i][c] - C*i*i);
        //        printf("%d\n", dp[i][c] - C*i*i);
        //        ans = max(ans, dp[i][c] - C*i*i);
        //    }
        //}
    printf("%d\n", ans);
}

