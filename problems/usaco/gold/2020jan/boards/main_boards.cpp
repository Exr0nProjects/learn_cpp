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
vector<pii> y(1);
set<int> desk;
unordered_map<int, int> dk;

typedef pair<pii, pair<bool, int> > Event; // x pos, ypos, {0: start, 1: end}, line id
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
        if (x1 < 0 || y1 < 0 || x2 > N || y2 > N)
            { --P; continue; }
        d[i] = abs(x1-x2) + abs(y1-y2);
        //printf("d[%d] = %d\n", i, d[i]);
        y.pb(mp(y1+1, y2+1));
        pq.push(mp(mp(x1, y1), mp(0, i)));  // FIX: sort events by x and y, not just x
        pq.push(mp(mp(x2, y2), mp(1, i)));
        desk.insert(y1+1), desk.insert(y2+1);
    }
    { int i=0; for (auto v : desk) dk[v] = ++i; }
    //i = 0;
    for (auto p : y) p.f = dk[p.f], p.s = dk[p.s];

    while (!pq.empty())
    {
        Event cur = pq.top(); pq.pop();
        //printf("event %d %d at %d\n", cur.s.f, cur.s.s, cur.f);
        if (cur.s.f)
        {
            bu(dk[y[cur.s.s].s], val[cur.s.s]);
        }
        else
        {
            val[cur.s.s] = bq(dk[y[cur.s.s].f]) + d[cur.s.s];   // FIX: use the dk array
            //printf("val %d = %d\n", cur.s.s, val[cur.s.s]);
        }
    }
    for (int i=1; i<=P; ++i) val[i] = max(val[i], val[i-1]);
    printf("%d\n", N+N-val[P]);
}

