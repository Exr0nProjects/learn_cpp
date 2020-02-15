/*
ID: spoytie2
TASK: where
LANG: C++14
*/

/*
 * Problem where ([!meta:srcpath!])
 * Create time: Sat 15 Feb 2020 @ 09:33 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
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

void setIO(const std::string &name = "where");

using namespace std;
const int MX = 30;
int N;
struct PCL
{
    int ai, aj, bi, bj;
    PCL(int ai, int aj, int bi, int bj): ai(ai), aj(aj), bi(bi), bj(bj) {};
};

string img[MX];

// PCL finding
int vis[MX][MX];
void dfs(cn y, cn x, cn ai, cn aj, cn bi, cn bj, char id)
{
    //printf("    connecting with %d %d\n", y, x);
    vis[y][x] = id;
    const int delta_y[4] = {0, 1, 0, -1};
    const int delta_x[4] = {1, 0, -1, 0};

    FOR(d, 4)
    {
        int dy = delta_y[d];
        int dx = delta_x[d];
        //printf("%+d, %+d\n", dy, dx);
        if ( ai <= y+dy && y+dy <= bi && aj <= x+dx && x+dx <= bj
         &&  img[y][x] == img[y+dy][x+dx] && !vis[y+dy][x+dx])
        {
            dfs(y+dy, x+dx, ai, aj, bi, bj, id);
        }
    }
}
bool isPCL(cn ai, cn aj, cn bi, cn bj)
{
    //printf("checking (%d, %d), (%d, %d)\n", ai, aj, bi, bj);
    FOR_(i, ai, bi+1) FOR_(j, aj, bj+1) vis[i][j] = 0; // reset vis array

    //printf("VIS:\n");
    //FOR(i, N) { FOR(j, N) printf("%2c", vis[i][j] ? vis[i][j] : '.'); printf("\n"); }
    //printf("\n");

    map<char, int> color_count;
    FOR_(i, ai, bi+1) FOR_(j, aj, bj+1)
    {
        if (vis[i][j]) continue;
        //printf("  new color section at %d %d!\n", i, j);
        ++color_count[img[i][j]];
        dfs(i, j, ai, aj, bi, bj, img[i][j]);
    }
    int sum = 0; // FIX: forgot to initialize with zero
    TRAV(p, color_count) sum += p.S;
    //printf("num colors: %d, num reigons: %d\n\n", color_count.size(), sum);
    return color_count.size() == 2 && sum == 3;
}

// PCL checking
vector<PCL> pcls;
bool contains(cn i, cn o)
{
    return (
            pcls[o].ai <= pcls[i].ai
            &&pcls[o].bi >= pcls[i].bi
            &&pcls[o].aj <= pcls[i].aj
            &&pcls[o].bj >= pcls[i].bj
           );
}

int checked=0, checked_out =0;
bool isLargest(cn i)
{
    ++checked;
    FOR(o, pcls.size())
    {
        if (i == o) continue;
        if (contains(i, o)) return false; // FIX: should check if j contains i not if i contains j
    }
    ++checked_out;
    return true;
}

int main()
{
    //setIO();

    freopen("where.in", "r", stdin);
    freopen("where.out", "w+", stdout);

    scanf("%d", &N);
    FOR(i, N) cin >> img[i];

    FOR(i, N) FOR(j, N) vis[i][j] = '#'; // create PCL flood fill boundaries with vis array

    FOR(ai, N) FOR(aj, N)
        FOR_(bi, ai, N) FOR_(bj, aj, N)
        {
            if (isPCL(ai, aj, bi, bj))
            {
                pcls.emplace_back(ai, aj, bi, bj);
                //printf("(%d, %d) (%d, %d) is a PCL!\n", ai, aj, bi, bj);
            }
        }

    int ret = 0;
    FOR(i, pcls.size())
    {
        if (isLargest(i))
        {
            ++ret;
            printf("-> (%d, %d), (%d, %d)\n", pcls[i].ai, pcls[i].aj, pcls[i].bi, pcls[i].bj);
        }
    }

    //printf("pcl size: %d\n", pcls.size());

    printf("%d\n", ret);

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
