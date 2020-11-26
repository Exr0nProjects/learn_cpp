/*
 * Problem 2 (contests/standard-xjoi/1649/2)
 * Create time: Thu 26 Nov 2020 @ 13:37 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <set>
#include <unordered_map>
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
ll gcd(ll a, ll b) { while (b^=a^=b^=a%=b); return a; }

using namespace std;
const int MX = 12;
const int MXN = 2020;

unordered_map<ll, ll> dp;
inline ll chash(ll n, ll k, ll x) { return n << 38 | k << 34 | x; }
inline pair<pii, int> unhash(ll h) { return mp(mp(h>>38, h>>34 & 0xf), h&0x3ffffffff); }

inline ll add(ll x, int k, int v)
{
    --k;
    const ll n = x >> (k*3) & 7;
    const ll tot = x >> 30;
    const ll blanked = x & ~(7<<(k*3)) & ~(7<<30);
    return blanked | (tot+v << 30) | (n+v <<(k*3));
}
inline ll cnt(ll x) {
    return x >> 30;
}

set<int> q[MX];
int N, K, dest[MXN];

ll op(int n, int k, int x)
{
    printf("%d %d %d\n", n, k, x);
    if (dp.count(chash(n, k, x))) return dp[chash(n, k, x)];
    dp[chash(n, k, x)] = 1e18;
    if (!n && !k) return 0; // base case
    ll ans = 1e18;
    if (k > 1) ans = min(ans, op(n, k-1, x));               // came from left
    if (k < N) ans = min(ans, op(n, k+1, x));               // came from right
    if (cnt(x) && q[k].count(n))                            // picked up passenger
        ans = min(ans, op(n-1, k, add(x, dest[n], -1)));
    if (cnt(x) < 4) ans = min(ans, op(n, k, add(x, k, 1))); // dropped off pasenger
    dp[chash(n, k, x)] = ans + 1;
    return ans + 1;
}

int main()
{
    sc(N, K);
    for (int i=1; i<=N; ++i)
    {
        int a, b; sc(a, b);
        dest[i] = b;
        q[a].insert(i);
    }
    ll ans = 1e18;
    for (int e=1; e<=K; ++e)
        ans = min(ans, op(N, e, 0));
    printf("%lld\n", ans);
    //// bitmask test
    //ll x=0, k, v;
    //while (sc(k, v))
    //{
    //    ll g = add(x, k, v);
    //    for (int i=0; i<10; ++i)
    //    {
    //        printf("%d ", (g >> i*3) &7);
    //    }
    //    printf("tot %lld       %lld\n", (g>>30)&0xf, g);
    //    x = g;
    //}
    //// hash test
    //int n, k, x;
    //while (sc(n, k, x))
    //{
    //    auto cur = unhash(chash(n, k, x));
    //    printf("%d %d %d\n", cur.f.f, cur.f.s, cur.s);
    //}
}

