#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <chrono>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
#define rand(l,h) (rng()%(h-l+1)+l)
// sparse segtree binary search in a casegen :/

const ll N = 2e1;
const ll P = 1e1;
//const ll N = 1e9;
//const ll P = 1e5;

bool vis[N][N];

ll tsum[N<<2], lc[N<<2], rc[N<<2], rt=0, tcnt=0;
void update(ll q, ll v, ll &k=rt, ll tl=1, ll tr=N)
{
    if (!k) k = ++tcnt;
    printf("update %d %d at %d (%d..%d)\n", q, v, k, tl, tr);
    if (tl == tr) return tsum[k] = v, void();
    ll mid = tl + (tr-tl>>1);
    if (q <= mid) update(q, v, lc[k], tl, mid);
    else update(q, v, rc[k], mid+1, tr);
    tsum[k] = tsum[lc[k]] + tsum[rc[k]];
}
ll pquery(ll p, ll &k=rt, ll tl=1, ll tr=N)
{
    printf("pquery %d at %d (%d..%d)\n", p, k, tl, tr);
    if (!k) return tl+p-1;  // FIX: tl + p -1 not just p bc need to account for left
    if (tl == tr) return tl;
    ll mid = tl + (tr-tl>>1);
    if (p <= mid-tl+1-tsum[lc[k]]) return pquery(p, lc[k], tl, mid);
    else return pquery(p-(mid-tl+1-tsum[lc[k]]), rc[k], mid+1, tr);
}

int main()
{
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    //while (true)
    //{
    //    ll t, x;
    //    scanf("%lld%lld", &t, &x);
    //    if (~t) update(t, x);
    //    else printf("%d\n", pquery(x));
    //}
    //while (true) printf("%d\n", rand(1, 20));
    printf("%d %d\n", N, P);
    for (int i=1; i<=P; ++i)
    {
        ll x1, y1, x2, y2;
        x1 = rand(1, N-2*i), x2 = rand(1, N-2*i),
        y1 = rand(1, N-2*i), y2 = rand(1, N-2*i);
        if (x1 > x2) x1 ^= x2 ^= x1 ^= x2;
        if (y1 > y2) y1 ^= y2 ^= y1 ^= y2;
        x1 = pquery(x1); y1 = pquery(y1);
        x2 = pquery(x2); y2 = pquery(y2);
        update(x1, 1); update(y1, 1);
        update(x2, 1); update(y2, 1);
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

