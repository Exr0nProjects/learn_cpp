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
ll N, D, vis[MX], tmin[MX<<5], addt[MX<<5];
ll alc=1, lc[MX<<5], rc[MX<<5], rt[MX];

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
//        printf("%2d:%2d%+2d  ", k, tmin[k], addt[k], lc[k], rc[k]);
//        for (ll i=1; i<1<<d; ++i) printf("         ");
//    }
//    printf("\n");
//}

void dupe(ll &k)
{
    tmin[alc] = tmin[k];
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
    tmin[k] += addv;
}

void update(ll ql, ll qr, ll addv, ll &k, ll tl=1, ll tr=1<<D)
{
    if (qr < tl || tr < ql) return;
    if (ql <= tl && tr <= qr) return apply(addv, k, tl, tr);
    dupe(k); ll mid = tl + (tr-tl>>1);
    update(ql, qr, addv, lc[k], tl, mid);
    update(ql, qr, addv, rc[k], mid+1, tr);
    tmin[k] = min(tmin[lc[k]], tmin[rc[k]]) + addt[k];  // FIX: changed equ--combine with lazy add tag
}
ll get_next_group_part_3(ll kth, ll k, ll tl=1, ll tr=1<<D, ll acc=0)
{   // this works for min array. could've used delta arrays too and previous method
    //printf("get #%d @ %d(%d..%d)\n", kth, k, tl, tr);
    if (tl == tr) return tl;
    acc += addt[k];
    ll lmin = tmin[lc[k]] + acc;
    ll mid = tl + (tr-tl>>1);
    //printf("    min of %d..%d = %d, stepping %s\n", tl, mid, lmin, kth >= lmin ? "left" : "right");
    if (kth >= lmin)
        return get_next_group_part_3(kth, lc[k], tl, mid, acc);
    else
        return get_next_group_part_3(kth, rc[k], mid+1, tr, acc);
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
        //lc[i] = i<<1;
        //rc[i] = i<<1|1;
    }

    for (ll i=1; i<=N; ++i)
    {
        rt[i] = rt[i-1];
        ll d; scanf("%d", &d);
        update(vis[d]+1, i, 1, rt[i]);  // FIX: fencepost typo--vis[d] +1 not just vis[d]
        vis[d] = i;
        //dump(rt[i]);
    }

    for (ll k=1; k<=N; ++k)
    {
        ll cnt = 0;
        for (ll e=N; e>0; ++cnt)
        {
            ll got = get_next_group_part_3(k, rt[e]);
            e = got-1;
        }
        printf("%d\n", cnt);
    }
    printf("\n");

    //ll ans[MX] = {}, last_count = 0;
    //for (ll k=1; k<=N; ++k)
    //    ans[count_groups(k)] ++;
    ////ll k=1, groups;
    ////for (; k<=N; ++k)
    ////{
    ////    groups = count_groups(k);
    ////    ans[groups] ++;
    ////    //printf("added to %d\n", groups);
    ////    if (last_count == groups) break;
    ////    else last_count = groups;
    ////}
    ////ans[groups] -= 2;
    //////printf("found dupe at k=%d\n", k);
    ////for (--k; k<=N;)
    ////{
    ////    //printf("binary searching for other end of %d (k %d)\n", groups, k);
    ////    // binary search over k
    ////    ll l=k, r=N+1;  // exclude r, so leave k as an option, TODO shouldn't be needed
    ////    for (; l+1<r;)
    ////    {
    ////        ll mid = l+r>>1;
    ////        //printf("    %d..%d, mid %d has %d\n", l, r, mid, count_groups(mid));
    ////        if (count_groups(mid) < groups)
    ////            r = mid;
    ////        else
    ////            l = mid;
    ////    }
    ////    //printf("binary search got %d\n", l);
    ////    ans[groups] += l-k+1;
    ////    k = l+1;
    ////    //printf("now k is %d\n", k);
    ////    groups = count_groups(k);
    ////}
    ////
    //bool gone=0;
    //for (ll k=N; k>0; --k)
    //{
    //    for (ll i=0; i<ans[k]; ++i)
    //    {
    //        if (gone) printf(" ");
    //        else gone = 1;
    //        printf("%lld", k);
    //    }
    //}
    //printf("\n");
    //
	return 0;
}

