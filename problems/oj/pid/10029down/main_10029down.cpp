/*
TASK: 10029down
LANG: C++14
*/

/*
 * Problem 10029down (oj/pid/10029down)
 * Create time: Sat 04 Apr 2020 @ 18:39 (PDT)
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

void setIO(const std::string &name = "10029down");

using namespace std;
const int MX = 25001;
map<string, int> id_by_str;
vector<string> str_by_id;

// string id system
int N=0;
inline int getId(string s)
{
    if (!id_by_str.count(s))
    {
	id_by_str[s] = id_by_str.size();
	str_by_id.pb(s);
	N = id_by_str.size();
    }
    return id_by_str[s];
}

// graph construction
bool isEditStep(string a, string b)
{
    if ((int)labs(a.size() - b.size()) > 1) return false;
    if (a.size() < b.size()) swap(a, b);

    int l = 0; // number of same letters on the left
    for (; l < b.size() && a[l] == b[l]; ++l);

    if (l == b.size()) return true; // same all the way through

    int r = 1; // number of same letters on the right
    for (; r < b.size() && a[a.size()-r] == b[b.size()-r]; ++r);
    --r; // fencepost

    if (l + r + 1 == a.size()) return true; // just one letter different
    return false;
}

// graph longest path
list<int> head[MX];
int dist[MX];
int op(int src)
{
    if (dist[src]) return dist[src];
    int ret=0;
    TRAV(nxt, head[src])
	ret = max(ret, op(nxt));
    ++ret; // FIX: this
    dist[src] = ret;
    return ret;
}

int main()
{
    setIO();
    str_by_id.reserve(MX);
    string word;
    while (cin >> word)
    {
	// check edge between every pair target that came before it
	FOR(i, getId(word))
	{
	    if (isEditStep(str_by_id[i], word))
	    {
		// "lexographically ordered"
		if (str_by_id[i] < word)
		    head[i].pb(getId(word));
		else
		    head[getId(word)].pb(i);
	    }
	}
    }

    int longest = 0;
    FOR(i, N)
	longest = max(longest, op(i));
    
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
