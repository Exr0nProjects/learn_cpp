/*
 * Problem 2_cf787e (contests/dated/2020_06_19/2_cf787e)
 * Create time: Wed 24 Jun 2020 @ 10:14 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
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

using namespace std;
const ll MX = 100111;
ll N, D, vis[MX], tsum[MX<<6], addt[MX<<6];
ll alc=1, lc[MX<<6], rc[MX<<6], rt[MX];

void dupe(ll &k)
{
    tsum[alc] = tsum[k];
    addt[alc] = addt[k];
    lc[alc] = lc[k];
    rc[alc] = rc[k];
    k = alc++;
}
void apply(ll addv, ll &k, ll tl, ll tr)
{
    if (!addv) return;
    dupe(k);
    addt[k] += addv;
    tsum[k] += addv * (tr-tl+1);
}
void push(ll &k, ll tl, ll tr)
{
    ll mid = tl + (tr-tl>>1);
    dupe(k);
    apply(addt[k], lc[k], tl, mid);
    apply(addt[k], rc[k], mid+1, tr);
    addt[k] = 0;
}
void comb(ll k)
{
    tsum[k] = tsum[lc[k]] + tsum[rc[k]];
}

void update(ll ql, ll qr, ll addv, ll &k, ll tl=1, ll tr=1<<D)
{
    if (qr < tl || tr < ql) return;
    if (ql <= tl && tr <= qr) return apply(addv, k, tl, tr);
    dupe(k); ll mid = tl + (tr-tl>>1);
    update(ql, qr, addv, lc[k], tl, mid);
    update(ql, qr, addv, rc[k], mid+1, tr);
    comb(k);
}
//ll query(ll ql, ll qr, ll &k, ll tl=1, ll tr=1<<D, ll acc=0)
//{
//    if (ql < tl || tr < ql) return 0;
//    if (ql <= tl && tr <= qr) return tsum[k] + acc;
//    acc += addt[k]; ll mid = tl + (tr-tl>>1);   // TODO: if query broke, replace acc with push()
//    return query(ql, qr, lc[k], tl, mid, acc)
//         + query(ql, qr, rc[k], mid+1, tr, acc);
//}
ll query(ll q, ll &k, ll tl=1, ll tr=1<<D, ll acc=0)
{
    if (tl == tr) return tsum[k] + acc;
    acc += addt[k];
    //push(k, tl, tr);
    ll mid = tl+(tr-tl>>1);
    if (q <= mid) return query(q, lc[k], tl, mid, acc);
    else return query(q, rc[k], mid+1, tr, acc);
}

ll bins(ll s, ll k)
{
    ll l=s, r=N+1;   // exclude r
    for (ll i=1; i<20; ++i)
    {
        ll mid = l + (r-l>>1);
        printf("        query %d..%d = %d\n", s, mid, query(s, rt[mid]));
        if (query(s, rt[mid]) <= k)
            l = mid;
        else
            r = mid;
    }
    printf("    bins from %d with %d colors => %d..%d\n", s, k, s, l);
    return l;
}

int main()
{
    scanf("%lld", &N);
    D = 64-__builtin_clzll(N);

    rt[0] = alc++;
    for (ll i=1; i<1<<D; ++i)
    {
        lc[i] = alc++;
        rc[i] = alc++;
    }

    for (ll i=1; i<=N; ++i)
    {
        rt[i] = rt[i-1];
        ll d; scanf("%d", &d);
        update(vis[d], i, 1, rt[i]);
        vis[d] = i;
    }

    vector<int> ans;
    for (ll k=1; k<=N; ++k)
    {
        ll cnt=0;
        for (ll s=1; s <= N; ++cnt)
            s = bins(s, k)+1;
        ans.pb(cnt);
        printf("\n");
    }
    for (int a : ans) printf("%lld ", a); printf("\n");

	return 0;
}

