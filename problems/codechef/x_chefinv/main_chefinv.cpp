/*
 * Problem chefinv (codechef/chefinv)
 * Create time: Fri 15 Jan 2021 @ 16:33 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
#define f first
#define s second
using namespace std;

const ll MX = 2e5+10;

ll N, M, arr[MX];
ll tsum[MX<<6], lc[MX<<6], rc[MX<<6], rt[MX], tcnt=0;
void dupe(ll &k)
{
	tsum[++tcnt] = tsum[k];
	lc[tcnt] = lc[k];
	rc[tcnt] = rc[k];
	k = tcnt;
}
// void push not needed bc only point updates
// void apply(ll &k, ll tl, ll tr);
void update(ll q, ll v, ll &k, ll tl=1, ll tr=N)
{
	if (q < tl || q > tr) return;
	dupe(k);
	// db("    update %lld <- %lld at %lld (%lld..%lld)\n", q, v, k, tl, tr);
	if (tl == tr) return tsum[k] += v, void();
	ll mid = tl + ((tr-tl)>>1);
	if (q <= mid) update(q, v, lc[k], tl, mid);
	else update(q, v, rc[k], mid+1, tr);
	tsum[k] = tsum[lc[k]] + tsum[rc[k]];
}
ll query(ll ql, ll qr, ll k1, ll k2, ll tl=1, ll tr=N)
{
	if (qr < tl || tr < ql) return 0;
	// db("    query %lld, %lld @ %lld, %lld (%lld..%lld) (%lld)\n", ql, qr, k1, k2, tl, tr, tsum[k2]-tsum[k1]);
	if (ql <= tl && tr <= qr) return tsum[k2]-tsum[k1];
	// dupe(k1); dupe(k2);
	ll mid = tl + ((tr-tl)>>1);
	return query(ql, qr, lc[k1], lc[k2], tl, mid)
		+  query(ql, qr, rc[k1], rc[k2], mid+1, tr);
}

void dump(ll k)
{
	ll q[MX], dep[MX], ql=1, qr=0; ll pdep = 3;
	for (q[++qr%=MX] = k, dep[qr] = pdep; ql-1!=qr; ++ql) {
		k = q[ql]; ll d = dep[ql];
		if (d != pdep) db("\n"); pdep = d;
		// db("%3d (%-2d %2d)  ", tsum[k], lc[k], rc[k]);
		for (int i=0; i<(1<<d); ++i) db("             ");
		if (lc[k]) q[++qr%=MX] = lc[k], dep[qr] = d-1;
		if (rc[k]) q[++qr%=MX] = rc[k], dep[qr] = d-1;
	}
}

map<ll, ll> desc;
ll bit[MX];
ll bq(ll x)
{
	ll ans = 0;
	for (; x; x-=x&-x) ans += bit[x];
	return ans;
}
void bu(ll x, ll v)
{
	for (; x<=N; x+=x&-x) bit[x] += v;
}

int main()
{
	// N = 10;
	// ll rt = 1, alwayszero=0;
	// while (true) {
	// 	ll t, k, v; scanf("%lld%lld%lld", &t, &k, &v);
	// 	if (t == 1) update(k, v, rt);
	// 	else printf("-> %lld\n", query(k, v, alwayszero, rt));
	// }
	scanf("%lld%lld", &N, &M);
	for (int i=1; i<=N; ++i) scanf("%lld", arr+i);
	// descretize
	for (int i=1; i<=N; ++i) desc[arr[i]] = 0;
	ll cnt=0; for (auto &p : desc) p.s = ++cnt;
	for (int i=1; i<=N; ++i) arr[i] = desc[arr[i]];
	// db("descretized: "); for (int i=1; i<=N; ++i) db("%3lld", arr[i]); db("\n");
	// count inversions
//eeee
	ll invs = 0;
	for (int k=N; k; --k) {
		invs += bq(arr[k]-1);
		bu(arr[k], 1);
	}
	// db("total inversions = %lld\n", invs);
	// init PST
	rt[0] = 0;
	for (int i=1; i<=N; ++i) rt[i] = rt[i-1], update(arr[i], 1, rt[i])
		                         // , dump(rt[i]), db("\nrt[1] = %lld\n=====================\n", rt[1])
		                        ;
	// answer queries
	for (int i=1; i<=M; ++i) {
		ll a, b; scanf("%lld%lld", &a, &b);
		// db("got %lld %lld\n", a, b);
		if (arr[a] == arr[b]) { printf("%lld\n", invs); continue; }
		ll ans = 0, sign = -1;
		if (arr[a] < arr[b]) sign = 1;
		// db("rt[1] = %d\n", rt[1]);
		ll lab = max(arr[a], arr[b]), sab = min(arr[a], arr[b]);
		ll mid = query(sab+1, lab-1, rt[a], rt[b-1]);
		ll lo = query(arr[a], arr[a], rt[a], rt[b-1]);
		ll hi = query(arr[b], arr[b], rt[a], rt[b-1]);
		// db("got %lld, 2*%lld, %lld\n", lo, mid, hi);
		printf("%lld\n", invs + sign + sign*(lo+2*mid+hi));
	}
}
