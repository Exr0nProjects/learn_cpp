/*
 * Problem intest (spoj/intest)
 * Create time: Sun 30 Aug 2020 @ 11:26 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <bits/stdc++.h>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb(x) ((x)-=(x)&-(x))

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
//struct Edge { int f, t, n; } edges[-1]; int head[-1];

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
_ilb sc(int &a) { ll x; bool b=sc(x); a=x; return b; }
_ilb sc(int &a, int &b) { return sc(a)&&sc(b); }
_ilb sc(int &a, int &b, int &c) { return sc(a, b)&&sc(c); }
_ilb sc(int&a,int&b,int&c,int&d){return sc(a,b)&&sc(c,d);}
_ilb sc(ll &a, ll &b) { return sc(a)&&sc(b); }
_ilb sc(ll &a, ll &b, int &c) { return sc(a, b)&&sc(c); }

using namespace std;
const int MX = 1e5+11;

int N, P, d[MX], bit[MX<<2][MX<<2];
vector<pair<pii, pii> > boards;
set<int> desk;
unordered_map<int, int> dk;

int bq(pii x)
{
    int mx = 0;
    for (; x.f; lb(x.f))
        for (int y=x.s; y; lb(y))
            mx = max(mx, bit[x.f][y]);
    return mx;
}

int main()
{
    sc(N, P);
    desk.insert(N);
    for (int i=0; i<P; ++i)
    {
        int x1, y1, x2, y2;
        sc(x1, y1, x2, y2);
        d[i] = abs(x1-x2) + abs(y1-y2);
        boards.pb(mp(mp(x1, y1), mp(x2, y2)));
        desk.insert(x1), desk.insert(x2),
        desk.insert(y1), desk.insert(y2);
    }
    int i=0; for (auto v : desk) dk[v] = ++i;
    //i = 0;
    for (auto p : boards)
        p.f.f = dk[p.f.f], p.f.s = dk[p.f.s],
        p.s.f = dk[p.s.f], p.s.s = dk[p.s.s];
        //printf("%d,%d -> %d,%d for %d\n", p.f.f, p.f.s, p.s.f, p.s.s, d[i++]);
    sort(boards.begin(), bords.end());
    int mx = 0;
    i = 0;
    for (auto p : boards)
    {
        int v = bq(p.f) + d[++i];
        mx = max(mx, v);
        bu(p.s, v);
    }
    printf("%d\n", N*N-mx);
}

