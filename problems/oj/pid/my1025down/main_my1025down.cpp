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
#include <set>
#include <algorithm>

#define ll long long

using namespace std;
const int MX = 61;
const int MT = 210;
ll N, T, memo[MX][MT]; // FIX: make sure memo is large enough! different dimension sizes!
ll _dist[MX], _pref[MX]; // pref[i] (prefix dist)= time to get from first station to [i]
set<ll> first, last; // train departures

ll op(const ll i, const ll t, const ll const *dist, const ll const *pref) // N^2 log N
{   //         ^           ^                  ^                     ^
    //         ^           ^                  ^                     ^ prefix sum on station distances from the start
    //         ^           ^                  ^ distances between stations
    //         ^           ^ current time aka time to be here at
    //         ^ station idx

    if (!i && !t) return 0;
    if (t <= 0) return 1<<30;

    // if (memo[i][t] < 1<<30) return memo[i][t];	// this makes the answer 17
    if (memo[i][t] > 0) return memo[i][t];		// this makes the answer 17 too
    // ll ret = memo[i][t];				// this makes the answer 10
    ll ret = 1<<30;

    // from trains
    if (i && first.count(t-pref[i])) // not at first station && exists a train from first station : arrives here now
    {
	ret = min(ret, op(i-1, t-dist[i], dist, pref));
    }
    if (i < N-1 && last.count(t-pref[N-1]+pref[i])) // not at last station && exists train from last : arrives here now
    {
	ret = min(ret, op(i+1, t-dist[i+1], dist, pref));
    }
    // waited at this station
    ret = min(ret, op(i, t-1, dist, pref)+1);

    // if (memo[i][t] > -1 && memo[i][t] != ret) printf("at (%3d %3d) was %3d now %3d\n", i, t, memo[i][t], ret);
    memo[i][t] = ret;
    return ret;
}

int main()
{
    int kase=0;
    while (scanf("%d%d", &N, &T) == 2)
    {
	if (!N) break;
	// clear memo
	for (int i=0; i<MX; ++i)
	    for (int j=0; j<MT; ++j)
		memo[i][j] = -1;
	// clear others
	memset(_dist, 0, sizeof(_dist));
	memset(_pref, 0, sizeof(_pref));
	first.clear();
	last.clear();
	
	// input
	for (ll i=1; i<N; ++i)
	{
	    scanf("%d", &_dist[i]);
	    _pref[i] = _dist[i] + _pref[i-1];
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
	ll ret = op(N-1, T, _dist, _pref);

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

// should be 16
*/
