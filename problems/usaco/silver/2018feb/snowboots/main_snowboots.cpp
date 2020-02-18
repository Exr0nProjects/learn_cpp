/*
ID: spoytie2
TASK: snowboots
LANG: C++14
*/

/*
 * Problem snowboots ([!meta:srcpath!])
 * Create time: Tue 18 Feb 2020 @ 08:27 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
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

void setIO(const std::string &name = "snowboots");

using namespace std;
const int MX = 260;
int N, B, depth[MX], si[MX], di[MX];

bool canReach(cn max_discard, cn pos=0, cn boot=0)
{
    //printf("    canReach from pos %d with boot %d\n", pos, boot);
    if (boot > max_discard) return false;
    if (pos >= N) return true;

    int next = pos+di[boot];
    bool ret = 0;
    if (si[boot] >= depth[pos])
    {
        for (; next > pos; --next)
        {
            if (depth[next] <= si[boot]){
                ret |= canReach(max_discard, next, boot);
            }
        }
    }
    ret |= canReach(max_discard, pos, boot+1);
    return ret;
}

int binarySearch(cn l, cn r) // inc l exc r
{
    //printf("binary search %d - %d\n", l, r);
    if (l+1 >= r) return l;
    int m = (l+r)/2;
    if (canReach(m)) return binarySearch(l, m);
    else return binarySearch(m, r);
}

int main()
{
    setIO();
    scanf("%d%d", &N, &B);
    FOR(i, N) scanf("%d", &depth[i]);
    FOR(i, B) scanf("%d%d", &si[i], &di[i]);

    printf("%d\n", binarySearch(0, B)+1); // +1 because binarySearch returns the last one that we cannot reach with

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
