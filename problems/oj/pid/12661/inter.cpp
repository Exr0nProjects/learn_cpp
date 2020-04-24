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
#define g(t, i) get<i>(t)
#define mt make_tuple

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

using namespace std;
const int MX = 311;
const int max_e = 50050;

struct edge{
    int u, v, a, b, w; //from 'u' to 'v'; open for 'a', closed for 'b'; has a weight of w
    bool operator < (const edge& b) const{
	return u < b.u;
    }
} edges[max_e];

int U[max_e], dist[MX]; //U helps with binary search
int V, E, src, des;
bool vis[MX];

int main() {

    int kase = 0;
    while(scanf("%d%d%d%d", &V, &E, &src, &des) == 4){

	memset(U, 0, sizeof(U));

	for(int i = 0; i<E; i++){
	    scanf("%d%d%d%d%d", &edges[i].u, &edges[i].v, &edges[i].a, &edges[i].b, &edges[i].w);
	} 

	sort(edges, edges + E);

	for(int i = 0; i<E; i++){
	    U[i] = edges[i].u;
	}

	// djikstra
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, false, sizeof(vis));

	priority_queue<pair<int, int>, deque<pair<int, int> >, greater<pair<int, int> > > pq;
	pair<int, int> s{0, src};
	dist[src] = 0;
	pq.push(s);

	while(!pq.empty()){
	    pair<int, int> cur = pq.top(); pq.pop();
	    // printf("at %d after %d\n", cur.s, cur.f);

	    if(cur.s == des)
		printf("Case %d: %d\n", ++kase, cur.f);

	    if(vis[cur.s]) continue;

	    vis[cur.s] = true;

	    int ind = lower_bound(U, U + E, cur.s) - U;

	    if(U[ind] != cur.s) continue;

	    for(int i = ind; edges[i].u == cur.s && i < E; i++){
		edge e = edges[i];

		pair<int, int> b {0, e.v};

		if(e.w > e.a) continue;

		if((cur.f % (e.a + e.b) < e.a) && ((cur.f % (e.a + e.b)) + e.w <= e.a)){
		    b.f = cur.f + e.w;
		}else{
		    b.f = cur.f + e.a + e.b - (cur.f % (e.a + e.b)) + e.w;
		}

		if (dist[b.s] > b.f){
		    dist[b.s] = b.f;
		    pq.push(b);
		}
	    }	
	}
    }

    return 0;
}

