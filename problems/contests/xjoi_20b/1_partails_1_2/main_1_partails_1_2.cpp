/*
 * Problem 1_partails_1_2 (contests/xjoi_20b/1_partails_1_2)
 * Create time: Sat 28 Nov 2020 @ 20:11 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>


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

inline ll pow(ll b, ll e, ll m)
{
    ll ret=1;
    for (; e; e>>=1, (b*=b)%=m)
        if (e&1) (ret *= b)%=m;
    return ret;
}

void setIO(const std::string &name = "1_partails_1_2")
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

using namespace std;
const int MX = -1;

int T;

int main()
{
    sc(T);
    while (T--)
    {
        int k, a, b, x; sc(k, a, b, x);
        dl l = 0, r = x, v1 = a, v2 = -b;
        vector<dl> ans = {};
        map<dl, int> pos = {};
        int pad=0, cycle=0;
        bool yes = 0;
        for (int i=0; i<k; ++i)
        {
            //printf("\nl at %.5lf going %2.0lf         r at %.5lf going %2.0lf\n", l, v1, r, v2);
            if (v1 * v2 < 0)            // opposite directions
            {
                //printf("    going opposite directions: ");
                if (v1 > 0 && v2 < 0)   // towards eachother
                {
                    //printf("towards\n");
                    l = r = l+(r-l)/(v1-v2)*v1;
                    v1 *= -1, v2 *= -1;
                }
                else
                {
                    //printf("away\n");
                    --i;                // away, doesn't count as meeting
                    if (abs(l/v1 - (100-r)/v2) < 1e-6)  // hit at same time
                        //printf("                       hit at same time\n"),
                        l=0, r=100, v1*=-1, v2*=-1;
                    else if (l/v1 < (100-r)/v2)         // left hits first
                        //printf("                       left side hit first\n"),
                        r-=v2*l/v1, l=0, v1 *= -1;
                    else
                        //printf("                       right side hit first\n"),
                        l-=(100-r)/v2*v1, r=100, v2 *= -1;
                }
            }
            else
            {
                //printf("    going same     direction : ");
                if (v2 < 0)
                {
                    //printf("left\n");
                    if (r/v2 > l/v1)    // doesn't catch up in time
                        --i, r -= l/v1*v2, l = 0, v1*=-1;
                    else
                        l = r = l-(r-l)/(v1-v2)*v1, v2*=-1;
                }
                else
                {
                    //printf("right\n");
                    if ((100-r)/v2 < (100-l)/v1)    // doesn't catch up in time
                        --i, l += (100-r)/v2*v1, r = 100, v2*=-1;
                    else
                        l = r = l+(r-l)/(v1-v2)*v1, v1*=-1;
                }
            }
            if (l == r)
            {
                //printf("-> %lf %d\n", l, i);
                l = round(1e8*l)/1e8;
                if (!pos.count(l))
                {
                    //printf("pos %lf = %d\n", l, i),
                    ans.pb(l), pos[l] = i;
                }
                else
                {
                    pad = pos[l], cycle = i-pos[l];
                    yes = 1;
                    break;
                }
            }
        }
        //printf("pad %d cycle %d k-pad %d\n", pad, cycle, k-pad);
        if (cycle == 1) printf("%.5lf\n", l);
        else if (cycle || pad || yes) printf("%.5lf\n", ans[(k - pad) % cycle + pad-1]);
        else printf("%.5lf\n", l);
    }
}

