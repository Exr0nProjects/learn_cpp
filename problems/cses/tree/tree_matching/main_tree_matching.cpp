/*
 * Problem tree_matching (cses/tree/tree_matching)
 * Create time: Thu 03 Dec 2020 @ 18:54 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <set>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iostream>

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

//void setIO(const std::string &name = "tree_matching")
//{
//    //ios_base::sync_with_stdio(0); cin.tie(0);
//    if (fopen((name + ".in").c_str(), "r") != 0)
//        freopen((name + ".in").c_str(), "r", stdin),
//        freopen((name + ".out").c_str(), "w+", stdout);
//}
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
const int MX = 2e3+11;

int N, sum0[MX], sum1[MX], gans=0;
struct Edge { int t, n; } eg[MX<<1]; int hd[MX], ecnt=2;
void addEdge(int u, int v, int b=1)
{
    eg[ecnt] = { v, hd[u] };
    hd[u] = ecnt++;
    if (b) addEdge(v, u, 0);
}

int kans(int c, bool take=0, int p=1)
{
    //printf("at %d from %d with %d\n", c, p, take);
    if (c > 1 && !eg[hd[c]].n) return take;

    if (take)
    {
        int sum = 0;
        for (int e=hd[c]; e; e=eg[e].n) if (eg[e].t != p)   // FIX: eg[e].t not e needs to not be p
        {
            sum1[eg[e].t] = kans(eg[e].t, 1, c);
            sum += sum0[eg[e].t] = kans(eg[e].t, 0, c);
        }
        return sum+1;
    }
    //
    //    return sum;
    //if (take) for (int e=hd[c]; e; e=eg[e].n) if (eg[e].t != p)
    //
    //{
    //    printf("    at %d <- %d could go to %d\n", c, p, eg[e].t);
    //    sum += delt[eg[e].t];
    //    if (!take) delt[eg[e].t] -= kans(eg[e].t, 1, c);
    //}
    //if (take) return sum;
    int ret = 0;
    for (int e=hd[c]; e; e=eg[e].n) if (eg[e].t != p)
        ret = max(ret, sum0[c] - sum0[eg[e].t] + sum1[eg[e].t]);
    return ret;
}

int main()
{
    sc(N);
    F(i, N-1) addEdge(sc(), sc());
    printf("%d\n", max(kans(1, 0), kans(1, 1)-1));  // FIX: have to do both bc else not populated correctly
}

