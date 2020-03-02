/*
ID: spoytie2
TASK: 2
LANG: C++14
*/

/*
 * Problem 2 ([!meta:srcpath!])
 * Create time: Wed 19 Feb 2020 @ 09:09 (PST)
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
#define dl double
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

void setIO(const std::string &name = "2");

using namespace std;
const int MX = 500010;
int N, K, value[MX], weight[MX];

bool test(dl ans)
{
    vector<dl> math;
    FOR(i, N)
    {
        math.PB(value[i] - weight[i]*ans);
    }
    sort(math.begin(), math.end(), greater<dl>{});
    dl sum=0;
    FOR(i, K) sum += math[i];
    return sum >= 0;
}

dl binarySearch(dl l, dl r)
{
    FOR(i, 100)
    {
        dl m = (l+r)/2;
        if (test(m)) l=m;
        else r=m;
    }
    return l;
}

int main()
{
    //setIO();
    scanf("%d%d", &N, &K);
    FOR(i, N) scanf("%d", &weight[i]);
    FOR(i, N) scanf("%d", &value[i]);

    printf("%.2lf\n", binarySearch(0, 1<<30));

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
