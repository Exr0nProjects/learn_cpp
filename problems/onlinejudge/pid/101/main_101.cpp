/*
ID: spoytie2
TASK: 101
LANG: C++14
*/

/*
 * Problem 101 ([!meta:srcpath!])
 * Create time: Tue 11 Feb 2020 @ 07:08 (PST)
 * Accept time: [!meta:end!]
 *
 * STL #2 (https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=835&page=show_problem&problem=37)
 */

#include <iostream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
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

void setIO(const std::string &name = "101");

using namespace std;
const int MX = 50;

list<int> world[MX];
int loc[MX]; // location of block n

int N, src, dst;

int read(int &op)
{
    char buf[80];
    scanf("\n%s", buf);
    if (buf[0] == 'q')
    {
        return 0;
    }

    op = 0;
    if (buf[0] == 'm')
        op |= 2;
    scanf("%d%s", &src, buf);
    if (buf[1] == 'n')
        op |= 1;
    scanf("%d", &dst);
    return 1;
}

void output()
{
    FOR(i, N)
    {
        printf("%d:", i);
        //    for(; !world[i].empty(); world[i].pop_front())
        //    {
        //      printf(" %d", world[i].front());
        //    }
        FOR(j, world[i].size())
        {
            printf(" %d", world[i].front());
            world[i].push_back(world[i].front());
            world[i].pop_front();
        }
        printf("\n");
    }
}

int main()
{
    setIO();
    scanf("%d", &N);
    FOR(i, N)
    world[i].push_back(i); // TODO: use list.splice();
    iota(loc, loc + N, 0);

    //  output();

    int operation;
    while (read(operation))
    {
        //    printf("(%d) %d -> %d\n", operation, src, dst);
        if (loc[src] == loc[dst])
            continue;

        auto &s_pile = world[loc[src]];
        auto &d_pile = world[loc[dst]];

        if (operation & 2) // move type
        {
            for (; s_pile.back() != src; s_pile.pop_back())
            {
                loc[s_pile.back()] = s_pile.back();
                world[s_pile.back()].push_back(s_pile.back());
            }
        }
        if (operation & 1) // onto type
        {
            for (; d_pile.back() != dst; d_pile.pop_back())
            {
                loc[d_pile.back()] = d_pile.back();
                world[d_pile.back()].push_back(d_pile.back());
            }
        }
        // do the final move
        bool found = 0;
        for (auto it = s_pile.begin(); it != s_pile.end() && !s_pile.empty();)
        {
            //      printf("checking %d found? %d\n", *it, found);
            if (*it == src)
                found = true;
            if (found)
            {
                loc[*it] = dst;
                d_pile.push_back(*it);
                it = s_pile.erase(it);
            }
            else
            {
                ++it;
            }
        }
        //    output();
    }

    output();

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
