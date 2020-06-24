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

#include <chrono>
using namespace std::chrono;
// from https://stackoverflow.com/a/19555298
ll get_ns()
{
    return duration_cast< microseconds >(
        system_clock::now().time_since_epoch()
    ).count();
}

//#define RESET "\033[0m"
//#define BLACK "\x1b[38;5;239m"
//void dump(ll k)
//{
//    queue<ll> bfs; bfs.push(k);
//    ll d = D+1;
//    printf(BLACK);
//    for (ll i=1; i<1<<1+D; ++i)
//    {
//        if (__builtin_popcount(i) == 1) { --d; printf("\n"); }
//        k = bfs.front(); bfs.pop();
//        if (i >= 1<<D) printf(RESET);
//        bfs.push(lc[k]); bfs.push(rc[k]);
//        //printf("%2d: %2d+%2d (%-2d %2d)  ", k, tsum[k], addt[k], lc[k], rc[k]);
//        //for (ll i=1; i<1<<d; ++i) printf("                   ");
//        printf("%2d: %2d%+2d   ", k, tsum[k], addt[k], lc[k], rc[k]);
//        for (ll i=1; i<1<<d; ++i) printf("           ");
//    }
//    printf("\n");
//}

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

void update(ll ql, ll qr, ll addv, ll &k, ll tl=1, ll tr=1<<D)
{
    if (qr < tl || tr < ql) return;
    if (ql <= tl && tr <= qr) return apply(addv, k, tl, tr);
    dupe(k); ll mid = tl + (tr-tl>>1);
    update(ql, qr, addv, lc[k], tl, mid);
    update(ql, qr, addv, rc[k], mid+1, tr);
    tsum[k] = tsum[lc[k]] + tsum[rc[k]];
}
//ll query(ll q, ll k, ll tl=1, ll tr=1<<D, ll acc=0)
//{
//    //printf("recs: %d..%d +%d\n", tl, tr, acc);
//    if (tl == tr) return tsum[k] + acc;
//    acc += addt[k];
//    ll mid = tl+(tr-tl>>1);
//    if (q <= mid) return query(q, lc[k], tl, mid, acc);
//    else return query(q, rc[k], mid+1, tr, acc);
//}

ll query_iter(ll q, ll k, ll tl=1, ll tr=1<<D)
{
    ll acc = addt[k];
    for (; tl < tr; acc += addt[k])
    {
        //const ll mid = tl + (tr-tl>>1);
        const ll mid = tr+tl>>1;
        if (q <= mid) k = lc[k], tr = mid;
        else          k = rc[k], tl = mid+1;
        //printf("iter: %d..%d +%d\n", tl, tr, acc);
    }
    return tsum[k] + acc - addt[k]; // FIX: equ--subtract extra addt[k]
}

ll bins(ll s, ll k)
{
    ll l=s, r=N+1;   // exclude r
    for (ll i=1; r-l>1; ++i)
    {
        ll mid = l + (r-l>>1);
        //printf("        query %d..%d = %d\n", s, mid, query(s, rt[mid]));
        //if (query(s, rt[mid]) != query_iter(s, rt[mid])) printf("NOT EQUAL!!! %d vs %d\n", query(s, rt[mid]), query_iter(s, rt[mid]));
        //printf("\n"); query(s, rt[mid]);
        if (query_iter(s, rt[mid]) <= k)
            l = mid;
        else
            r = mid;
    }
    //printf("    bins from %d with %d colors => %d..%d\n", s, k, s, l);
    return l;
}

ll count_groups(ll k)
{
    ll cnt = 0;
    for (ll s=1; s <= N; ++cnt)
    {
        ll l=s, r=N+1;   // exclude r
        for (ll i=1; r-l>1; ++i)
        {
            //ll mid = l + (r-l>>1);
            const ll mid = l+r >>1;
            if (query_iter(s, rt[mid]) <= k)
                l = mid;
            else
                r = mid;
        }
        s = l+1;
    }
    return cnt;
}

int main()
{
    scanf("%lld", &N);
    D = 64-__builtin_clzll(N);

    ll ns = get_ns();
    rt[0] = alc++;
    for (ll i=1; i<1<<D; ++i)
    {
        lc[i] = alc++;
        rc[i] = alc++;
        //lc[i] = i<<1;
        //rc[i] = i<<1|1;
    }
    //printf("init psegtree took %d mus\n", get_ns() - ns);
    ns = get_ns();

    for (ll i=1; i<=N; ++i)
    {
        rt[i] = rt[i-1];
        ll d; scanf("%d", &d);
        update(vis[d]+1, i, 1, rt[i]);  // FIX: fencepost typo--vis[d] +1 not just vis[d]
        vis[d] = i;
        //dump(rt[i]);
    }
    //printf("input took %d mus\n", get_ns() - ns);

    ll start_mus = get_ns();

    ll ans[MX] = {}, last_count = 0;
    ll k=1, groups;
    for (; k<=N; ++k)
    {
        groups = count_groups(k);
        ans[groups] ++;
        printf("added to %d\n", groups);
        if (last_count == groups) break;
        else last_count = groups;
    }
    ans[groups] -= 2;
    printf("found dupe at k=%d\n", k);
    for (--k; k<=N; ++k)
    {
        printf("binary searching for other end of %d (k %d)\n", groups, k);
        // binary search over k
        ll l=0, r=k+1;  // exclude r, so leave k as an option, TODO shouldn't be needed
        for (; l<r;)
        {
            ll mid = l+r>>1;
            printf("    %d..%d, mid %d has %d\n", l, r, mid, count_groups(mid));
            if (count_groups(mid) < groups)
                l = mid;
            else
                r = mid;
        }
        printf("binary search got %d\n", l);
        ans[groups] += k-l-1;
        k += k-l-1;
        printf("now k is %d\n", k);
        groups = count_groups(k);
    }

    for (ll k=N; k>0; --k)
    {
        for (ll i=0; i<ans[k]; ++i)
            printf("%lld ", k);
    }
    printf("\n");

    start_mus = get_ns() - start_mus;
    //printf("on average, each k took %d mus for a total of %d\n", start_mus / N, start_mus);

	return 0;
}

