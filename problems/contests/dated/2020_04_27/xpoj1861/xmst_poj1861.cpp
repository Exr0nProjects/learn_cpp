// AC 5 May 2020 @ 17:51 PDT
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 15111;

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
	scanf("%d%d", &N, &M);
	init();
	vector<pair<int, pair<int, int> > > edges;
	for (int i=0; i<M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges.push_back(make_pair(w, make_pair(u, v)));
	}
	sort(edges.begin(), edges.end());
	int count=0, cost=0;
	vector<pair<int, int> > used;
	for (int i=0; i<edges.size(); ++i)
	{
		if (find(edges[i].second.first) != find(edges[i].second.second))
		{
			merge(edges[i].second.first, edges[i].second.second);
			++count;
			cost = edges[i].first;
			used.push_back(edges[i].second);
		}
		if (count + 1 == N) break;
	}
	printf("%d\n%d\n", cost, count);
	for (int i=0; i<count; ++i)
	{
		printf("%d %d\n", used[i].first, used[i].second);
	}
}



