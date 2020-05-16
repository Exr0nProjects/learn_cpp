/*
TASK: 1_poj2726
LANG: C++14
*/

/*
 * Problem 1_poj2726 (contests/dated/2020_05_04/1_poj2726)
 * Create time: Sat 16 May 2020 @ 12:27 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

void setIO(const std::string &name = "1_poj2726");

using namespace std;
const int MX = 10111;
int N, cost[MX], dist[MX], okay[MX];
vector<pair<int, int> > sortcost, sortdist;

void check(vector<pair<int, int> > &sorted, int update[])
{
	int mn = 1<<30;
	for (int i=0; i<sorted.size(); ++i)
	{
		if (mn > update[sorted[i].s])
			++okay[sorted[i].s];
		mn = min(mn, update[sorted[i].s]);
	}
}

int main()
{
	while (scanf("%d", &N) == 1)
	{
		if (!N) break;
		memset(cost, 0, sizeof cost);
		memset(dist, 0, sizeof dist);
		memset(okay, 0, sizeof okay);
		sortcost.clear();
		sortdist.clear();
		sortcost.reserve(N);
		sortdist.reserve(N);

		for (int i=0; i<N; ++i)
		{
			scanf("%d%d", &dist[i], &cost[i]);
			sortcost.pb(mp(cost[i], i));
			sortdist.pb(mp(dist[i], i));
		}
		sort(sortcost.begin(), sortcost.end());
		sort(sortdist.begin(), sortdist.end());

		check(sortcost, dist);
		check(sortdist, cost);

		int ret=0;
		for (int i=0; i<N; ++i)
			ret += okay[i]/2;	// +1 if == 2 :sunglasses:
		printf("%d\n", ret);
	}

    return 0;
}

