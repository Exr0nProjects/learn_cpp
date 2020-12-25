/*
TASK: boards
LANG: C++14
*/

/*
 * Problem boards (usaco/gold/2020jan/boards)
 * Create time: Mon 13 Apr 2020 @ 13:00 (PDT)
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

void setIO(const std::string &name = "boards");

using namespace std;
const int MX = -1;
int N, M;
set<pair<int, int> > vis;
pair<int, int> dst;
map<pair<int, int>, pair<int, int> > boards;

ll dist(pii a, pii b)
{
    return b.F-a.F + b.S-a.S;
}

int main()
{
    setIO();
    scanf("%d%d", &N, &M);
    dst = mp(N, N);
    FOR(m, M)
    {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	boards[mp(a, b)] = mp(c, d);
    }

    // djikstra
    priority_queue<pair<ll, pii>, deque<pair<ll, pii> >, greater<pair<ll, pii> > > pq;
    pq.push(mp(0, mp(0, 0)));
    while (!pq.empty())
    {
	auto cur = pq.top(); pq.pop();

	if (vis.count(cur.S)) continue;
	vis.insert(cur.S);

	// printf("%lld @ (%d %d)\n", cur.F, cur.S.F, cur.S.S);
	if (cur.S.F == N && cur.S.S == N)
	{
	    printf("%lld\n", cur.F);
	    break;
	}

	cur.S = boards[cur.S]; // use the springboard

	TRAV(p, boards)
	{
	    if (p.F.F >= cur.S.F && p.F.S >= cur.S.S)
		pq.push(mp(cur.F + dist(cur.S, p.F), p.F));
	    pq.push(mp(cur.F + dist(cur.S, dst), dst)); // walk all the way to the end
	}
    }

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
