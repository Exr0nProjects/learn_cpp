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
const ll MX = 1e5+11;

queue<int> q;
list<int> has[MX];
int N, M, cnt[MX], djf[MX], djs[MX], ans[MX];
// cnt[i] is the number of distinct groups that admire group i

int find(int n)
{
    if (djf[n] != n) djf[n] = find(djf[n]);
    return djf[n];
}

bool merge(int a, int b)
{
    //printf("merge %d and %d\n", a, b);
    a = find(a), b = find(b);
    if (djf[a] == djf[b]) return false;
    if (djs[a] < djs[b]) swap(a, b);
    printf("has[%d] %d has[%d] %d\n", a, has[a].size(), b, has[b].size());
    djs[a] += djs[b];
    djf[b] = a;
    has[a].splice(has[a].end(), has[b]);
    cnt[a] += cnt[b];
    cnt[b] = 0;
    printf("has[%d] %d (%d) has[%d] %d\n\n", a, has[a].size(), cnt[a], b, has[b].size());
    //printf("    res size: %d\n", has[a].size());
    if (cnt[a] > 1) q.push(a);
    return true;
}

int main()
{
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w+", stdout);
    for (int i=1; i<MX; ++i) djf[i] = i, djs[i] = 1;    // FIX: init djs
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        has[u].pb(v);
        ++cnt[u];
    }
    for (int i=1; i<=N; ++i)
        if (has[i].size() > 1) q.push(i);
    while (!q.empty())
    {
        printf("q size: %d\n", q.size());
        int cur = q.front(); q.pop();
        //printf("has[%d] %d cnt %d\n", cur, has[cur].size(), cnt[cur]);
        while (cnt[cur] > 1 && has[cur].size() > 1)
        {
            int back = has[cur].back();
            has[cur].pop_back();
            cnt[cur] -= merge(has[cur].back(), back);
        }
    }
    int cur = 0;
    for (int i=1; i<=N; ++i)
    {
        if (!ans[find(i)]) ans[find(i)] = ++cur;
        //printf("%d\n", ans[find(i)]);
    }

	return 0;
}

