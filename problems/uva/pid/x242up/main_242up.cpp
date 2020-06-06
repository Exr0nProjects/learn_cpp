/*
TASK: 242up
LANG: C++14
*/

/*
 * Problem 242up (oj/pid/242up)
 * Create time: Thu 19 Mar 2020 @ 18:26 (PDT)
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

void setIO(const std::string &name = "242up");

using namespace std;
const int MX = 1011;
int S, N, tab[MX], bcover=0;
vector<int> stamps, bstamps;

int main()
{
    // setIO();
    while (scanf("%d%d", &S, &N) == 2)
    {
        bcover = 0; // FIX: clear bcover for each test case, not each denomenation set
        bstamps.clear();

        FOR(i, N)
        {
            memset(tab, 0x7f, sizeof(tab));
            stamps.clear();

            int cnt;
            scanf("%d", &cnt);
            stamps.reserve(cnt);
            FOR(i, cnt)
            {
                int d;
                scanf("%d", &d);
                stamps.push_back(d);
                tab[d] = 1;
            }

            tab[0] = 0; // FIX: start coverage at zero, tab[0] = 0 (not inf)
            int coverage;
            for (coverage=0; coverage<MX; ++coverage)
            {
                // printf("uh\n");
                FOR(k, coverage)
                {
                    tab[coverage] = min(tab[coverage], tab[k] + tab[coverage-k]);
                    // printf("tab[%d] = tab[%d](%d) + tab[%d](%d) = %d\n", coverage, k, tab[k], coverage-k, tab[coverage-k], tab[coverage]);
                }
                if (tab[coverage] > S) break;
            }

            sort(stamps.begin(), stamps.end(), greater<int>{});
            if (coverage > bcover || (coverage == bcover && (
                            stamps.size() < bstamps.size() ||
                            (stamps.size() == bstamps.size() && stamps < bstamps)
                        )
                    )
                )
            {
                bcover = coverage;
                bstamps = stamps;
            }
        }
        printf("max coverage =%4d :", bcover-1); // FIX: bcover-1 because previous loop stopped when bcover doesn't work
        for (auto it=bstamps.rbegin(); it!=bstamps.rend(); ++it) printf("%3d", *it);
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
