/*
TASK: 242down
LANG: C++14
*/

/*
 * Problem 242down (oj/pid/242down)
 * Create time: Thu 19 Mar 2020 @ 17:47 (PDT)
 * Accept time: Thu 19 Mar 2020 @ 18:25 (PDT)
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

void setIO(const std::string &name = "242down");

using namespace std;
const int MX = 1011;
int S, N, needed[MX];
vector<int> stamps;
int best_cover;
vector<int> best;

int op(int val)
{
    int &ret = needed[val];
    if (ret < 1<<30) return ret;
    FOR_(k, 1, val/2+1)
    {
        ret = min(ret, op(k) + op(val-k));
    }
    return ret;
}

int main()
{
    // setIO();
    while (scanf("%d%d", &S, &N) == 2)
    {
        if (!S) break;
        best_cover=0;
        best.clear();

        FOR(n, N)
        {
            memset(needed, 0x7f, sizeof(needed));
            stamps.clear();

            int count;
            scanf("%d", &count);
            stamps.reserve(count);
            FOR(c, count)
            {
                int d;
                scanf("%d", &d);
                stamps.push_back(d);
                needed[d] = 1;
            }

            int coverage=0;
            while (op(coverage+1) <= S)
                ++coverage;

            sort(stamps.begin(), stamps.end(), greater<int>{});
            if (best.empty()) // FIX: incase best coverage is zero
            {
                best_cover = coverage;
                best = stamps;
            }
            else if (coverage >  best_cover
                    || (coverage == best_cover && (stamps.size() < best.size() ||
                            (stamps.size() == best.size() && stamps < best)
                    ))
                )
            {
                best_cover = coverage;
                best = stamps;
            }
        }
        printf("max coverage =%4d :", best_cover);
        for (auto it=best.rbegin(); it !=best.rend(); ++it) printf("%3d", *it);
        printf("\n");
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
