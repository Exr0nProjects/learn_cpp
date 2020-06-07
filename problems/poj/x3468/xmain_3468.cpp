/*
 * Problem 3468 (poj/3468)
 * Create time: Sat 06 Jun 2020 @ 14:26 (PDT)
 * Accept time: Sun 07 Jun 2020 @ 13:29 (PDT)
 * helpful link: https://kartikkukreja.wordpress.com/2013/12/02/range-updates-with-bit-fenwick-tree/
 */

#include <iostream>
#include <cstring>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 1000111;
ll N, Q, delt[MX], pref[MX];

ll raw_prefix(ll bit[], int n)
{
	ll tot = 0;	// FIX: smah, missing ll here
	for (; n; n-=n&-n)
		tot += bit[n];
	return tot;
}

void raw_update(ll bit[], int n, ll v)
{
	for (; n<=N; n+=n&-n)
		bit[n] += v;
}

ll query(int l, int r)
{
	--l;
	// TODO: understand this algebraic magic
	ll tot = (ll)((ll)r+1LL)*(ll)raw_prefix(delt, r) - (ll)raw_prefix(pref, r);
	tot -= (ll)((ll)l+1LL)*(ll)raw_prefix(delt, l) - (ll)raw_prefix(pref, l);
	return (ll)tot;
}

void update(int l, int r, ll v)
{
	raw_update(delt, l, v);
	raw_update(delt, r+1, -v);			// +1 cuz thats the delta between arr[r] and arr[r+1]
	raw_update(pref, l, l*v);			// pref[i] = i*delt[i], TODO: why multiply?
	raw_update(pref, r+1, (r+1)*-v); 	// "undo" previous line
}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i=0; i<N; ++i)
	{
		ll t; scanf("%lld", &t);
		update(i+1, i+1, t);
	}

	for (int i=0; i<Q; ++i)
	{
		char c = ' '; while (c < 'A' || c > 'Z') scanf("%c", &c);
		int l, r; scanf("%d%d", &l, &r);
		if (c == 'Q') printf("%lld\n", query(l, r));
		if (c == 'C')
		{
			ll d; scanf("%lld", &d);
			update(l, r, d);
		}
		//dump();
	}

	return 0;
}

