// malkvisits silver 10 june 2020

#include <iostream>
#include <vector>

#define pb push_back

using namespace std;
const int MX = 100111;
vector<int> head[MX];
char barns[MX];
int N, M, group[MX], groups=1;

void dfs(int cur, int pre=0)
{
	group[cur] = groups;
	for (auto nxt : head[cur])
		if (nxt != pre)
			if (barns[nxt] == barns[cur])
				dfs(nxt, cur);
}

int main()
{
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w+", stdout);

	scanf("%d%d\n", &N, &M);
	for (int i=1; i<=N; ++i)
		scanf("%c", &barns[i]);

	for (int i=1; i<N; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		head[u].pb(v);
		head[v].pb(u);
	}

	for (int i=1; i<=N; ++i)
	{
		if (group[i]) continue;
		++groups;
		dfs(i);
	}

	for (int i=0; i<M; ++i)
	{
		int u, v;
		char c;
		scanf("%d %d %c", &u, &v, &c);	// FIX (todo)
		if (group[u] != group[v]) printf("1");
		else printf("%d", barns[u] == c);
	}

	printf("\n");
}

