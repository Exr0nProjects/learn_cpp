/*
 * Problem 4_hdu4578 (contests/dated/2020_06_12/4_hdu4578)
 * Create time: Mon 15 Jun 2020 @ 14:23 (PDT)
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
const int MX = 100111;
//const int MOD = 1e9 +7;	// FIX: logic--i forgot mod exists
const int MOD = 10007;	// FIX: logic--i forgot mod exists
ll N, D, Q, segt[MX<<1][3], mult[MX<<1], addt[MX<<1];

void dump()
{
	//return;
	int d = D+1;
	for (int k=1; k<1<<1+D; ++k)
	{
		if (__builtin_popcount(k) == 1) { printf("\n"); --d; }
		printf("%3lld *%2lld +%2lld ", segt[k][0], mult[k], addt[k]);
		//printf("d %lld\n", d);
		for (int j=1; j<1<<d; ++j) printf("            ");
	}
	printf("\n");
}
inline void apply_tags(ll mulv, ll addv, ll tl, ll tr, ll k)	// FIX: logic--handle combos of tags, not just base mutual exclusives
{
	printf("        apply <%lld %lld> (%lld..%lld) to <%lld %lld> cur %lld\n", mulv, addv, tl, tr, mult[k], addt[k], segt[k][0]);
	mult[k] = mult[k] * mulv % MOD;	// FIX: equ--don't handle special mulv update if mult == 0, since set should just set, push to addt
	addt[k] = (addt[k] * mulv + addv) % MOD;	// TODO: modulo on tags might brick something

	//printf("            segt %lld\n", segt);

	if (addv == 0)	// TODO: both could mulv and addv exist
	{
		segt[k][0] *= mulv;
	}
	else
	{
		//printf("     uping. segt %lld\n", segt);
		const ll mod = addv		// FIX: typo--addv not addt
				* (tr-tl+1);	// FIX: equ--apply_tags shouldn't divide range by 2, that's push_down's job
		//printf("mod = %lld .. %lld -> %lld\n", tr, tl, tr-tl+1>>1);
		if (mulv)
			segt[k][0] += mod;
		else
			segt[k][0] = mod;
	}
	segt[k][0] %= MOD;
	printf("           => <%lld %lld> (%lld..%lld) to <%lld %lld> cur %lld\n\n", mulv, addv, tl, tr, mult[k], addt[k], segt[k][0]);
}

void apply_tags(int mulv, int addv, int tl, int tr, int k)
{
	mult[k] = mult[k] * mulv % MOD;
	addt[k] = (addt[k] * mulv + addv) % MOD;
	segt[k][0] = (segt[k][0] * mult[k] * (tr-tl+1>>1) + addt[k]) % MOD;
}
void push_down(ll k, ll tl, ll tr)
{
	if (mult[k] == 1 && addt[k] == 0) return;
	//printf("    push_down (%lld..%lld) @ %lld <%lld %lld>\n", tl, tr, k, mult[k], addt[k]);
	const ll lc = k<<1, rc=lc|1, mid=tl+(tr-tl>>1);

	//apply_tags(mult[k], addt[k], tl, mid, mult[lc], addt[lc], segt[lc]);
	//apply_tags(mult[k], addt[k], mid+1, tr, mult[rc], addt[rc], segt[rc]);	// FIX: typo--mid+1, tr not tl, mid+1 smah
	apply_tags(mult[k], addt[k], tl, mid, lc);
	apply_tags(mult[k], addt[k], mid+1, tr, rc);	// FIX: typo--mid+1, tr not tl, mid+1 smah
	mult[k] = 1; addt[k] = 0;	// FIX: reset current tags
	//printf("    end push_down\n");
}
//void push_down_inline(ll k, ll tl, ll tr)
//{
//    if (mult[k] == 1 && addt[k] == 0) return;
//    //printf("    push_down (%lld..%lld) @ %lld <%lld %lld>\n", tl, tr, k, mult[k], addt[k]);
//    const ll lc = k<<1, rc=lc|1, mid=tl+(tr-tl>>1);
//    const ll mod = addt[k] * (tr-tl+1>>1);
//
//    mult[lc] = mult[lc] * mult[k] % MOD;
//    addt[lc] = (addt[lc] * mult[k] + addt[k]) % MOD;
//
//    mult[rc] = mult[rc] * mult[k] % MOD;
//    addt[rc] = addt[rc] * mult[k] % MOD;
//    addt[rc] = (addt[rc] + addt[k]) % MOD;
//
//    if (addt[k] == 0)
//    {
//        segt[lc] *= mult[k];
//        segt[rc] *= mult[k];
//    }
//    else
//    {
//        //printf("     uping. segt %lld\n", segt);
//        //printf("mod = %lld .. %lld -> %lld\n", tr, tl, tr-tl+1>>1);
//        if (mult[k])
//        {
//            segt[lc] += mod;
//            segt[rc] += mod;
//        }
//        else
//        {
//            segt[lc] = segt[rc] = mod;
//        }
//    }
//    segt[lc] %= MOD;
//    segt[rc] %= MOD;
//}
void collect(ll k, ll tl, ll tr)
{
	segt[k][0] = segt[k<<1][0] + segt[k<<1|1][0];
	//printf("collected %lld + %lld = %lld\n", segt[k<<1], segt[k<<1|1], segt[k]);
}
void update(ll ql, ll qr, ll mulv, ll addv, ll k=1, ll tl=1, ll tr=1<<D)
{
	//printf("    update(%lld..%lld *%lld +%lld) @ %lld (%lld..%lld)\n", ql, qr, mulv, addv, k, tl, tr);
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr)
	{
		//dump();
		//mult[k] = mult[k] * mulv % MOD;
		//addt[k] = (addt[k] * mulv + addv) % MOD;
        //
		//if (addv == 0)
		//{
		//    segt[k][0] *= mulv;
		//}
		//else
		//{
		//    const ll mod = addv	* (tr-tl+1);
		//    if (mulv)
		//        segt[k][0] += mod;
		//    else
		//        segt[k][0] = mod;
		//}
		//segt[k] %= MOD;

		apply_tags(mulv, addv, tl, tr, k);
		return;
	}
	push_down(k, tl, tr);
	ll mid = tl + (tr-tl>>1);	// FIX: typo--tl + ... not lc + ...
	update(ql, qr, mulv, addv, k<<1, tl, mid);
	update(ql, qr, mulv, addv, k<<1|1, mid+1, tr);
	collect(k, tl, tr);
}
ll query(ll ql, ll qr, int p, ll k=1, ll tl=1, ll tr=1<<D)
{
	//printf("    query(%lld..%lld) @ %lld (%lld..%lld : %d)\n", ql, qr, k, tl, tr, segt[k][p]);
	if (qr<tl || tr<ql) return 0;
	if (ql<=tl && tr<=qr) return segt[k][p];
	push_down(k, tl, tr);
	ll mid = tl + (tr-tl>>1);
	return query(ql, qr, p, k<<1, tl, mid) + query(ql, qr, p, k<<1|1, mid+1, tr) % MOD;
}

int main()
{
	while (~scanf("%lld%lld", &N, &Q))
	{
		if (!N && !Q) break;
		memset(segt, 0, sizeof segt);
		memset(mult, 0, sizeof mult);
		memset(addt, 0, sizeof addt);
		D = log2(N)+1;
		for (int k=1; k<1<<1+D; ++k) mult[k] = 1;	// FIX: default mult to 1 not 0, which means set
		dump();

		for (int i=0; i<Q; ++i)
		{
			ll c, l, r, v;
			scanf("%lld%lld%lld%lld", &c, &l, &r, &v);
			if (c == 1) update(l, r, 1, v);
			if (c == 2) update(l, r, v, 0);
			if (c == 3) update(l, r, 0, v);
			if (c == 4) printf("%lld\n", query(l, r, v-1) % MOD);
			dump();
		}
	}

	//scanf("%lld%lld", &N, &Q);
	//D = log2(N)+1;
	//for (int k=1; k<1<<1+D; ++k) mult[k] = 1;	// FIX: default mult to 1 not 0, which means set
	////dump();
	//for (ll i=0; i<N; ++i)						// FIX: iter indexing--was 1..N for update, now 0..N-1 for direct build
	//    scanf("%lld", &segt[(1<<D)+i]);
	//for (int k=(1<<D)-1; k; --k)				// FIX: optimization--build tree in O(N)
	//    segt[k] = segt[k<<1] + segt[k<<1|1];
	////dump();
    //
	//for (int q=0; q<Q; ++q)
	//{
	//    //printf("uhhhh $ ");
	//    ll c, l, r;						// FIX: typo--ll not int smah (wrote int after deciding to convert to ll)
	//    scanf("%lld%lld%lld", &c, &l, &r);
	//    //printf("%lld %lld %lld\n", c, l, r);
	//    if (c == 4) printf("%lld\n", query(l, r)%MOD);
	//    else
	//    {
	//        ll v; scanf("%lld", &v);	// FIX: typo--ll not int smah (wrote int after deciding to convert to ll)
	//        //printf("and %lld, soo      %lld..%lld mod %lld\n", v, l, r, v);
	//        if (c == 1) update(l, r, 1, v);
	//        if (c == 2) update(l, r, v, 0);
	//        if (c == 3) update(l, r, 0, v);
	//    }
	//    //dump();
	//}

	return 0;
}

