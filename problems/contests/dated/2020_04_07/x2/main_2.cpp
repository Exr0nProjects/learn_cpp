/*
TASK: 2
LANG: C++14
*/

/*
 * Problem 2 (contests/dated/2020_04_07/2)
 * Create time: Wed 08 Apr 2020 @ 07:53 (PDT)
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
#define F first
#define S second
#define g(t, i) get<i>(t)
#define mt make_tuple

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "2");

using namespace std;
const int MX = 50111;
int N, pepl[MX], ans=0, dst=-1, far=0;
list<int> head[MX];

void calcDist(int cur, int pre=-1, int stp=0)
{
    ans = max(ans, stp * pepl[cur]);
    if (dst < stp)
    {
	dst = stp;
	far = cur;
    }

    for (int nxt : head[cur])
	if (nxt != pre)
	    calcDist(nxt, cur, stp+1);
}

int main()
{
    scanf("%d", &N);
    for (int i=0; i<N; ++i)
	scanf("%d", &pepl[i+1]);
    for (int i=0; i<N-1; ++i)
    {
	int u, v;
	scanf("%d%d", &u, &v);
	head[u].pb(v);
	head[v].pb(u);
    }

    calcDist(1); // find one corner
    calcDist(far); // find the other, use dist from first corner
    calcDist(far); // use dist from second corner

    printf("%d\n", ans);

    return 0;
}

void setIO(const string &name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // fast cin/cout
    if (fopen((name + ".in").c_str(), "r") != nullptr)
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w+", stdout);
    }
}
