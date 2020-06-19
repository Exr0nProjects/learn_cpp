/*
 * Problem 4 (contests/2020summer401/2/4)
 * Create time: Fri 19 Jun 2020 @ 11:16 (PDT)
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
const ll MX = 100111;
ll N, K, req[MX], hav[MX];

bool check(ll num)	// FIX: ll num not int
{
	ll need=0;
	for (ll i=0; i<N && need <= K; ++i)
		need += hav[i] - num*req[i];
	printf("need %lld\n", need);
	return need <= K;
}

int main()
{
	scanf("%lld%lld", &N, &K);
	for (ll i=0; i<N; ++i)
		scanf("%lld", &req[i]);
	for (ll i=0; i<N; ++i)
		scanf("%lld", &hav[i]);

	ll l=0, r=(ll)1<<20;
	for (ll i=0; i<70; ++i)
	{
		printf("%lld..%lld\n", l, r);
		ll mid = l + (r-l>>1);
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%lld\n", l);

	return 0;
}

