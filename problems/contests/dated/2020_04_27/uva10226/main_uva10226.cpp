/*
TASK: uva10226
LANG: C++14
*/

/*
 * Problem uva10226 (contests/dated/2020_04_27/uva10226)
 * Create time: Wed 29 Apr 2020 @ 10:59 (PDT)
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

void setIO(const std::string &name = "uva10226");

using namespace std;
const int MX = -1;
map<string, int> cnt;
int tot = 0, kase;

int main()
{
	string line;
	scanf("%d\n\n", &kase);
	while (kase)
	{
		getline(cin, line);
		if (line.length())
		{
			++cnt[line];
			++tot;
		}
		else
		{
			TRAV(p, cnt)
				printf("%s %.4lf\n", p.f.c_str(), (dl)p.s*100/tot);
			printf("\n");
			cnt.clear();
			tot=0;
			--kase;
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
