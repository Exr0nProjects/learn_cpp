/*
 * Problem 1053 (usaco/gold/2020dec/1053)
 * Create time: Sat 19 Dec 2020 @ 12:51 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 1e3+10;
const ll _x[] = { 1, 0, -1, 0 };
const ll _y[] = { 0, 1, 0, -1 };
ll N, D, ans=0;
char grid[MX][MX];

ll smx[MX][MX], near[MX][MX];
bool vis[MX][MX][4];

bitset<MX*MX*(MX+1)> fvis;
void flood(ll x, ll y, ll c)
{
    if (!c) return;
    if (fvis.test((x-1)*MX*MX+(y-1)*MX+c)) return;
    if (!smx[x][y]) ++ans, grid[x][y] = 'x';
    fvis.set((x-1)*MX*MX+(y-1)*MX+c);
    for (int n=0; n<4; ++n)
        flood(x+_x[n], y+_y[n], c-1);
}

int main()
{
    scanf("%lld%lld", &N, &D);
    memset(grid, '#', sizeof grid);
    for (int i=1; i<=N; ++i) scanf("%s", grid[i]+1);
    queue<pair<ll, pair<ll, ll> > > sq, hq;
    queue<tuple<ll, ll, ll, ll> > sq2;
    for (int i=1; i<=N; ++i) for (int j=1; j<=N; ++j)
        //if (grid[i][j] == 'S') sq.push(mp(0, mp(i, j))); else
        if (grid[i][j] == '#') hq.push(mp(0, mp(i, j))); else
        if (grid[i][j] == 'S') for (int n=0; n<4; ++n)
            sq2.push(mt(0, i, j, n));

    while (hq.size())
    {
        ll d; pair<ll, ll> c;
        tie(d, c) = hq.front(); hq.pop();
        //db("at %d %d for %d, size %d\n", c.f, c.s, d, hq.size());
        if (near[c.f][c.s]) continue; near[c.f][c.s] = d;
        for (int n=0; n<4; ++n)
        {
            const ll nx = c.f+_x[n], ny = c.s+_y[n];
            if (grid[nx][ny] != '#' && !near[nx][ny])
                hq.push(mp(d+1, mp(nx, ny)));
        }
    }
    //for (int i=1; i<=N; ++i) { for (int j=1; j<=N; ++j) db("%3d", near[i][j]); db("\n"); }
    while (sq2.size())
    {
        ll d, x, y, n; tie(d, x, y, n) = sq2.front(); sq2.pop();
        if (vis[x][y][n] > d) continue; vis[x][y][n] = d;
        //db("at %d %d %d %d\n", d, x, y, n);
        smx[x][y] = max(smx[x][y], d/D+1);
        if (d % D == 0) if (near[x][y] < d/D+1) { --smx[x][y]; continue; } // replication would hit wall
        //db("to %d,%d gets %d >= %d and %d < %d\n", x+_x[n], y+_y[n], near[x+_x[n]][y+_y[n]], d/D+1, vis[x+_x[n]][y+_y[n]][n], d+1);
        if (near[x+_x[n]][y+_y[n]] >= d/D+1 && vis[x+_x[n]][y+_y[n]][n] < d+1)
            sq2.push(mt(d+1, x+_x[n], y+_y[n], n));
    }
    for (int i=1; i<=N; ++i) { for (int j=1; j<=N; ++j) if (smx[i][j]) db("%3d", smx[i][j]); else db("  ."); db("\n"); }


    ll ans2=0;
    for (int i=1; i<=N; ++i) for (int j=1; j<=N; ++j)
        if (smx[i][j])
            flood(i, j, smx[i][j]),
                ++ans2,
            db("");
    printf("ans %d ans2 %d\n", ans, ans2);
    for (int i=1; i<=N; ++i) { for (int j=1; j<=N; ++j) db("%3c", grid[i][j]); db("\n"); }

    //typedef tuple<ll, ll, ll> St;
    //priority_queue<St, deque<St>, greater<St> > pq;
    //for (int i=1; i<=N; ++i) for (int j=1; j<=N; ++j)
    //    if (smx[i][j]) pq.push(mt(smx[i][j], i, j));
    //for (; pq.size();)
    //{
    //    ll d, x, y; tie(d, x, y) = pq.top(); pq.pop();
    //    //db("at %d %d %d\n", d, x, y);
    //    if (smx[x][y] > d) continue;
    //    smx[x][y] = d; ++ans;
    //    for (int n=0; n<4; ++n) if (smx[x+_x[n]][y+_y[n]] < d-1)
    //        pq.push(mt(d-1, x+_x[n], y+_y[n]));
    //}
    printf("%lld\n", ans+ans2);
}

