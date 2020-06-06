/*
TASK: 10801
LANG: C++14
*/

/*
 * Problem 10801 (oj/pid/10801)
 * Create time: Mon 20 Apr 2020 @ 11:57 (PDT)
 * Accept time: [!meta:end!]
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
#define f first
#define s second

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
	for (int i=0; i<MXN; ++i) stops[i].clear();
	for (int i=0; i<MXF; ++i) stopsat[i].clear();
	memset(speed, 0, sizeof speed);
	memset(dist, 0x40, sizeof dist);

	for (int i=0; i<N; ++i) scanf("%d", &speed[i]);

	cin.ignore(); // FIX: waymo's string stream code
	for (int i=0; i<N; ++i)
	{
	    string a;
	    getline(cin, a);
	    istringstream iss (a);
	    int temp;
	    while(iss >> temp){
		stops[i].pb(temp);
		stopsat[temp].pb(i);
	    }
	}

	// djikstra
	priority_queue<pair<int, State>, deque<pair<int, State> >, greater<pair<int, State> > > pq;
	pq.emplace(-60, mp(0, MXN-1));	// dummy start node, -60 to counteract minute wait to change elevators
	bool legit=0;
	while (!pq.empty())
	{
	    pair<int, State> cur = pq.top(); pq.pop();
	    // printf("floor %d elev %d after %d\n", cur.s.f, cur.s.s, cur.f);

	    if (cur.s.f == K)
	    {
		printf("%d\n", max(cur.f, 0));	// FIX: don't output -60 if target floor is zero
		legit=1;
		break;
	    }

	    if (dist[cur.s.f][cur.s.s] < cur.f) continue;

	    for (auto e : stopsat[cur.s.f])
		for (auto f : stops[e])
		{
		    const int eta = cur.f + (e != cur.s.s)*60 + abs(cur.s.f - f) * speed[e];
		    if (dist[f][e] > eta)
		    {
			dist[f][e] = eta;
			pq.emplace(eta, mp(f, e));
		    }
		}
	}
	if (!legit) printf("IMPOSSIBLE\n");
    }

    return 0;
}

