/*
 * Problem 4 (contests/2020summer401/3/4)
 * Create time: Sat 20 Jun 2020 @ 17:21 (PDT)
 * Accept time: Sat 20 Jun 2020 @ 20:41 (PDT)
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

int main()
{

	ll d; scanf("%lld", &d);
	ll base=1, len = 1, add=0;
	for (; len <= d; ++base)
	{
		add += (ll)log10(base) + 1;
		//printf("%3lld added on %3lld\n", base, add);
		len += add;
		//printf("len = %lld\n", len);
	}
	----base; len-=add; --len;
	//printf("base %lld, len %lld\n", base, len);

	ll pad=1;
	for (; len<d; ++pad)
	{
		len += (ll)log10(pad)+1;
	}
	--pad;
	//printf("pad %lld len %lld\n", pad, len);

	while (len > d) --len, pad /= 10;

	printf("%lld\n", pad%10);

	return 0;
}

