/*
ID: spoytie2
TASK: sprime
LANG: C++14
*/

/*
 * Problem sprime ([!meta:srcpath!])
 * Create time: Tue 18 Feb 2020 @ 15:08 (PST)
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

void setIO(const std::string &name = "sprime");

using namespace std;
const int MX = -1;
int N;


bool isPrime(cn n)
{
    if (n < 2) return 0;
    FOR_(i, 2, (int) sqrt(n) +1)
    {
        //printf("%d / %d => %d", n, i, n%i == 0);
        if (n%i == 0) return false;
    }
    return true;
}

int generate(cn n)
{
    if ((int) log10(n) +1 == N)
    {
        printf("%d\n", n);
    }
    FOR(i, 10)
    {
        if (isPrime(n*10+i))
        {
            generate(n*10+i);
        }
    }
}

int main()
{
    setIO();
    scanf("%d", &N);

    generate(0);

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
