/*
ID: spoytie2
TASK: pprime
LANG: C++14
*/

/*
 * Problem pprime ([!meta:srcpath!])
 * Create time: Tue 18 Feb 2020 @ 14:31 (PST)
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

void setIO(const std::string &name = "pprime");

using namespace std;
int a, b;

bool isPrime(cn n)
{
    //printf("n: %d, sqrt(n): %d\n", n, (int) sqrt(n));
    FOR_(i, 2, (int) sqrt(n) +1) // FIX: start at 2, everything is divisible by one
    {
        //printf("    divisible by %d ? %d\n", i, n%(i));
        if (n%i == 0) return false;
    }
    return true;
}

int pivotPal(int n)
{
    int ret = n;
    n /= 10;
    while (n)
    {
        ret *= 10;
        ret += n%10;
        n /= 10;
    }
    return ret;
}

int reflectPal(int n)
{
    int ret = n;
    while (n)
    {
        ret *= 10;
        ret += n%10;
        n /= 10;
    }
    return ret;
}

int main()
{
    setIO();
    scanf("%d%d", &a, &b);
    if (a > b) swap(a, b);

    vector<int> pals;
    FOR(i, b)
    {
        if (pivotPal(i) > b) break;
        if (reflectPal(i) < a) continue;
        pals.push_back(pivotPal(i));
        pals.push_back(reflectPal(i));
    }

    sort(pals.begin(), pals.end());
    TRAV(n, pals)
    {
        if (n > b) break;
        if (n >= a && isPrime(n)) printf("%d\n", n);
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
