/*
TASK: 2
LANG: C++14
*/

/*
 * Problem 2 (contests/dated/2020_04_20/2)
 * Create time: Mon 20 Apr 2020 @ 09:05 (PDT)
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

void setIO(const std::string &name = "2");

using namespace std;
const int MX = -1;
ll ret=0;
void dfs(int num, int pre, int k)
{
    if (k == 0 && num == 0) ++ret;
    if (k <= 0 || num <= 0) return;
    for (int i=pre; i<=num; ++i)
	dfs(num-i, i, k-1);
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    dfs(n, 1, k);
    printf("%lld\n", ret);

    return 0;
}
