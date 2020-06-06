/*
TASK: 821
LANG: C++14
*/

/*
 * Problem 821 (oj/pid/821)
 * Create time: Sun 19 Apr 2020 @ 12:11 (PDT)
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

void setIO(const std::string &name = "821");

using namespace std;
const int MX = 111;
int dist[MX][MX];
int id[MX]; // id system for numbers cuz they aren't continuous
set<int> nums;
bool last_was_zeros = false;

int main()
{
    int kase=0;
    int u, v;
    memset(dist, 0x38, sizeof dist);		// FIX: can't do 0x40 because 2* that is overflow
    memset(id, 0, sizeof id); // shouldn't be needed
    while (scanf("%d%d", &u, &v) == 2)
    {
	if (u || v)
	{
	    last_was_zeros = 0;
	    nums.insert(u);
	    if (!id[u]) id[u] = nums.size();
	    nums.insert(v);
	    if (!id[v]) id[v] = nums.size();
	    dist[id[u]][id[v]] = 1;
	}
	else
	{
	    if (last_was_zeros)
		break;	// end of input

	    const int N = nums.size();
	    FOR_(k, 1, N+1) FOR_(i, 1, N+1) FOR_(j, 1, N+1)
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	    // FOR(i, N+1) { FOR(j, N+1) printf("%10d", dist[i][j]); printf("\n"); }

	    dl avg=0;
	    FOR_(i, 1, N+1) FOR_(j, 1, N+1) if (i != j)
		avg += dist[i][j];

	    printf("Case %d: average length between pages = %.3lf clicks\n", ++kase, avg/(N*N-N));

	    memset(dist, 0x38, sizeof dist);
	    memset(id, 0, sizeof id);
	    nums.clear();
	    last_was_zeros = 1;
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
