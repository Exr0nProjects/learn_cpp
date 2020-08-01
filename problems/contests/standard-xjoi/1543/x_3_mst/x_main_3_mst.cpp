/*
 * Problem 3_mst (contests/standard-xjoi/1543/3_mst)
 * Create time: Sat 01 Aug 2020 @ 15:08 (PDT)
 * Accept time: Sat 01 Aug 2020 @ 15:21 (PDT)
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
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
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 111;
int N, adj[MX][MX], vis[MX]; // djs[MX], djf[MX];
//int find(int n)
//{
//    if (djf[n] !=n) djf[n] = find(djf[n]);
//    return djf[n];
//}
//bool merge(int a, int b)
//{
//    a = find(a);
//    b = find(b);
//    if (a == b) return 0;
//    if (djs[a] < djs[b]) swap(a, b);
//    djs[a] += djs[b];
//    djf[b] = a;
//    return 1;
//}

int main()
{
    scanf("%d", &N);
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=N; ++j)
            scanf("%d", &adj[i][j]);
    int M; scanf("%d", &M);
    for (int i=0; i<M; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u][v] = adj[v][u] = 0;
    }
    //for (int i=0; i<=MX; ++i) djs[i] = 1, djf[i] = i;

    int cost=0;
    priority_queue<pair<int, int>, deque<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i=2; i<=N; ++i) pq.push(mp(adj[1][i], i));
    while (!pq.empty())
    {
        pii cur = pq.top(); pq.pop();
        //printf("cost %d to %d\n", cur.f, cur.s);
        if (vis[cur.s]) continue;
        vis[cur.s] = 1;
        //if (find(1) == find(cur.s)) continue;
        cost += cur.f;
        for (int i=1; i<=N; ++i) if (!vis[i])
            pq.push(mp(adj[cur.s][i], i));
    }
    printf("%d\n", cost);

	return 0;
}

