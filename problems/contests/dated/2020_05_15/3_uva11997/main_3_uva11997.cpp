/*
TASK: 3_uva11997
LANG: C++14
*/

/*
 * Problem 3_uva11997 (contests/dated/2020_05_15/3_uva11997)
 * Create time: Tue 26 May 2020 @ 16:46 (PDT)
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

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "3_uva11997");

using namespace std;
const int MX = 1111;
int N, nums[MX][MX];
priority_queue<int, deque<int>, greater<int> > pq, other;

int main()
{
	while (scanf("%d", &N) == 1)
	{
		for (int i=0; i<N; ++i) for (int j=0; j<N; ++j)
			scanf("%d", &nums[i][j]);
		for (int j=0; j<N; ++j) pq.push(nums[0][j]);
		for (int i=1; i<N; ++i)
		{
			tmp.clear();
			for (int k=0; k<N; ++k)
			{
				tmp.push(pq.top());
				pq.pop();
			}
			pq = {};
			for (int j=0; j<N; ++j)
		}


	return 0;
}

