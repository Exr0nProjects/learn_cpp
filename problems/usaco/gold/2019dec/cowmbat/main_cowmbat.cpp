/*
TASK: cowmbat
LANG: C++14
*/

/*
 * Problem cowmbat (usaco/gold/2019dec/cowmbat)
 * Create time: Tue 21 Apr 2020 @ 16:25 (PDT)
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

void setIO(const std::string &name = "cowmbat");

using namespace std;
const int MX = 100111;
const int MXM = 30;
string S;
int N, M, K, adj[MXM][MXM];
map<string, int> dist;

bool legit(const string &s)
{
    int chg=0;
    FOR_(i, 1, s.size())
    {
	if (s[i] != s[i-1])
	{
	    if (i - chg < K)
		return false;
	    chg = i;
	}
    }
    return s.size() - chg >= K;
}

int main()
{
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w+", stdout);
    scanf("%d%d%d", &N, &M, &K);
    cin >> S;
    FOR(i, M) FOR(j, M)
	scanf("%d", &adj[i][j]);

    priority_queue<pair<int, string>, deque<pair<int, string> >, greater<pair<int, string> > > pq;
    pq.emplace(0, S);
    while (!pq.empty())
    {
	pair<int, string> cur = pq.top(); pq.pop();
	// printf("at %s after %d\n", cur.S.c_str(), cur.F);
	if (dist.count(cur.S) && dist[cur.S] < cur.F)
	    continue;
	dist[cur.S] = cur.F;

	if (legit(cur.S))
	{
	    printf("%d\n", cur.F);
	    break;
	}

	FOR(i, cur.S.size()) FOR(c, M) if (c + 'a' != cur.S[i])
	{
	    string then = cur.S;
	    then[i] = c+'a';
	    // printf("	going %s -> %s\n", cur.S.c_str(), then.c_str());
	    if (!dist.count(then) || dist[then] > cur.F + adj[cur.S[i]-'a'][c])
		pq.emplace(cur.F + adj[cur.S[i]-'a'][c], then);
	}
    }

    return 0;
}
