/*
 * Problem 2182 (poj/2182)
 * Create time: Sun 07 Jun 2020 @ 13:14 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
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
const int MX = 8111;
ll N, arr[MX], ans[MX], delt[MX], pref[MX];

ll rprefix(ll bit[], int i)
{
	ll tot = 0;
	for (; i; i-=i&-i)
		tot += bit[i];
	return tot;
}

void rupdate(ll bit[], int i, ll v)
{
	for (; i<=N; i+=i&-i)
		bit[i] += v;
}

ll query(int l, int r)	// NOTE: techincally only need point query
{
	--l;
	ll tot = (ll)(r+1)*rprefix(delt, r) - rprefix(pref, r);
	tot -= (ll)(l+1)*rprefix(delt, l) - rprefix(pref, l);
	return tot;
}

void update(int l, int r, ll v)
{
	rupdate(delt, l, v);
	rupdate(delt, r+1, -v);
	rupdate(pref, l, (ll)l*v);
	rupdate(pref, r+1, (ll)(r+1)*-v);
}

int main()
{
	scanf("%d", &N);
	for (int i=2; i<=N; ++i)
	{
		int d; scanf("%d", &d);
		update(i, i, d);
	}

	//for (int i=1; i<=N; ++i) printf("%3d", query(i, i)); printf("\ninput complete\n");

	for (int k=1; k<=N; ++k)
	{
		//for (int i=1; i<=N; ++i) printf("%3d", query(i, i)); printf("\n");
		for (int i=N; i>0; --i)
			if (!ans[i] && !query(i, i))			// not processed and minimum
			{
				//printf("next min: %d\n", i);
				ans[i] = k;
				update(i+1, N, -1);
				break;
			}
	}

	for (int i=1; i<=N; ++i)
		printf("%d\n", ans[i]);

	return 0;
}

