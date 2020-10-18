/*
 * Problem 3 (contests/standard-xjoi/1731/3)
 * Create time: Sun 18 Oct 2020 @ 15:26 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

#define ll long long
#define dl double

#define gpq(T) priority_queue<T, deque<T>, greater<T> >
#define CMA , // https://stackoverflow.com/q/13842468/10372825
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb(x) ((x)&-(x))

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)
//struct Edge { int u, v, n; } eg[MX]; int hd[MX], ecnt=0;

void setIO(const std::string &name = "3")
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
#define gcd(_a, _b) ({auto a=_a;auto\
    b=_b;while(b)(a)%=(b),(a)^=(b)^=(a)^=(b);a;})

using namespace std;
const int MX = 1e6+11;

int P, S, pi[MX];
char p[MX], s[MX];

void kpi()
{
    pi[0] = -1;
    for (int i=1; i<P; ++i)
    {
        for (pi[i] = pi[i-1]; ~pi[i] && p[pi[i]+1] != p[i];
                pi[i] = pi[pi[i]]);
        //printf("pi[%d] = %d\n", i, pi[i]);
        pi[i] += p[pi[i]+1] == p[i];
    }
}

int match(int i=0)
{
    int k=-1;
    for (; i<S; ++i)
    {
        //printf("i   = %d\n", i);
        for (; ~k && p[k+1] != s[i]; k=pi[k]);
        //printf("  i = %d k = %d\n", i, k);
        if (p[k+1] == s[i]) ++k;
        if (k == P-1) break;
    }
    //printf("i = %D\n", i);
    return i;
}

int main()
{
    scanf("%s%s", s, p);
    //scanf("%s", p);
    P = strlen(p);

    S = strlen(s);
    kpi();

    //for (int i=0; i<P; ++i) printf("%3d", pi[i]); printf("\n");

    printf("%d\n", match(0)-P+2);
}

