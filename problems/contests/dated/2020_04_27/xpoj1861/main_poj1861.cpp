/*
TASK: poj1861
LANG: C++14
*/

/*
 * Problem poj1861 (contests/dated/2020_04_27/poj1861)
 * Create time: Wed 29 Apr 2020 @ 13:48 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <vector>
#include <utility>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 15111;
vector<pair<int, pair<int, int> > > edges;
int N, M;

// djs
int comps, djs[MX], djf[MX];
vector<pair<int, int> > merges;
void init()
{
	comps = N;
	for (int i=0; i<MX; ++i) djs[i] = 1;
	for (int i=0; i<MX; ++i) djf[i] = i;
	merges.clear();
}
int find(int n)
{
	if (djf[n] != n) djf[n] = find(djf[n]);
	return djf[n];
}
void merge(int oa, int ob)
{
	int a = find(oa);
	int b = find(ob);
	if (a == b) return;
	if (djs[a] < djs[b]) swap(a, b);
	djs[a] += djs[b];
	djf[a] = b;
	--comps;
	//printf("merged %d %d\n", oa, ob);
	merges.push_back(make_pair(oa, ob));
	//printf("merges.size() = %d\n", merges.size());
}

bool check(int mx)
{
	init();
	for (int i=0; i<edges.size() && edges[i].first <= mx; ++i)
		merge(edges[i].second.first, edges[i].second.second);
	return comps == 1;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges.push_back(make_pair(w, make_pair(u, v)));
	}
	sort(edges.begin(), edges.end());	// not needed

	int l=0, r=1<<25;
	for (int i=0; i<50; ++i)
	{
		if (l+1==r)break;
		int m = (l+r)/2;
		if (check(m)) r = m;
		else l = m;
		//printf("merges.size() = %d\n", merges.size());
	}
	printf("%d\n%d\n", r, merges.size());
	for (int i=0; i<merges.size(); ++i)
		printf("%d %d\n", merges[i].first, merges[i].second);

    return 0;
}
