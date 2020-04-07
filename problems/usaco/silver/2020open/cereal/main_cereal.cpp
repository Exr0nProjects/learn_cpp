/*
TASK: cereal
LANG: C++14
*/

/*
 * Problem cereal (usaco/silver/2020open/cereal)
 * Create time: Mon 06 Apr 2020 @ 17:17 (PDT)
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

void setIO(const std::string &name = "cereal");

using namespace std;
const int MX = 100111;
int N, M, take[MX], second[MX], output[MX];
int fc[MX], sc[MX]; // first choice, second choice

int main()
{
    setIO();
    scanf("%d%d", &N, &M);
    int taken=0;
    FOR(i, N)
    {
	scanf("%d%d", &fc[i], &sc[i]);
    }
    FORR(i, N)
    {
	int a = fc[i];
	int b = sc[i];
	if (!take[a]++)
	{
	    ++taken;
	    second[a] = b;
	}
	else
	{
	    if (!take[second[a]]++)
	    {
		++taken;
	    }
	}
	// printf("%d\n", taken);
	output[i] = taken;
    }

    FOR(i, N) printf("%d\n", output[i]);

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
