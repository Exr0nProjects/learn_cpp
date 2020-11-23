/*
 * Problem 1 (contests/standard-xjoi/1634/1)
 * Create time: Mon 23 Nov 2020 @ 10:24 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <set>
#include <unordered_set>
#include <map>
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
//struct Edge { int u, v, n; } eg[MX]; int hd[MX], ecnt=0;

inline ll pow(ll b, ll e, ll m)
{
    ll ret=1;
    for (; e; e>>=1, (b*=b)%=m)
        if (e&1) (ret *= b)%=m;
    return ret;
}

void setIO(const std::string &name = "1")
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
const int MX = 2e5+11;

multimap<ll, ll, greater<ll> > hd[2]; // [side] < tastiness, eid >
ll N, D, ans[MX], taste[2][MX], loc_ans[2][MX];

unordered_set<ll> vis;

int main()
{
    sc(N, D);
    for (int s=0; s<2; ++s)
        for (int i=1; i<=N; ++i)
        {
            int inp[2]; sc(inp[0], inp[1]);
            hd[!s].insert(mp(inp[!s], N*s+i));
            for (int k=2; k--;)
                taste[k][N*s+i] = inp[k];
        }

    //for (int s=0; s<2; ++s)
    //{
    //    printf("==========================\nside %d\n", s);
    //    for (auto p : hd[s]) printf("%3d -> { %3d .. %3d }\n", p.f, taste[0][p.s], taste[1][p.s]);
    //}
    //printf("==========================\n");

    memset(ans, 0x3f, sizeof ans);

    queue<pair<ll, ll> > q;   // < tastiness, side >
    q.push(mp(0, 0)); q.push(mp(0, 1));
    while (!q.empty())
    {
        pair<ll, ll> cur = q.front(); q.pop();
        //printf("%d:%03d\n", cur.s, cur.f);
        if (vis.count(cur.s*N+cur.f)) continue;
        vis.insert(cur.s*N+cur.f);

        for (auto it = hd[cur.s].lower_bound(cur.f);
                it != hd[cur.s].end() && it->f >= cur.f - D; ++it)
        {
            loc_ans[!cur.s][taste[!cur.s][it->s]] = // remember the depth on the other side
                ans[it->s] = min(ans[it->s], loc_ans[cur.s][cur.f]+1);
            q.push(mp(taste[!cur.s][it->s], !cur.s));
            //printf("   -> %d:%03d with %3d\n", !cur.s, taste[!cur.s][it->s], ans[it->s]);
        }
    }
    for (int i=1; i<=N; ++i)
        printf("%d\n", ans[i] > 1e9 ? -1 : ans[i]);
}

