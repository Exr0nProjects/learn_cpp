#include <vector>
#include <iostream>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;
const int MX = 100111;
int N, M;

// djs
int djs[MX], djf[MX];
void init()
{
	for (int i=0; i<MX; ++i)
	{
		djs[i] = 1;
		djf[i] = i;
	}
}
int find(int n)
{
	if (djf[n] != n) djf[n] = find(djf[n]);
	return djf[n];
}
void merge(int a, int b)
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
	vector<pair<int, pair<int, int> > > edges;
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges.pb(mp(w, mp(u, v)));
	}
	sort(edges.begin(), edges.end());
	int count=0, cost=0;
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
	printf("%d\n", cost);
}

