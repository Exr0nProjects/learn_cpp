/*
 * Problem 2 (contests/standard-xjoi/1613/2)
 * Create time: Thu 27 Aug 2020 @ 07:57 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <queue>
#include <list>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 1e4+11;

//vector<int> adj[MX];
queue<int> q;
list<int> has[MX];
int N, M, djf[MX], djs[MX], ans[MX];

int find(int n)
{
    if (djf[n] != n) djf[n] = find(djf[n]);
    return djf[n];
}

void merge(int a, int b)
{
    //printf("merge %d and %d\n", a, b);
    a = find(a), b = find(b);
    if (djf[a] == djf[b]) return;
    if (djs[a] < djs[b]) swap(a, b);
    djs[a] += djs[b];
    djf[b] = a;
    has[a].splice(has[a].end(), has[b]);
    //printf("    res size: %d\n", has[a].size());
    if (has[a].size() > 1) q.push(a);
}

int main()
{
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w+", stdout);
    for (int i=1; i<MX; ++i) djf[i] = i, djs[i] = 1;    // FIX: init djs
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; ++i)
    {
        int u, v; scanf("%d%d", &u, &v);
        has[u].pb(v);
    }
    for (int i=1; i<=N; ++i)
        if (has[i].size() > 1) q.push(i);
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        while (has[cur].size() > 1)
        {
            int back = has[cur].back();
            has[cur].pop_back();
            merge(has[cur].back(), back);
        }
    }
    int cnt = 0;
    for (int i=1; i<=N; ++i)
    {
        if (!ans[find(i)]) ans[find(i)] = ++cnt;
        printf("%d\n", ans[find(i)]);
    }

	return 0;
}

