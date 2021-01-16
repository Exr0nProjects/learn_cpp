/*
 * Problem 60_holloween_party (devskill/60_holloween_party)
 * Create time: Tue 12 Jan 2021 @ 13:40 (PST)
 * Accept time: [!meta:end!]
 *  0-1 bfs
 */
#include <cstdio>
#include <deque>
#include <utility>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
const ll MX = 110;
const ll _y[] = { 1, 0, -1, 0 };
const ll _x[] = { 0, 1, 0, -1 };

ll T, N, M, grid[MX][MX];
ll dist[MX][MX];

int main()
{
    scanf("%lld", &T);
    for (int tt=1; tt<=T; ++tt) {
        scanf("%lld%lld", &N, &M);
        memset(grid, 0, sizeof grid);
        memset(dist, 0, sizeof dist);
        for (int i=1; i<=N; ++i) {
            scanf("\n");
            for (int j=1; j<=M; ++j)
                scanf("%c", &grid[i][j]),
                grid[i][j] -= '0';
        }

        deque<pair<ll, ll> > q;
        q.pb(mp(1, 1)); dist[1][1] = 1;
        while (q.size())
        {
            ll y, x; tie(y, x) = q.front(); q.pop_front();
            //db("at %lld, %lld\n", y, x);
            if (y == N && x == M) break;
            for (int n=0; n<4; ++n)
                if (grid[y+_y[n]][x+_x[n]] && !dist[y+_y[n]][x+_x[n]]) {
                    dist[y+_y[n]][x+_x[n]] = dist[y][x];
                    if (grid[y+_y[n]][x+_x[n]] == grid[y][x])
                        q.pf(mp(y+_y[n], x+_x[n]));
                    else ++dist[y+_y[n]][x+_x[n]],
                        q.pb(mp(y+_y[n], x+_x[n]));
                }
        }
        printf("Case %d: %lld\n", tt, dist[N][M]-1);
    }
}

