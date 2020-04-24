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

#define cont continue
#define int_max 0x3f3f3f3f
#define byte_max 0x3f
#define max_v 330
#define max_e 50050

using namespace std;

struct node{
    int dist, key;
    bool operator < (const node& b) const{
	return dist > b.dist;
    }
} ;

struct edge{
    int u, v, a, b, w; //from 'u' to 'v'; open for 'a', closed for 'b'; has a weight of w
    bool operator < (const edge& b) const{
	return u < b.u;
    }
} edges[max_e];

int U[max_e], dist[max_v]; //U helps with binary search
int V, E, src, des;
bool vis[max_v];


int dijkstra(){

    memset(dist, byte_max, sizeof(dist));
    memset(vis, false, sizeof(vis));

    priority_queue<node> pq;
    node s {0, src};
    dist[src] = 0;
    pq.push(s);

    while(!pq.empty()){
	node cur = pq.top(); pq.pop();

	if(cur.key == des) return cur.dist;

	if(vis[cur.key]) cont;

	vis[cur.key] = true;

	int ind = lower_bound(U, U + E, cur.key) - U;

	if(U[ind] != cur.key) cont;

	for(int i = ind; edges[i].u == cur.key && i < E; i++){
	    edge e = edges[i];

	    node b {0, e.v};

	    if(e.w > e.a) cont;

	    if((cur.dist % (e.a + e.b) < e.a) && ((cur.dist % (e.a + e.b)) + e.w <= e.a)){
		b.dist = cur.dist + e.w;
	    }else{
		b.dist = cur.dist + e.a + e.b - (cur.dist % (e.a + e.b)) + e.w;
	    }


	    if(dist[b.key] > b.dist){
		dist[b.key] = b.dist;
		pq.push(b);
	    }



	}	

    }

    return -1;

}



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

	printf("Case %d: %d\n", ++kase, dijkstra());

    }



    return 0;
}

