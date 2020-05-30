// 30 May 2020

const int MX = 10000;
ll N, bidx[MX];
void build()
{
	scanf("%lld", &N);
	memset(bidx, 0, sizeof bidx);
	for (int i=1; i<=N; ++i)		// FIX: one indexed
		scanf("%lld", &bidx[i]);
	// TODO: ^^^^^^^^^^^^^^^^^^^ that without another array
}
ll prefix(ll idx)
{
	ll tot=0;
	for(; idx; idx -= idx&-idx)
		tot += bidx[idx];
	return tot;
}
ll query(ll l, ll r) // inc inc
{
	--l;							// ensure include left
	ll tot = 0;
	for (; r; r-=r&-r)	// TODO: don't go all the way down to zero
		tot += bidx[r];
	for (; l; l-=l&-l)
		tot -= bidx[l];
	return tot;
}
void update(ll i, ll v)
{
	for (; i<=N; i+=i&-i)	// FIX: i<=N not just i, since i goes up
		bidx[i] += v;
}

