/*
 * Problem wpuzzles (spoj/wpuzzles)
 * Create time: Mon 26 Oct 2020 @ 18:29 (PDT)
 * Accept time: Mon 26 Oct 2020 @ 22:21 (PDT)
 * problem: find occurances of words in a word finder puzzle
 * AC Automaton in all the directions
 */

#include <set>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>


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

void setIO(const std::string &name = "wpuzzles")
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
const int MX = 1e3+10;
const int MXL = 1e6+11;
const int delta[] = {-1, 0, 1};

char grid[MX][MX];
int T, L, C, W, wlen[MX];   // length of each word

int trie[MXL][30], fail[MXL], dep[MXL], isw[MXL], lcnt=1;
//                                      ^^^ isw[i] means this node is the end of word i
bool hasw[MXL], failvis[MXL];  // has a word in failpointer linkedlist; visited this node on failtrail already
pair<pair<int, int>, char> ans[MX];

vector<int> useChar(int &cur, int c)
{
    //printf("    using char '%c' on %d\n", c+'A', cur);
    for (; cur && !trie[cur][c]; cur=fail[cur]);    // KMP flashbacks
    if (trie[cur][c]) cur = trie[cur][c];
    //printf("        went to %d\n", cur);
    // follow failtrail for skipped words
    vector<int> tans;
    for (int ftc=cur; ftc && !failvis[ftc] && hasw[ftc]; failvis[ftc]=1, ftc=fail[ftc])
    {
        //printf("           visiting %-3d on failtrail\n", ftc);
        if (isw[ftc]) tans.pb(isw[ftc]);
    }
    //printf("        got %d answers\n", tans.size());
    return tans;
}

inline bool ok(int y, int x)
{ return x >= 0 && x < C && y >= 0 && y < L; }

int main()
{
    sc(T);
    while (T--)
    {
        sc(L, C, W);
        memset(trie, 0, sizeof trie);
        memset(fail, 0, sizeof fail);
        memset(hasw, 0, sizeof hasw);
        memset(dep, 0, sizeof dep);
        memset(isw, 0, sizeof isw);
        lcnt=1;
        for (int i=1; i<=W; ++i) ans[i] = {};

        for (int i=0; i<L; ++i) scanf("%s", grid[i]);
        scanf("%*c");   // FIX: input--consume newline
        // construct trie
        for (int i=1; i<=W; ++i)
        {
            int cur=0, c=_gc()-'A';
            while (true)
            {
                if (c < 0)
                {
                    wlen[i] = dep[cur]-1;
                    hasw[cur] = 1, isw[cur] = i;
                    break;
                }
                if (!trie[cur][c])
                    //par[lcnt] = cur,
                    dep[lcnt] = dep[cur]+1,
                    trie[cur][c] = lcnt++;
                //printf("got char '%c' -> %d\n", c+'A', trie[cur][c]);
                cur = trie[cur][c], c = _gc() - 'A';
            }
        }
        // construct failpointers
        typedef pair<pair<int, int>, char> QState;
        queue<QState> q;   // cur, pre, char
        //q.push(mp(mp(0, 0), 26));
        for (int i=0; i<26; ++i) if (trie[0][i])    // FIX: push root node manually
            q.push(mp(mp(trie[0][i], 0), 26));  // FIX: first order nodes don't failpoint to themselves
        while (!q.empty())
        {
            QState c = q.front(); q.pop();
            //printf("q cur %d <- %d (%c)\n", c.f.f, c.f.s, c.s+'A');
            // construct fail pointer
            for (fail[c.f.f] = fail[c.f.s]; fail[c.f.f] && !trie[fail[c.f.f]][c.s]; // FIX: typo--go while fail[c.f.f], not stop when it
                    fail[c.f.f] = fail[fail[c.f.f]]);   // kmp flashbacks
            if (trie[fail[c.f.f]][c.s]) fail[c.f.f] = trie[fail[c.f.f]][c.s];
            hasw[c.f.f] |= hasw[fail[c.f.f]];
            // bfs
            for (int i=0; i<26; ++i) if (trie[c.f.f][i])
                q.push(mp(mp(trie[c.f.f][i], c.f.f), i));
        }

        //// debug ac automaton
        //printf("    "); for (int i=0; i<26; ++i) printf("%3c", i+'A'); printf("\n");
        //for (int i=0; i<lcnt; ++i)
        //{
        //    printf("%-3d ", i);
        //    for (int j=0; j<26; ++j)
        //        if (trie[i][j]) printf("%3d", trie[i][j]);
        //        else printf("  .");
        //    printf("   ->%3d     isw %-3d hasw %d dep %-3d\n", fail[i], isw[i], hasw[i], dep[i]);
        //}

        // check the grid
        for (int i=0; i<L; ++i) for (int d=-1; d<2; ++d)
        {
            // start on left side
            memset(failvis, 0, sizeof failvis);
            //printf("left  side d=%d\n", d);
            for (int y=i, x=0, cur=0; ok(y, x); ++x, y+=d)
            {
                vector<int> g = useChar(cur, grid[y][x]-'A');
                //printf("        cur = %d\n", cur);
                //for (auto a : g) printf("    setting ans %d\n", a), ans[a] = mp(mp(y-wlen[a]*d, x-wlen[a]), 'B'+d);
                for (auto a : g) ans[a] = mp(mp(y-wlen[a]*d, x-wlen[a]), 'B'+d+1);
            }
            // start on right side
            memset(failvis, 0, sizeof failvis);
            //printf("right side d=%d\n", d);
            for (int y=i, x=C-1, cur=0; ok(y, x); --x, y+=d)
            {
                vector<int> g = useChar(cur, grid[y][x]-'A');
                //printf("        cur = %d\n", cur);
                //for (auto a : g) printf("    setting ans %d\n", a), ans[a] = mp(mp(y-wlen[a]*d, x+wlen[a]), 'H'-d);
                for (auto a : g) ans[a] = mp(mp(y-wlen[a]*d, x+wlen[a]), 'H'-d-1);
            }
        }
        for (int i=0; i<C; ++i) for (int d=-1; d<2; ++d)
        {
            // start from the top edge
            memset(failvis, 0, sizeof failvis);
            //printf("top   edge");
            for (int x=i, y=0, cur=0; ok(y, x); ++y, x+=d)
            {
                vector<int> g = useChar(cur, grid[y][x]-'A');
                //printf("        cur = %d\n", cur);
                //for (auto a : g) printf("    setting ans %d\n", a), ans[a] = mp(mp(y-wlen[a], x-wlen[a]*d), 'E');
                for (auto a : g) ans[a] = mp(mp(y-wlen[a], x-wlen[a]*d), 'F'-d-1);
            }
            // bottom edge
            //printf("bot   edge");
            memset(failvis, 0, sizeof failvis);
            for (int x=i, y=L-1, cur=0; ok(y, x); --y, x+=d)
            {
                vector<int> g = useChar(cur, grid[y][x]-'A');
                //printf("        cur = %d\n", cur);
                //for (auto a : g) printf("    setting ans %d\n", a), ans[a] = mp(mp(y+wlen[a], x-wlen[a]*d), 'A');
                for (auto a : g) ans[a] = mp(mp(y+wlen[a], x-wlen[a]*d), ~d?'A'+d:'H');
            }
        }
        for (int i=1; i<=W; ++i)
            printf("%d %d %c\n", ans[i].f.f, ans[i].f.s, ans[i].s);
        printf("\n");
    }
}

