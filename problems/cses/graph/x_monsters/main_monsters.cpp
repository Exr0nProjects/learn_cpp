/*
 * Problem monsters (cses/graph/monsters)
 * Create time: Sun 06 Dec 2020 @ 21:00 (PST)
 * Accept time: [!meta:end!]
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

void setIO(const std::string &name = "monsters")
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
//void addEdge(int u=0, int v=0, bool b=1)
//{
//    if (!u) sc(u, v);
//    eg[ecnt] = { v, hd[u] };
//    hd[u] = ecnt++;
//    if (b) addEdge(v, u, 0);
//}

using namespace std;
const int MX = 1e3+11;
const int _y[] = { 0, 1, 0, -1 };
const int _x[] = { 1, 0, -1, 0 };
const char _c[] = { 'R', 'D', 'L', 'U' };

int N, M;
int ax=-1, ay=-1, ans[MX*MX/2], acnt=0; // FIX: bounds--ans can be up to N^2 / 2 ish
char buf[MX][MX];
int near[MX][MX], pre[MX][MX];

//bool dfs(int y, int x, int dep=0)
//{
//     return 0;
//    printf("at %d, %d    after %d\n", y, x, dep);
//    if (y==1 || x==1 || y==N || x==M) return 1;
//    //printf("uh\n");
//    near[y][x] = -1;
//    for (int d=0; d<4; ++d)
//        if (dfs(y+_y[d], x+_x[d], dep+1))
//        { ans[acnt++] = _c[d]; return 1; }
//    return 0;
//}

bool bfs(int y, int x)
{
    queue<tuple<int, int, int> > q; q.push(mt(y, x, 1));
    while (q.size())
    {
        un(y, x, dep) = q.front(); q.pop();
        if (y==1 || x==1 || y==N || x==M) { ay=y, ax=x; return 1; }

        for (int d=0; d<4; ++d)
            if (buf[y+_y[d]][x+_x[d]] == '.' && near[y+_y[d]][x+_x[d]] > dep)
                near[y+_y[d]][x+_x[d]] = -1,
                pre [y+_y[d]][x+_x[d]] = d,
                q.push(mt(y+_y[d], x+_x[d], dep+1));
    }
    return 0;
}

int main()
{
    sc(N, M);
    //memset(buf, '*', sizeof buf);
    F(i, N) scanf("%s", buf[i]+1);

    queue<pii> q;
    memset(near, 0x3f, sizeof near);

    F(i, N) F(j, M) if (buf[i][j] == 'M')
        near[i][j] = 0, q.push(mp(i, j));
    while (q.size())
    {
        un(y, x) = q.front(); q.pop();
        for (int d=0; d<4; ++d) if (near[y+_y[d]][x+_x[d]] > 1e9 && // could be cleaner
                   (buf[y+_y[d]][x+_x[d]] == '.' || buf[y+_y[d]][x+_x[d]] == 'A'))
                near[y+_y[d]][x+_x[d]] = near[y][x] + 1,
                q.push(mp(y+_y[d], x+_x[d]));
    }
    //F(i, N) { F(j, M) if (near[i][j] >= 0) printf("%3d", near[i][j]); else printf("  ."); printf("\n"); }

    F(i, N) F(j, M) if (buf[i][j] == 'A')
    {   // how to make this block look good :/
        if (!bfs(i, j))
        {
            printf("NO\n");
            return 0;
        }
        break;
    }
    while (buf[ay][ax] != 'A')
    {
        int d = pre[ay][ax];
        //printf("at %d %d\n", ay, ax),
        ans[acnt++] = _c[d],
        ay-=_y[d], ax-=_x[d];
    }

    printf("YES\n%d\n", acnt);
    while (acnt--) printf("%c", ans[acnt]); printf("\n");
}

