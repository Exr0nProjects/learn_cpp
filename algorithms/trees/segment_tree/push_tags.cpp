// codechef addmul
#include <iostream>
#include <cstring>
#include <cmath>

#define ll long long

using namespace std;
const int MX = 100111;
const ll MOD = 1e9 + 7;
ll N, D, M, segt[MX<<2], mult[MX<<2], addt[MX<<2]; // multiplication then addition, set is encoded as *=0

void apply(ll mulv, ll addv, ll k, ll tl, ll tr)
{	// update all tags and accumulator arrays for the child
	mult[k] = mult[k] * mulv % MOD;
	addt[k] = (addt[k] * mulv + addv) % MOD;
	segt[k] = (segt[k] * mulv + addv * (tr-tl+1)) % MOD;
}
void push(ll k, ll tl, ll tr)
{	// check if tags[k] exists, apply tags[k] to each child, then reset tags[k]
	if (mult[k] == 1 && !addt[k]) return; // empty tag
	const ll mid = tl + (tr-tl>>1);
	apply(mult[k], addt[k], k<<1, tl, mid);
	apply(mult[k], addt[k], k<<1|1, mid+1, tr);
	mult[k] = 1; addt[k] = 0;
}
void comb(ll k, ll tl, ll tr)
{	// update accumulator arrays based on children
	segt[k] = (segt[k<<1] + segt[k<<1|1]) % MOD;
}

void update(ll ql, ll qr, ll mulv, ll addv, ll k=1, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr) { apply(mulv, addv, k, tl, tr); return; }
	push(k, tl, tr);
	const ll mid = tl + (tr-tl>>1);
	update(ql, qr, mulv, addv, k<<1, tl, mid);
	update(ql, qr, mulv, addv, k<<1|1, mid+1, tr);
	comb(k, tl, tr);
}
ll query(ll ql, ll qr, ll k=1, ll tl=1, ll tr=1<<D)
{
	if (qr < tl || tr < ql) return 0;
	if (ql <= tl && tr <= qr) return segt[k];
	push(k, tl, tr);
	const ll mid = tl + (tr-tl>>1);
	return (query(ql, qr, k<<1, tl, mid) + query(ql, qr, k<<1|1, mid+1, tr)) % MOD;
}

int main()
{
	scanf("%d%d", &N, &M);
	D = log2(N)+1;
	for (int k=1; k<1<<D; ++k) mult[k] = 1;
	for (int i=1; i<=N; ++i)
	{
		int d; scanf("%d", &d);
		update(i, i, 0, d);
	}
	for (int i=0; i<M; ++i)
	{
		int c, l, r; scanf("%d%d%d", &c, &l, &r);
		if (c == 4) { printf("%d\n", query(l, r) % MOD); continue; }
		else
		{
			int v; scanf("%d", &v);
			if (c == 1) update(l, r, 1, v);
			if (c == 2) update(l, r, v, 0);
			if (c == 3) update(l, r, 0, v);
		}
	}
}

