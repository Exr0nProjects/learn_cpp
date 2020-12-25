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
#define mt make_tuple
#define f first
#define s second
#define lb(x) ((x)&-(x))

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

int N, P;
int val[100010];
int d[MX], bit[MX<<1];
vector<pii> ay(1);
set<int> desk;
unordered_map<int, int> dk;

typedef tuple<ll, ll, bool, ll> Event; // x pos, ypos, {1: start, 0: end}, line id
priority_queue<Event, deque<Event>, greater<Event> > pq;

int bq(int x)
{
    int mx = 0;
    for (; x; x-=lb(x))
        mx = max(mx, bit[x]);
    return mx;
}
void bu(int x, int v)
{
    for (; x<=MX; x+=lb(x))
        bit[x] = max(bit[x], v);
}

int main()
{
    //freopen("boards.in", "r", stdin);
    freopen("boards.out", "w+", stdout);
    //sc(N, P);
    scanf("%d%d", &N, &P);

    for (int i=1; i<=P; ++i)
    {
        int x1, y1, x2, y2;
        //sc(x1, y1, x2, y2);
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        //if (x1 < 0 || y1 < 0 || x2 > N || y2 > N) // no data satisfies this
        //    { --P; --i; printf("WEWOWEWO\n"); continue; }
        d[i] = abs(x1-x2) + abs(y1-y2);
        //printf("d[%d] = %d\n", i, d[i]);
        ay.pb(mp(y1+1, y2+1));
        pq.push(mt(x1, y1, 1, i));  // FIX: sort events by x and y, not just x
        pq.push(mt(x2, y2, 0, i));
        desk.insert(y1+1), desk.insert(y2+1);
    }
    { int i=0; for (auto v : desk) dk[v] = ++i; }
    //i = 0;
    for (auto p : ay) p.f = dk[p.f], p.s = dk[p.s];

    while (!pq.empty())
    {
        ll x, y, i; bool t; tie(x, y, t, i) = pq.top(); pq.pop();
        //printf("event %d %d at %d\n", i, t, y, x);
        if (t)
        {
            val[i] = bq(dk[ay[i].f]) + d[i];   // FIX: use the dk array
            //printf("val %d = %d\n", cur.s.s, val[cur.s.s]);
        }
        else bu(dk[ay[i].s], val[i]);
    }
    for (int i=1; i<=P; ++i) val[i] = max(val[i], val[i-1]);
    printf("%d\n", N+N-val[P]);
}

