/*
ID: spoytie2
TASK: herding
LANG: C++14
*/

/*
 * Problem herding ([!meta:srcpath!])
 * Create time: Fri 21 Feb 2020 @ 09:18 (PST)
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

void setIO(const std::string &name = "herding");

using namespace std;
const int MX = 100010;
int N, pos[MX];

int solve_min()
{ // aghh there are so many fenceposts
    //                     \/ -2 to ignore the two end cows
    //                                                \/ <---- gap is two or more
    if (pos[N-2]-pos[0] == N-2 && pos[N-1]-pos[N-2] > 2) return 2; // if there is a clump and one off to the right, return two moves
    if (pos[N-1]-pos[1] == N-2 && pos[1]  -pos[0]   > 2) return 2; // same but to the left
    int best=0, beg, end=0; // init best=0 because we always max it, never set explicitly
    for (beg=0; beg<N; ++beg)
    {
        //            \/ -1 because we check +1 later
        //                         \/   <--- here
        for (; end < N-1 && pos[end+1]-pos[beg] <= N-1; ++end); // increment end of window until the next one would put it out of reach of the beginning
        //printf("window: %d..%d with %d gaps\n", beg, end, end-beg+1);
        best = max(best, end - beg +1);
    }
    //printf("%d - %d = %d\n", N, best);
    return N-best;
}

int main()
{
    setIO();
    scanf("%d", &N);
    FOR(i, N) scanf("%d", &pos[i]);

    sort(pos, pos+N);
    //FOR(i, N) printf("%3d", pos[i]); printf("\n");

    int min_ans = solve_min();
    //int max_ans = (pos[N-1] - pos[0] - N +1) - min(pos[N-1] - pos[N-2], pos[1] - pos[0]); // (# gaps) - min(right_waste, left_waste);
    int max_ans = max(pos[N-1] - pos[1], pos[N-2] - pos[0]) - (N-2); // max(range if waste left, range if we waste right) - (cows in between)

    printf("%d\n%d\n", min_ans, max_ans);

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
