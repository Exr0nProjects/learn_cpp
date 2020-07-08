/*
 * Problem 3_uva122 (contests/dated/2020_07_07/3_uva122)
 * Create time: Tue 07 Jul 2020 @ 14:28 (PDT)
 * Accept time: [!meta:end!]
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
//set<int> shouldve;
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
            printf("%d ", tree[cur]);
            if (tree[cur<<1]) bfs.push(cur<<1);
            if (tree[cur<<1|1]) bfs.push(cur<<1|1);
        }
        printf("\n");
    }
    shouldve.clear();
    memset(tree, 0, sizeof tree);
    broke = 0;
}

//bool insert(int v, char path[])
bool insert(int v, string &path)
{
    int cur = 1;
    for (int i=0; i<MX && (path[i] == 'L' || path[i] == 'R'); ++i)
    {
        //printf("at %d path[%d] = '%c'\n", cur, i, path[i]);
        //shouldve.insert(cur);
        shouldve.pb(cur);
        cur <<=1;
        if (path[i] == 'R')
            cur |= 1;
    }
    if (tree[cur]) broke = 1;
    tree[cur] = v;
    return broke;
}

//bool input()
//{
//    //char path[MX];
//    int v, scanned;
//    char dumb;
//    string path;
//    string group;
//    while (cin >> group)
//    {
//        if (group.size() == 2) return true;
//        stringstream ss(group);
//        ss >> dumb >> v >> dumb >> path;
//        //printf("got '%s' => %d '%s'\n", group.c_str(), v, path.c_str());
//        insert(v, path);
//    }
//    //getline(cin, line);
//    //stringstream ss(line);
//    //while (ss >> dumb)
//    //{
//    //    if (ss.peek() == ')') return true;
//    //    ss >> v >> dumb >> path;
//    //    //insert(v, path);
//    //}
//    return false;
//}

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
        //printf("not complete\n"); continue;

        //if (isend) dump();
    }

	return 0;
}

