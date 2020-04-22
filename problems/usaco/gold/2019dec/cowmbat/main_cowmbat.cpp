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
const int MXM = 30;
string S;
map<string, int> stringId;
deque<string> idString;
int id(const string &s)
{
    if (!stringId.count(s))
    {
	stringId[s] = stringId.size();
	idString.pb(s);
    }
    return stringId[s];
}
    
int N, M, K, adj[MXM][MXM];
map<int, int> dist;

bool legit(int id)
{
    const string &s = idString[id];
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
    // freopen("cowmbat.out", "w+", stdout);
    scanf("%d%d%d", &N, &M, &K);
    cin >> S;
    id(S);	// register
    FOR(i, M) FOR(j, M)
	scanf("%d", &adj[i][j]);
    printf("id(S): %d\n", id(S));

    priority_queue<pair<int, int>, deque<pair<int, int> >, greater<pair<int, int> > > pq;
    printf("id(S): %d\n", id(S));
    pq.emplace(0, id(S));
    printf("id(S): %d\n", id(S));
    while (!pq.empty())
    {
	pair<int, int> cur = pq.top(); pq.pop();
	printf("cur.S: %d\n", cur.S);
	printf("at %s after %d\n", idString[cur.S].c_str(), cur.F);
	if (idString.size() > 10 || stringId.size() > 10 || pq.size() > 10 || dist.size() > 10) return 0;
	if (dist.count(cur.S) && dist[cur.S] < cur.F)
	    continue;
	dist[cur.S] = cur.F;
	return 0;

	if (legit(cur.S))
	{
	    printf("%d\n", cur.F);
	    break;
	}

	FOR(i, N) FOR(c, M) if (c + 'a' != idString[cur.S][i])
	{
	    string then = idString[cur.S];
	    const int thendist = cur.F + adj[idString[cur.S][i]-'a'][c];
	    then[i] = c+'a';
	    // printf("	going %s -> %s\n", cur.S.c_str(), then.c_str());
	    if (!dist.count(id(then)) || dist[id(then)] > thendist)
		pq.emplace(thendist, id(then));
	}
    }

    return 0;
}
