/*
 * Problem [!meta:pid!] ([!meta:srcpath!])
 * Create time: [!meta:beg!]
 * Accept time: [!meta:end!]
 *
 */

#define nt int
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

#define dl double

#define gpq(...) priority_queue<__VA_ARGS__, deque<__VA_ARGS__>, greater<__VA_ARGS__> >
#define pb push_back
#define pii pair<nt, nt>
#define mp make_pair
#define f first
#define s second
#define mt make_tuple
#define un(...) nt __VA_ARGS__; tie(__VA_ARGS__)
#define lb(x) ((x)&-(x))

#define F(i,b) for (nt i=1; i<=(b); ++i)
#define R(i,b) for (nt i=(b); i>=1; --i)
#define N(e,c) for (nt e=hd[c]; e; e=eg[e].n)
#define TN(e,c,p) N(e,c) if (eg[e].t != p)

inline nt pow(nt b, nt e, nt m)
{
    nt ret=1;
    for (; e; e>>=1, (b*=b)%=m)
        if (e&1) (ret *= b)%=m;
    return ret;
}

void setIO(const std::string &name = "[!meta:pid!]")
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen((name + ".in").c_str(), "r") != 0)
        freopen((name + ".in").c_str(), "r", stdin),
        freopen((name + ".out").c_str(), "w+", stdout);
}
#define _gc getchar_unlocked
inline bool sc(nt &n)
{
    nt neg = 1;
    register char c;
    do c = _gc(); while (isspace(c));
    if (c == '-') neg = -1, c = _gc();
    for (n=0; c >= '0' && c <= '9'; c=_gc())
        (n *= 10) += (c-'0');
    n *= neg;
    return c != EOF;
}
inline nt sc() { nt x; sc(x); return x; }
#define _ilb inline bool
_ilb sc(nt&a,nt&b){return sc(a)&&sc(b);}
_ilb sc(nt&a,nt&b,nt&c){return sc(a,b)&&sc(c);}
_ilb sc(nt&a,nt&b,nt&c,nt&d){return sc(a,b)&&sc(c,d);}
nt gcd(nt a, nt b) { while (b^=a^=b^=a%=b); return a; }

using namespace std;
const nt MX = -1;

//struct Edge { nt t, n; } eg[MX*MX]; nt hd[MX], ecnt=2;
//void addEdge(nt u=0, nt v=0, bool b=1)
//{
//    if (!u) sc(u, v);
//    eg[ecnt] = { v, hd[u] };
//    hd[u] = ecnt++;
//    if (b) addEdge(v, u, 0);
//}

int main()
{
    setIO();

}

