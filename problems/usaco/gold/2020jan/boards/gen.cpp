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
#define rand(l,h) (uniform_int_distribution<int>(l,h)(rng))
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
    updatesub(qy, 1, sub[k]);
    tsum[k] = tsum[lc[k]] + tsum[rc[k]];
}
ll querysub(ll q, ll k=1, ll tl=1, ll tr=N)
{
    //printf("querysub %d @ %d (%d..%d)\n", q, k, tl, tr);
    if (tl == tr) return tsum[k];
    ll mid = tl + (tr-tl>>1);
    if (q <= tl) return querysub(q, lc[k], tl, mid);
    else return querysub(q, rc[k], mid+1, tr);
}
ll pquerysub(ll p, ll &k=rt, ll tl=1, ll tr=N)
{
    //printf("pquerysub %d at %d (%d..%d)\n", p, k, tl, tr);
    if (!k) return tl+p-1;  // FIX: tl + p -1 not just p bc need to account for left
    if (tl == tr) return tl;
    ll mid = tl + (tr-tl>>1);
    if (p <= mid-tl+1-tsum[lc[k]]) return pquerysub(p, lc[k], tl, mid);
    else return pquerysub(p-(mid-tl+1-tsum[lc[k]]), rc[k], mid+1, tr);
}
pair<ll, ll> pquery(ll px, ll py, ll k=rt, ll tl=1, ll tr=N)
{
    //printf("query %d,%d at %d (%d..%d)\n", px, py, k, tl, tr);
    if (!k) return mp(tl-1 + px, py);
    if (tl == tr) return mp(tl, pquerysub(py, sub[k]));
    ll mid = tl + (tr-tl>>1);
    ll leftsz = mid-tl+1-querysub(py, sub[lc[k]]);
    if (px <= leftsz) return pquery(px, py, lc[k], tl, mid);
    else return pquery(px-leftsz, py, rc[k], mid+1, tr);
}

int main()
{
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    //while (true)
    //{
    //    ll t, x, y;
    //    scanf("%lld%lld%lld", &t, &x, &y);
    //    if (~t) update(x, y);
    //    else { auto p = pquery(x, y); printf("%d, %d\n", p.f, p.s); }
    //}
    //while (true) printf("%d\n", rand(1, 20));
    printf("%d %d\n", N, P);
    for (int i=1; i<=P; ++i)
    {
        ll x1, y1, x2, y2;
        x1 = rand(1, N-i), x2 = rand(1, N-i),
        y1 = rand(1, N-i), y2 = rand(1, N-i);
        //printf("index %d %d %d %d\n", x1, x2, y1, y2);
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        tie(x1, y1) = pquery(x1, y1);
        tie(x2, y2) = pquery(x2, y2);
        update(x1, y1); update(x2, y2);
        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }

    return 0;
}

