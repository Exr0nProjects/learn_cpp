/*
 * Problem med5 (teamscode_spring_2021/med5)
 * Create time: Sat 24 Apr 2021 @ 15:14 (PDT)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define F(i, N) for (ll i=1; i<=N; ++i)
using namespace std;

const ll MX = 1e3 + 10;
const ll dx[] = { 1, 0, -1, 0 };
const ll dy[] = { 0, 1, 0, -1 };
ll grid[MX][MX], dist[MX][MX], cnt[MX][MX];
ll N, M, ans=0, ansdist=1e9;

//tuple<ll, ll> q[MX*MX];
//ll ql=1, qr=0;
//ll bfs()
//{
//    ll ans = 0;
//    dist[1][1] = 1;
//    cnt[1][1] = 1;
//    q[++qr] = { 1, 1 };
//    for (; ql <= qr; ++ql) {
//        ll y, x; tie(y, x) = q[ql];
//
//        //printf("at %lld, %lld after %lld\n", y, x, dist[y][x]);
//
//        for (int d=0; d<4; ++d) {
//            if (!dist[y+dy[d]][x+dx[d]] && !grid[y+dy[d]][x+dx[d]])
//                dist[y+dy[d]][x+dx[d]] =  dist[y][x] + 1,
//                q[++qr] = { y+dy[d], x+dx[d] };
//            if (dist[y+dy[d]][x+dx[d]] == dist[y][x] + 1) {
//                cnt[y+dy[d]][x+dx[d]] += cnt[y][x];
//                //printf("cnt[%lld][%lld] += cnt[%lld][%lld] (%lld) -> %lld\n", y+dy[d], x+dx[d], y, x, cnt[y][x], cnt[y+dy[d]][x+dx[d]]);
//            }
//        }
//    }
//    return cnt[N][M];
//}
ll dfs(ll y, ll x, ll d=1)
{
    if (dist[y][x] < d) return 0;
    dist[y][x] = d;
    if (y == N && x == M) {
        if (d < ansdist) ans = 1, ansdist = d;
        else if (d == ansdist) ++ans;
        return 1;
    }

    ll thisa = 0;
    for (int d=0; d<4; ++d)
        if (!grid[y+dy[d]][x+dx[d]])
            thisa += dfs(y+dy[d], x+dx[d]);
    if (!thisa) grid[y][x] = 1;
}

int main()
{
    scanf("%lld%lld", &N, &M);
    memset(grid, 1, sizeof grid);
    memset(dist, 0x3f, sizeof dist);
    F(i, N) F(j, M) scanf("%lld", &grid[i][j]);
    printf("%lld\n", dfs(1, 1));
}
