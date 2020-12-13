/*
 * Problem visitfj (usaco/gold/2017feb/visitfj)
 * Create time: Sat 12 Dec 2020 @ 16:01 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll int
#define mt make_tuple
using namespace std;
const ll MX = 110;

typedef tuple<ll, ll, ll, ll> St; // < time, y, x, dist%3 >

ll N, T, grid[MX][MX], dist[MX][MX][4];
const ll _y[] = { 1, 0, -1, 0 };
const ll _x[] = { 0, 1, 0, -1 };

int main()
{
    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w+", stdout);
    scanf("%d%d", &N, &T);
    memset(grid, -1, sizeof grid);
    for (int i=1; i<=N; ++i) for (int j=1; j<=N; ++j)
        scanf("%d", &grid[i][j]);
    grid[1][1] = 0; // don't stop to eat at the first field, does this break things
    //printf("um\n");

    memset(dist, 0x3f, sizeof dist);
    priority_queue<St, deque<St>, greater<St> > pq;
    pq.push(mt(0, 1, 1, 0));
    ll ans = 1e9; // FIX: don't know ans state
    while (pq.size())
    {
        ll t, y, x, d; tie(t, y, x, d) = pq.top(); pq.pop();
        if (grid[y][x] < 0) continue;
        if (dist[y][x][d] <= t) continue;
        //printf("at %d, %d mod %d after %d    -> %d\n", y, x, d, t, grid[y][x]<0);
        dist[y][x][d] = t;
        if (d == 3) d = 0, t += grid[y][x];
        if (y == N && x == N) ans = min(ans, t);
        for (int n=0; n<4; ++n)
            pq.push(mt(t+T, y+_y[n], x+_x[n], d+1));
    }
    printf("%d\n", ans);
}

