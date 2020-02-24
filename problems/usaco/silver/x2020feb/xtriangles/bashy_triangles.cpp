/*
ID: spoytie2
TASK: triangles
LANG: C++14
*/

/*
 * Problem triangles ([!meta:srcpath!])
 * Create time: Sun 23 Feb 2020 @ 14:42 (PST)
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

void setIO(const std::string &name = "triangles");

using namespace std;
const int MX = -1;
const ll mod = pow(10, 9) + 7;
int N;
vii points;
map<int, vi> horz, vert;

int main()
{
    setIO();
    scanf("%d", &N);
    FOR(i, N)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        points.push_back(MP(x, y));
        horz[x].PB(y);
        vert[y].PB(x);
    }

    ll ret=0;
    TRAV(p, points)
    {
        ll hsum=0, vsum=0;
        TRAV(y, horz[p.F]) hsum += abs(p.S-y);
        TRAV(x, vert[p.S]) vsum += abs(p.F-x);
        //printf("    point (%lld %lld) hsum %lld vsum %lld\n", p.F, p.S, hsum, vsum);
        ret = (ret + hsum*vsum%mod) % mod;
    }

    printf("%d\n", (int) (ret%mod));

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
