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
//const int offset = 10000;
const int offset=0;
int N;
vii points;
vi horz_idx, vert_idx;
map<int, vector<ll> > horz, vert;

int main()
{
    setIO();
    scanf("%d", &N);
    FOR(i, N)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x += offset;
        y += offset;
        points.emplace_back(x, y);

        // TODO: my big brain prefix sum method doesn't work as easily as this because it needs to be sorted in both x and y
        if (horz.count(x)) horz[x].push_back(horz[x][horz[x].size()-1] + y);
        else horz[x].push_back(y);
        horz_idx.push_back(horz[x].size()-1);

        if (vert.count(y)) vert[y].push_back(vert[y][vert[y].size()-1] + x);
        else vert[y].push_back(x);
        vert_idx.push_back(vert[y].size()-1);
    }

    TRAV(p, horz)
    {
        printf("horizontal prefix sum %d:", p.F);
        TRAV(n, p.S) printf("%5lld", n);
        printf("\n");
    }
    TRAV(p, vert)
    {
        printf("vertical prefix sum %d:", p.F);
        TRAV(n, p.S) printf("%5lld", n);
        printf("\n");
    }
    FOR(i, points.size())
    {
        printf("point (%d %d) is h#%d and v#%d\n", points[i].F, points[i].S, horz_idx[i], vert_idx[i]);
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
