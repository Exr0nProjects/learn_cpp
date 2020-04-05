/*
TASK: 10029up
LANG: C++14
*/

/*
 * Problem 10029up (oj/pid/10029up)
 * Create time: Sun 05 Apr 2020 @ 11:28 (PDT)
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

void setIO(const std::string &name = "10029up");

using namespace std;
const int MX = -1;
map<string, int> dist;

int main()
{
    setIO();
    string word;
    int global = 0;
    while (cin >> word)
    {
	int ret = 0;
	// generate possibilities
	FOR(i, word.size())
	{
	    string next = word;
	    next.erase(i, 1);
	    if (dist.count(next))
		ret = max(ret, dist[next]);
	    for (char l='a'; l<='z'; ++l)
	    {
		next = word;
		next[i] = l;
		if (dist.count(next))
		    ret = max(ret, dist[next]);
		next = word;
		next.insert(i, 1, l);
		if (dist.count(next))
		    ret = max(ret, dist[next]);
		// add to the end
		if (!i)
		{
		    next = word + l;
		    if (dist.count(next))
			ret = max(ret, dist[next]);
		}
	    }
	}
	++ret; // FIX: count a step
	dist[word] = ret;
	global = max(global, ret);
    }

    printf("%d\n", global);

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
