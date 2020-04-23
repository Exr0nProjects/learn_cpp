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

#define cont continue
#define int_max 0x3f3f3f3f
#define byte_max 0x3f
#define pow_2(n) (1 << n)

#define mp make_pair
#define f first
#define s second
#define pb push_back

using namespace std;
const int MXN = 10;
const int MXF = 110;
typedef pair<int, pair<int, int> > node; // < dist, < floor, tower > >

bool stop[MXN][MXF], vis[MXN][MXF];
int cost[MXN], dist[MXN][MXF], n, k;
list<int> stops[MXN];
list<int> stopsat[MXF];

int main() {

    while(cin >> n >> k){
	for (int i=0; i<MXN; ++i) stops[i].clear();
	for (int i=0; i<MXF; ++i) stopsat[i].clear();
	memset(cost, 0, sizeof(cost));
	memset(dist, byte_max, sizeof(dist));
	memset(vis, false, sizeof(vis));

	for(int i = 0; i<n; i++){
	    cin >> cost[i];
	}

	cin.ignore();
	for(int i = 0; i<n; i++){
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

	priority_queue<node, deque<node>, greater<node> > pq;
	pq.emplace(-60, mp(0, n+1));
	bool legit=0;
	while(!pq.empty()){
	    node cur = pq.top(); pq.pop();
	    // printf("floor %d elev %d after %d\n", cur.s.f, cur.s.s, cur.f);
	    //printf("tower -> %5d; floor -> %5d; dist -> %5d\n", cur.t, cur.fl, cur.dist);

	    if(cur.s.f == k)
	    {
		printf("%d\n", cur.f);
		legit=1;
		break;
	    }

	    if(vis[cur.s.s][cur.s.f]) cont;

	    vis[cur.s.s][cur.s.f] = true;

	    for (auto i : stopsat[cur.s.f])
	    {
		for (auto j : stops[i])
		{
		    if (j == cur.s.f) cont;

		    int& D = dist[i][j];
		    const int w = cur.f + (cur.s.s != i)*60 + abs(cur.s.f - j) * cost[i];

		    if(D > w){
			D = w;
			pq.emplace(w, mp(j, i));
		    }
		}
	    }
	}

	if (!legit)
	    cout << "IMPOSSIBLE\n";
    }	
    return 0;
}

