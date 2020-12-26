#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <chrono>
#include <tuple>
#include <utility>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define db(...) fprintf(stderr, __VA_ARGS__)
#define rand(l,h) (rng()%(h-l+1)+l)
using namespace std;
// 2d sparse segtree binary search in a casegen :/

const ll N = 2e1;
const ll P = 1e1;
//const ll N = 1e9;
//const ll P = 1e5;

bool vis[N][N];

ll tsum[P<<6], lc[P<<6], rc[P<<6], sub[P<<6], rt=0, tcnt=0;
void updatesub(ll q, ll v, ll &k=rt, ll tl=1, ll tr=N)
{
    if (!k) k = ++tcnt;
    //printf("updatesub %d %d at %d (%d..%d)\n", q, v, k, tl, tr);
    if (tl == tr) return tsum[k] = v, void();
    ll mid = tl + (tr-tl>>1);
    if (q <= mid) updatesub(q, v, lc[k], tl, mid);
    else updatesub(q, v, rc[k], mid+1, tr);
    tsum[k] = tsum[lc[k]] + tsum[rc[k]];
}
void update(ll qx, ll qy, ll &k=rt, ll tl=1, ll tr=N)
{
    if (!k) k = ++tcnt;
    //printf("update %d %d at %d (%d..%d)\n", qx, qy, rt, tl, tr);
    if (tl == tr) return updatesub(qy, 1, sub[k]), tsum[k] = tsum[sub[k]], void();
    ll mid = tl + (tr-tl>>1);
    if (qx <= mid) update(qx, qy, lc[k], tl, mid);
    else update(qx, qy, rc[k], mid+1, tr);
    tsum[k] = tsum[lc[k]] + tsum[rc[k]];
}
ll pquerysub(ll p, ll &k=rt, ll tl=1, ll tr=N)
{
    //printf("pquery %d at %d (%d..%d)\n", p, k, tl, tr);
    if (!k) return tl+p-1;  // FIX: tl + p -1 not just p bc need to account for left
    if (tl == tr) return tl;
    ll mid = tl + (tr-tl>>1);
    if (p <= mid-tl+1-tsum[lc[k]]) return pquerysub(p, lc[k], tl, mid);
    else return pquerysub(p-(mid-tl+1-tsum[lc[k]]), rc[k], mid+1, tr);
}
pair<ll, ll> pquery(ll px, ll py, ll k=rt, ll tl=1, ll tr=N)
{
    if (!k) return mp(tl-1 + px, py);
    if (tl == tr) return mp(tl, pquerysub(py, sub[k]));
    ll mid = tl + (tr-tl>>1);
    if (px < mid-tl+1-tsum[lc[k]]) return pquery(px, py, lc[k], tl, mid);
    else return pquery(px-(mid-tl+1-tsum[lc[k]]), py, rc[k], mid+1, tr);
}

int main()
{
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    while (true)
    {
        ll t, x, y;
        scanf("%lld%lld%lld", &t, &x, &y);
        if (~t) update(x, y);
        else { auto p = pquery(x, y); printf("%d, %d\n", p.f, p.s); }
    }
    //while (true) printf("%d\n", rand(1, 20));
    printf("%d %d\n", N, P);
    for (int i=1; i<=P; ++i)
    {
        ll x1, y1, x2, y2;
        x1 = rand(1, N-2*i), x2 = rand(1, N-2*i),
        y1 = rand(1, N-2*i), y2 = rand(1, N-2*i);
        if (x1 > x2) x1 ^= x2 ^= x1 ^= x2;
        if (y1 > y2) y1 ^= y2 ^= y1 ^= y2;

        tie(x1, y1) = pquery(x1, y1);
        tie(x2, y2) = pquery(x2, y2);
        update(x1, y1); update(x2, y2);
        //do
        //    x1 = rand(0 , N), y1 = rand(0 , N),
        //    x2 = rand(x1, N), y2 = rand(y1, N),
        //    db("%d %d %d %d\n", x1, y1, x2, y2);
        //while (!vis[x1][y1] && !vis[x2][y2]);
        //do db("%d %d %d\n", i, x1, y1), x1 = rand(0, N), y1 = rand(0, N); while (vis[x1][y1]);
        //vis[x1][y1] = 1;
        //do db("%d %d %d\n", i, x2, y2), x2 = rand(x1, N), y2 = rand(y1, N); while (vis[x2][y2]);
        //vis[x2][y2] = 1;
        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }

    return 0;
}

