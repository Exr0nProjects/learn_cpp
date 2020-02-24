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
map<pii, pii> point_prefix_idx;
map<int, vector<ll> > horz, vert;

int main()
{
    setIO();
    scanf("%d", &N);
    FOR(i, N)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        points.push_back(MP(x, y));
    }

    sort(points.begin(), points.end());
    TRAV(p, points)
    {
        horz[p.F].PB(p.S);
        if (horz[p.F].size() > 1)
            horz[p.F][horz[p.F].size()-1] += horz[p.F][horz[p.F].size()-2]; // prefix sum
        point_prefix_idx[p].F = horz[p.F].size()-1;
        swap(p.F, p.S); // to sort by y the next time around
    }

    sort(points.begin(), points.end());
    TRAV(p, points)
    {
        vert[p.F].PB(p.S);
        if (vert[p.F].size() >1)
            vert[p.F][vert[p.F].size()-1] += vert[p.F][vert[p.F].size()-2]; // prefix sum
        swap(p.F, p.S); // to sort by y the next time around
        point_prefix_idx[p].S = vert[p.S].size()-1;
    }

    //TRAV(p, horz)
    //{
        ////printf("horizontal prefix sum %d:", p.F);
        //TRAV(n, p.S) printf("%7lld", n);
        //printf("\n");
    //}
    //TRAV(p, vert)
    //{
        //printf("vertical prefix sum %d:", p.F);
        //TRAV(n, p.S) printf("%7lld", n);
        //printf("\n");
    //}

    ll ret=0;
    TRAV(p, points)
    {
        //ll hsum=0, vsum=0;
        //TRAV(y, horz[p.F]) hsum += abs(p.S-y);
        //TRAV(x, vert[p.S]) vsum += abs(p.F-x);
        auto &idx = point_prefix_idx[p];
        auto &h = horz[p.F];
        auto &v = vert[p.S];
        ll hsum_l = idx.F > 0 ? ((idx.F*p.S) - (h[idx.F-1])) : 0;
        ll hsum_r = ((h[h.size()-1]-h[idx.F])-((h.size()-1-idx.F)*p.S));

        ll vsum_l = idx.S > 0 ? ((idx.S*p.F) - (v[idx.S-1])) : 0;
        ll vsum_r = ((v[v.size()-1]-v[idx.S])-((v.size()-1-idx.S)*p.F));

        //printf("    point (%lld %lld) w/ idx (%lld %lld) hsum %lld+%lld vsum %lld+%lld\n", p.F, p.S, idx.F, idx.S, hsum_l, hsum_r, vsum_l, vsum_r);

        ret = (ret + (hsum_l + hsum_r)*(vsum_l + vsum_r)%mod) % mod;
    }

    printf("%d\n", (int) (ret%mod));

    return 0;
}

/*

4
0 0
0 1
1 0
1 2
=> 3

4
0 0
0 1
2 0
5 0
=> 7
*/

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
