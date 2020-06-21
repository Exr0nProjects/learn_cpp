/*
 * Problem 4 (contests/2020summer401/3/4)
 * Create time: Sat 20 Jun 2020 @ 17:21 (PDT)
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
const ll MX = -1;

ll digits(ll n)
{
	ll tot=0;
	tot += min(n, 9LL);
	if (n > 9) tot += (min(n, 99LL)-9) * 2;
	if (n > 99) tot += (min(n, 999LL)-99) * 3;
	return tot;
}

int main()
{

	while (1)
	{
		ll d; scanf("%lld", &d);
		printf("%lld\n", digits(d));
	}

	return 0;
}

