/*
ID: spoytie2
TASK: lifegaurds
LANG: C++14
*/

/*
 * Problem lifegaurds ([!meta:srcpath!])
 * Create time: Wed 19 Feb 2020 @ 19:14 (PST)
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

void setIO(const std::string &name = "lifeguards");

using namespace std;
const int MX = 100010;
int N;
vii shift_change;
//map<int, int> gaurd_alone;
ll gaurd_alone[MX];
ll total_time=0;

int main()
{
    setIO();
    scanf("%d", &N);
    FOR(i, N)
    {
        int b, e;
        scanf("%d%d", &b, &e);
        shift_change.emplace_back(b, i);
        shift_change.emplace_back(e, i);
    }
    sort(shift_change.begin(), shift_change.end());

    //printf("events: \n");
    //TRAV(p, shift_change) printf("t=%d g=%d\n", p.F, p.S);

    bool worked[MX] = {};
    int num_working=0, working=0;
    FOR(i, shift_change.size())
    {
        pair<int, int> &event = shift_change[i];
        if (worked[event.S]) --num_working;
        else ++num_working;
        worked[event.S] = ! worked[event.S]; // toggle gaurd state
        working ^= event.S; // toggle this lifegaurd's working state, this works because toggling twice does net noop
        //                     therefore when num_working is 1, working will be a valid lifegaurd id
        //printf("event at time %d: gaurds %c= %d -> %d       ", event.F, worked[event.S] ? '+' : '-', event.S, num_working);
        if (i < shift_change.size()-1)
        {
            if (num_working == 1) // alone
            {
                gaurd_alone[working] += shift_change[i+1].F - event.F; // works alone until the next event
            }
            if (num_working > 0)
            {
                total_time += shift_change[i+1].F - event.F; // FIX: don't double count overlap between gaurd work times
            }
        }
    }

    ll min_time=gaurd_alone[0];
    FOR(i, N)
    {
        if (gaurd_alone[i] < min_time)
        {
            min_time = gaurd_alone[i];
        }
    }

    printf("%lld\n", total_time - min_time);

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
