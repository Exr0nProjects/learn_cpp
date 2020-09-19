/*
 * Problem 2 (contests/standard-xjoi/1629/2)
 * Create time: Sat 19 Sep 2020 @ 09:44 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
#include <array>

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

using namespace std;
const int MX = -1;

map<array<ll, 5>, ll> cnt;
ll N, cur[10], pie[10];

int main()
{
    sc(N);
    F(i, N)
    {
        //F(i, 5) sc(cur[i-1]);
        for (ll i=0; i<5; ++i) sc(cur[i]);
        F(x, 31)
        {
            array<ll, 5> key{};
            for (ll i=4, p=4; ~i; --i)
            {
                //printf("    i %d x>>i %d\n", i, (x>>i)&1);
                if ((x>>i)&1) key[p--] = cur[i];
            }
            //printf("%2d:", x); for (int i=0; i<=4; ++i) printf("%3d", key[i]); printf("\n");
            ++cnt[key];
        }
    }

    ll popcnt = 0;
    for (auto p : cnt)
    {
        while (popcnt < 5 && p.f[4-popcnt]) ++popcnt;
        pie[popcnt] += p.s * (p.s-1) / 2;

        //for (int i=0; i<=4; ++i) printf("%3d", p.f[i]);
        //printf("  : %d          (%d)\n", p.s, popcnt);
    }
    //for (int i=1; i<=5; ++i) printf("%3d", pie[i]); printf("\n");

    ll tot = N*(N-1)/2 - pie[1] + pie[2] - pie[3] + pie[4] - pie[5];
    printf("%lld\n", tot);
}

