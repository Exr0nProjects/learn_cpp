/*
 * Problem 1 (contests/standard-xjoi/1614/1)
 * Create time: Thu 27 Aug 2020 @ 18:11 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <list>
#include <queue>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 1e5+11;

int N, M, C;
int in[MX], cost[MX], ans[MX];
list<pair<int, int> > h[MX];

int main()
{
    scanf("%d%d%d", &N, &M, &C);
    for (int i=1; i<=N; ++i)
    {
        int w; scanf("%d", &w);
        ++in[i]; h[0].pb(mp(w, i));
    }
    for (int i=0; i<C; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        h[u].pb(mp(w, v));
        ++in[v];
    }
    priority_queue<pair<int, int>, deque<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(mp(0, 0));
    while (!pq.empty())
    {
        pair<int, int> c = pq.top(); pq.pop();
        ans[c.s] = c.f;
        for (auto e : h[c.s])
        {
            cost[e.s] = max(cost[e.s], c.f + e.f);
            if (!--in[e.s]) pq.push(mp(cost[e.s], e.s));
        }
    }

    for (int i=1; i<=N; ++i) printf("%d\n", ans[i]);

	return 0;
}

