/*
 * Problem 13 (contests/xcup_coding/2020-11-07/13)
 * Create time: Sat 07 Nov 2020 @ 15:06 (PST)
 * Accept time: [!meta:end!]
 *  xcup hard 3
 */
#include <set>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

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
//
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
const int MXN = 2e4+10;
const int MXM = 5e4+10;
const int MXL = 1e5+11;
const int delta[] = {-1, 0, 1};

vector<int> hd[MXL];

int N, M;

map<int, int> trie[MXL];
int fail[MXL], wcnt[MXL], roll[MXN], /*isw[MXL],*/ viscnt[MXL], lcnt=1;
int nameans[MXN];
bool failvis[MXN], isw[MXL];

pair<vector<int>, vector<int> > names[MXN];

int useChar(int &cur, int c)
{
    //printf("    using char '%2d' on %2d    ", c, cur);
    for (; cur && !trie[cur].count(c); cur=fail[cur]);    // KMP flashbacks
    if (trie[cur].count(c)) cur = trie[cur][c];
    //printf("        went to %d\n", cur);
    int twcnt = 0;
    for (int ftc=cur; ftc && !failvis[ftc] && wcnt[ftc]; failvis[ftc]=1, ftc=fail[ftc])
        //printf("    at %d\n", ftc),
        ++viscnt[ftc], twcnt += isw[ftc];
    //{
    //    //printf("           visiting %-3d on failtrail\n", ftc);
    //    if (isw[ftc]) tans.pb(isw[ftc]);
    //}
    ////printf("        got %d answers\n", tans.size());
    //return tans;
    return twcnt;
}

void insert(int idx)
{
    int len; sc(len);
    int cur=0;
    while (len--)
    {
        int c = sc();
        if (!trie[cur].count(c))
            //dep[lcnt] = dep[cur]+1,
            trie[cur][c] = lcnt++;
        cur = trie[cur][c];
        //printf(" got %d -> %d\n", c, cur);
    }
    //printf("----\n");
    //wlen[idx] = dep[cur]-1;
    roll[idx] = cur;
    //isw[cur] = idx;
    isw[cur] = 1;
    wcnt[cur]++;
}

int dfs(int c)
{
    for (int n : hd[c])
        viscnt[c] += dfs(n);
    return viscnt[c];
}

int main()
{
    sc(N, M);
    // store names for querying later
    for (int i=1; i<=N; ++i)
    {
        int len=sc(); names[i].f.reserve(len);
        while (len--) names[i].f.pb(sc());
        len=sc(); names[i].s.reserve(len);
        while (len--) names[i].s.pb(sc());
    }
    // construct trie
    for (int i=1; i<=M; ++i) insert(i);
    // construct failpointers
    typedef pair<pair<int, int>, char> QState;
    queue<QState> q;   // cur, pre, char
    //q.push(mp(mp(0, 0), 26));
    //for (int i=0; i<26; ++i) if (trie[0].count(i))    // FIX: push root node manually
    for (auto p: trie[0])
        q.push(mp(mp(p.s, 0), 26));  // FIX: first order nodes don't failpoint to themselves

    while (!q.empty())
    {
        QState c = q.front(); q.pop();
        //printf("q cur %d <- %d (%c)\n", c.f.f, c.f.s, c.s+'A');
        // construct fail pointer
        for (fail[c.f.f] = fail[c.f.s]; fail[c.f.f] && !trie[fail[c.f.f]].count(c.s);
                fail[c.f.f] = fail[fail[c.f.f]]);   // kmp flashbacks
        if (trie[fail[c.f.f]].count(c.s)) fail[c.f.f] = trie[fail[c.f.f]][c.s];

        wcnt[c.f.f] += wcnt[fail[c.f.f]];
        hd[fail[c.f.f]].pb(c.f.f); // construct tree of fail
        //hasw[c.f.f] |= hasw[fail[c.f.f]];
        // bfs
        for (auto p : trie[c.f.f])
        //for (int i=0; i<26; ++i) if (trie[c.f.f].count(i))
            q.push(mp(mp(p.s, c.f.f), p.f));
    }

    // debug ac automaton
    //printf("    "); for (int i=0; i<26; ++i) printf("%3d", i); printf("\n");
    //for (int i=0; i<lcnt; ++i)
    //{
    //    printf("%-3d ", i);
    //    for (int j=0; j<27; ++j)
    //        if (trie[i].count(j)) printf("%3d", trie[i][j]);
    //        else printf("  .");
    //    printf("   ->%3d     wcnt %d\n", fail[i], wcnt[i]);
    //}

    // call roll
    for (int i=1; i<=N; ++i)
    {
        memset(failvis, 0, sizeof failvis);
        int cur=0; for (auto nxt : names[i].f)
            //printf("%3d", nxt),
            nameans[i] += useChar(cur, nxt);
        //printf("\n");

        cur=0; for (auto nxt : names[i].s)
            //printf("%3d", nxt),
            nameans[i] += useChar(cur, nxt);
        //printf("\n");
    }

    dfs(0);

    for (int i=1; i<=M; ++i) printf("%d\n", viscnt[roll[i]]);
    for (int i=1; i<=N; ++i) printf("%d ", nameans[i]); printf("\n");
}

