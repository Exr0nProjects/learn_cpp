/*
TASK: 10801
LANG: C++14
*/

/*
 * Problem 10801 (oj/pid/10801)
 * Create time: Mon 20 Apr 2020 @ 11:57 (PDT)
 * Accept time: [!meta:end!]
 * TODO: TLE
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
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define g(t, i) get<i>(t)
#define mt make_tuple

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "10801");

using namespace std;
const int MXN = 10;
const int MXF = 110;
typedef pair<int, int> State; // <floor number, elevator id>
list<int> stops[MXN];
list<int> stopsat[MXF];
int N, K, speed[MXN], dist[MXF][MXN];

int main()
{
    while (scanf("%d%d", &N, &K) == 2)
    {
	FOR(i, MXN) stops[i].clear();
	FOR(i, MXF) stopsat[i].clear();
	memset(speed, 0, sizeof speed);
	memset(dist, 0x40, sizeof dist);

	FOR(i, N) scanf("%d", &speed[i]);
	for (int i=0; i<N;)
	{
	    int f, c;
	    scanf("%d%c", &f, &c);
	    stops[i].pb(f);
	    stopsat[f].pb(i);
	    if (c == '\n') ++i;
	}

	// djikstra
	priority_queue<pair<int, State>, deque<pair<int, State> >, greater<pair<int, State> > > pq;
	pq.emplace(-60, mp(0, MXN-1));	// dummy start node, -60 to counteract minute wait to change elevators
	bool legit=0;
	while (!pq.empty())
	{
	    pair<int, State> cur = pq.top(); pq.pop();
	    
	    if (cur.S.F == K)
	    {
		legit=1;
		cout << cur.F << endl;
		break;
	    }

	    if (dist[cur.S.F][cur.S.S] < cur.F) continue;	// FIX: dist.count, cuz its a map
	    dist[cur.S.F][cur.S.S] = cur.F;

	    // change elevators
	    TRAV(e, stopsat[cur.S.F])
		if (e != cur.S.S)
		{
		    State then(cur.S.F, e);
		    if (dist[then.F][then.S] > cur.F+60)
			pq.emplace(cur.F + 60, then);
		}
	    // change floors
	    TRAV(f, stops[cur.S.S])
		if (f != cur.S.F)
		{
		    State then(f, cur.S.S);
		    const int eta = cur.F + abs(cur.S.F - f)*speed[cur.S.S];
		    if (dist[then.F][then.S] > eta)
			pq.emplace(eta, then);
		}
	}
	if (!legit) cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
