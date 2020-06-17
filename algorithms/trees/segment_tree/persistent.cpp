// persistent segtree 1, 17 june 2020
#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

#define ll long long
using namespace std;

const ll MX = 100111;
ll N, D, M, segt[MX<<6], addt[MX<<6];
ll alloc=1, root[MX], lc[MX<<6], rc[MX<<6];

void dump(ll k)
{
	ll d = D+1;
	queue<int> bfs;
	bfs.push(k);
	for (int i=1; i<1<<1+D; ++i)
	{
		if (__builtin_popcount(i) == 1) { --d; printf("\n"); }
		k = bfs.front(); bfs.pop();
		bfs.push(lc[k]);
		bfs.push(rc[k]);

		printf("%2d: %2d +%-2d(%-2d %2d) ", k, segt[k], addt[k], lc[k], rc[k]);
		for (int i=1; i<1<<d; ++i) printf("                  ");
	}
}
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

void dupe(ll &k)
{
	lc[alloc] = lc[k];
	rc[alloc] = rc[k];
	k = alloc++;
}

void update(ll ql, ll qr, ll v, ll &k, ll tl=1, ll tr=1<<D)
{	// TODO: wait, this is range update not point, does it still work?
	if (qr < tl || tr < ql) return;
	dupe(k);
	if (ql <= tl && tr <= qr) return apply(v, k, tl, tr);
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	update(ql, qr, v, lc[k], tl, mid);
	update(ql, qr, v, rc[k], mid+1, tr);
	comb(k);
}
ll query(ll ql, ll qr, ll k, ll tl=1, ll tr=1<<D)
{
	if (qr<tl || tr<ql) return 0;
	if (ql <= tl && tr <= qr) return segt[k];
	push(k, tl, tr); ll mid = tl + (tr-tl>>1);
	return query(ql, qr, lc[k], tl, mid) + query(ql, qr, lc[k], mid+1, tr);
}

int main()
{
	scanf("%d%d", &N, &M);
	D = log2(N)+1;

	// FIX: init the storage
	root[0] = alloc++;	// 1 indexed for consistency
	for (int i=1; i<1<<D; ++i)
	{
		lc[i] = alloc++;
		rc[i] = alloc++;
	}

	for (int i=1; i<=M; ++i)
	{
		dump(root[i-1]); printf("\n\nt = %d $ ", i);
		root[i] = root[i-1];
		int c, l, r, v;
		scanf("%d%d%d%d", &c, &l, &r, &v);
		if (c == 1) update(l, r, v, root[i]);
		if (c == 2) printf("%d\n", query(l, r, root[v]));
	}
}
