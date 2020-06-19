/*
 * Problem 3 (contests/2020summer401/2/3)
 * Create time: Fri 19 Jun 2020 @ 10:57 (PDT)
 * Accept time: Fri 19 Jun 2020 @ 11:16 (PDT)
 *
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
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

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 11000111;
ll N, Q, addt[MX], counter=0;

struct Edge { int t, n; } edges[MX<<1];
ll head[MX], alloc=1;
void addEdge(int a, int b)
{
	edges[alloc].t = b;
	edges[alloc].n = head[a];
	head[a] = alloc++;
}
void traverse(ll cur, ll pre=0, ll acc=0)
{
	acc += addt[cur];
	for (ll e=head[cur]; e; e=edges[e].n)
	{
		if (edges[e].t != pre)
			traverse(edges[e].t, cur, acc);
	}
	addt[cur] = acc;
}

//list<int> head[MX];
//void addEdge(ll a, ll b)
//{
//    head[a].pb(b);
//}
//void traverse(ll cur, ll pre=0, ll acc=0)
//{
//    if (counter++ > MX) return;
//    acc += addt[cur];
//    for (ll nxt : head[cur])
//        if (nxt != pre)
//            traverse(nxt, cur, acc);
//    addt[cur] = acc;
//}

int main()
{
	scanf("%lld%lld", &N, &Q);
	for (ll i=1; i<N; ++i)
	{
		ll u, v; scanf("%lld%lld", &u, &v);
		addEdge(u, v); addEdge(v, u);
	}

	for (ll i=0; i<Q; ++i)
	{
		ll d, v; scanf("%lld%lld", &d, &v);
		addt[d] += v;
	}

	traverse(1);
	for (ll i=1; i<=N; ++i) printf("%lld\n", addt[i]);

	return 0;
}

