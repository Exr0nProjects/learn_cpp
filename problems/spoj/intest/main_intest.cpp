/*
 * Problem intest (spoj/intest)
 * Create time: Sun 30 Aug 2020 @ 11:26 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define F(i,b) for (ll i=1; i<=(b); ++i)
#define R(i,b) for (ll i=(b); i>=1; --i)

inline ll sc()
{
    int neg = 1;
    register ll n = 0;
    register char c;
    do c = getchar();
    while ((c < '0' || c > '9') && c != '-' && c != '+');
    if (c == '-') neg = -1, c = getchar();
    while (c >= '0' && c <= '9')
        (n *= 10) += (c-'0'), c = getchar();
    return n * neg;
}

inline bool sc(ll &n)
{
    int neg = 1;
    n = 0;
    register char c;
    do c = getchar(); while (isspace(c));
    if (c == '-') neg = -1, c = getchar();
    while (c >= '0' && c <= '9')
        (n *= 10) += (c-'0'), c = getchar();
    n *= neg;
    return c != EOF;
}
#define _ilb inline bool
_ilb sc(int &a) { ll x; bool b=sc(x); a=x; return b; }
_ilb sc(int &a, int &b) { return sc(a)&&sc(b); }
_ilb sc(int &a, int &b, int &c) { return sc(a, b)&&sc(c); }
_ilb sc(ll &a, ll &b) { return sc(a)&&sc(b); }
_ilb sc(ll &a, ll &b, int &c) { return sc(a, b)&&sc(c); }

//struct Edge { int f, t, n; } edges[-1]; int head[-1];

using namespace std;
const int MX = -1;

int main()
{
    //int N=sc(), K=sc(), tot=0;
    int N, K, tot = 0; sc(N); sc(K);
    //printf("%d %d\n", N, K);
    while (N--) { int x; sc(x); if (!(x%K)) ++tot; }
    //while (N--) if (!(sc()%K)) ++tot;
    printf("%d\n", tot);

    return 0;
}

