/*
ID: spoytie2
TASK: 5
LANG: C++14
*/

/*
 * Problem 5 ([!meta:srcpath!])
 * Create time: Wed 19 Feb 2020 @ 10:27 (PST)
 * Accept time: Sun 23 Feb 2020 @ 08:59 (PST)
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

void setIO(const std::string &name = "5");

using namespace std;
const int MX = 60010;
int N;
ll pos[MX], vel[MX];

bool overlap(const double time)
{
    // compare min end and max begin
    double mn=pos[0]+vel[0]*time, mx=pos[0]-vel[0]*time;
    FOR_(i, 1, N)
    {
        mn = min(mn, pos[i] + vel[i]*time);
        mx = max(mx, pos[i] - vel[i]*time);
    }
    return mn >= mx;
}

double binarySearch(double l, double r)
{
    if (r-l < 0.0000001) return l;
    double m = (l+r)/2;
    if (overlap(m)) return binarySearch(l, m);
    else return binarySearch(m, r);
}

int main()
{
    //setIO();
    scanf("%d", &N);
    FOR(i, N)
    {
        scanf("%lld", &pos[i]);
    }
    FOR(i, N) scanf("%lld", &vel[i]);

    //for(;;) {
        //double time;
        //scanf("%lf", &time);
        //printf("%d\n", canMeet(time*scalar));
    //}


    printf("%0.5lf\n", binarySearch(0, (double) (1<<30)));

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
