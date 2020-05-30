// 30 May 2020

#include <iostream>
#define ll long long
const int MX = 10000;

ll N, bidx[MX];
void update(ll i, ll v);
void build()
{
	scanf("%lld", &N);
	memset(bidx, 0, sizeof bidx);
	//for (int i=1; i<=N; ++i)		// FIX: one indexed
	//    scanf("%lld", &bidx[i]);
	//// TODO: ^^^^^^^^^^^^^^^^^^^ that without another array
	for (int i=1; i<=N; ++i)
	{
		int t;
		scanf("%d", &t);
		update(i, t);
	}
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
	for (; r>l; r-=r&-r)	// TODO: don't go all the way down to zero
		tot += bidx[r];
	for (; l!=r; l-=l&-l)
		tot -= bidx[l];
	return tot;
}
void update(ll i, ll v)
{
	for (; i<=N; i+=i&-i)	// FIX: i<=N not just i, since i goes up
		bidx[i] += v;
}
void dump()
{
	for (int i=1; i<=N; ++i)
		printf("%3lld", bidx[i]);
	printf("\n");
	// TODO: print the tree structure
}

int main()
{
	build();
	while (1)
	{
		char c = ' '; while (c < 'a' || c > 'z') scanf("%c", &c);
		int a, b; scanf("%d%d", &a, &b);
		if (c == 'q')
			printf("%lld\n", query(a, b));
		if (c == 'u')
			update(a, b);
		dump();
	}
}

