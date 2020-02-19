/*
ID: spoytie2
TASK: 5
LANG: C++14
*/

/*
 * Problem 5 ([!meta:srcpath!])
 * Create time: Wed 19 Feb 2020 @ 10:27 (PST)
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

void setIO(const std::string &name = "5");

using namespace std;
const int MX = 60010;
const int scalar = 100000;
int N;
ll pos[MX], vel[MX];

bool canMeet(const ll time)
{
    // make ranges
    vector<pair<ll, ll> > ranges;
    FOR(i, N)
    {
        pair<ll, ll> r(pos[i] - vel[i]*time, pos[i] + vel[i]*time);
        //printf("pushing range (p %lld v %lld) -> %lld..%lld\n", pos[i], vel[i], r.F, r.S);
        ranges.push_back(r);
    }
    // check if they overlap
    pair<ll, ll> overlap = ranges[0];
    TRAV(p, ranges)
    {
        if ((p.F <= overlap.F && overlap.F <= p.S)
         || (overlap.F <= p.F && p.F <= overlap.S))
        {
            // if overlap
            overlap = {max(p.F, overlap.F), min(p.S, overlap.S)};
        }
        else
        {
            //printf("ERR! %lld..%lld X %lld..%lld\n", overlap.F, overlap.S, p.F, p.S);
            return false; // this one doesn't make it!
        }
    }
    return true;
}

ll binarySearch(ll l, ll r)
{
    if (l+1 >= r) return l;
    ll m = (l+r)/2;
    if (canMeet(m)) return binarySearch(l, m);
    else return binarySearch(m, r);
}

int main()
{
    //setIO();
    scanf("%d", &N);
    FOR(i, N)
    {
        scanf("%lld", &pos[i]);
        pos[i] *= scalar;
    }
    FOR(i, N) scanf("%lld", &vel[i]);

    //for(;;) {
        //double time;
        //scanf("%lf", &time);
        //printf("%d\n", canMeet(time*scalar));
    //}


    printf("%0.5lf\n", (double)(binarySearch(0, (double) (1<<30) * scalar)+1)/scalar);

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
