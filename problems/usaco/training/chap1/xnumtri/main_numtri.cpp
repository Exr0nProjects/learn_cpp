/*
ID: spoytie2
TASK: numtri
LANG: C++14
*/

/*
 * Problem numtri ([!meta:srcpath!])
 * Create time: Tue 18 Feb 2020 @ 13:55 (PST)
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

void setIO(const std::string &name = "numtri");

using namespace std;
const int MX = 1010;
int R, triangle[MX*MX/2], tab[MX*MX/2];

int dp(cn p, cn l=1)
{
    if (p > R*(R+1)/2) return 0; // FIX: base case
    if (tab[p] >= 0) return tab[p];
    int ret = triangle[p];
    ret += max(dp(p+l, l+1), dp(p+l+1, l+1)); // FIX: not a binary tree, so we don't do *2 *2+1
    tab[p] = ret;
    return ret;
}

int main()
{
    setIO();
    scanf("%d", &R);
    int cnt=0;
    FOR(i, R)
    {
        FOR(j, i+1) // FIX: i starts as 0 not 1 so we need to do +1
        {
            //printf("cnt = %d\n", cnt);
            tab[cnt] = -1; // FIX: use dp for a triangle of zeros too
            scanf("%d", &triangle[cnt++]);
        }
    }

    printf("%d\n", dp(0));

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
