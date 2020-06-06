/*
 * Problem 3468 (poj/3468)
 * Create time: Sat 06 Jun 2020 @ 14:26 (PDT)
 * Accept time: [!meta:end!]
 * helpful link: https://kartikkukreja.wordpress.com/2013/12/02/range-updates-with-bit-fenwick-tree/
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 100111;
ll N, Q, arr[MX], delt[MX], pref[MX];

ll raw_prefix(ll bit[], int n)
{
	int tot = 0;
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
	ll tot = (l+1)*raw_prefix(delt, l) - raw_prefix(pref, l);
	tot -= (r+1)*raw_prefix(delt, r) - raw_prefix(pref, r);
	return tot;
}

void update(int l, int r, int v)
{
	raw_update(delt, l, v);
	raw_update(delt, r+1, -v);			// +1 cuz thats the delta between arr[r] and arr[r+1]
	raw_update(pref, l, l*v);			// pref[i] = i*delt[i], TODO: why multiply?
	raw_update(pref, r+1, (r+1)*-v); 	// "undo" previous line
}

//void update(int l, int r, int v)
//{
//    for (; l<=N; l+=l&-l)
//        delt[l] += v;
//    for (; r<=N; r+=r&-r)
//        delt[r] -= v;
//}

//void dump()
//{
//    for (int i=0; i<N; ++i)
//        printf("%3d", arr[i]);
//    printf("\n");
//}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i=0; i<N; ++i)
	{
		scanf("%d", &arr[i]);
		if (i) delt[i] = arr[i] - arr[i-1];
		else delt[i] = arr[i];
		pref[i] = i*delt[i];
	}

	for (int i=0; i<Q; ++i)
	{
		char c = ' '; while (c < 'A' || c > 'Z') scanf("%c", &c);
		int l, r; scanf("%d%d", &l, &r);
		if (c == 'Q') printf("%lld\n", query(l, r));
		if (c == 'C')
		{
			int d; scanf("%d", &d);
			update(l, r, d);
		}
		//dump();
	}

	return 0;
}

