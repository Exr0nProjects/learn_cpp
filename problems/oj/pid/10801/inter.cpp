#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>
#include <functional>
#include <list>
#include <fstream>

#define int_max 0x3f3f3f3f
#define byte_max 0x3f
#define pow_2(n) (1 << n)

#define pb push_back
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
bool vis[MXF][MXN];

int main()
{

    while(cin >> N >> K){
	for (int i=0; i<MXN; ++i) stops[i].clear();
	for (int i=0; i<MXF; ++i) stopsat[i].clear();
	memset(speed, 0, sizeof speed);
	memset(dist, 0x40, sizeof dist);
	memset(vis, 0, sizeof vis);

	for (int i=0; i<N; ++i) scanf("%d", &speed[i]);

	cin.ignore();
	for(int i = 0; i<N; i++){
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
		printf("%d\n", max(cur.f, 0));
		legit=1;
		break;
	    }

	    if (vis[cur.s.f][cur.s.s]) continue;
	    vis[cur.s.f][cur.s.s] = true;

	    for (auto e : stopsat[cur.s.f])
		for (auto f : stops[e])
		{
		    if (f == cur.s.f) continue;
		    const int eta = cur.f + (e != cur.s.s)*60 + abs(cur.s.f - f) * speed[e];
		    if (dist[f][e] > eta)
		    {
			dist[f][e] = eta;
			pq.emplace(eta, mp(f, e));
		    }
		}
	}
	if (!legit) cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

