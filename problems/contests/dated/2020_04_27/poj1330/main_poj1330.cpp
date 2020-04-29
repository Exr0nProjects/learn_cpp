/*
TASK: poj1330
LANG: C++14
*/

/*
 * Problem poj1330 (contests/dated/2020_04_27/poj1330)
 * Create time: Wed 29 Apr 2020 @ 11:40 (PDT)
 * Accept time: [!meta:end!]
 *
 */

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
const int MX = 10111;
list<int> head[MX];
char hasParent[MX];
int N, a, b;

int find(int cur)
{
	//printf("cur %d a%d b%d\n", cur, a, b);
	if (cur == a || cur == b)
		return cur;
	vector<int> child;
	TRAV(nxt, head[cur])
		if (find(nxt))
			child.pb(nxt);
	if (child.size() == 0)
		return 0;
	if (child.size() == 1)
		return child[0];
	if (child.size() == 2)
		return cur;
}

int main()
{
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d", &N);
		memset(hasParent, 0, sizeof hasParent);
		FOR(i, MX) head[i].clear();
		FOR(i, N-1)
		{
			int p, c;
			scanf("%d%d", &p, &c);
			head[p].pb(c);
			hasParent[c] = 1;
		}
		scanf("%d%d", &a, &b);
		FOR(i, N)
			if (!hasParent[i+1])
			{
				printf("%d\n", find(i+1));
				break;
			}
	}

    return 0;
}
