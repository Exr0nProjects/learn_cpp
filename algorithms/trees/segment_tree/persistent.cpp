// persistent segtree 1, 17 june 2020
#include <iostream>
#include <cstring>

#define ll long long
using namespace std;

const ll MX = 100111;
ll N, D, M, segt[MX<<6], addt[MX<<6], lc[MX<<6], rc[MX<<6];

void apply(ll addv, ll k, ll tl, ll tr)
{
	addt[k] += addv;
	segt[k] += addv * (tr-tl+1);
}
void push(ll k, ll tl, ll tr)
{
	if (!addt[k]) return;
	ll mid = tl + (tr-tl>>1);
	apply(addt[k], lc[k], tl, mid);
	apply(addt[k], rc[k], mid+1, tr);
	addt[k] = 0;
}
void comb(ll k)
{
	segt[k] = segt[lc[k]] + segt[rc[k]];
}

void update(ll ql, ll qr, ll v, ll k=1, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr) return apply(v, k, tl, tr);
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	update(ql, qr, v, lc[k], tl, mid);
	update(ql, qr, v, rc[k], mid+1, tr);
	comb(k);
}
ll query(ll ql, ll qr, ll k=1, ll tl=1, ll tr=1<<D)
{
	if (qr<tl || tr<ql) return 0;
	if (ql <= tl && tr <= qr) return segt[k];
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	return query(ql, qr, lc[k], tl, mid) + query(ql, qr, lc[k], mid+1, tr);
}
