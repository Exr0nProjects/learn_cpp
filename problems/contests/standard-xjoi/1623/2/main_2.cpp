/*
 * Problem 2 (contests/standard-xjoi/1623/2)
 * Create time: Sun 06 Sep 2020 @ 10:36 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

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
#define _ilb inline bool
_ilb sc(int&a){ll x;bool b=sc(x);a=x;return b;}
_ilb sc(int&a,int&b){return sc(a)&&sc(b);}
_ilb sc(int&a,int&b,int&c){return sc(a,b)&&sc(c);}
_ilb sc(int&a,int&b,int&c,int&d){return sc(a,b)&&sc(c,d);}
_ilb sc(ll&a,ll&b){return sc(a)&&sc(b);}
_ilb sc(ll&a,ll&b,ll&c){return sc(a,b)&&sc(c);}
_ilb sc(ll&a,ll&b,ll&c,ll&d){return sc(a,b)&&sc(c,d);}

using namespace std;
const int MX = 7501;

int N, K;

struct Pair
{
    int first, second, v;
    Pair() {}
    void operator()(int a, int b) {
        first = a, second = b;
        v = max( (ll)2019201913*a + (ll)2019201949*b,
                 (ll)2019201913*b + (ll)2019201949*a) % 2019201997;
    }
    bool operator<(const Pair &o) const
    { return v < o.v; }
};

Pair srt[MX*MX/2];

int djf[MX], djs[MX];
int find(int n)
{
    if (djf[n] != n) djf[n] = find(djf[n]);
    return djf[n];
}
bool merge(Pair p)
{
    p.f = find(p.f);
    p.s = find(p.s);
    if (p.f == p.s) return 0;
    if (djs[p.f] < djs[p.s]) swap(p.f, p.s);
    djs[p.f] += djs[p.f];
    djf[p.s] = p.f;
    return 1;
}

int main()
{
    sc(N, K);

    int cnt=0; F(i, N) F(j, i-1) srt[cnt++](i, j);
    sort(srt, srt+cnt);

    F(i, N) djf[i] = i, djs[i] = 1;
    int groups = N;
    for (int i=0; i<cnt; ++i)
    {
        groups -= merge(srt[i]);
        if (groups < K) { printf("%d\n", srt[i].v); return 0; }
    }

}

