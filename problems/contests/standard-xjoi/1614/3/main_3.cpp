/*
 * Problem 3 (contests/standard-xjoi/1614/3)
 * Create time: Thu 27 Aug 2020 @ 16:45 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>
#include <random>
#include <map>
#include <set>
#include <string>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <chrono>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = -1;

int N, pos[MX];
list<int> h[MX];

int remain(int c, int p, int k)
{
    memset(pos, 0, 1+k<<2);
    for (int n : h[c]) if (n != p)
        ++pos[remain(n, c, k)];
    int ret=-1;
    if (~k&1 && pos[k>>1]&1) ret = k>>1;    // if even k, center must match self
    for (int i=1; i<=k>>1; ++i)
        if (pos[i] != pos[k-i])
        {
            if (~ret) return -1;
            else ret = pos[i] > pos[k-i] ? i : k-i;
        }
    return ret;
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; ++i)
    {
        int u, v; scanf("%d%d", &u, &v);
        h[u].pb(v); h[v].pb(u);
    }

	return 0;
}

