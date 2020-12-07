/*
 * Problem labyrinth (cses/graph/labyrinth)
 * Create time: Sun 06 Dec 2020 @ 15:50 (PST)
 * Accept time: Sun 06 Dec 2020 @ 16:25 (PST)
 *
 */

#include <set>
#include <map>
#include <tuple>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

#define ll long long
#define dl double

#define gpq(...) priority_queue<__VA_ARGS__, deque<__VA_ARGS__>, greater<__VA_ARGS__> >
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mt make_tuple
#define un(...) ll __VA_ARGS__; tie(__VA_ARGS__)
#define lb(x) ((x)&-(x))

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
#define N(e,c) for (int e=hd[c]; e; e=eg[e].n)
#define TN(e,c,p) N(e,c) if (eg[e].t != p)

inline ll pow(ll b, ll e, ll m)
{
    ll ret=1;
    for (; e; e>>=1, (b*=b)%=m)
        if (e&1) (ret *= b)%=m;
    return ret;
}

void setIO(const std::string &name = "labyrinth")
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

//struct Edge { int t, n; } eg[MX*MX]; int hd[MX], ecnt=2;
using namespace std;
const int MX = 1e3+11;
int N, M;

int _y[] = { 0, 1, 0, -1 };
int _x[] = { 1, 0, -1, 0 };
char _c[] = { 'R', 'D', 'L', 'U' };

int dir[MX][MX];
char buf[MX][MX], path[MX*MX];

int ey=-1, ex=-1;

void bfs(int y, int x, int d=-2)
{
    queue<tuple<int, int, int> > q;
    buf[y][x] = '.'; // FIX: replace starting position w/ blank
    q.push(mt(y, x, d));
    while (q.size())
    {
        un(y, x, d) = q.front(); q.pop();
        //printf("at %d, %d    %d\n", y, x, d);

        if (buf[y][x] == 'B') { dir[y][x] = d, ey = y, ex = x; break; }
        if (buf[y][x] != '.' || ~dir[y][x]) continue;
        dir[y][x] = d;
        for (int d=0; d<4; ++d)
            q.push(mt(y+_y[d], x+_x[d], d));
    }
}

int main()
{
    sc(N, M);
    memset(dir, -1, sizeof dir);
    memset(buf, '#', sizeof buf);
    F(i, N) scanf("%s", buf[i]+1);

    F(i, N) F(j, M)
        if (buf[i][j] == 'A')
        { bfs(i, j); break; }

    if (ey < 0) { printf("NO\n"); return 0; }
    //printf("yes, apparently\n");
    //F(i, N) { F(j, M) printf("%3d", dir[i][j]); printf("\n"); }

    // reconstruct
    int cnt=0; while (dir[ey][ex] >= 0)
    {
        int d = dir[ey][ex];
        //printf("at %d, %d     %d\n", ey, ex, dir[ey][ex]);
        path[++cnt] = _c[d];
        ey -= _y[d], ex -= _x[d];   // FIX: don't modify vars while reading them
        //printf("                      -> %d +%d +%d -> %d %d\n", dir[ey][ex], _y[dir[ey][ex]], _x[dir[ey][ex]], ey, ex);
    }

    printf("YES\n%d\n", cnt);
    do printf("%c", path[cnt]); while (--cnt); printf("\n");
}

