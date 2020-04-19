/*
TASK: 658
LANG: C++14
*/

/*
 * Problem 658 (onlinejudge/pid/658)
 * Create time: Wed 04 Mar 2020 @ 18:12 (PST)
 * Accept time: [!meta:end!]
 ! FIX: didn't clear everything correctly
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "658");

using namespace std;
const int MX = 110;
typedef int bugset;
typedef pair<bugset, bugset> pre; // pair<need, needn't>
typedef pair<bugset, bugset> post; // pair<fix, create>
typedef pair<pre, post> patch; // pair< pre: <need, needn't>, post: <fix, create> >

int N, M;

vector<pair<int, patch> > patches; // <dist, patch>

unordered_map<bugset, int> dist;

inline bool canApply(bugset cur, pre p)					// N
{
    FOR(n, N)
    {
        if ((p.F & 1<<n) && !(cur & 1<<n)) return false;
        if ((p.S & 1<<n) &&  (cur & 1<<n)) return false;
    }
    return true;
}

inline bugset applyPatch(bugset cur, post p)				// N
{
    FOR(n, N)
    {
        if (p.F & 1<<n) cur &= ~(1<<n);
        if (p.S & 1<<n) cur |=  (1<<n);
    }
    return cur;
}

int main()
{
    // setIO();
    int kase=0;
    // while (scanf("%d%d", &N, &M) == 2)
    while (cin >> N >> M)						// Kase
    {
        if (!N || !M) break;
        patches.clear();
	patches.reserve(M);
        dist.clear();
        //printf("N = %d, M = %d\n", N, M);
        // input
        FOR(m, M)							// MN+
        {
            int t;
            scanf("%d", &t);

            // input patch bugsets
            char c;
            scanf("%*c"); // FIX: get rid of seperator space
            //     input pre
            bugset need=0, neednt=0; // FIX: init to zero
            FOR(n, N)
            {
                scanf("%c", &c);
                if (c == '+') need |= (1<<n);
                if (c == '-') neednt |= (1<<n);
            }
            scanf("%*c"); // get rid of seperator space
            //     input post
            bugset fix=0, create=0;
            FOR(n, N)
            {
                scanf("%c", &c);
                if (c == '+') create |= (1<<n);
                if (c == '-') fix |= (1<<n);
            }
            //printf("    patch +%d -%d => +%d -%d\n", need, neednt, fix, create);
            patches.EB(t, MP(MP(need, neednt), MP(fix, create)));
        }
        //printf("patches avaliable: %d\n", patches.size());
	bool finished = 0;
        if (kase++) printf("\n");
        printf("Product %d\n", kase);

        bugset src = (1<<N)-1;
	priority_queue<pair<int, bugset> > pq;
        pq.emplace(0, src);
        while (!pq.empty())							// 2^N * M * N
        {
            //printf("pq size: %d\n", pq.size());
            pair<int, bugset> cur = pq.top(); pq.pop();
            //printf("cur pq state: %d after %d\n", cur.S, cur.F);
	    if (dist[cur.S] < cur.F) continue;

            if (!cur.S)
            {
                printf("Fastest sequence takes %d seconds.\n", cur.F);
		finished = 1;
                break;
            }

            TRAV(p, patches)							// M*N
            {
                bugset applied = applyPatch(cur.S, p.S.S);
                if (!dist.count(applied)) dist[applied] = 1<<30;
                if (canApply(cur.S, p.S.F) && cur.F + p.F < dist[applied])
                {
                    //printf("    inserting %d\n", applyPatch(cur.S, p.S.S));
                    dist[applied] = cur.F + p.F;
                    pq.emplace(cur.F + p.F, applied);
                }
            }
        }
        if (!finished) printf("Bugs cannot be fixed.\n");
    }
    printf("\n");

    return 0;
}

void setIO(const string &name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // fast cin/cout
    if (fopen((name + ".in").c_str(), "r") != nullptr)
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w+", stdout);
    }
}
