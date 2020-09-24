/*
 * Problem 1 (contests/standard-xjoi/1630/1)
 * Create time: Wed 23 Sep 2020 @ 19:19 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>

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
//struct Edge { int u, v, n; } edges[MX]; int head[MX], ecnt=0;

void setIO(const std::string &name = "1")
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
const int MX = 1e5+1;

int N, a[MX], bit[MX];
map<int, int> dsc;
pair<int, int> c[MX];

void bu(int x, int v)
{
    for (; x<=N; x+=lb(x))
        bit[x] += v;
}
int bq(int x)
{
    int ret=0;
    //printf("bq(%d) ", x);
    for (; x; x-=lb(x))
        ret += bit[x];
    //printf("=> %d\n", ret);
    return ret;
}

int main()
{
    sc(N); F(i, N) sc(a[i]);
    //F(i, N) dsc[a[i]];
    //int i=1; for (auto &p : dsc) p.s = i++;
    //F(i, N) a[i] = dsc[a[i]];

    //F(i, N) printf("%3d", a[i]); printf("\n");
    //int ans=0;
    //for (int i=N; i; --i)   // FIX: inversions back to front
    //{
    //    //F(i, N) printf("%3d", bit[i]); printf("\n");
    //    if (bq(a[i]-1) > 1) ++ans;
    //    bu(a[i]);
    //}
    //printf("%d\n", ans);

    //for (int i=N; i; --i)
    //{
    //    bu(a[i], 1);   // normally after but no colision
    //    a[i] = bq(a[i]-1);
    //}
    //
    //
    //int ans=0, cnt;
    //do {
    //    ++ans;
    //    //printf("a: "); F(i, N) printf("%3d", a[i]); printf("\n");
    //    cnt = 0;
    //    for (int i=N; i; --i)
    //    {
    //        int g = lower_bound(c, c+cnt, mp(a[i], 0)) - c;
    //        //printf("    a[%d] = %d -> %d\n", i, a[i], g);
    //        if (g == cnt) c[cnt++] = mp(a[i], i);
    //        else c[g] = min(c[g], mp(a[i], i));
    //    }
    //    for (int i=0; i<cnt; ++i)
    //    {
    //        //printf("a[c[%d]] = a[%d] = %d\n", i, c[i].s, a[c[i].s]);
    //        if (a[c[i].s]) --a[c[i].s];
    //        c[i] = mp(0, 0);
    //    }
    //    //printf("b: "); F(i, N) printf("%3d", a[i]); printf("\n");
    //    for (int i=0; i<=N; ++i)
    //    {
    //        int g = lower_bound(c, c+cnt, mp(a[i], 0)) - c;
    //        //printf("    a[%d] = %d -> %d\n", i, a[i], g);
    //        if (g == cnt) c[cnt++] = mp(a[i], i);
    //        else c[g] = min(c[g], mp(a[i], i));
    //    }
    //    for (int i=0; i<cnt; ++i)
    //    {
    //        //printf("a[c[%d]] = a[%d] = %d\n", i, c[i].s, a[c[i].s]);
    //        if (a[c[i].s]) --a[c[i].s];
    //        c[i] = mp(0, 0);
    //    }
    //    //printf("c: "); F(i, N) printf("%3d", a[i]); printf("\n");
    //    bool flag = 0;
    //    F(i, N) if (a[i]) flag=1;
    //    if (!flag) break;
    //} while (true);
    //printf("%d\n", ans);


    int ans=0, cnt;
    do {
        ++ans;
        //printf("a: "); F(i, N) printf("%3d", a[i]); printf("\n");
        for (int i=1; i<N; ++i)
            if (a[i] > a[i+1]) swap(a[i], a[i+1]);
        for (int i=N-1; i; --i)
            if (a[i] > a[i+1]) swap(a[i], a[i+1]);
        bool flag = 0;
        F(i, N-1) if (a[i] > a[i+1]) flag=1;
        if (!flag) break;
    } while (true);
    printf("%d\n", ans);
}

