/*
TASK: 4
LANG: C++14
*/

/*
 * Problem 4 (contests/dated/2020_04_07/4)
 * Create time: Tue 07 Apr 2020 @ 18:35 (PDT)
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

void setIO(const std::string &name = "4");

using namespace std;
const int MX = 50111000;

ll N;
const ll MOD = 998244353;
int h_tab[MX];

ll h_m(long long m)
{ // return highest power of two that is a factor of m
    // printf("    getting value of %d\n", m);
    if (m+10 < MX && h_tab[m]) return h_tab[m];
    ll og = m;
    ll ret = 0;
    while (m % 2 == 0)
    {
	++ret;
	m /= 2;
    }
    if (m+10 < MX) h_tab[og] = ret;
    return ret;
}

ll f_i(long long num)
{
    // printf("f_i %d (%d)\n", num, (ll)sqrt(num)+1);
    ll ret = 0;

    for (ll i=1; i<(ll)sqrt(num)+1; ++i)
    {
	if (num % i) continue; // not a factor
	ret = (ret + ((ll) 1<<h_m(i))) % MOD;
	if (i*i != num)
	    ret = (ret + ((ll) 1<<h_m(num/i))) % MOD;
    }
    // printf("=> %d\n", ret);
    return ret;
}

int main()
{
    scanf("%lld", &N);

    ll ret = 0;
    FOR_(i, 1, N+1)
	ret = (ret + f_i(i)) % MOD;

    printf("%lld\n", ret);

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
