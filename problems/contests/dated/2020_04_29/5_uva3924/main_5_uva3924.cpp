/*
TASK: 5_uva3924
LANG: C++14
*/

/*
 * Problem 5_uva3924 (contests/dated/2020_04_29/5_uva3924)
 * Create time: Thu 30 Apr 2020 @ 18:02 (PDT)
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

void setIO(const std::string &name = "5_uva3924");

using namespace std;
const int MX = 400111;
int alloc=1, trie[MX][30];
bool isend[MX];
int tab[MX];

char buf[MX];

void clear()
{
	alloc = 1;
	memset(tab, 0, sizeof tab);
	memset(trie, 0, sizeof trie);
	memset(isend, 0, sizeof isend);
}
void insert(string &s)
{
	int cur=0;
	for (int i=s.length()-1; i>=0; --i)
	{
		if (!trie[cur][s[i]-'a'])
			trie[cur][s[i]-'a'] = alloc++;
		cur=trie[cur][s[i]-'a'];
	}
	isend[cur] = 1;
}
int countback(int idx)
{
	int cur=0, tot=0;
	do {
		cur = trie[cur][buf[idx]-'a'];
		printf("moving to %d (via %c)\n", cur, buf[idx]);
		//if (isend[cur]) tot += tab[idx];
		if (isend[cur]) tot += 1;
		tot %= 20071027;
		-- idx;
		if (idx < 0) break;
	} while (cur);
	return tot;
}

int main()
{
	while (scanf("%s", buf))
	{
		if (!buf[0]) break;
		int S;
		scanf("%d", &S);
		string word;
		for (int i=0; i<S; ++i)
		{
			cin >> word;
			insert(word);
		}

		while (true)
		{
			memset(buf, 0, sizeof buf);
			scanf("%s", buf);
			printf("got %d chars: %s\n", strlen(buf), buf);
			printf("=> %d\n", countback(strlen(buf)-1));
		}

		int i;
		for (i=0; buf[i]; ++i)
		{
			tab[i] = countback(i);
		}
		printf("%d\n", tab[i-1]);
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
