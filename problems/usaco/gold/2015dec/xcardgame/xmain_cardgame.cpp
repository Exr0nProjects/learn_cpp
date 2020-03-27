/*
TASK: cardgame
LANG: C++14
*/

/*
 * Problem cardgame (usaco/gold/2015dec/cardgame)
 * Create time: Thu 26 Mar 2020 @ 21:01 (PDT)
 * Accept time: Thu 26 Mar 2020 @ 21:23 (PDT)
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

void setIO(const std::string &name = "cardgame");

using namespace std;
const int MX = 50111;
int N, eleft[MX/2], eright[MX/2], bessie[MX];
bool ehas[MX*2];

int main()
{
    setIO();
    // input
    scanf("%d", &N);
    FOR(i, N/2)
    {
        scanf("%d", &eleft[i]);
        ehas[eleft[i]] = 1;
    }
    FOR(i, N/2)
    {
        scanf("%d", &eright[i]);
        ehas[eright[i]] = 1;
    }
    // count bessie's cards
    int idx=0;
    FORR_(i, 1, N*2+1)
        if (!ehas[i])
            bessie[idx++] = i;

    reverse(bessie, bessie+N/2);
    // FOR(i, N) printf("%3d", bessie[i]); printf("\n");

    sort(eleft, eleft+N/2);
    sort(eright, eright+N/2, greater<int>{});

    int score=0;
    // play the first half
    for (int i=0, j=0; i<N/2 && j<N/2; ++i, ++j) // i is else idx, j is bessie idx
    {
        while (bessie[j] < eleft[i]) ++j;
        if (j<N/2) ++score;
    }
    // play the second half
    for (int i=0, j=N/2; i<N/2 && j<N; ++i, ++j)
    {
        while (bessie[j] > eright[i]) ++j;
        if (j<N) ++score;
    }

    printf("%d\n", score);

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
