/*
TASK: 658
LANG: C++14
*/

/*
 * Problem 658 (onlinejudge/pid/658)
 * Create time: Wed 04 Mar 2020 @ 18:12 (PST)
 * Accept time: Sun 19 Apr 2020 @ 10:58 (PDT)
 ! FIX: didn't clear everything correctly
 ! FIX: pq was a max heap smh
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

int dura[MX];
char before[MX][MX], after[MX][MX];

unordered_map<bugset, int> dist;

inline bool canApply(bugset cur, int patch)				// N
{
    FOR(n, N)
    {
	if (before[patch][n] == '+' && !(cur & 1<<n)) return false;
        if (before[patch][n] == '-' &&  (cur & 1<<n)) return false;
    }
    return true;
}

inline bugset applyPatch(bugset cur, int patch)				// N
{
    FOR(n, N)
    {
        if (after[patch][n] == '-') cur &= ~(1<<n);
        if (after[patch][n] == '+') cur |=  (1<<n);
    }
    return cur;
}

int main()
{
    int kase=0;
    while (cin >> N >> M)						// Kase
    {
        if (!N || !M) break;
        dist.clear();
        // input
        FOR(m, M)							// MN+
            scanf("%d%s%s", &dura[m], before[m], after[m]);

        //printf("patches avaliable: %d\n", patches.size());
	bool finished = 0;
        if (kase++) printf("\n");
        printf("Product %d\n", kase);

        bugset src = (1<<N)-1;
	priority_queue<pair<int, bugset>, deque<pair<int, bugset> >, greater<pair<int, bugset> > > pq;
	// FIX: use greater for pq, how was it not breaking more???  ^^^^^^^
        pq.emplace(0, src);
        while (!pq.empty())							// 2^N * M * N
        {
            pair<int, bugset> cur = pq.top(); pq.pop();
	    if (dist[cur.S] < cur.F) continue;

            if (!cur.S)
            {
                printf("Fastest sequence takes %d seconds.\n", cur.F);
		finished = 1;
                break;
            }

	    FOR(m, M) if (canApply(cur.S, m))
            {
                bugset applied = applyPatch(cur.S, m);
                if (!dist.count(applied))
		    dist[applied] = 1<<30;

                if (cur.F + dura[m] < dist[applied])
                {
                    dist[applied] = cur.F + dura[m];
                    pq.emplace(cur.F + dura[m], applied);
                }
            }
        }
        if (!finished) printf("Bugs cannot be fixed.\n");
    }
    printf("\n");

    return 0;
}

/*
2 3
2 +0 -+
0 -0 --
4 +0 --
=> 2 seconds
*/
