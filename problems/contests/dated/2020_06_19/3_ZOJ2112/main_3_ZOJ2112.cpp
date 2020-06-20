/*
 * Problem 3_ZOJ2112 (contests/dated/2020_06_19/3_ZOJ2112)
 * Create time: Sat 20 Jun 2020 @ 09:22 (PDT)
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
const ll MX = 50111;
ll N, D, Q;
ll alloc=1, segt[MX<<6], addt[MX<<6], lc[MX<<6], rc[MX<<6], rt[MX];
void dupe(ll &k)
{
	segt[alloc] = segt[k];
	addt[alloc] = addt[k];
	lc[alloc] = lc[k];
	rc[alloc] = rc[k];
	k = alloc++;
}
void apply(ll addv, ll &k, ll tl, ll tr)
{
	if (!addv) return;
	dupe(k);
	addt[k] = addv;
	segt[k] += addv * (tr-tl+1);
}
void push(ll &k, ll tl, ll tr)
{
	dupe(k);
	ll mid = tl + (tr-tl>>1);
	apply(addt[k], lc[k], tl, mid);
	apply(addt[k], rc[k], mid+1, tr);
	addt[k] = 0;
}
void comb(ll k)
{
	segt[k] = segt[lc[k]] + segt[rc[k]];
}

void update(ll ql, ll qr, ll addv, ll &k, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr) return apply(addv, k, tl, tr);
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	update(ql, qr, addv, lc[k], tl, mid);
	update(ql, qr, addv, rc[k], mid+1, tr);
	comb(k);
}
//ll query(ll ql, ll qr, ll k, ll tl=1, ll tr=1<<D, ll setv=-1)
//{
//    if (qr < tl || tr < ql) return;
//    if (setv < 0) setv = sett[k];
//    if (ql <= tl && tr <= qr) return setv < 0 ? segt[k] : setv*(tr-tl+1);
//    ll mid = tl + (tr-tl>>1);
//    return query(ql, qr, lc[k], tl, mid, setv)
//         + query(ql, qr, rc[k], mid+1, tr, setv);
//}
ll querykth(ll k1, ll k2, ll kth, ll tl=1, ll tr=1<<D)
{
	if (tl == tr) return tl;
	push(k1, tl, tr); push(k2, tl, tr);
	ll mid = tl + (tr-tl>>1);
	ll lsize = segt[lc[k2]] - segt[lc[k1]];
	if (lsize >= kth)
		return querykth(lc[k1], lc[k2], kth, tl, mid);
	else
		return querykth(lsize, mid+1, tr);
}

int main()
{
	int T; scanf("%lld", &T);
	while (T--)
	{
		scanf("%lld%lld", &N, &Q);
		D = log2(N) +1;
		memset(segt, 0, sizeof segt);
		memset(addt, 0, sizeof addt);
		memset(lc, 0, sizeof lc);
		memset(rc, 0, sizeof rc);
		memset(rt, 0, sizeof rt);

		rt[0] = alloc ++;
		for (ll k=1; k<1<<1+D; ++k)
		{
			lc[k] = alloc++;
			rc[k] = alloc++;
		}
		for (ll i=1; i<=N; ++i)
		{
			ll d; scanf("%lld", &d);
			rt[i] = rt[i-1];
			update(d+1, d+1, 1, rt[i]);
		}

		for (ll i=0; i<Q; ++i)
		{
			char c=0; scanf("\n%c", &c);
			ll l, r; scanf("%lld%lld", &l, &r);
			if (c == 'Q')
			{
				ll v; scanf("%lld", &v);
				printf("%lld\n", querykth(l, r, v));
			}
			else if (c == 'C')
			{
				//update(l, l, r, );
				// TODO
			}
			else printf("got char '%c'\n", c);
		}
	}
	return 0;
}

