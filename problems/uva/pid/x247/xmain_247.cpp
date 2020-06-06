/*
ID: spoytie2
TASK: 247
LANG: C++14
*/

/*
 * Problem 247 ([!meta:srcpath!])
 * Create time: Sat 22 Feb 2020 @ 09:02 (PST)
 * Accept time: Sun 19 Apr 2020 @ 12:06 (PDT)
 *
 * Graph problem #3 https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=853&page=show_problem&problem=183
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

void setIO(const std::string &name = "test");

using namespace std;
const int MX = 30;
map<string, int> name_id;
vector<string> id_name;
int id(const string &s)
{
    if (name_id.count(s)) return name_id[s];
    name_id[s] = id_name.size();
    id_name.push_back(s);
    return id_name.size()-1;
}

int dist[MX][MX];

int main()
{
    // setIO();
    int N, M, kase=1;
    while (scanf("%d%d", &N, &M) > 0)
    {
        if (N == 0 && M == 0) return 0;
        name_id.clear();
        id_name.clear();
        FOR(i, MX) FOR(j, MX) dist[i][j] = 1; // FIX: don't int overflow
        FOR(i, M)
        {
            string A, B;
            cin >> A >> B;
            int a = id(A);
            int b = id(B);
            dist[a][b] = 0;
            //printf("dist[%d][%d] = %d\n", a, b, dist[a][b]);
        }
        FOR(k, N)
        {
            FOR(i, N) FOR(j, N) if (dist[i][j] > dist[i][k] + dist[k][j])
            {
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
        // figure out sccs from floyd
        map<int, set<int> > circles;
        bool vis[MX] = {};
        FOR(i, N)
        {
            if (vis[i]) continue;
            vis[i] = 1;
            circles[i]; // FIX: add lonely members to output as well
            FOR(j, N)
            {
                //printf("%3d", dist[i][j]);
                if (i == j) continue;
                if (!dist[i][j] && !dist[j][i]) // FIX: use 0 to mean connected
                {
                    vis[j] = 1;
                    circles[i].insert(j);
                }
            }
            //printf("\n");
        }
        // output
        if (kase > 1) printf("\n");
        printf("Calling circles for data set %d:\n", kase);
        if (M > 0)
            TRAV(p, circles)
            {
                printf("%s", id_name[p.F].c_str());
                TRAV(id, p.S)
                {
                    printf(", %s", id_name[id].c_str());
                }
                printf("\n");
            }
        ++kase;
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
