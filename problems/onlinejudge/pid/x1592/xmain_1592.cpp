/*
ID: spoytie2
TASK: 1592
LANG: C++14
*/

/*
 * Problem 1592 ([!meta:srcpath!])
 * Create time: Mon 17 Feb 2020 @ 10:43 (PST)
 * Accept time: Tue 18 Feb 2020 @ 13:14 (PST)
 *
 */

#include <iostream>
#include <sstream>
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

void setIO(const std::string &name = "1592");

using namespace std;

map<string, int> id_str;
vector<string> str_id;

int encode(string s)
{
    if (! id_str.count(s))
    {
        id_str[s] = id_str.size();
        str_id.push_back(s);
    }
    return id_str[s];
}

int db[10010][20];

void test(cn h, cn w)
{
    FOR(c1, w) FOR_(c2, c1+1, w)
    {
        map<pii, int> at;
        FOR(i, h)
        {
            pii rep(db[i][c1], db[i][c2]);
            if (at.count(rep))
            {
                printf("NO\n%d %d\n%d %d\n", at[rep]+1, i+1, c1+1, c2+1);
                return;
            }
            at[rep] = i;
        }
    }
    printf("YES\n");
}

int main()
{
    setIO();
    int h, w;
    char cell[90];
    //while (scanf("%d %d\n", &h, &w) > 0)
    while (scanf("%[^\n]\n", cell))
    {
        stringstream ss(cell);
        if (!(ss >> h >> w)) break;

        id_str.clear();
        str_id.clear();

        FOR(i, h)
        {
            FOR(j, w)
            {
                scanf("%[^,\n]%*c", cell);
                //printf("got %s\n", cell);
                db[i][j] = encode(cell);
            }
        }
        //FOR(i, h)
        //{
        //FOR(j, w)
        //{
        //printf("%3d", db[i][j]);
        //}

        //printf("\n");
        //}
        test(h, w);
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
