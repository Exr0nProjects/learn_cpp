/*
 * Problem cownav (usaco/gold/2017jan/cownav)
 * Create time: Sun 06 Dec 2020 @ 13:49 (PST)
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

void setIO(const std::string &name = "cownav")
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
const int MX = 32;

const int _x[] = { 0, 1, 0, -1 };
const int _y[] = { 1, 0, -1, 0 };

int N; char buf[MX][MX];
typedef tuple<int, int, int> Cow; // xpos, ypos, dir (0=up, 1=right, 2=down, 3=left)
typedef array<Cow, 2> State;
map<State, int> dist;

State move(State s, int cmd)  //    command: -1 = left, 0 = forward, 1 = right
{
    for (Cow& c : s)
    {
        un(x, y, d) = c;
        if (cmd) d = (d+4+cmd)%4, c = mt(x, y, d);
        else if (x != N || y != N)
        {
            x += _x[d]; y += _y[d];
            //printf("move to %d %d (where its '%c')\n", x, y, buf[N-y+1][x]);
            if (buf[N-y+1][x] == 'E') c = mt(x, y, d);
            //if (buf[N-y+1][x] == 'E') printf("    yayy it worked\n"), c = mt(x, y, d);
        }
    }
    //for (Cow c : s) { un(x, y, d) = c; printf("%d %d %d\n", x, y, d); }
    return s;
}
bool isEnd(State s)
{
    bool yes = 1;
    for (Cow &c : s)
    {   un(x, y, d) = c;
        yes &= (x == N && y == N);
    }
    return yes;
}

void print(State s)
{
    for (Cow c : s) { un(x, y, d) = c; printf("%d %d %d    ", x, y, d); }
    printf("\n");
}


int main()
{
    setIO();
    sc(N);
    //memset(buf, 'x', sizeof buf);
    F(i, N) scanf("%s", buf[i]+1);

    //F(i, N) F(j, N) printf("%d %d: '%c'\n", i, j, buf[N-j+1][i]);
    //
    //for (int i=0; i<=N+1; ++i) { for (int j=0; j<=N+1; ++j) printf("%2c", buf[i][j]); printf("\n"); }
    //
    //State s = { mt(1, 1, 2), mt(1, 1, 3) };
    //for (Cow c : s) { un(x, y, d) = c; printf("%d %d %d\n", x, y, d); }
    //s = move(s, 0);

    queue<State> q; q.push({ mt(1, 1, 0), mt(1, 1, 1) });
    int ans = 0;
    while (q.size())
    {
        State cur = q.front(); q.pop();
        //printf("at "); print(cur);
        if (isEnd(cur)) { printf("%d\n", dist[cur]); break; }
        for (int i=-1; i<=1; ++i)
        {
            State n = move(cur, i);
            if (!dist.count(n))
            {
                //printf("got "); print(n);
                dist[n] = dist[cur]+1;
                q.push(n);
            }
        }
    }
}

