/*
TASK: 10029down
LANG: C++14
*/

/*
 * Problem 10029down (oj/pid/10029down)
 * Create time: Sat 04 Apr 2020 @ 18:39 (PDT)
 * Accept time: Sun 05 Apr 2020 @ 09:55 (PDT)
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

void setIO(const std::string &name = "10029down");

using namespace std;
const int MX = 25001;
map<string, int> dist;

// graph longest path
int op(const string &src)
{
    if (dist[src]) return dist[src];		// N
    int ret=0;

    FOR(i, src.size())
    {
	string nxt = src;
	// delete
	nxt.erase(i, 1); // FIX: erase just one character, not to the end
	// cout << "delete " << src << "->" << nxt << endl;
	if (nxt < src && dist.count(nxt))
	    ret = max(ret, op(nxt));
	for (char l='a'; l<='z'; ++l)
	{
	    // modify
	    nxt = src;
	    nxt[i] = l;
	    // cout << "modify " << src << "->" << nxt << endl;
	    if (nxt < src && dist.count(nxt))
		ret = max(ret, op(nxt));
	    // add; TODO: needed?
	    nxt = src;
	    nxt.insert(i, 1, l);
	    // cout << "insert " << src << "->" << nxt << endl;
	    if (nxt < src && dist.count(nxt))
		ret = max(ret, op(nxt));
	    // add at the end... only run once, for the first iter of `i` for loop
	    if (!i)
	    {
		nxt = src;
		nxt = src + l;
		// cout << "ins e " << src << "->" << nxt << endl;
		if (nxt < src && dist.count(nxt))
		    ret = max(ret, op(nxt));
	    }
	}
    }
    // printf("=============================\nret: %d\n", ret);

    ++ret; // FIX: count this
    dist[src] = ret;
    return ret;
}

int main()
{
    setIO();
    string word;
    while (cin >> word)
    {
	dist[word] = 0;
    }

    int longest = 0;
    TRAV(p, dist)
	longest = max(longest, op(p.F));
    
    printf("%d\n", longest);

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
