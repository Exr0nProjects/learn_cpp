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
//inline ll sc(bool &e)
//{
//    int neg = 1;
//    register ll n = 0;
//    register char c = getchar_unlocked();
//    while ((c <  '0' || c >  '9') && c != '-'
//            && c != '+' && c!=EOF)
//        c = getchar_unlocked();
//    if (c == '-') neg = -1, c = getchar_unlocked();
//    while ((c <  '0' || c >  '9') && c!=EOF)
//        c = getchar_unlocked();
//    while ( c >= '0' && c <= '9'  && c!=EOF)
//        (n *= 10) += (c-'0'), c = getchar_unlocked();
//    e = c != EOF;
//    return n * neg;
//}
//inline ll sc()
//{
//    int neg = 1;
//    register ll n = 0;
//    register char c = getchar_unlocked();
//    while ((c <  '0' || c >  '9') && c != '-' && c != '+')
//        c = getchar_unlocked();
//    if (c == '-') neg = -1, c = getchar_unlocked();
//    while ((c <  '0' || c >  '9'))
//        c = getchar_unlocked();
//    while ((c >= '0' && c <= '9'))
//        (n *= 10) += (c-'0'), c = getchar_unlocked();
//    return n * neg;
//}

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

//struct Edge { int f, t, n; } edges[-1]; int head[-1];

using namespace std;
const int MX = -1;

int main()
{
    int N=sc(), K=sc(), tot=0;
    //printf("%d %d\n", N, K);
    //while (N--) { int x; sc(x); if (!(x%K)) ++tot; }
    while (N--) if (!(sc()%K)) ++tot;
    printf("%d\n", tot);

    return 0;
}

