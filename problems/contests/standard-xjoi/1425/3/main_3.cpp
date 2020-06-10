/*
 * Problem 3 (contests/standard-xjoi/1425/3)
 * Create time: Tue 09 Jun 2020 @ 07:36 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstring>
#include <vector>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 101;
int N, root=0;
bool vis[MX];

vector<int> head[MX];

int depth(int cur, int pre=0)	// FIX: check each subtree depth individually
{
	//++viscnt;
	vis[cur] = 1;
	if (pre && head[cur].size() == 0) return 0;
	if (pre && head[cur].size() != 2) return -1;

	// i didn't mean it, but this looks alot like XC2000268AH's code
	// much credit to them for making me realize that you need to check subtree depth
	int lef = depth(head[cur][0], cur);
	int rig = depth(head[cur][1], cur);
	if (lef != rig) return -1;
	return lef + 1;
}

int main()
{
	scanf("%d", &N);
	if (__builtin_popcount(N+1) != 1)
	{ printf("no\n"); return 0; }

	for (int i=1; i<=N; ++i)
	{
		int parent;
		scanf("%d", &parent);
		if (parent < 0) root = i;
		else head[parent].pb(i);
	}

	int dep = depth(root);		// FIX: ordering, this needs to assign vis before reading it
	for (int i=0; i<MX; ++i)
		if (head[i].size() && !vis[i])
		{ printf("no\n"); return 0; }

	printf("%s\n", dep >= 0 && true /* viscnt == N */ ? "yes" : "no");

	return 0;
}

