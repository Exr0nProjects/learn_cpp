/*
TASK: 1
LANG: C++14
*/

/*
 * Problem 1 (contests/dated/2020_04_07/1)
 * Create time: Tue 07 Apr 2020 @ 20:25 (PDT)
 * Accept time: Tue 07 Apr 2020 @ 20:55 (PDT)
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

void setIO(const std::string &name = "1");

using namespace std;
const int MX = -1;
int N, M;
bool rotated=0;

void print(int i, int j)
{
    if (rotated)
	printf("%d %d\n", j+1, M-i+1);
    else
	printf("%d %d\n", i+1, j+1);
}

void drawStack(int i, int j)
{
    bool shift=0;
    for (int k=i; k>=0; --k)
    {
	print(k, j-shift);
	shift = !shift; // toggle shift
    }
    for (int k=0; k<=i; ++k)
    {
	print(k, j-shift);
	shift = !shift;
    }
}

int main()
{
    scanf("%d", &N);

    printf("%d\n", N*(N+1)-1);

    M = N+1;

    if (N%2) // rotate
    {
	swap(N, M);
	rotated = 1;
    }

    for (int j=M-1; j>0; j-=2)
	drawStack(N-1, j);

    for (int i=N-1; i>=0; --i)
	print(i, 0);

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
