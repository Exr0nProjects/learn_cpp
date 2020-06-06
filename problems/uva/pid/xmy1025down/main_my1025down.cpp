/*
TASK: my1025down
LANG: C++14
*/

/*
 * Problem my1025down (oj/pid/my1025down)
 * Create time: Sun 05 Apr 2020 @ 10:13 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstring>
#include <unordered_set>
#include <algorithm>

#define ll long long

using namespace std;
const int MX = 61;
const int MT = 210;
ll N, T, memo[MX][MT]; // FIX: make sure memo is large enough! different dimension sizes!
ll dist[MX], pref[MX]; // pref[i] (prefix dist)= time to get from first station to [i]
unordered_set<ll> first, last; // train departures

ll op(const ll i, const ll t) // N^2 log N
{
    if (memo[i][t] > 0) return memo[i][t];
    if (!i && !t) return 0;
    if (t <= 0) return 1<<30;

    ll ret = 1<<30;
    // from trains
    if (i && first.count(t-pref[i])) // not at first station && exists a train from first station : arrives here now
	ret = min(ret, op(i-1, t-dist[i]));
    if (i < N-1 && last.count(t-pref[N-1]+pref[i])) // not at last station && exists train from last : arrives here now
	ret = min(ret, op(i+1, t-dist[i+1]));
    // waited at this station
    ret = min(ret, op(i, t-1)+1);

    memo[i][t] = ret;
    return ret;
}

int main()
{
    int kase=0;
    while (scanf("%d%d", &N, &T) == 2)
    {
	if (!N) break;
	// clears
	for (int i=0; i<MX; ++i) for (int j=0; j<MT; ++j) memo[i][j] = -1;
	memset(dist, 0, sizeof dist);
	memset(pref, 0, sizeof pref);
	first.clear();
	last.clear();
	
	// input
	for (ll i=1; i<N; ++i)
	{
	    scanf("%d", &dist[i]);
	    pref[i] = dist[i] + pref[i-1];
	}
	int m, dep;
	scanf("%d", &m);
	for (ll i=0; i<m; ++i)
	{
	    scanf("%d", &dep);
	    first.insert(dep);
	}
	scanf("%d", &m);
	for (ll i=0; i<m; ++i)
	{
	    scanf("%d", &dep);
	    last.insert(dep);
	}

	// top down
	ll ret = op(N-1, T);

	// output
	++kase;
	printf("Case Number %d: ", kase);
	if (ret < 1<<30)
	    printf("%d\n", ret);
	else
	    printf("impossible\n");
    }

    return 0;
}

/*
12 200
1 5 5 6 7 8 9 10 11 13 19
11
1 26 36 71 88 90 97 99 143 147 171
15
1 38 62 68 83 88 129 130 133 134 139 141 168 178 190
0
=> 16
*/
