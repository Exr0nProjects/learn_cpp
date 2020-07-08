/*
 * Problem 3_uva122 (contests/dated/2020_07_07/3_uva122)
 * Create time: Tue 07 Jul 2020 @ 14:28 (PDT)
 * Accept time: Wed 08 Jul 2020 @ 11:42 (PDT)
 *
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <list>
#include <array>
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
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
const ll MX = 286;
deque<int> shouldve;
int tree[MX*MX];
bool broke = 0;

void dump()
{
    for (auto i : shouldve)
        if (!tree[i])
            broke = 1;
    if (broke)
        printf("not complete\n");
    else
    {
        queue<int> bfs;
        bfs.push(1);
        while (!bfs.empty())
        {
            int cur = bfs.front(); bfs.pop();
            if (cur > 1) printf(" ");
            printf("%d", tree[cur]);
            if (tree[cur<<1]) bfs.push(cur<<1);
            if (tree[cur<<1|1]) bfs.push(cur<<1|1);
        }
        printf("\n");
    }
    shouldve.clear();
    memset(tree, 0, sizeof tree);
    broke = 0;
}

bool insert(int v, string &path)
{
    int cur = 1;
    for (int i=0; i<MX && (path[i] == 'L' || path[i] == 'R'); ++i)
    {
        shouldve.pb(cur);
        cur <<=1;
        if (path[i] == 'R')
            cur |= 1;
    }
    if (tree[cur]) broke = 1;
    tree[cur] = v;
    return broke;
}

int main()
{
    int v, scanned;
    char dumb;
    string path;
    string group;
    while (cin >> group)
    {
        if (group.size() == 2) { dump(); continue; }
        stringstream ss(group);
        ss >> dumb >> v >> dumb >> path;
        insert(v, path);
    }

	return 0;
}

