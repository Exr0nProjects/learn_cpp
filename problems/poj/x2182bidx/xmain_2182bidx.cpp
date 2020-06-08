/*
 * Problem 2182bidx (poj/2182bidx)
 * Create time: Mon 08 Jun 2020 @ 07:05 (PDT)
 * Accept time: Mon 08 Jun 2020 @ 07:26 (PDT)
 *
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
const int MX = 8111;

int N, arr[MX], bidx[MX];

int query(int l, int r)
{
	if (r < l) return 0;
	--l;
	int tot = 0;
	for (; r>l; r-=r&-r)
		tot += bidx[r];
	for (; l>r; l-=l&-l)
		tot -= bidx[l];
	return tot;
}

void update(int i, int v)
{
	for (; i<=N; i+=i&-i)
		bidx[i] += v;
}

int main()
{
	scanf("%d", &N);
	update(1, 1);
	for (int i=2; i<=N; ++i)
	{
		scanf("%d", &arr[i]);
		update(i, 1);
	}

	for (int i=N; i>0; --i)
	{

		int l=1, r=N+1; // inc exc; FIX: actually should be N+1 not i+1 (shouldn'tv changed it earlier)
		for (int b=0; b<60; ++b)
		{
			int m = (l+r)/2;
			if (query(1, m-1) <= arr[i])	// FIX: binary search comparator: le not lt
				l = m;
			else
				r = m;
		}
		update(l, -1);
		arr[i] = l;
	}

	for (int i=1; i<=N; ++i)
		printf("%d\n", arr[i]);

	return 0;
}

