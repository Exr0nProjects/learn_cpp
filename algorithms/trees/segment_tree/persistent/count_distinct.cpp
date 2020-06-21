// persistent segtree to count distinct numbers in a range
// Sun 21 Jun 2020 @ 10:33 (PDT)

#include <iostream>
#include <numeric>
#define ll long long
using namespace std;

const ll MX = 100111;
ll N, D, Q, vis[MX], segt[MX<<6], addt[MX<<6];
ll alc=1, lc[MX<<6], rc[MX<<6], rt[MX];

void dupe(ll &k)
{
	segt[alc] = segt[k];
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
	segt[k] += addv * (tl-tr+1);
}
void push(ll &k, ll tl, ll tr)
{
	ll mid = tl + (tr-tl>>1);
	apply(addt[k], lc[k], tl, mid);
	apply(addt[k], rc[k], mid+1, tr);
	addt[k] = 0;
}
void comb(ll k)
{
	segt[k] = segt[lc[k]], segt[rc[k]];
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
ll query(ll q, ll k, ll tl=1, ll tr=1<<D)
{
	if (q < tl || q > tr) return 0;
	if (tl == tr) return segt[k];
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	if (q <= mid) return query(q, lc[k], tl, mid);
	else return query(q, rc[k], mid+1, tr);
}

int main()
{
	scanf("%lld%lld", &N, &Q);

	D = log2(N) +1;
	rt[0] = alc++;
	for (ll i=1; i<1<<D; ++i)
	{
		lc[i] = alc++;
		rc[i] = alc++;
	}

	for (ll i=1; i<=N; ++i)
	{
		ll d; scanf("%lld", &d);
		rt[i] = rt[i-1];
		printf("updating %d @ %d: %d..%d\n", d, i, vis[d]+1, i);
		update(vis[d]+1, i, 1, rt[i]);
		vis[d] = i;
	}
	for (ll i=0; i<Q; ++i)
	{
		ll l, r; scanf("%lld%lld", &l, &r);
		printf("%lld\n", query(l, rt[r]));
	}
}
