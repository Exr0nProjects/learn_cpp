// 7 May 2020, FIX: use long long

#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
const int MX = 100111;
ll N, M;

// djs
ll djs[MX], djf[MX];
void init()
{
	for (int i=0; i<MX; ++i)
	{
		djs[i] = 1;
		djf[i] = i;
	}
}
ll find(ll n)
{
	if (djf[n] != n) djf[n] = find(djf[n]);
	return djf[n];
}
void merge(ll a, ll b)
{
	a = find(a); b = find(b);
	if (a == b) return;
	if (djs[a] < djs[b]) swap(a, b);
	djs[a] += djs[b];
	djf[b] = a;
}

int main()
{
	init();
	vector<pair<ll, pair<ll, ll> > > edges;
	scanf("%lld%lld", &N, &M);
	for (int i=0; i<M; ++i)
	{
		ll u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		edges.pb(mp(w, mp(u, v)));
	}
	sort(edges.begin(), edges.end());
	ll count=0, cost=0;
	for (auto e : edges)
	{
		if (find(e.second.first) != find(e.second.second))
		{
			merge(e.second.first, e.second.second);
			++count;
			cost += e.first;
		}
		if (count + 1 == N) break;
	}
	printf("%lld\n", cost);
}

