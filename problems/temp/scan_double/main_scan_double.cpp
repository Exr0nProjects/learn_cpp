#include <iostream>

//#define ll long long
//#define dl double
//
//#define pii pair<int, int>
//#define pb push_back
//#define mp make_pair
//#define f first
//#define s second
//#define lb(x) ((x)&-(x))
//
//#define F(i,b) for (ll i=1; i<=(b); ++i)
//#define R(i,b) for (ll i=(b); i>=1; --i)
////struct Edge { int u, v, n; } edges[MX]; int head[MX], ecnt=0;
//
//void setIO(const std::string &name = "scan_double")
//{
//    //ios_base::sync_with_stdio(0); cin.tie(0);
//    if (fopen((name + ".in").c_str(), "r") != 0)
//        freopen((name + ".in").c_str(), "r", stdin),
//        freopen((name + ".out").c_str(), "w+", stdout);
//}
//#define _gc getchar_unlocked
//inline bool sc(ll &n)
//{
//    int neg = 1;
//    register char c;
//    do c = _gc(); while (isspace(c));
//    if (c == '-') neg = -1, c = _gc();
//    for (n=0; isdigit(c); c=_gc())
//        (n *= 10) += (c-'0');
//    n *= neg;
//    return c != EOF;
//}
inline bool sc(dl &n)
{
    int neg = 1;
    register char c;
    do c = _gc(); while (isspace(c));
    if (c == '-') neg = -1, c = _gc();
    for (n=0; isdigit(c); c=_gc())
        (n *= 10) += (c-'0');
    if (c != '.') return n*=neg, c != EOF;
    dl p = 1; c = _gc();
    for (; isdigit(c); c=_gc())
        n += (p /= 10) * (c-'0');
    n *= neg;
    return c != EOF;
}
//inline ll sc() { ll x; sc(x); return x; }
//#define _ilb inline bool
//_ilb sc(int&a){ll x;bool b=sc(x);a=x;return b;}
//_ilb sc(int&a,int&b){return sc(a)&&sc(b);}
//_ilb sc(int&a,int&b,int&c){return sc(a,b)&&sc(c);}
//_ilb sc(int&a,int&b,int&c,int&d){return sc(a,b)&&sc(c,d);}
//_ilb sc(ll&a,ll&b){return sc(a)&&sc(b);}
//_ilb sc(ll&a,ll&b,ll&c){return sc(a,b)&&sc(c);}
//_ilb sc(ll&a,ll&b,ll&c,ll&d){return sc(a,b)&&sc(c,d);}
//_ilb sc(dl&a,dl&b){return sc(a)&&sc(b);}
//_ilb sc(dl&a,dl&b,dl&c){return sc(a,b)&&sc(c);}
//_ilb sc(dl&a,dl&b,dl&c,dl&d){return sc(a,b)&&sc(c,d);}

using namespace std;
const int MX = -1;

inline float scan(char **p)
{
    float n; int neg=1;
    while (!isdigit(**p) && **p != '-' && **p != '.') ++*p;
    if (**p == '-') neg = -1, ++*p;
    for (n=0; isdigit(**p); ++*p)
        (n *= 10) += (**p-'0');
    if (*(*p)++ != '.') return n*neg;
    for (float d=1; isdigit(**p); ++*p)
        n += (d /= 10) * (**p-'0');
    return n*neg;
}

int main()
{
    char *buf = new char[100];
    gets(buf);
    printf("'%s'\n", buf);

    for (int i=0; i<1; ++i)
        printf("%lf\n", scan(&buf));
}

