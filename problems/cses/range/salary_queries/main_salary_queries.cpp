/*
 * Problem salary_queries (cses/range/salary_queries)
 * Create time: Sat 12 Dec 2020 @ 21:33 (PST)
 * Accept time: [!meta:end!]
 * sparse diverted segtree
 */

#include <bits/stdc++.h>
#define ll long long
const int MX = 2e5+10;

ll N, Q, lc[MX<<6], rc[MX<<6], tsum[MX<<6], tcnt=0, rt=0;

void dupe(ll &k)
{
    k = ++tcnt;
    printf("k is %d\n", k);
}

void update(ll q, ll v, ll &k=rt, ll tl=1, ll tr=N)
{
    if (!k) dupe(k);
    printf("update %d for %d at %d (%d..%d) -> %d    %d\n", q, v, k, tl, tr, lc[k], rc[k]);
    if (q < tl || tr > q) return;
    if (tl == tr) { tsum[k] += v; return; } // FIX: return after base case
    ll mid = tl + (tr-tl>>1);
    if (q <= mid) update(q, v, lc[k], tl, mid);
    else update(q, v, rc[k], mid+1, tr);
    tsum[k] = tsum[lc[k]] + tsum[rc[k]];
}
ll query(ll ql, ll qr, ll &k=rt, ll tl=1, ll tr=N)
{
    printf("query %d..%d at %d (%d..%d)\n", ql, qr, k, tl, tr);
    if (!k) return 0;
    if (qr < tl || tr < ql) return 0;
    if (tl <= ql && qr <= tr) return tsum[k];
    ll mid = tl + (tr-tl>>1);
    return query(ql, qr, lc[k], tl, mid)
         + query(ql, qr, rc[k], mid+1, tr);
}

int main()
{
    scanf("%d%d", &N, &Q);
    for (int i=1; i<=N; ++i)
    {
        int s; scanf("%d", &s);
        update(s, 1);
    }
    for (int i=1; i<=Q; ++i)
    {
        char c; int a, b;
        scanf("\n%c%d%d", &c, &a, &b);
        if (c == '!') update(a, b);
        else printf("%d\n", query(a, b));
    }
}
