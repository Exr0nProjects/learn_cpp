/*
 * Problem 14 (tcp2020/14)
 * Create time: Sun 19 Jul 2020 @ 11:22 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <tuple>
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
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
const ll MX = 2100;

vector<pair<int, int> > head[MX];
int N, M, S, T;
dl dist[MX];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        head[u].pb(mp(v, w));
        head[v].pb(mp(u, w));
    }
    scanf("%d%d", &S, &T);

    priority_queue<pair<dl, int>, deque<pair<dl, int> >, greater<pair<dl, int> > > pq;
    pq.push(0, S);
    while (!pq.empty())
    {
        pair<dl, int> cur = pq.top(); pq.pop();
        if (cur.s == T) { printf("%.8d\n", cur.f); break; }
        if (dist[cur.s] < cur.f) continue;
        for (int i=0; i<head[cur.s].size(); ++i)
        {
            pq.push();
        }
    }


	return 0;
}

