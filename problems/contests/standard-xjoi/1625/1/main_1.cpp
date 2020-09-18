/*
 * Problem 1 (contests/standard-xjoi/1625/1)
 * Create time: Fri 18 Sep 2020 @ 12:50 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <set>

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

using namespace std;
const int MX = 5e3+11;
const int MOD = 1e9+7;

int N, M, K, lcnt[30];
//int kp[MX][MX];
//int kp[MX] = {1, 0, 0, 2, 1, 0, 4, 4, 1, 8, 12};
int kp[MX][MX];
int linepsb[MX];
//list<int> words[MX];
//int words[MX][MX]; // # of words of rhyme i and len j
multiset<int> lens;
multiset<int> words[MX]; // length of words with rhyme i

ll temp_exp[40];
int mexp(int b, int p, int m)
{
    // log N modular exponentiation
    if (!b) return 0;
    temp_exp[0] = b;
    for (int x=1; 1<<x<=p; ++x)
        temp_exp[x] = temp_exp[x-1]*temp_exp[x-1]%m;
        //printf("temp_exp[%d] = %d\n", x, temp_exp[x]);
    ll tot = 1;
    for (int x=0; x<32; ++x) if (p>>x&1)
        tot = tot * temp_exp[x] % m;
    //printf("%d ** %d %% %d = %lld\n", b, p, m, tot);
    return tot;
}

int main()
{
    //setIO();
    sc(N, M, K);
    for (int i=1; i<=N; ++i)
    {
        int s, c; sc(s, c);
        //words[c].pb(s);
        lens.insert(s);
        words[c].insert(s);
    }
    for (int i=1; i<=M; ++i)
    {
        char a; scanf("%c%*c", &a);
        //printf("'%c'\n", a);
        ++lcnt[a-'A'+1];
    }
    //for (int i=1; i<=30; ++i) printf("%d\n", lcnt[i]);

    // unbounded knapsack over all words
    //kp[0] = 1;
    //for (int l : lens)
    //    for (int j=l; j<=K; ++j)
    //        kp[j] += kp[j-l];

    //memset(kp, 0, sizeof kp);
    kp[0][0] = 1;
    for (int i=1; i<=N; ++i)
    {
        for (int l : lens)
            for (int j=l; j<=K; ++j)
                //printf("%d * %d\n", i, kp[i-1][j-l]),
                (kp[i][j] += (i)*kp[i-1][j-l]) %= MOD;
    }
    int d = 0;
    for (int j=0; j<=K; ++j)
    {
        for (int i=N; ~i; --i)
            (kp[i][j] += kp[i+1][j]) %= MOD;
        kp[0][j] >>= d;
        if (j > 3 && !(j-(j&-j))) ++d; // increment d at powers of two
    }


    //// unbounded knapsack for each rhyme class
    //for (int c=1; c<=N; ++c)
    //{
    //    kp[c][0] = 1;
    //    for (int w : words[c])
    //        for (int j=w; j<=N; ++j)
    //            kp[c][j] += kp[c][j-w];
    //}

    //for (int i=0; i<=K; ++i) printf("%3d ", i); printf("\n"); for (int j=0; j<=K; ++j) printf("%3d ", kp[0][j]); printf("\n");
    // calculate possible lines for each rhyme class
    for (int c=1; c<=N; ++c)
        for (int l : words[c])
            //printf("%d -> %d\n", K-l, kp[K-l]),
            linepsb[c] += kp[0][K-l];

    //for (int c=1; c<=N; ++c) printf("class %d has %d posib\n", c, linepsb[c]);

    ll total = 1;
    for (int i=1; i<=26; ++i) if (lcnt[i])  // FIX: condition--skip if letter doesn't exist
    {
        int tot = 0;
        for (int c=1; c<=N; ++c)
            tot = (tot + mexp(linepsb[c], lcnt[i], MOD)) % MOD;
        //printf("total = %d\n", total);
        total = total * tot % MOD;
    }
    printf("%lld\n", total % MOD);
}

