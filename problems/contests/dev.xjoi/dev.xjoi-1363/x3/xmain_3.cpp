/*
ID: spoytie2
TASK: 3
LANG: C++14
*/

/*
 * Problem 3 ([!meta:srcpath!])
 * Create time: Wed 19 Feb 2020 @ 09:22 (PST)
 * Accept time: Sun 23 Feb 2020 @ 09:28 (PST)
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
#include <exception>
#include <algorithm>
#include <functional>

#define cn const int
#define ll long long
#define cl const long long
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 0x7FFFFFFF

#define FOR_(i, b, e) for (int i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (int i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define SORT(a, n) std::sort((a), (a) + (n))
#define TRAV(a, x) for (auto &a : x)
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name = "3");

using namespace std;
const int MX = 10010;
int N, K;
double lens[MX];

bool canCut(double len)
{
    int num=0;
    FOR(i, N)
    {
        num += floor(lens[i]/len);
    }
    return num >= K;
}

double binarySearch(double l, double r)
{
    for (int i=0; i<100; i++)
    {
        double m = (r + l) /2;
        if (canCut(m)) l=m;
        else r=m;
    }
    return l;
}

int main()
{
    //setIO();
    scanf("%d%d", &N, &K);
    FOR(i, N)
    {
        scanf("%lf", &lens[i]);
    }

    printf("%.2lf\n", floor(binarySearch(0, 1<<30)*100)/100);

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
