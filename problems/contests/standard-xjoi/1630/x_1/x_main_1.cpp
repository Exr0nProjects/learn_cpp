/*
 * Problem 1 (contests/standard-xjoi/1630/1)
 * Create time: Wed 23 Sep 2020 @ 19:19 (PDT)
 * Accept time: Sun 27 Sep 2020 @ 13:02 (PDT)
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
const int MX = 1e5+1;

int N, bit[MX];
//map<int, int> dsc;
pair<int, int> srt[MX];

void bu(int x)
{
    for (; x<=N; x+=lb(x))
        ++bit[x];
}
int bq(int x)
{
    int ret=0;
    for (; x; x-=lb(x))
        ret += bit[x];
    return ret;
}

int main()
{
    //sc(N); F(i, N) ++dsc[a[i] = sc()];
    //int i=1; for (auto &n : dsc) n.s = i, i+=n.s;
    //F(i, N) a[i] = dsc[a[i]];
    ////F(i, N) printf("%3d", a[i]); printf("\n");

    sc(N); F(i, N) srt[i] = mp(sc(), i);
    sort(srt+1, srt+N+1);

    int ans=1;  // FIX: ans=1 cuz its always atleast one iter
    F(i, N)
    {
        bu(srt[i].s);
        ans = max(ans, (int)i-bq(i));
    }
    printf("%d\n", ans);
}

