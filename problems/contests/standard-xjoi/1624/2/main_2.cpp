/*
 * Problem 2 (contests/standard-xjoi/1624/2)
 * Create time: Thu 17 Sep 2020 @ 00:06 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

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
const int MX = 1e5+11;

int N, a[MX], t[MX], b[MX], scnt=0;

int main()
{
    sc(N);
    for (int i=1; i<=N; ++i) sc(a[i]);

    for (int i=1; i<=N; ++i)
    {
        int g = lower_bound(t, t+scnt, a[i]) - t;
        //printf("bins %d got %d\n", a[i], g);
        if (g && b[g-1] > a[i])
            printf("%d\n", i), i+=N;
        t[g] = a[i];
        if (!b[g]) b[g] = a[i], ++scnt;
    }
}

