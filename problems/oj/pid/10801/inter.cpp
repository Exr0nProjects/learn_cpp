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
#define max_v 110
#define N 6
#define pow_2(n) (1 << n)

#define mp make_pair
#define f first
#define s second



using namespace std;

typedef pair<int, pair<int, int> > node; // < dist, < floor, tower > >

bool stop[N][max_v], vis[N][max_v];
int cost[N], dist[N][max_v], n, k;

int get_dist(int tower, int s, int d){
	if(!stop[tower][s] || !stop[tower][d]) return int_max;
	else return abs(s - d) * cost[tower];
}

int ele(int cur_ele, int i){
	if(cur_ele == i)
		return 0;
	else
		return 60; 
}

int dijkstra(){
	
	memset(dist, byte_max, sizeof(dist));
	memset(vis, false, sizeof(vis));
	
	priority_queue<node, deque<node>, greater<node> > pq;
	
	for(int i = 0; i<n; i++){
		if(!stop[i][0]) cont;
		dist[i][0] = 0;
		pq.emplace(0, mp(0, i));
	}
	
	while(!pq.empty()){
		node cur = pq.top(); pq.pop();
		
		// printf("floor %d elev %d after %d\n", cur.s.f, cur.s.s, cur.f);
		//printf("tower -> %5d; floor -> %5d; dist -> %5d\n", cur.t, cur.fl, cur.dist);
		
		
		if(cur.s.f == k) return cur.f;
		
		if(vis[cur.s.s][cur.s.f]) cont;
		
		vis[cur.s.s][cur.s.f] = true;
		
		for(int i = 0; i<n; i++){
			if(!stop[i][cur.s.f]) cont;
			
			for(int j = 0; j<=100; j++){
				if(!stop[i][j] || j == cur.s.f) cont;
				
				int& D = dist[i][j];
				int w = cur.f + get_dist(i, cur.s.f, j) + ele(cur.s.s, i);
				
				if(D > w){
					D = w;
					pq.emplace(w, mp(j, i));
				}
			}
		}
	}
	return -1;
}


int main() {
	
	while(cin >> n >> k){
		memset(cost, 0, sizeof(cost));
		memset(stop, false, sizeof(stop));
		
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
				stop[i][temp] = true;
			}
		}
		
		int ans = dijkstra();
		
		if(ans >= 0)
			cout << ans << endl;
		else
			cout << "IMPOSSIBLE\n";
	}	
  	return 0;
}

