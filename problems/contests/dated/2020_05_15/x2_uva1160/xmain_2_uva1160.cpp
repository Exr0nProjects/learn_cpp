/*
TASK: 2_uva1160
LANG: C++14
*/

/*
 * Problem 2_uva1160 (contests/dated/2020_05_15/2_uva1160)
 * Create time: Mon 25 May 2020 @ 10:29 (PDT)
 * Accept time: Mon 25 May 2020 @ 10:46 (PDT)
 *
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
int djs[MX], djf[MX];
void init()
{
	for (int i=0;i <MX; ++i)
	{
		djs[i] = 1;
		djf[i] = i;
	}
}
int find(int n)
{
	if (djf[n] != n) djf[n] = find(djf[n]);
	return djf[n];
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (djs[a] < djs[b]) swap(a, b);
	djs[a] += b;
	djf[b] = a;
}

int main()
{
	int a, b, tot=0;
	init();
	while (scanf("%d", &a) == 1)
	{
		if (a < 0)
		{
			printf("%d\n", tot);
			tot=0;
			init();
			scanf("%d", &a);
		}
		scanf("%d", &b);
		//printf("find(%d)=%d find(%d)=%d\n", a, find(a), b, find(b));
		if (find(a) == find(b)) ++tot;
		else merge(a, b);
	}

    return 0;
}

