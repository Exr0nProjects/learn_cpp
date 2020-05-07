// AC 7 May 2020, FIX: use long long

#include <iostream>
#include <queue>
#include <list>

#define ll long long

using namespace std;
const int MX = 100111;
list<pair<ll, ll> > head[MX];
bool vis[MX];

int main()
{
	int N, M;
	scanf("%lld%lld", &N, &M);
	for (int i=0; i<M; ++i)
	{
		ll u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		head[u].push_back(make_pair(w, v));
		head[v].push_back(make_pair(w, u));
	}
	ll count=0, cost=0;
	priority_queue<pair<ll, ll>, deque<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
	pq.push(make_pair(0, 1)); // <weight, node>
	while (!pq.empty())
	{
		pair<ll, ll> cur = pq.top(); pq.pop();
		if (vis[cur.second]) continue;
		vis[cur.second] = true;
		++count;
		cost += cur.first;
		if (count == N) break; // FIX: loop over nodes not edges, so count == N not count+1 == N
		for (list<pair<ll, ll> >::iterator it=head[cur.second].begin(); it!=head[cur.second].end(); ++it)
			pq.push(*it);
	}

	printf("%lld\n", cost);
}

