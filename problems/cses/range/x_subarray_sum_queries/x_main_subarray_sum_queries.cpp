/*
 * Problem subarray_sum_queries (cses/range/subarray_sum_queries)
 * Create time: Sat 12 Dec 2020 @ 22:04 (PST)
 * Accept time: Sat 12 Dec 2020 @ 22:28 (PST)
 * ray pass me the dishes
 */

#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;
const ll MX = 2e5+10;
ll N, M;
ll tsub[MX<<2], tlef[MX<<2], trig[MX<<2], tall[MX<<2];  // FIX: segtree bounds need to be bigger

void apply(ll setv, ll k)   // when many tags
{
    tall[k] = setv;
    tsub[k] = tlef[k] = trig[k] = max(setv, 0ll);
}
//void comb(ll k, ll tl, ll tr, lc=0, rc=0)   // when many statistics
//{
//    if (!lc && !rc) lc = k<<1, rc = k<<1|1;
void comb(ll k, ll tl, ll tr)
{
    const ll lc = k<<1, rc = k<<1|1;
    tsub[k] = max(max(tsub[lc], tsub[rc]), trig[lc]+tlef[rc]);
    tlef[k] = max(tlef[lc], tall[lc]+tlef[rc]);
    trig[k] = max(trig[rc], tall[rc]+trig[lc]);
    tall[k] = tall[lc] + tall[rc];
}

void update(ll q, ll v, ll k=1, ll tl=1, ll tr=N)
{
    if (q < tl || tr < q) return;
    if (tl == tr) { apply(v, k); return; }
    ll mid = tl + (tr-tl>>1);
    if (q <= mid) update(q, v, k<<1, tl, mid);
    else update(q, v, k<<1|1, mid+1, tr);
    comb(k, tl, tr);
}

//ll tcopy(ll src, ll dst)
//{
//    tsub[dst] = tsub[src];
//    tlef[dst] = tlef[src];
//    trig[dst] = trig[src];
//    tall[dst] = tall[src];
//    return tsub[dst];
//}
//ll query(ll ql, ll qr, ll k=1, ll tl=1, ll tr=N)
//{
//    if (qr < tl || tr < ql) return tcopy(0, k+4*N);
//    if (ql <= tl && tr <= qr) return tcopy(k, k+4*N);
//    ll mid = tl + (tr-tl>>1);
//    query(ql, qr, k<<1, tl, mid);
//    query(ql, qr, k<<1|1, mid+1, tr);
//    comb(k+4*N, tl, tr, (k<<1)+4*N, (k<<1|1)+4*N);
//    return tsub[k+4*N];
//}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1; i<=N; ++i)
    {
        int v; scanf("%d", &v);
        update(i, v);
    }
    for (int i=1; i<=M; ++i)
    {
        int k, x; scanf("%d%d", &k, &x);
        update(k, x);
        printf("%lld\n", tsub[1]);
    }
}

