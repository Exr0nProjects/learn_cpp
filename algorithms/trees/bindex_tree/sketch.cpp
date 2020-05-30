// trying to piece together a binary index tree

const int MX = 1000;
int N, bidx[MX];

void build()
{
	// clears
	// TODO: is this max efficiency?
	int temp[MX] = {};
	for (int i=0; i<N; ++i)
	{
		scanf("%d", &temp[i]);
		if (i) temp[i] += temp[i-1];
		bidx[i] = temp[i] - temp[i&-1];
	}
}
int query_bad(ll l, ll r)
{
	ll ret = 0;
	for (; r; r -= r&-r)
		ret += bidx[r];
	for (; l; l -= l&-l)
		ret -= bidx[l];
	return ret;
}
void update(ll i, ll v)
{
	for (; i<(N+(N&-N)); i += i&-i)
		bidx[i] += v;
}
